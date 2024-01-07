
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using std::string;

class Movie
{
	private:
		string name;
		string genre;
		string rating;
		string format;
		int ticketsPurchased;
		int ticketsAdult;
		int ticketsChild;
		double adultPrice;
		double childPrice;
		string showDate;
		string showTime;
		const char **seat;
	
	public:
		static constexpr double ADULT_PRICE = 9.75;
		static constexpr double CHILD_PRICE = 7.75;
		static constexpr double SALES_TAX = 0.0825;
		static const int NUM_SEATS = 4;
		static const int MAX_SEATS = 16;
		
		Movie();
		Movie(string, string, string, string);
		~Movie();
		
		void selectShowDate(int);
		void selectShowTime(int);
		void selectSeat(const char **choice, int);
		void setTicketsAdultChild(int, int);
		int calcSeatsRemaining();
		double calcTotalAdultPrice(double);
		double calcTotalChildPrice(double);
		double calcTotalPrice(double, double);
		bool editMovie(string, string, string, string, double, double);
		
		string getName() const;
		string getGenre() const;
		string getRating() const;
		string getFormat() const;
		int getTicketsPurchased() const;
		int getTicketsAdult() const;
		int getTicketsChild() const;
		double getAdultPrice() const;
		double getChildPrice() const;
		string getShowDate() const;
		string getShowTime() const;
		const char** getSeat() const;
};

#endif // MOVIE_H
