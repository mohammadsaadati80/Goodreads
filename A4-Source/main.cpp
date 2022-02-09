#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "functions.hpp"
#include "Author.hpp"
#include "Book.hpp"
#include "User.hpp"
#include "Review.hpp"
#include "FollowEdges.hpp"
#include "Goodreads.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	string assets_address = argv[ASSETS_ADDRESS];
	vector<Author> authors_class_info = read_authors_info(assets_address);
	vector<Book> books_class_info = read_books_info(assets_address, authors_class_info);
	vector<User> users_class_info = read_user_info(assets_address, authors_class_info, books_class_info);
	vector<Review> reviews_class_info = read_reviews_info(assets_address, users_class_info, books_class_info);
	vector<Follow_edges> follow_edges_class_info = read_follow_edges_info(assets_address, users_class_info);
	Goodreads goodreas_info(authors_class_info, books_class_info, users_class_info, reviews_class_info, follow_edges_class_info);
	cheak_command(goodreas_info);
	return 0;
}