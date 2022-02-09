#ifndef GOODREADS_H
#define GOODREADS_H "GOODREADS_H"

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

#define ROUND_UP_TO_TWO_DECIMAL_PLACES 2
#define PRINT_BOOKS "Books:"
#define PRINT_AVERAGE_RATING "Average Rating: "
#define RATE 0
#define NUMBER_OF_REVIEWS 1
#define PRINT_NUMBER_OF_LIKES "Number of Likes: "
#define HAVING_GENRE_IN_COMMON 5
#define NOT_HAVING_GENRE_IN_COMMON 0
#define PRINT_REVIEWS "Reviews:"
#define MAX_OF_TOP_BOOKS_FOR_USER 3
#define FIRST_SUBTRACT 0
#define SECOND_SUBTRACT 1
#define TWO_SUBTRACT 2

class Goodreads {
public:
	Goodreads(std::vector<Author> authors, std::vector<Book> books, std::vector<User> users, std::vector<Review> reviews, std::vector<Follow_edges> follow_edges);
	void show_author_info_by_author_id(int id);
	void show_author_info_by_id(int id);
	void show_book_info_by_author_id(int id);
	void show_arranged_shelf_book_by_user_id_and_genre(int user_id, std::string user_shelf_type, std::string genre);
	double user_credit(int user_id);
	int find_number_of_user_reviews_likes(int user_id);
	int find_number_of_likes();
	int find_number_of_user_reviews(int user_id);
	void best_book();
	std::vector<std::vector<int> > filling_book_rating_vector();
	std::vector<std::vector<int> > calculate_the_books_review(std::vector<std::vector<int> > books_rating);
	std::vector<double> calculate_books_average_rating(std::vector<std::vector<int> > books_rating);
	int find_max_average_rating_book_id(std::vector<double> books_average_rating);
	void find_best_reviewer();
	std::vector<int> create_user_likes_vevtor();
	std::vector<int> calculate_the_number_of_likes_for_every_user(std::vector<int> user_likes);
	int find_max_like_user_id(std::vector<int> user_likes);
	void recommend_first_approach(int user_id);
	std::vector<double> calculate_books_rating();
	std::vector<std::vector<double> > filling_books_rating_vector();
	std::vector<double> find_all_user_credit();
	std::vector<double> books_score(std::vector<double> books_rating, int user_id);
	int check_have_common_in_favorite_genre(Book current_book, int user_id);
	int find_max_book_score(std::vector<double> books_rating);
	void show_review_based_on_book_id(int book_id);
	void recommend_second_approach(int user_id);
	void find_all_following_of_input_user(int current_user_id, std::vector<int> &all_following_of_input_user, int input_user_id);
	bool check_not_choosen_current_user_before(int current_user_id, std::vector<int> all_following_of_input_user, int input_user_id);
	std::vector<std::vector<int> > find_top_books_for_followings_user(std::vector<double> books_rating, std::vector<int> all_following_of_input_user);
	std::vector<Book*> sort_book_by_id(std::vector<Book*> books);
	std::vector<Book*> books_swap(std::vector<Book*> books, int current, int swap_element);
	std::vector<int> find_top_books_for_current_user(std::vector<double> books_rating, int current_user_id);
	std::vector<int> calculate_the_number_of_repetitions_for_each_book(std::vector<int> all_following_of_input_user, std::vector<std::vector<int> > top_books_for_every_user);
	int find_most_repeated_book(std::vector<int> number_of_repetitions_for_each_book);
	int find_max_number_of_repeated_from_all_book(std::vector<int> number_of_repetitions_for_each_book);
	std::vector<int> find_books_with_most_repeated(int max_number_of_repeated_from_all_book, std::vector<int> number_of_repetitions_for_each_book);
	int find_book_with_most_repeated(std::vector<int> books_with_most_repeated);

private:
	std::vector<Book*> find_books_by_author_id(int id);

	std::vector<Author> authors_class_info;
	std::vector<Book> books_class_info;
	std::vector<User> users_class_info;
	std::vector<Review> reviews_class_info;
	std::vector<Follow_edges> follow_edges_class_info;
};

#endif 