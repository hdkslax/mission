/*
* idea: switch with no break
*/
public class DayInYear {
    // month - which month in the year
    // day - which day in the month
    public int dayInYear(int month, int day){
        int sumDays = 0;
        switch(month){
            case 12:
                sumDays += 31;
            case 11:
                sumDays += 30;
            case 10:
                sumDays += 31;
            case 9:
                sumDays += 30;
            case 5:
                sumDays += 30;
            case 4:
                sumDays += 31;
            case 3:
                sumDays += 28;
            case 2:
                sumDays += 31;
            case 1:
                sumDays += day;
        }
        return sumDays;
    }

}
