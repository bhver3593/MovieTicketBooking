
#include "movie.h"

Movie::Movie() : name(""), genre(""), rating(""), format(""), ticketsPurchased(0),
	ticketsAdult(0), ticketsChild(0), adultPrice(ADULT_PRICE), childPrice(CHILD_PRICE), 
	showDate(""), showTime("") 
{
	seat = new const char *[NUM_SEATS];
	for(int i = 0; i < NUM_SEATS; ++i)
	{
		seat[i] = "XX";
	}
}

Movie::Movie(string newName, string newGenre, string newRating, string newFormat) :
	ticketsPurchased(0), ticketsAdult(0), ticketsChild(0), adultPrice(ADULT_PRICE), 
	childPrice(CHILD_PRICE), showDate(""), showTime("")
{
	if(newName != "" && newGenre != "" && newRating != "" && newFormat != "")
	{
		name = newName;
		genre = newGenre;
		format = newFormat;
		rating = newRating;
	}
	seat = new const char *[NUM_SEATS];
	for(int i = 0; i < NUM_SEATS; ++i)
	{
		seat[i] = "XX";
	}
}

Movie::~Movie()
{
/*
	for(int i = 0; i < NUM_SEATS; ++i)
	{
		delete seat[i];
	}
	delete [] seat;
*/
}

double Movie::calcTotalAdultPrice(double newAdultTickets)
{
	double numAdultTickets = 0;
	if(newAdultTickets >= 0)
	{
		numAdultTickets = newAdultTickets;
	}
	return ADULT_PRICE * numAdultTickets;
}

double Movie::calcTotalChildPrice(double newChildTickets)
{
	double numChildTickets = 0;
	if(newChildTickets >= 0)
	{
		numChildTickets = newChildTickets;
	}
	return CHILD_PRICE * numChildTickets;
}

double Movie::calcTotalPrice(double adultTickets, double childTickets)
{
	double totalAdultPrice = 0;
	double totalChildPrice = 0;
	double totalTax = 0;
	if(adultTickets >= 0 && childTickets >= 0)
	{
		totalAdultPrice = calcTotalAdultPrice(adultTickets);
		totalChildPrice = calcTotalChildPrice(childTickets);
		totalTax = (totalAdultPrice + totalChildPrice) * SALES_TAX;
	}
	return (totalAdultPrice + totalChildPrice + totalTax);
}

void Movie::selectShowDate(int choice)
{
	if(choice > 0 && choice < 5)
	{
		switch(choice)
			{
				case 1:
					showDate = "2022-12-22";
					break;
				case 2:
					showDate = "2022-12-23";
					break;
				case 3:
					showDate = "2022-12-24";
					break;
				case 4:
					showDate = "2022-12-25";
					break;	
			} 	
	}
}

void Movie::selectShowTime(int choice)
{
	if(choice > 0 && choice < 5)
	{
		switch(choice)
		{
			case 1:
				showTime = "12:30 PM";
				break;
			case 2:
				showTime = "2:15 PM";
				break;
			case 3:
				showTime = "4:45 PM";
				break;
			case 4:
				showTime = "7:00 PM";
				break;	
		} 
	}
}

void Movie::setTicketsAdultChild(int newTicketsAdult, int newTicketsChild)
{
	if(newTicketsAdult >= 0 && newTicketsChild >= 0)
	{
		ticketsAdult = newTicketsAdult;
		ticketsChild = newTicketsChild;
	}
}

void Movie::selectSeat(const char **choice, int numSeatsPurchased)
{
	seat = choice;
	if(numSeatsPurchased > 0)
	{
		ticketsPurchased = numSeatsPurchased;
	}
}

bool Movie::editMovie(string newName, string newGenre, string newRating, string newFormat,
	double newAdultPrice, double newChildPrice)
{
	bool flag = false;
	if(newName != "" && newGenre != "" && newRating != "" && newFormat != ""
		&& newAdultPrice > 0 && newChildPrice > 0)
	{	
		name = newName;
		genre = newGenre;
		rating = newRating;
		format = newFormat;
		adultPrice = newAdultPrice;
		childPrice = newChildPrice;
		flag = true;
	}
	return flag;
}

int Movie::calcSeatsRemaining() { return (MAX_SEATS - ticketsPurchased); }

string Movie::getName() const { return name; }

string Movie::getGenre() const { return genre; }

string Movie::getRating() const { return rating; }

string Movie::getFormat() const { return format; }

int Movie::getTicketsPurchased() const { return ticketsPurchased; }

int Movie::getTicketsAdult() const { return ticketsAdult; }

int Movie::getTicketsChild() const { return ticketsChild; }

double Movie::getAdultPrice() const { return adultPrice; }

double Movie::getChildPrice() const { return childPrice; }

string Movie::getShowDate() const { return showDate; }

string Movie::getShowTime() const { return showTime; }

const char** Movie::getSeat() const { return seat; }



