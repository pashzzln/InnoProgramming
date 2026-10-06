import java.time.Duration;
import java.time.LocalTime;

class Time{
    LocalTime time;
    
    public Time(LocalTime time){
        this.time = time;
    }

    void compareTo(Time t){
        Duration duration = Duration.between(this.time, t.time);
        long hours = duration.abs().toHours();
        long minutes = duration.abs().toMinutesPart();
        long seconds = duration.abs().toSecondsPart();
        System.out.println("Hours - " + hours + ", Minutes - " + minutes + ", Seconds - " + seconds);
    }
}

public class ex7 {
    public static void main(String[] args) {
        Time t1 = new Time(LocalTime.of(14, 20, 0));
        Time t2 = new Time(LocalTime.of(10, 0, 15));

        t1.compareTo(t2);
    }
}
