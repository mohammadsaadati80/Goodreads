#ifndef USER_H
#define USER_H "USER_H"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "Author.hpp"
#include "Book.hpp"

#define PRINT_ID "id: "
#define PRINT_NAME "Name: "
#define PRINT_PLACE_OF_BIRTH "Place of Birth: "
#define PRINT_MEMBER_SINCE "Member Since: "
#define PRINT_COMMA ", "
#define PRINT_FAVORITE_GENRES "Favorite Genres: "
#define PRINT_FAVORITE_AUTHORS "Favorite Authors: "
#define PRINT_NUMBER_OF_BOOKD_IN_READ_SHELF "Number of Books in Read Shelf: "
#define PRINT_NUMBER_OF_BOOKD_IN_WANT_TO_READ_SHELF "Number of Books in Want to Read Shelf: "
#define PRINT_NUMBER_OF_BOOKD_IN_CURRENTLY_READING_SHELF "Number of Books in Currently Reading Shelf: "
#define READ "read"
#define WANT_TO_READ "want_to_read"
#define CURRENTLY_READING "currently_reading"
#define SEPARATOR_FOR_SHOWING_BOOKS "***"

class User {
public:
	User(int id, std::string name, std::string place_of_birth, std::string member_since, std::vector<Author*> favorite_authors, std::vector<std::string> favorite_genres, std::vector<Book*> want_to_read, std::vector<Book*> currently_reading, std::vector<Book*> read);
	int get_user_id();
	std::vector<std::string> get_user_favorite_genres();
	std::vector<Book*> get_user_want_to_read();
	std::vector<Book*> get_user_currently_reading();
	std::vector<Book*> get_user_read();
	void show_user_info_by_id();
	std::vector<std::string> sort_user_favorite_genres(std::vector<std::string> user_favorite_genres);
	std::vector<std::string> user_favorite_genres_swap(std::vector<std::string> user_favorite_genres, int current, int swap_element);
	std::vector<Author*> sort_user_favorite_authors_by_id(std::vector<Author*> user_favorite_authors);
	std::vector<Author*> favorite_authors_swap(std::vector<Author*> user_favorite_authors, int current, int swap_element);
	void show_arranged_shelf_book_by_user_id_and_genre(std::string user_shelf_type, std::string genre);
	void sort_shelf_book_by_genre(std::vector<Book*> shelf_books, std::string genre);
	std::vector<Book*> sort_book_by_name(std::vector<Book*> books);
	std::vector<Book*> sort_book_by_id_for_same_name(std::vector<Book*> books);
	std::vector<Book*> sort_book_by_id(std::vector<Book*> books, int start, int end);
	std::vector<Book*> books_swap(std::vector<Book*> books, int current, int swap_element);
	void print_sorted_shelf_books(std::vector<Book*> sorted_books);
	
private:
	int user_id;
	std::string user_name;
	std::string user_place_of_birth;
	std::string user_member_since;
	std::vector<Author*> user_favorite_authors;
	std::vector<std::string> user_favorite_genres;
	std::vector<Book*> user_want_to_read;
	std::vector<Book*> user_currently_reading;
	std::vector<Book*> user_read;
};

#endif