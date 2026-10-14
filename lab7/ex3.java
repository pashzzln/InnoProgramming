import static java.lang.Math.abs;

class TimeCreator {

    Time createTime(int h){
        return new Time(h);
    }

    Time createTime(int h, int m){
        return new Time(h, m);
    }

    Time createTime(int h, int m, int s){
        return new Time(h, m, s);
    }

    static class Time{
        private int hours;
        private int minutes;
        private int seconds;

        private Time(int h){
            this.hours = h;
            this.minutes = 0;
            this.seconds = 0;
            this.convert();
        }

        private Time(int h, int m){
            this.hours = h;
            this.minutes = m;
            this.seconds = 0;
            this.convert();
        }

        private Time(int h, int m, int s){
            this.hours = h;
            this.minutes = m;
            this.seconds = s;
            this.convert();
        }

        void convert(){
            if (this.seconds > 59){
                this.minutes += this.seconds / 60;
                this.seconds = this.seconds % 60;
            }
            if (this.minutes > 59){
                this.hours += this.minutes / 60;
                this.minutes = this.minutes % 60;
            }
            if (this.hours > 23){
                this.hours = this.hours % 24;
            }
        }

        Time inc(){

            this.convert();

            if (this.hours == 23 && this.minutes == 59 && this.seconds == 59) {this.hours = 0; this.minutes = 0; this.seconds = 0; return this;}
            if (this.minutes == 59 && this.seconds == 59) {this.hours += 1; this.minutes = 0; this.seconds = 0; return this;}
            if (this.seconds == 59) {this.minutes += 1; this.seconds = 0; return this;}

            this.seconds += 1;
            return this;
        }

        public int getHours() {
            return hours;
        }

        public void setHours(int hours) {
            this.hours = hours;
        }

        public int getMinutes() {
            return minutes;
        }

        public void setMinutes(int minutes) {
            this.minutes = minutes;
        }

        public int getSeconds() {
            return seconds;
        }

        public void setSeconds(int seconds) {
            this.seconds = seconds;
        }

        @Override
        public String toString() {
            return hours + ":" + minutes + ":" + seconds;
        }

        Time difference(Time t) {
            int s1 = this.hours*3600 + this.minutes*60 + this.seconds;
            int s2 = t.getHours()*3600 + t.getMinutes()*60 + t.getSeconds();
            int s = abs(s1 - s2);
            return new Time(0, 0, s);
        }
    }

}

public class ex3 {
    public static void main(String[] args){
        TimeCreator t = new TimeCreator();

        TimeCreator.Time t1 = t.createTime(12, 30, 30);
        TimeCreator.Time t2 = t.createTime(20, 10, 57);

        t2.inc().inc().inc();

        System.out.println(t1.difference(t2));
    }
}
