#include "Book.hpp"
using namespace std;

Book::Book(int id, string title, Author* author, string genre)
{
	book_id = id;
	book_title = title;
	book_author = author;
	book_genre = genre;
}

int Book::get_id() { return book_id; };

string Book::get_title() { return book_title; }

int Book::get_author_id() { return book_author->get_id(); }

string Book::get_genre() { return book_genre; }

void Book::show_book_info_by_author_id()
{
	cout << PRINT_ID << book_id << PRINT_TITLE2 << book_title << endl;
}

void Book::show_full_book_info()
{
	cout << PRINT_ID << book_id << endl;
	cout << PRINT_TITLE << book_title << endl;
	cout << PRINT_GENRE << book_genre << endl;
	cout << PRINT_AUTHOR << book_author->get_name() << endl;
}


