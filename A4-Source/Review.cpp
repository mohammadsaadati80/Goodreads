#include "Review.hpp"
using namespace std;

Review::Review(int id, Book* book, User* user, int rating, string date, int number_of_likes)
{
	review_id = id;
	review_book = book;
	review_user = user;
	review_rating = rating;
	review_date = date;
	review_number_of_likes = number_of_likes;
}

int Review::get_review_id() { return review_id; }

int Review::get_review_book_id() { return review_book->get_id(); }

int Review::get_review_user_id() { return review_user->get_user_id(); }

int Review::get_review_rating() { return review_rating; }

string Review::get_review_date() { return review_date; }

int Review::get_review_number_of_likes() { return review_number_of_likes; }

void Review::show_review()
{
	cout << PRINT_ID << get_review_id() << PRINT_RATING << get_review_rating() << PRINT_LIKES << get_review_number_of_likes() << PRINT_DATE << get_review_date() << endl;
}