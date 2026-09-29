//p.zelenov@innopolis.university

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rover {
    int x;
    int y;
    int battery;
    int heat;
    int cargo;
    int mode; // 0 - IDLE, 1 - ACTIVE, 2 - SAFE
    int distance;
    int accepted;
    int rejected;
    int restores;
    int checkpoint_valid;
} Rover;

int L; // rover's zone
int CAP; // carrying capacity of the rover
int BMAX; // maximum battery capacity

// maximum of two numbers
int max(int a, int b){
    if (a > b) return a;
    else return b;
}

// minimum of two numbers
int min(int a, int b){
    if (a < b) return a;
    else return b;
}

// Starting work of the rover
int start_rover (Rover* r){
    if (r->mode == 1) return -1; // mode is ACTIVE
    if (r->mode == 2) return -2; // mode is SAFE
    if (r->battery < 5) return -3; // battery is less than 5
    if (r->heat >= 80) return -4; // heat is equal or more than 80
    r->mode = 1;
    return 1; // rover starts (ACTIVE mode)
}

// Stopping work of the rover
int stop_rover(Rover* r){
    if (r->mode != 1) return -5; // mode is not ACTIVE
    r->mode = 0;
    return 2; // rover stops (IDLE mode)
}

// Moving the rover to the (x, y)
int move_rover(Rover* r, int* rx, int* ry, int dx, int dy){
    
    int new_x = *rx + dx;
    int new_y = *ry + dy;
    int d = abs(dx) + abs(dy);
    int e = d * (2 + r->cargo);
    
    
    if (r->mode != 1) return -10; // mode is not ACTIVE
    if (d == 0) return -11; // if dx and dy both are 0 then the sum of their absolute values (it is d) will be zero
    if (abs(new_x) > L || abs(new_y) > L) return -12; // absolute value of x > L means that if x < 0 then x < -L, if x > 0 then x > L
    if (r->battery < e) return -13; // battery is less than required
    
    *rx = new_x;
    *ry = new_y;
    r->battery -= e;
    r->heat += d + r->cargo;
    r->distance += d;
    
    if (r->heat >= 100 || r->battery == 0) r->mode = 2; // rover is in SAFE mode
    
    return 3; // rover moves
}

// Loading cargo on the rover
int load_cargo(Rover* r, int w){
    if (r->mode != 0) return -20; // mode is not IDLE
    if (r->x !=0 || r->y != 0) return -21; // rover is not at the base
    if (w <= 0) return -22; // weight of cargo is equal or less than 0
    if (r->cargo + w > CAP) return -23; // rover cant lift the cargo
    
    r->cargo += w;
    return 4; // cargo is lifted
}

// Unloading cargo from the rover
int unload_cargo(Rover* r, int w){
    if (r->mode == 1) return -30; // mode is ACTIVE
    if (w <= 0) return -31; // weight of cargo is equal or less than 0
    if (w > r->cargo) return -32; // required weight is greater than cargo weight
    
    r->cargo -= w;
    return 5; // cargo is unloaded
}

// Cooling the rover
int cool_rover(Rover* r){
    if (r->mode == 1) return -40; // mode is ACTIVE
    
    r->heat = max(0, r->heat-25);
    
    if (r->mode == 2 && r->heat < 80 && r->battery > 0) r->mode = 0; // If rover is in SAFE mode, heat is less than 80 and battery is greater than 0, rover will be in IDLE mode
    
    return 6; // rover is cooled
}

// Recharging the rover
int recharge_rover(Rover* r, int amount){
    if (r->mode == 1) return -50; // mode is ACTIVE
    if (r->x !=0 || r->y != 0) return -51; // rover is not at the base
    if (amount <= 0) return -52; // amount of charging is equal or less than 0
    
    r->battery = min(BMAX, r->battery + amount);
    if (r->mode == 2 && r->heat < 80 && r->battery > 0) r->mode = 0; // If rover is in SAFE mode, heat is less than 80 and battery is greater than 0, rover will be in IDLE mode
    return 7; // rover is recharged
}

// Saving state of the rover
int save_state(Rover* r, int* checkpoint){
    if (r->mode != 0) return -60; // mode is not IDLE
    
    *checkpoint = r->x;
    *(checkpoint+1) = r->y;
    *(checkpoint+2) = r->battery;
    *(checkpoint+3) = r->heat;
    *(checkpoint+4) = r->cargo;
    r->checkpoint_valid = 1;
    
    return 8; // state is saved
}

// Restoring state
int restore_state(Rover* r, int* checkpoint){
    if (r->mode == 1) return -70; // mode is ACTIVE
    if (r->checkpoint_valid == 0) return -71; // checkpoint isnt valid
    
    r->x = *(checkpoint);
    r->y = *(checkpoint + 1);
    r->battery = *(checkpoint + 2);
    r->heat = *(checkpoint + 3);
    r->cargo = *(checkpoint + 4);
    
    r->mode = 0;
    
    r->restores += 1;
    
    return 9; // state is restored
}


// printing status of the rover, command_name - firts letter (s for status, f for finish)
void print_status(FILE* file, Rover* r, char command_name) {
    fprintf(file, "%c %d %d %d %d %d %d %d %d %d %d %d\n", command_name, r->x, r->y, r->battery, r->heat, r->cargo, r->mode, r->distance, r->accepted, r->rejected, r->restores, r->checkpoint_valid);
}

int main(int argc, const char * argv[]) {
    
    // creating rover (filling its states with zero)
    Rover rover;
    rover.x = 0;
    rover.y = 0;
    rover.battery = 0;
    rover.heat = 0;
    rover.cargo = 0;
    rover.mode = 0;
    rover.distance = 0;
    rover.accepted = 0;
    rover.rejected = 0;
    rover.restores = 0;
    rover.checkpoint_valid = 0;
    
    // array for checkpoint
    int checkpoint[5];
    
    // string for reading commands
    char command[9];
    
    // opening files for inout and output
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    // returning 1 if one of those files are null
    if (input == NULL || output == NULL){
        return 1;
    }
    
    char buffer[100]; // buffer for reading strings
    
    // reading first string
    if (fgets(buffer, 100, input) != NULL){
        sscanf(buffer, "%d %d %d %d %d", &rover.battery, &BMAX, &rover.heat, &CAP, &L);
    }
    
    int N = 0; // number of commands
    // reading number of commands
    if (fgets(buffer, 100, input) != NULL){
        sscanf(buffer, "%d", &N);
    }
    
    // reading commands
    for (int i = 0; i < N; i++){
        
        int arg1; // argument 1 if exists
        int arg2; // argument 2 if exists
        
        int code = 0; // returning code for each command
        
        if (fgets(buffer, 100, input)!= NULL){
            sscanf(buffer, "%8s %d %d", command, &arg1, &arg2);
            
            if ( strcmp(command, "STATUS") == 0 ) {print_status(output, &rover, 'S'); continue;}
            
            if ( strcmp(command, "START") == 0 ) code = start_rover(&rover);
            
            if ( strcmp(command, "STOP") == 0 ) code = stop_rover(&rover);
            
            if ( strcmp(command, "MOVE") == 0 ) code = move_rover(&rover, &rover.x, &rover.y, arg1, arg2);
            
            if ( strcmp(command, "LOAD") == 0 ) code = load_cargo(&rover, arg1);
            
            if ( strcmp(command, "UNLOAD") == 0 ) code = unload_cargo(&rover, arg1);
            
            if ( strcmp(command, "COOL") == 0 ) code = cool_rover(&rover);
            
            if ( strcmp(command, "RECHARGE") == 0 ) code = recharge_rover(&rover, arg1);
            
            if ( strcmp(command, "SAVE") == 0 ) code = save_state(&rover, checkpoint);
            
            if ( strcmp(command, "RESTORE") == 0 ) code = restore_state(&rover, checkpoint);
            
            fprintf(output, "R %d\n", code);
            
            if (code > 0) rover.accepted += 1;
            else if (code < 0) rover.rejected += 1;
        }
        
    }
    
    print_status(output, &rover, 'F'); // printing final status of the rover (finnidhing program)
    
    fclose(input); fclose(output); // closing files
}
