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
	ifstream fs;
	fs.open(filename, ios_base::in);

	if(!fs.is_open()) return COULD_NOT_OPEN_FILE;

	std::string line;

	while (std::getline(fs, line))
	{
		stringstream ss(line);
		book b;
		std::string id, title, author, state, patronid;

		std::getline(ss, id, ',');
		std::getline(ss, title, ',');
		std::getline(ss, author, ',');
		std::getline(ss, state, ',');
		std::getline(ss, patronid, ',');

		b.book_id = std::stoi(id, nullptr, 10);
		b.title = title;
		b.author = author;
		b.state = static_cast<book_checkout_state>(std::stoi(state, nullptr, 10));
		b.loaned_to_patron_id = std::stoi(patronid, nullptr, 10);

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
	while(books.size() > 0)
	{
		book b = books.back();
		books.pop_back();

		fs << std::to_string(b.book_id) << "," << b.title << "," << b.author
				<< "," << b.state << "," << b.loaned_to_patron_id << endl;
	}

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

	std::string line;

	while (std::getline(fs, line))
	{
		stringstream ss(line);
		patron p;
		string id, name, books;

		std::getline(ss, id, ',');
		std::getline(ss, name, ',');
		std::getline(ss, books, ',');

		p.patron_id = std::stoi(id, nullptr, 10);
		p.name = name;
		p.number_books_checked_out = std::stoi(books, nullptr, 10);

		patrons.push_back(p);
	}

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

	while(patrons.size() > 0)
	{
		patron p = patrons.back();
		patrons.pop_back();

		fs << std::to_string(p.patron_id) << "," << p.name << "," << p.number_books_checked_out << endl;
	}

	fs.close();
	return SUCCESS;
}
