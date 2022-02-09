#ifndef BOOK_H
#define BOOK_H "BOOK_H"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "Author.hpp"

#define PRINT_TITLE2 " Title: "
#define PRINT_TITLE "Title: "
#define PRINT_AUTHOR "Author: "
#define PRINT_GENRE "Genre: "

class Book {
public:
	Book(int id, std::string title, Author* author, std::string genre);
	int get_id();
	std::string get_title();
	int get_author_id();
	std::string get_genre();
	void show_book_info_by_author_id();
	void show_full_book_info();

private:
	int book_id;
	std::string book_title;
	Author* book_author;
	std::string book_genre;
};

#endif 