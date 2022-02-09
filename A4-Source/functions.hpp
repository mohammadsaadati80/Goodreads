#ifndef FUNCTIONS_H
#define FUNCTIONS_H "FUNCTIONS_H"
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
#include "User.hpp"
#include "Review.hpp"
#include "FollowEdges.hpp"
#include "Goodreads.hpp"

#define MAIN_SEPARATOR ','
#define SPECIAL_SEPARATOR '$'
#define AUTHORS_FILE_NAME "/authors.csv"
#define BOOKS_FILE_NAME "/books.csv"
#define FOLLOW_EDGES_FILE_NAME "/follow_edges.csv"
#define REVIEWS_FILE_NAME "/reviews.csv"
#define USERS_FILE_NAME "/users.csv"
#define FIRST_VALID_LINE 1
#define AUTHOR_ID 1
#define AUTHOR_NAME 2
#define AUTHOR_GENDER 3
#define AUTHOR_MEMBER_SINCE 4
#define AUTHOR_YEAR_OF_BIRTH 5
#define AUTHOR_PLACE_OF_BIRTH 6
#define AUTHOR_GENRES 7
#define LINE_ELEMENT 0
#define ID 1
#define NAME 1
#define GENDER 2
#define MEMBER_SINCE 3
#define YEARS_OF_BIRTH 2
#define PLACE_OF_BIRTH 4
#define LINE_COUNT 0
#define ASSETS_ADDRESS 1
#define TITLE 2
#define AUTHOR 3
#define GENRE 4
#define USER_NAME 2
#define USER_PLACE_OF_BIRTH 3
#define USER_MEMBER_SINCE 4
#define USER_FAVORITE_AUTHORS 5
#define USER_FAVOROTE_GENRES 6
#define USER_WANT_TO_READ 7
#define USER_CURRENTLY_READING 8
#define USER_READ 9
#define BOOK 2
#define USER 3
#define RATING 4
#define DATE 5
#define NUMBER_OF_LIKES 6
#define FOLLOWINGS 2
#define FOLLOWERS 3
#define ROUND_UP_TO_SIX_DECIMAL_PLACES 6
#define SHOW_AUTHOR_INFO "show_author_info"
#define SHOW_SORTED_SHELF "show_sorted_shelf"
#define CREDIT "credit"
#define BEST_BOOK "best_book"
#define BEST_REVIEWER "best_reviewer"
#define RECOMMEND_FIRST_APPROACH "recommend_first_approach"
#define RECOMMEND_SECOND_APPROACH "recommend_second_approach"

std::vector<std::string> read_file_lines(std:: string address);
std::vector<Author> read_authors_info(std::string assets_address);
Author create_new_author_class(std::string line);
int convert_number_string_to_int(std::string line_element);
std::vector<std::string> create_genres_vector(std::string genres);
std::vector<Book> read_books_info(std::string assets_address, std::vector<Author> &authors_class_info);
Book create_new_book_class(std::string line, std::vector<Author> &authors_class_info);
std::vector<User> read_user_info(std::string assets_address, std::vector<Author> &authors_class_info, std::vector<Book> &books_class_info);
User create_new_user_class(std::string line, std::vector<Author> &authors_class_info, std::vector<Book> &books_class_info);
std::vector<Author*> find_authors_by_id(std::string favorite_authors, std::vector<Author> &authors_class_info);
std::vector<Book*> find_book_by_id(std::string books, std::vector<Book> &books_class_info);
std::vector<Review> read_reviews_info(std::string assets_address, std::vector<User> &users_class_info, std::vector<Book> &books_class_info);
Review create_new_review_class(std::string line, std::vector<User> &users_class_info, std::vector<Book> &books_class_info);
std::vector<Follow_edges> read_follow_edges_info(std::string assets_address, std::vector<User> &users_class_info);
Follow_edges create_new_follow_edges_class(std::string line, std::vector<User> &users_class_info);
std::vector<User*> find_user_by_id(std::string users_id, std::vector<User> &users_class_info);
void cheak_command(Goodreads goodreas_info);

#endif