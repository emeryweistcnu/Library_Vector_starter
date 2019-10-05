#include <fstream>
#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	ofstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	//TODO Load books from file here

	if(books.size() < 1) return NO_BOOKS_IN_LIBRARY;

	fs.close();
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	if(books.size() < 1) return NO_BOOKS_IN_LIBRARY;

	ofstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	//TODO Write to file here

	fs.close();
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ofstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	//TODO Load patrons here

	fs.close();
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	if(patrons.size() < 1) return NO_PATRONS_IN_LIBRARY;

	ofstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	//TODO Save patrons to file here

	fs.close();
	return SUCCESS;
}
