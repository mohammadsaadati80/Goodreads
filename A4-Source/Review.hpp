#ifndef REVIEW_H
#define REVIEW_H "REVIEW_H"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "Book.hpp"
#include "User.hpp"

#define PRINT_RATING " Rating: "
#define PRINT_LIKES " Likes: "
#define PRINT_DATE " Date: "

class Review {
public:
	Review(int id, Book* book, User* user, int rating, std::string date, int number_of_likes);
	int get_review_id();
	int get_review_book_id();
	int get_review_user_id();
	int get_review_rating();
	std::string get_review_date();
	int get_review_number_of_likes();
	void show_review();

private:
	int review_id;
	Book* review_book;
	User* review_user;
	int review_rating;
	std::string review_date;
	int review_number_of_likes;
};

#endif 