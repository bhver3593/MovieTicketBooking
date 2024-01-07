

#define ROWS 4
#define COLUMNS 4 
#define NUM_MOVIES 6

#include "main.h"

int main()
{
	string seatList[ROWS][COLUMNS] = { "A4", "A3", "A2", "A1",
												  "B4", "B3", "B2", "B1",
												  "C4", "C3", "C2", "C1",
												  "D4", "D3", "D2", "D1" };
	
	bool seatTaken[ROWS][COLUMNS] = { false, false, false, false,
												 false, false, false, false, 
												 false, false, false, false,
												 false, false, false, false };
	
	Movie movies[NUM_MOVIES] = { Movie("Titanic", "Romance", "PG-13", "2D"),
										  Movie("The Avengers", "Action", "PG-13", "2D"),
										  Movie("The Shining", "Horror", "R", "2D"),
										  Movie("The Hangover", "Comedy", "R", "2D"),
										  Movie("Interstellar", "Sci-Fi", "PG-13", "2D"),
										  Movie("Forrest Gump", "Drama", "PG-13", "2D") };
	
	int menuChoice;
	char menuAnswer;
	
	int movieID;
	int dateID;
	int timeID;
	
	const int NUM_SEATS = Movie::NUM_SEATS;
	const char *seatChoice[NUM_SEATS];
	const char **seats;
	int count = 0;
	int adultTickets;
	int childTickets;
	int totalTickets;
	double totalAdultPrice;
	double totalChildPrice;
	const double SALES_TAX = Movie::SALES_TAX;
	double totalTax;
	double totalPrice;
	char seatRow;
	char seatColumn;
	int rowSelected;
	int colSelected;
	
	string name;
	string genre;
	string rating;
	string format;
	double adultPrice;
	double childPrice;

	do
	{
		cout << "\nWelcome to The Movie Ticket Booking System" << endl << endl;
		
		printMenu();
		cout << "Please select an option from the main menu: ";
		cin >> menuChoice;
		while(menuChoice < 0 || menuChoice > 8)
		{
			cout << "Incorrect menu option. Please re-enter: ";
			cin >> menuChoice;
		}
		cout << endl;
		
		switch(menuChoice)
		{	
			case 1:
			{
				cout << "Book Tickets:" << endl << endl;
				
				printMovieList(movies);
				cout << "Select movie by entering movie ID: ";
				cin >> movieID;
				while(movieID < 0 || movieID > NUM_MOVIES)
				{
					cout << "Incorrect movie ID. Please re-enter: ";
					cin >> movieID;
				}
				cout << endl << "Movie Selected: " << movies[--movieID].getName() << endl << endl;
				
				printShowDates();
				cout << "Select show date by entering date ID: ";
				cin >> dateID;
				while(dateID < 0 || dateID > 4)
				{
					cout << "Incorrect date ID. Please re-enter: ";
					cin >> dateID;
				}
				movies[movieID].selectShowDate(dateID);
				cout << endl << "Show Date: " << movies[movieID].getShowDate() << endl << endl;
				
				printShowTimes();
				cout << "Select show time by entering time ID: ";
				cin >> timeID;
				while(timeID < 0 || timeID > 4)
				{
					cout << "Incorrect time ID. Please re-enter: ";
					cin >> timeID;
				}
				movies[movieID].selectShowTime(timeID);
				cout << endl << "Show Time: " << movies[movieID].getShowTime() << endl << endl;
				
				cout << endl;
				printSeats(seatList);
				cout << endl << endl;
				
				cout << "How many adult tickets would you like to purchase? ";
				cin >> adultTickets;
				while(adultTickets < 0 || adultTickets > NUM_SEATS)
				{
					cout << "Can only purchase a maximum of 4 tickets." << endl;
					cout << "Please re-enter the number of adult tickets you would like to purchase: ";
					cin >> adultTickets;
				}
				
				cout << "How many child tickets would you like to purchase? ";
				cin >> childTickets;
				while(childTickets < 0 || childTickets > NUM_SEATS)
				{
					cout << "Can only purchase a maximum of 4 tickets." << endl;
					cout << "Please re-enter the number of child tickets you would like to purchase: ";
					cin >> childTickets;
				}
				
				totalTickets = adultTickets + childTickets;
				while(childTickets < 0 || totalTickets < 0 || totalTickets > NUM_SEATS)
				{
					totalTickets = adultTickets;
					cout << "Can only purchase a maximum of 4 tickets." << endl;
					cout << "Please re-enter the number of child tickets you would like to purchase: ";
					cin >> childTickets;
					totalTickets = adultTickets + childTickets;
				}
				movies[movieID].setTicketsAdultChild(adultTickets, childTickets);				
				
				do
				{
					cout << "\nSelect a seat: ";
					char *tempSeat = new char;
					cin >> tempSeat;
					
					seatChoice[count] = tempSeat;
					seatRow = seatChoice[count][0];
					seatColumn = seatChoice[count][1];
					
					selectRowColumn(seatRow, seatColumn, rowSelected, colSelected);
					
					while(rowSelected == -1 || colSelected == -1 || 
						seatTaken[rowSelected][colSelected] == true)
					{
						cout << "Invalid seat selection or seat has already been filled" << endl;
						cout << "Please select another seat: ";
						cin >> tempSeat;
					
						seatChoice[count] = tempSeat;
						seatRow = seatChoice[count][0];
						seatColumn = seatChoice[count][1];			
					
						selectRowColumn(seatRow, seatColumn, rowSelected, colSelected);
					}
			
					if(rowSelected != -1 && colSelected != -1 && seatTaken[rowSelected][colSelected] == false)
					{
						seatTaken[rowSelected][colSelected] = true;
						count++;
					}
					
				} while(count < totalTickets);
				
				movies[movieID].selectSeat(seatChoice, count);		
				seats = movies[movieID].getSeat();
				cout << "\nSeats Selected: ";
				for(int i = 0; i < count; ++i)
					cout << seats[i] << " ";
				count = 0;
				cout << endl << endl;
				
				resetSeatsTaken(seatTaken);
				printTotalPrice(movies, movieID, adultTickets, childTickets, SALES_TAX);
				
				cout << "Movie Booking Processed Successfully" << endl;
				
				cout << "\nWould you like to return to the menu? " << endl;
				cout << "Answer 'y' or 'Y' for Yes, any other key for No: ";
				cin >> menuAnswer;
				break;
			}
				
			case 2:
			{
				cout << "Show Tickets:" << endl << endl;

				printMovieTickets(movies);
				
				cout << "\nWould you like to return to the menu? " << endl;
				cout << "Answer 'y' or 'Y' for Yes, any other key for No: ";
				cin >> menuAnswer;
				break;
			}
				
			case 3:
			{
				cout << "Show Movie List:" << endl << endl;
				
				printMovieList(movies);
				
				for(int i = 0; i < NUM_MOVIES; ++i)
				{
					cout << "Movie: " << movies[i].getName() << endl;
					cout << "Number of seats purchased: " << movies[i].getTicketsPurchased() << endl;
					cout << "Number of seats remaining: " << movies[i].calcSeatsRemaining() << endl;
					cout << endl;
				}

				cout << "\nWould you like to return to the main menu? " << endl;
				cout << "Answer 'y' or 'Y' for Yes, any other key for No: ";
				cin >> menuAnswer;
				break;
			}
				
			case 4:
			{
				exit(EXIT_SUCCESS);
			}
			
			case 5:
			{
				cout << "Add New Movie:" << endl << endl;
					
				cout << "\nWould you like to return to the main menu? " << endl;
				cout << "Answer 'y' or 'Y' for Yes, any other key for No: ";
				cin >> menuAnswer;
				break;
			}
				
			case 6:
			{
				cout << "Edit Existing Movie" << endl << endl;
				
				printMovieList(movies);
				cout << "Which movie would you like to edit?" << endl;
				cout << "Select movie by entering movie ID: ";
				cin >> movieID;
				while(movieID < 0 || movieID > NUM_MOVIES)
				{
					cout << "Incorrect movie ID. Please re-enter: ";
					cin >> movieID;
				}
				cout << endl << "Movie Selected: " << movies[--movieID].getName() << endl << endl;
				
				cout << "New Name: ";
				cin.ignore();
				getline(cin, name);
				cout << "New Genre: ";
				getline(cin, genre);
				cout << "New Rating: ";
				getline(cin, rating);
				cout << "New Format: ";
				getline(cin, format);
				cout << "New Adult Price: ";
				cin >> adultPrice;
				cout << "New Child Price: ";
				cin >> childPrice;
				if(movies[movieID].editMovie(name, genre, rating, format, adultPrice, childPrice))
				{
					cout << endl << "Updated Movie List" << endl << endl;
					printMovieList(movies);
				}
				else
				{
					cout << endl << "Incorrect input. Unable to update movie list" << endl;
				}
				
				cout << "\nWould you like to return to the main menu? " << endl;
				cout << "Answer 'y' or 'Y' for Yes, any other key for No: "; 
				cin >> menuAnswer;
				break;
			}
				
			case 7:
			{
				cout << "Delete Existing Movie" << endl << endl;
				
				
				cout << "\nWould you like to return to the main menu? " << endl;
				cout << "Enter 'y' or 'Y' for Yes, any other key for No: ";
				cin >> menuAnswer;
				break;
			}
			
			case 8:
			{
				exit(EXIT_SUCCESS);
			}
		}
		
	} while (toupper(menuAnswer) == 'Y');
	
	return EXIT_SUCCESS;
}





