//Constructors
//As of JDK version 1.1, replaced by Calendar.set(year + 1900, month, date) or GregorianCalendar(year + 1900, month, date).
Date(int year, int month, int date)

//Allocates a Date object and initializes it to represent the specified number of milliseconds since the standard base time known as "the epoch", namely January 1, 1970, 00:00:00 GMT.
Date(long date)

//Methods
boolean	after(Date when)
boolean	before(Date when)
void	setTime(long time)

