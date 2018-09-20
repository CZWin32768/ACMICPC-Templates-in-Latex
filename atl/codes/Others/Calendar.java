//Constructors:
GregorianCalendar(int year, int month, int dayOfMonth)
GregorianCalendar(int year, int month, int dayOfMonth, int hourOfDay, int minute)
GregorianCalendar(int year, int month, int dayOfMonth, int hourOfDay, int minute, int second)

//Fields
//Field number for get and set indicating the day of the month.
static int	DAY_OF_MONTH
//Field number for get and set indicating the day of the week.
static int	DAY_OF_WEEK
//Field number for get and set indicating the day number within the current year.
static int	DAY_OF_YEAR
//Field number for get and set indicating the hour of the day.
static int	HOUR_OF_DAY
//Field number for get and set indicating the week number within the current month.
static int	WEEK_OF_MONTH
//Field number for get and set indicating the week number within the current year.
static int	WEEK_OF_YEAR
//Field number for get and set indicating the second within the minute.
static int	SECOND
//Field number for get and set indicating the minute within the hour.
static int	MINUTE
//Field number for get and set indicating the hour of the morning or afternoon.
static int	HOUR
//Field number for get and set indicating the day of the month.
static int	DATE
//Field number for get and set indicating the month.
static int	MONTH
//Field number for get and set indicating the year.
static int	YEAR
//The currently set time for this calendar, expressed in milliseconds after January 1, 1970, 0:00:00 GMT.
protected long	time

//Methods:
//Converts calendar field values to the time value (millisecond offset from the Epoch).
protected void	computeTime()
//Returns the number of weeks in the week year represented by this GregorianCalendar.
int	getWeeksInWeekYear()
//Returns the week year represented by this GregorianCalendar.
int	getWeekYear()
//Determines if the given year is a leap year.
boolean	isLeapYear(int year)
//Sets the GregorianCalendar change date.
void setGregorianChange(Date date)
//Returns whether this Calendar represents a time after the time represented by the specified Object.
boolean	after(Object when)
//Returns whether this Calendar represents a time before the time represented by the specified Object.
boolean	before(Object when)
//Compares the time values (millisecond offsets from the Epoch) represented by two Calendar objects.
int	compareTo(Calendar anotherCalendar)
//Returns a Date object representing this Calendar's time value (millisecond offset from the Epoch").
Date getTime()


//Examples:
import java.util.GregorianCalendar;
import java.util.Calendar;

// Accessing Year, Month, Day etc.
Calendar calendar = new GregorianCalendar();

int year       = calendar.get(Calendar.YEAR);
int month      = calendar.get(Calendar.MONTH); 
int dayOfMonth = calendar.get(Calendar.DAY_OF_MONTH); // Jan = 0, not 1
int dayOfWeek  = calendar.get(Calendar.DAY_OF_WEEK);
int weekOfYear = calendar.get(Calendar.WEEK_OF_YEAR);
int weekOfMonth= calendar.get(Calendar.WEEK_OF_MONTH);

int hour       = calendar.get(Calendar.HOUR);        // 12 hour clock
int hourOfDay  = calendar.get(Calendar.HOUR_OF_DAY); // 24 hour clock
int minute     = calendar.get(Calendar.MINUTE);
int second     = calendar.get(Calendar.SECOND);
int millisecond= calendar.get(Calendar.MILLISECOND);

Calendar calendar = new GregorianCalendar();

//set date to last day of 2009
calendar.set(Calendar.YEAR, 2009);
calendar.set(Calendar.MONTH, 11); // 11 = december
calendar.set(Calendar.DAY_OF_MONTH, 31); // new years eve

//add one day
calendar.add(Calendar.DAY_OF_MONTH, 1);
//calendar.add(Calendar.DAY_OF_MONTH, -1);

//date is now jan. 1st 2010
int year       = calendar.get(Calendar.YEAR);  // now 2010
int month      = calendar.get(Calendar.MONTH); // now 0 (Jan = 0)
int dayOfMonth = calendar.get(Calendar.DAY_OF_MONTH); // now 1

// set gregorian change at another date
calendar.setGregorianChange(new Date(92, 12, 10));