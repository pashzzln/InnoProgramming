#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// minimum of two numbers
int min(int a, int b){
    if (a < b) return a;
    else return b;
}

// driver status
typedef enum {
    ACTIVE,
    RETIRED,
    DISQUALIFIED
} DriverStatus;

// race type
typedef enum {
    NORMAL_RACE,
    SPRINT_RACE
} RaceType;

// result type
typedef enum {
    FINISHED,
    DID_NOT_FINISH,
    DISQUALIFIED_RESULT
} ResultType;

// extra info
typedef union {
    float finish_time;
    char *dnf_reason;
    char *disqualification_reason;
} ResultExtra;


// race result
typedef struct {
    int driver_id;
    int position;
    ResultType result_type;
    ResultExtra extra;
} RaceResult;

// driver info
typedef struct {
    int driver_id;
    char *name;
    char *team;

    DriverStatus status;

    int races_completed;
    int wins;
    int points;
} Driver;

// race info
typedef struct {
    int id;
    RaceType type;
    int k; // number of results
    RaceResult *results;
} Race;

// find index of driver by id
int indexOfDriver(int id, Driver* drivers, int N){
    for (int i = 0; i < N; i++){
        if (drivers[i].driver_id == id){
            return i;
        }
    }
    return -1;
}

// printing driver info
void driverInfo(int id, Driver* drivers, int N, FILE* output){
    int index = indexOfDriver(id, drivers, N);
    if (index == -1){
        fputs("NOT FOUND\n", output);
    } else {
        Driver d = drivers[index];
        fprintf(output, "%d %s %s\n", d.driver_id, d.name, d.team);
        if (d.status == ACTIVE){
            fputs("STATUS ACTIVE\n", output);
        } else if (d.status == RETIRED){
            fputs("STATUS RETIRED\n", output);
        } else if (d.status == DISQUALIFIED){
            fputs("STATUS DISQUALIFIED\n", output);
        }
        fprintf(output, "RACES %d\n", d.races_completed);
        fprintf(output, "WINS %d\n", d.wins);
        fprintf(output, "POINTS %d\n", d.points);
    }
}

// printing team info
void teamInfo(char* name, Driver* drivers, int N, FILE* output){
    int team_drivers = 0; // number of drivers
    int points = 0; // points of all drivers
    int wins = 0; // wins of all drivers
    
    // sum of points and wins of the team
    for (int i = 0; i < N; i++){
        if (strcmp(drivers[i].team, name) == 0){
            team_drivers += 1;
            points += drivers[i].points;
            wins += drivers[i].wins;
        }
    }
    
    fprintf(output, "%s\n", name);
    fprintf(output, "DRIVERS %d\n", team_drivers);
    fprintf(output, "POINTS %d\n", points);
    fprintf(output, "WINS %d\n", wins);
}

// comparing two drivers
// points -> wins -> id
Driver drivercmp(Driver d1, Driver d2){
    if (d1.points > d2.points){
        return d1;
    } else if (d1.points < d2.points){
        return d2;
    } else {
        if (d1.wins > d2.wins){
            return d1;
        } else if (d1.wins < d2.wins){
            return d2;
        } else {
            if (d1.driver_id < d2.driver_id){
                return d1;
            } else {
                return d2;
            }
        }
    }
}

// finding the best driver
void top(Driver* drivers, int N, FILE* output){
    if (N == 0){
        fputs("NO DATA\n", output);
    } else {
        Driver top = drivers[0]; // the best driver
        
        for (int i = 0; i < N; i++){
            top = drivercmp(top, drivers[i]);
        }
        fprintf(output, "%d %s %s %d\n", top.driver_id, top.name, top.team, top.points);
    }
}

// all drivers from top to bottom
void standings(Driver* drivers, int N, FILE* output){
    for (int i = 0; i < N-1; i++){
        for (int j = i + 1; j < N; j++){
            Driver d1 = drivers[i];
            Driver d2 = drivers[j];
            Driver tmp;
            if (d1.points < d2.points){
                tmp = drivers[i];
                drivers[i] = drivers[j];
                drivers[j] = tmp;
            } else if (d1.points == d2.points){
                if (d1.wins < d2.wins){
                    tmp = drivers[i];
                    drivers[i] = drivers[j];
                    drivers[j] = tmp;
                } else if (d1.wins == d2.wins){
                    if (d1.driver_id > d2.driver_id){
                        tmp = drivers[i];
                        drivers[i] = drivers[j];
                        drivers[j] = tmp;
                    }
                }
            }
        }
        fprintf(output, "%d %s %s %d %d\n", drivers[i].driver_id, drivers[i].name, drivers[i].team, drivers[i].points, drivers[i].wins);
    }
    fprintf(output, "%d %s %s %d %d\n", drivers[N-1].driver_id, drivers[N-1].name, drivers[N-1].team, drivers[N-1].points, drivers[N-1].wins); // printing last driver as "for" works only under N-1
}

// adding new driver
void addDriver(int id, char* name, char* team, Driver** drivers, int* N){
    
    //creating new slot for the driver
    Driver* tmp = realloc(*drivers, (*N + 1) * sizeof(Driver));
    // checking if not enough memory
    if (tmp == NULL) {
        return;
    }
    *drivers = tmp;
    
    // creating new driver
    (*drivers)[*N].driver_id = id;
    
    (*drivers)[*N].name = (char *) malloc(strlen(name) * sizeof(char) + 1);
    // checking if not enough memory
    if ((*drivers)[*N].name == NULL) {
        return;
    }
    strcpy((*drivers)[*N].name, name);
    
    (*drivers)[*N].team = (char *) malloc(strlen(team) * sizeof(char) + 1);
    // checking if not enough memory
    if ((*drivers)[*N].team == NULL) {
        return;
    }
    strcpy((*drivers)[*N].team, team);
    
    (*drivers)[*N].status = ACTIVE;
    
    (*drivers)[*N].races_completed = 0;
    (*drivers)[*N].wins = 0;
    (*drivers)[*N].points = 0;
    
    // increasing value of N
    *N += 1;
}

// changing status of the driver
void changeStatus(int id, Driver* drivers, int N, char status){
    int index = indexOfDriver(id, drivers, N);
    if (index != -1){
        if (status == 'r'){
            drivers[index].status = RETIRED;
        } else if (status == 'd'){
            drivers[index].status = DISQUALIFIED;
        }
    }
}

// printing race info
void raceInfo(int id, Race* races, int R, FILE* output){
    for (int i = 0; i < R; i++){
        if (races[i].id == id){
            
            fprintf(output, "RACE %d\n", races[i].id);
            
            int finished = 0;
            int dnf = 0;
            int dsq = 0;
            
            // calculating finished, dnf and dsq drivers
            for (int j = 0; j < races[i].k; j++){
                if (races[i].results[j].result_type == FINISHED){
                    finished += 1;
                } else if (races[i].results[j].result_type == DID_NOT_FINISH){
                    dnf += 1;
                } else if (races[i].results[j].result_type == DISQUALIFIED_RESULT){
                    dsq += 1;
                }
            }
            
            fprintf(output, "FINISHED %d\n", finished);
            fprintf(output, "DNF %d\n", dnf);
            fprintf(output, "DISQUALIFIED %d\n", dsq);
            
            // finding winner id
            int winner_id;
            
            int D = 0; // dnf/dsq results before first finished
            int firstFinishedPos = 1000; // position of the first finished
            
            for (int r = 0; r < races[i].k; r++){
                if (races[i].results[r].result_type == FINISHED){
                    firstFinishedPos = min(races[i].results[r].position, firstFinishedPos);
                }
            }
            D = firstFinishedPos - 1;
            
            for (int j = 0; j < races[i].k; j++){
                if (races[i].results[j].position - D == 1){
                    winner_id = races[i].results[j].driver_id;
                }
            }
            
            fprintf(output, "WINNER %d\n", winner_id);
            return;
        }
    }
    fputs("NOT FOUND\n", output);
}

int main(int argc, const char * argv[]) {
    
    // opening files
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    // checking if files can not be opened
    if (output == NULL || input == NULL) {
        return 1;
    }
    
    // set of drivers
    Driver* drivers;
    
    // reading number of pilots
    int N;
    fscanf(input, "%d", &N);
    
    // creating memory slots for drivers
    drivers = (Driver*) malloc(N * sizeof(Driver));
    
    // checking if not enough memory
    if (drivers == NULL) {
        return 1;
    }
    
    // reading pilots
    for (int i = 0; i < N; i++){
        int id;
        char name[31];
        char team[31];
        
        fscanf(input, "%d %s %s", &id, name, team);
        
        drivers[i].driver_id = id;
        drivers[i].name = (char *) malloc(strlen(name) * sizeof(char) + 1);
        // checking if not enough memory
        if (drivers[i].name == NULL) {
            return 1;
        }
        strcpy(drivers[i].name, name);
        drivers[i].team = (char *) malloc(strlen(team) * sizeof(char) + 1);
        // checking if not enough memory
        if (drivers[i].team == NULL) {
            return 1;
        }
        strcpy(drivers[i].team, team);
        drivers[i].status = ACTIVE;
        drivers[i].races_completed = 0;
        drivers[i].wins = 0;
        drivers[i].points = 0;
    }
    
    // set of races
    Race* races;
    
    // number of races
    int R;
    fscanf(input, "%d", &R);
    
    // creating memory slots for races
    races = (Race*) malloc(R * sizeof(Race));
    
    // checking if not enough memory
    if (races == NULL) {
        return 1;
    }
    
    //reading races info
    for (int i = 0; i < R; i++){
        int id;
        int k;
        char buffer[50];
        
        fscanf(input, "%d %s %d", &id, buffer, &k);
        
        races[i].id = id;
        races[i].k = k;
        
        // str -> enum
        if (strcmp(buffer, "NORMAL_RACE") == 0) races[i].type = NORMAL_RACE;
        if (strcmp(buffer, "SPRINT_RACE") == 0) races[i].type = SPRINT_RACE;
        
        // creating memory slots for results
        races[i].results = (RaceResult*) malloc(k * sizeof(RaceResult));
        
        // checking if not enough memory
        if (races[i].results == NULL) {
            return 1;
        }
        
        // reading results of the race
        for (int j = 0; j < k; j++){
            int id;
            int position;
            
            fscanf(input, "%d %d %s", &id, &position, buffer);
            
            races[i].results[j].driver_id = id;
            races[i].results[j].position = position;
            
            
            
            if (strcmp(buffer, "FINISHED") == 0) {
                races[i].results[j].result_type = FINISHED;
                fscanf(input, "%f", &races[i].results[j].extra.finish_time);
            }
            if (strcmp(buffer, "DID_NOT_FINISH") == 0){
                races[i].results[j].result_type = DID_NOT_FINISH;
                
                fscanf(input, "%s", buffer);
                
                // creating memory slots for dnf reason
                races[i].results[j].extra.dnf_reason = (char*) malloc(strlen(buffer) * sizeof(char) + 1);
                
                // checking if not enough memory
                if (races[i].results[j].extra.dnf_reason == NULL) {
                    return 1;
                }
                
                strcpy(races[i].results[j].extra.dnf_reason, buffer);
                
                continue;
            }
            if (strcmp(buffer, "DISQUALIFIED_RESULT") == 0){
                races[i].results[j].result_type = DISQUALIFIED_RESULT;
                
                fscanf(input, "%s", buffer);
                
                // creating memory slots for disqualification reason
                races[i].results[j].extra.disqualification_reason = (char*) malloc(strlen(buffer) * sizeof(char) + 1);
                
                // checking if not enough memory
                if (races[i].results[j].extra.disqualification_reason == NULL) {
                    return 1;
                }
                
                strcpy(races[i].results[j].extra.disqualification_reason, buffer);
                
                continue;
            }
        }
    }
    
    // adding points
    
    // points tables
    // index + 1 = place, value = points
    int nr[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1}; // points for normal race
    int sr[8] = {8, 7, 6, 5, 4, 3, 2, 1}; // points for sprint race
    
    // races
    for (int i = 0; i < R; i++){
        
        int D = 0; // dnf/dsq results before first finished
        int firstFinishedPos = 1000; // position of the first finished
        
        for (int r = 0; r < races[i].k; r++){
            if (races[i].results[r].result_type == FINISHED){
                firstFinishedPos = min(races[i].results[r].position, firstFinishedPos);
            }
        }
        
        D = firstFinishedPos - 1;
        
        // races results
        for (int r = 0; r < races[i].k; r++){
            
            // adding points for places
            for (int d = 0; d < N; d++){
                
                if (races[i].results[r].driver_id == drivers[d].driver_id){
                    
                    if (races[i].results[r].result_type == FINISHED){
                        
                        drivers[d].races_completed += 1;
                        
                        if (races[i].results[r].position - D == 1){
                            drivers[d].wins += 1;
                        }
                        
                        if (races[i].type == NORMAL_RACE){
                            
                            if (races[i].results[r].position < 11+D){
                                drivers[d].points += nr[races[i].results[r].position-D-1];
                            }
                            
                        } else if (races[i].type == SPRINT_RACE){
                            
                            if (races[i].results[r].position < 9+D){
                                drivers[d].points += sr[races[i].results[r].position-D-1];
                            }
                            
                        }
                        
                    }
                    
                }
            }
        }
    }
    
    // reading number of comands
    int Q;
    fscanf(input, "%d", &Q);
    
    // reading commands
    for (int i = 0; i < Q; i++){
        char buffer[50];
        int arg;
        char name[50];
        char team[50];
        
        fscanf(input, "%s", buffer);
        
        if (strcmp(buffer, "STANDINGS") == 0){
            standings(drivers, N, output);
        } else if (strcmp(buffer, "TOP") == 0){
            top(drivers, N, output);
        } else if (strcmp(buffer, "DRIVER") == 0){
            fscanf(input, "%d", &arg);
            driverInfo(arg, drivers, N, output);
        } else if (strcmp(buffer, "RETIRE") == 0){
            fscanf(input, "%d", &arg);
            changeStatus(arg, drivers, N, 'r');
        } else if (strcmp(buffer, "DISQUALIFY") == 0){
            fscanf(input, "%d", &arg);
            changeStatus(arg, drivers, N, 'd');
        } else if (strcmp(buffer, "RACE_STATS") == 0){
            fscanf(input, "%d", &arg);
            raceInfo(arg, races, R, output);
        } else if (strcmp(buffer, "TEAM") == 0){
            fscanf(input, "%s", team);
            teamInfo(team, drivers, N, output);
        } else if (strcmp(buffer, "ADD_DRIVER") == 0){
            fscanf(input, "%d", &arg);
            fscanf(input, "%s", name);
            fscanf(input, "%s", team);
            addDriver(arg, name, team, &drivers, &N);
        }
    }
    
    // freeing drivers
    for (int i = 0; i < N; i++) {
        free(drivers[i].name);
        free(drivers[i].team);
    }
    free(drivers);

    // freeing races
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < races[i].k; j++) {
            if (races[i].results[j].result_type == DID_NOT_FINISH) {
                free(races[i].results[j].extra.dnf_reason);
            } else if (races[i].results[j].result_type == DISQUALIFIED_RESULT) {
                free(races[i].results[j].extra.disqualification_reason);
            }
        }
        free(races[i].results);
    }
    free(races);
    
    // closing files
    fclose(input); fclose(output);
    return 0;
}
