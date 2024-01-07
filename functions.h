
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include "movie.h"
#include "main.h"

using std::cout;
using std::string;
using std::endl;
using std::left;
using std::setw;

void printMenu();
void printMovieList(Movie []);
void printShowDates();
void printShowTimes();
void printSeats(string [][COLUMNS]);
void resetSeatsTaken(bool [][COLUMNS]);
void printTotalPrice(Movie [], int, int, int, const double);
void printMovieTickets(Movie []);
void selectRowColumn(char, char, int&, int&);

#endif // FUNCTIONS_H
