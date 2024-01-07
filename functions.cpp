
#define ROWS 4
#define COLUMNS 4 
#define NUM_MOVIES 6

#include "functions.h"

void printMenu()
{
	cout << "Main Menu:" << endl << endl;
	cout << "1. Book Tickets" << endl;
	cout << "2. Show My Tickets" << endl;
	cout << "3. Show Movie List" << endl;
	cout << "4. Exit" << endl << endl;
	
	cout << "For staff members ONLY" << endl << endl;
	cout << "5. Add New Movie" << endl;
	cout << "6. Edit Existing Movie" << endl;
	cout << "7. Delete Existing Movie" << endl;
	cout << "8. Exit" << endl << endl;
}

void printMovieList(Movie movies[])
{
	cout << string(98, '-') << endl;
	cout << left << setw(12) << "| Movie ID";
	cout << setw(20) << "| Name";
	cout << setw(15) << "| Genre";
	cout << setw(10) << "| Rating";
	cout << setw(10) << "| Format";
	cout << setw(15) << "| Adult Price";
	cout << setw(15) << "| Child Price";
	cout << "|" << endl;
	for(int i = 0; i < NUM_MOVIES; ++i)
	{
		cout << "| " << setw(10) << i+1;
		cout << "| " << setw(18) << movies[i].getName();
		cout << "| " << setw(13) << movies[i].getGenre();
		cout << "| " << setw(8) << movies[i].getRating();
		cout << "| " << setw(8) << movies[i].getFormat();
		cout << "| " << setw(13) << movies[i].getAdultPrice();
		cout << "| " << setw(13) << movies[i].getChildPrice();
		cout << "|" << endl;
	}
	cout << string(98, '-') << endl;	
}

void printShowDates()
{
	cout << string(21, '-') << endl;
	cout << left << setw(5) << "| ID";
	cout << left << setw(15) << "| Show Dates" << "|" << endl;
	cout << setw(5) << "| 1";
	cout << setw(15) << "| 2022-12-22" << "|" << endl;
	cout << setw(5) << "| 2";
	cout << setw(15) << "| 2022-12-23" << "|" << endl;
	cout << setw(5) << "| 3";	
	cout << setw(15) << "| 2022-12-24" << "|" << endl;
	cout << setw(5) << "| 4";
	cout << setw(15) << "| 2022-12-25" << "|" << endl;
	cout << string(21, '-') << endl;
}

void printShowTimes()
{
	cout << string(21, '-') << endl;
	cout << left << setw(5) << "| ID";
	cout << setw(15) << "| Show Times" << "|" << endl;
	cout << setw(5) << "| 1";
	cout << setw(15) << "| 12:30 PM" << "|" << endl;
	cout << setw(5) << "| 2";
	cout << setw(15) << "| 2:15 PM" << "|" << endl;
	cout << setw(5) << "| 3";
	cout << setw(15) << "| 4:45 PM" << "|" << endl;
	cout << setw(5) << "| 4";
	cout << setw(15) << "| 7:00 PM" << "|" << endl;
	cout << string(21, '-') << endl;
}

void printSeats(string seatList[][COLUMNS])
{
	cout << string(28, '*') << endl;
	cout << "\tThe Screen" << endl;
	for(int i = 0; i < ROWS; ++i)
	{
		cout << endl << string(28, '=') << endl;
		for(int j = 0; j < COLUMNS; ++j)
		{
			cout << "    " << seatList[i][j];
		}
	}	
}

void resetSeatsTaken(bool seatTaken[][COLUMNS])
{
	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLUMNS; ++j)
		{
			seatTaken[i][j] = false;
		}
	}
}

void printTotalPrice(Movie movies [], int movieID, 
	int adultTickets, int childTickets, const double SALES_TAX)
{
	double totalAdultPrice;
	double totalChildPrice;
	double totalTax;
	double totalPrice;
	cout << std::fixed << std::showpoint << std::setprecision(2);
	totalAdultPrice = movies[movieID].calcTotalAdultPrice(adultTickets);
	totalChildPrice = movies[movieID].calcTotalChildPrice(childTickets);
	totalTax = (totalAdultPrice + totalChildPrice) * SALES_TAX;
	totalPrice = movies[movieID].calcTotalPrice(adultTickets, childTickets);
	cout << string(30, '-') << endl;
	cout << left << setw(16) << "Adult tickets x " << adultTickets << right 
		<< setw(8) << "$" << totalAdultPrice << endl;
	cout << left << setw(16) << "Child tickets x " << childTickets << right 
		<< setw(8) << "$" << totalChildPrice << endl;
	cout << left << setw(10) << "Tax" << right << setw(16)
		<< "$" << totalTax << endl;
	cout << string(30, '-') << endl;
	cout << left << setw(10) << "Total" << right << setw(15) 
		<< "$" << totalPrice << left << endl << endl; 
}

void printMovieTickets(Movie movies [])
{
	int numTickets;
	const char **seats;
	int adultTickets;
	int childTickets;
	for(int i = 0; i < NUM_MOVIES; ++i)
	{
		numTickets = movies[i].getTicketsPurchased();
		if(numTickets > 0)
		{
			cout << string(66, '-') << endl;
			cout << setw(20) << "| Name";
			cout << setw(15) << "| Genre";
			cout << setw(10) << "| Rating";
			cout << setw(10) << "| Format";
			cout << setw(10) << "| Seats";
			cout << "|" << endl;
			seats = movies[i].getSeat();		
			for(int j = 0; j < numTickets; ++j)
			{
				cout << "| " << setw(18) << movies[i].getName();
				cout << "| " << setw(13) << movies[i].getGenre();
				cout << "| " << setw(8) << movies[i].getRating();
				cout << "| " << setw(8) << movies[i].getFormat();
				cout << "| " << setw(8) << seats[j] << "|" << endl;
			}
			cout << "|" << string(64, ' ') << "|" << endl;
			cout << "|\tNumber of tickets: " << movies[i].getTicketsPurchased();
			adultTickets = movies[i].getTicketsAdult();
			childTickets = movies[i].getTicketsChild();
			cout << "\t\tPrice: $" << movies[i].calcTotalPrice(adultTickets, childTickets)
				<< string(12, ' ') << "|" << endl;
			cout << string(66, '-') << endl << endl;
		}
	}
}

void selectRowColumn(char seatRow, char seatColumn, int &rowSelected, int &colSelected)
{
	switch(seatRow)
	{
		case 'A':
			rowSelected = 0;
			break;
		case 'B':
			rowSelected = 1;
			break;
		case 'C':
			rowSelected = 2;
			break;
		case 'D':
			rowSelected = 3;
			break;
		default:
			rowSelected = -1;
	}
	switch(seatColumn)
	{
		case '4':
			colSelected = 0;
			break;
		case '3':
			colSelected = 1;
			break;
		case '2':
			colSelected = 2;
			break;
		case '1':
			colSelected = 3;
			break;
		default:
			colSelected = -1;
	}
}



