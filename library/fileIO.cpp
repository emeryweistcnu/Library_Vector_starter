#include <fstream>
#include <iostream>
#include <sstream>
#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	fstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	std::string line;
	std::vector<book>::iterator it = books.begin();

	while (std::getline(fs, line))
	{
		stringstream ss(line);
		book b;
		std::string id;
		std:: string title;
		std:: string author;
		std::getline(ss, id, ',');
		std::getline(ss, title, ',');
		std::getline(ss, author, ',');
		b.book_id = std::stoi(id, nullptr, 10);
		b.author = author;
		cout << line << endl;

		books.push_back(b);
	}

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

	fstream fs(filename);

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
	fstream fs(filename);

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

	fstream fs(filename);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	//TODO Save patrons to file here

	fs.close();
	return SUCCESS;
}
