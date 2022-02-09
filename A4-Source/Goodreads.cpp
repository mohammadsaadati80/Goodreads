#include "Goodreads.hpp"
using namespace std;

Goodreads::Goodreads(vector<Author> authors, vector<Book> books, vector<User> users, vector<Review> reviews, vector<Follow_edges> follow_edges)
{
	authors_class_info = authors;
	books_class_info = books;
	users_class_info = users;
	reviews_class_info = reviews;
	follow_edges_class_info = follow_edges;
}


void Goodreads::show_author_info_by_author_id(int id)
{
	show_author_info_by_id(id);
	show_book_info_by_author_id(id);
}

void Goodreads::show_author_info_by_id(int id)
{
	Author* author = &authors_class_info[id];
	author->show_author_info();
}

void Goodreads::show_book_info_by_author_id(int id)
{
	vector<Book*> books = find_books_by_author_id(id);
	cout << PRINT_BOOKS << endl;
	for (int current = 0;current < books.size(); current++)
		books[current]->show_book_info_by_author_id();
}


void Goodreads::show_arranged_shelf_book_by_user_id_and_genre(int user_id, string user_shelf_type, string genre)
{
	users_class_info[user_id].show_arranged_shelf_book_by_user_id_and_genre(user_shelf_type, genre);
}


double Goodreads::user_credit(int user_id)
{
	int number_of_user_reviews_likes = find_number_of_user_reviews_likes(user_id);
	int number_of_likes = find_number_of_likes();
	int number_of_user_reviews = find_number_of_user_reviews(user_id);
	int number_of_reviews = reviews_class_info.size();
	double subtract[TWO_SUBTRACT];
	if (number_of_likes != 0)
		subtract[FIRST_SUBTRACT] = double(number_of_user_reviews_likes) / double(number_of_likes);
	else
		subtract[FIRST_SUBTRACT] = 0;
	if (number_of_reviews != 0)
		subtract[SECOND_SUBTRACT] = double(number_of_user_reviews) / double(number_of_reviews);
	else
		subtract[SECOND_SUBTRACT] = 0;
	return  double(1) / double(2) * (subtract[FIRST_SUBTRACT] + subtract[SECOND_SUBTRACT]);
}

int Goodreads::find_number_of_user_reviews_likes(int user_id)
{
	int number_of_user_reviews_likes = 0;
	for (int current = 0; current < reviews_class_info.size(); current++)
		if (reviews_class_info[current].get_review_user_id() == user_id)
			number_of_user_reviews_likes += reviews_class_info[current].get_review_number_of_likes();
	return number_of_user_reviews_likes;
}

int Goodreads::find_number_of_likes()
{
	int number_of_likes = 0;
	for (int current = 0; current < reviews_class_info.size(); current++)
		number_of_likes += reviews_class_info[current].get_review_number_of_likes();
	return number_of_likes;
}

int Goodreads::find_number_of_user_reviews(int user_id)
{
	int number_of_user_reviews = 0;
	for (int current = 0; current < reviews_class_info.size(); current++)
		if (reviews_class_info[current].get_review_user_id() == user_id)
			number_of_user_reviews++;
	return number_of_user_reviews;
}


void Goodreads::best_book()
{
	vector<vector<int> > books_rating = filling_book_rating_vector();
	books_rating = calculate_the_books_review(books_rating);
	vector<double> books_average_rating = calculate_books_average_rating(books_rating);
	int book_id = find_max_average_rating_book_id(books_average_rating);
	books_class_info[book_id].show_full_book_info();
	cout << PRINT_AVERAGE_RATING << fixed << setprecision(ROUND_UP_TO_TWO_DECIMAL_PLACES) << books_average_rating[book_id] << endl;
}

vector<vector<int> > Goodreads::filling_book_rating_vector()
{
	vector<vector<int> > books_rating(books_class_info.size());
	for (int current = 0;current < books_class_info.size();current++)
	{
		books_rating[current].push_back(0);
		books_rating[current].push_back(0);
	}
	return books_rating;
}

vector<vector<int> > Goodreads::calculate_the_books_review(vector<vector<int> > books_rating)
{
	for (int current = 0;current < reviews_class_info.size();current++)
	{
		books_rating[reviews_class_info[current].get_review_book_id()][RATE] += reviews_class_info[current].get_review_rating();
		books_rating[reviews_class_info[current].get_review_book_id()][NUMBER_OF_REVIEWS]++;
	}
	return books_rating;
}

vector<double> Goodreads::calculate_books_average_rating(vector<vector<int> > books_rating)
{
	vector<double> books_average_rating;
	for (int current = 0;current < books_rating.size();current++)
		if (books_rating[current][NUMBER_OF_REVIEWS] != 0)
			books_average_rating.push_back(double(books_rating[current][RATE]) / double(books_rating[current][NUMBER_OF_REVIEWS]));
		else
			books_average_rating.push_back(double(0));
	return books_average_rating;
}

int Goodreads::find_max_average_rating_book_id(vector<double> books_average_rating)
{
	double max = 0;
	int element = 0;
	for (int current = 0; current < books_average_rating.size();current++)
		if (books_average_rating[current] > max)
		{
			max = books_average_rating[current];
			element = current;
		}
	return element;
}


void Goodreads::find_best_reviewer()
{
	vector<int> user_likes = create_user_likes_vevtor();
	user_likes = calculate_the_number_of_likes_for_every_user(user_likes);
	int user_id_that_have_max_likes = find_max_like_user_id(user_likes);
	users_class_info[user_id_that_have_max_likes].show_user_info_by_id();
	cout << PRINT_NUMBER_OF_LIKES << user_likes[user_id_that_have_max_likes] << endl;
}

vector<int> Goodreads::create_user_likes_vevtor()
{
	vector<int> user_likes;
	for (int count = 0; count < users_class_info.size();count++)
		user_likes.push_back(0);
	return user_likes;
}

vector<int> Goodreads::calculate_the_number_of_likes_for_every_user(vector<int> user_likes)
{
	for (int current = 0; current < reviews_class_info.size(); current++)
		user_likes[reviews_class_info[current].get_review_user_id()] += reviews_class_info[current].get_review_number_of_likes();
	return user_likes;
}

int Goodreads::find_max_like_user_id(vector<int> user_likes)
{
	int max = 0;
	int id = 0;
	for (int current = 0; current < user_likes.size(); current++)
		if (user_likes[current] > max)
		{
			max = user_likes[current];
			id = current;
		}
	return id;
}


void Goodreads::recommend_first_approach(int user_id)
{
	vector<double> books_rating = calculate_books_rating();
	books_rating = books_score(books_rating, user_id);
	int book_id = find_max_book_score(books_rating);
	books_class_info[book_id].show_full_book_info();
	show_review_based_on_book_id(book_id);
}

vector<double> Goodreads::calculate_books_rating()
{
	vector<vector<double> > book_rating = filling_books_rating_vector();
	vector<double> all_user_credit = find_all_user_credit();
	for (int current_review = 0;current_review < reviews_class_info.size(); current_review++)
	{
		book_rating[reviews_class_info[current_review].get_review_book_id()][RATE] += reviews_class_info[current_review].get_review_rating()*all_user_credit[reviews_class_info[current_review].get_review_user_id()];
		book_rating[reviews_class_info[current_review].get_review_book_id()][NUMBER_OF_REVIEWS]++;
	}
	vector<double> books_rating;
	for (int current = 0; current < books_class_info.size();current++)
		if (book_rating[current][NUMBER_OF_REVIEWS] != 0)
			books_rating.push_back(double(book_rating[current][RATE]) / double(book_rating[current][NUMBER_OF_REVIEWS]));
		else
			books_rating.push_back(0);
	return books_rating;
}

vector<vector<double> > Goodreads::filling_books_rating_vector()
{
	vector<vector<double> > books_rating(books_class_info.size());
	for (int current = 0;current < books_class_info.size();current++)
	{
		books_rating[current].push_back(double(0));
		books_rating[current].push_back(double(0));
	}
	return books_rating;
}

vector<double> Goodreads::find_all_user_credit()
{
	vector<double> all_user_credit;
	for (int current = 0;current < users_class_info.size();current++)
		all_user_credit.push_back(user_credit(current));
	return all_user_credit;
}

vector<double> Goodreads::books_score(vector<double> books_rating, int user_id)
{
	for (int currnet = 0;currnet < books_rating.size();currnet++)
		books_rating[currnet] += double(check_have_common_in_favorite_genre(books_class_info[currnet], user_id));
	return books_rating;
}

int Goodreads::check_have_common_in_favorite_genre(Book current_book, int user_id)
{
	vector<string> user_favorite_genres = users_class_info[user_id].get_user_favorite_genres();
	for (int current = 0;current < user_favorite_genres.size(); current++)
		if (user_favorite_genres[current] == current_book.get_genre())
			return HAVING_GENRE_IN_COMMON;
	return NOT_HAVING_GENRE_IN_COMMON;
}

int Goodreads::find_max_book_score(vector<double> books_rating)
{
	int book_id = 0;
	double score = 0;
	for (int current = 0;current < books_rating.size();current++)
		if (books_rating[current] > score)
		{
			score = books_rating[current];
			book_id = current;
		}
	return book_id;
}

void Goodreads::show_review_based_on_book_id(int book_id)
{
	cout << PRINT_REVIEWS << endl;
	for (int current = 0; current < reviews_class_info.size(); current++)
		if (reviews_class_info[current].get_review_book_id() == book_id)
			reviews_class_info[current].show_review();
}


void Goodreads::recommend_second_approach(int user_id)
{
	vector<int> all_following_of_input_user;
	find_all_following_of_input_user(user_id, all_following_of_input_user, user_id);
	vector<double> books_rating = calculate_books_rating();
	vector<vector<int> > top_books_for_following_users = find_top_books_for_followings_user(books_rating, all_following_of_input_user);
	vector<int> number_of_repetitions_for_each_book = calculate_the_number_of_repetitions_for_each_book(all_following_of_input_user, top_books_for_following_users);
	int book_id = find_most_repeated_book(number_of_repetitions_for_each_book);
	books_class_info[book_id].show_full_book_info();
	show_review_based_on_book_id(book_id);
}

void Goodreads::find_all_following_of_input_user(int current_user_id, vector<int> &all_following_of_input_user, int input_user_id)
{
	for (int current = 0; current < follow_edges_class_info[current_user_id].get_user_followings().size();current++)
		if (check_not_choosen_current_user_before(follow_edges_class_info[current_user_id].get_user_followings()[current]->get_user_id(), all_following_of_input_user, input_user_id))
		{
			all_following_of_input_user.push_back(follow_edges_class_info[current_user_id].get_user_followings()[current]->get_user_id());
			find_all_following_of_input_user(follow_edges_class_info[current_user_id].get_user_followings()[current]->get_user_id(), all_following_of_input_user, input_user_id);
		}
}

bool Goodreads::check_not_choosen_current_user_before(int current_user_id, vector<int> all_following_of_input_user, int input_user_id)
{
	for (int current = 0;current < all_following_of_input_user.size();current++)
		if (all_following_of_input_user[current] == current_user_id || current_user_id == input_user_id)
			return false;
	return true;
}

vector<vector<int> > Goodreads::find_top_books_for_followings_user(vector<double> books_rating, vector<int> all_following_of_input_user)
{
	vector<vector<int> > top_three_books_for_every_user;
	for (int current_user = 0;current_user < all_following_of_input_user.size();current_user++)
		top_three_books_for_every_user.push_back(find_top_books_for_current_user(books_rating, all_following_of_input_user[current_user]));
	return top_three_books_for_every_user;
}

vector<int> Goodreads::find_top_books_for_current_user(vector<double> books_rating, int current_user_id)
{
	vector<Book*> user_books = users_class_info[current_user_id].get_user_read();
	user_books = sort_book_by_id(user_books);
	int number_of_books_to_choose = MAX_OF_TOP_BOOKS_FOR_USER;
	if (user_books.size() < MAX_OF_TOP_BOOKS_FOR_USER)
		number_of_books_to_choose = user_books.size();
	vector<int> top_books_for_current_user;
	while (top_books_for_current_user.size() < number_of_books_to_choose)
	{
		int book_id = 0;
		double score = 0;
		for (int current = 0;current < user_books.size();current++)
			if (books_rating[user_books[current]->get_id()] > score)
			{
				score = books_rating[user_books[current]->get_id()];
				book_id = user_books[current]->get_id();
			}
		top_books_for_current_user.push_back(book_id);
		books_rating[book_id] = -1;
	}
	return top_books_for_current_user;
}

vector<Book*> Goodreads::sort_book_by_id(vector<Book*> books)
{
	for (int current = 0; current < books.size(); current++)
	{
		int current_id = books[current]->get_id();
		int swap_element = current;
		for (int id_for_compare = current + 1; id_for_compare < books.size(); id_for_compare++)
			if (current_id > books[id_for_compare]->get_id())
			{
				current_id = books[id_for_compare]->get_id();
				swap_element = id_for_compare;
			}
		books = books_swap(books, current, swap_element);
	}
	return books;
}

vector<Book*> Goodreads::books_swap(vector<Book*> books, int current, int swap_element)
{
	Book* temp = books[current];
	books[current] = books[swap_element];
	books[swap_element] = temp;
	return books;
}

vector<int> Goodreads::calculate_the_number_of_repetitions_for_each_book(vector<int> all_following_of_input_user, vector<vector<int> > top_books_for_every_user)
{
	vector<int> number_of_repetitions_for_each_book;
	for (int current = 0;current < books_class_info.size();current++)
		number_of_repetitions_for_each_book.push_back(0);
	for (int current_user = 0;current_user < top_books_for_every_user.size();current_user++)
		for (int current_book = 0; current_book < top_books_for_every_user[current_user].size();current_book++)
			number_of_repetitions_for_each_book[top_books_for_every_user[current_user][current_book]]++;
	return number_of_repetitions_for_each_book;
}

int Goodreads::find_most_repeated_book(vector<int> number_of_repetitions_for_each_book)
{
	int max_number_of_repeated_from_all_book = find_max_number_of_repeated_from_all_book(number_of_repetitions_for_each_book);
	vector<int> books_with_most_repeated = find_books_with_most_repeated(max_number_of_repeated_from_all_book, number_of_repetitions_for_each_book);
	return find_book_with_most_repeated(books_with_most_repeated);
}

int Goodreads::find_max_number_of_repeated_from_all_book(vector<int> number_of_repetitions_for_each_book)
{
	int max_number_of_repeated_from_all_book = 0;
	for (int current = 0;current < number_of_repetitions_for_each_book.size();current++)
		if (number_of_repetitions_for_each_book[current] > max_number_of_repeated_from_all_book)
			max_number_of_repeated_from_all_book = number_of_repetitions_for_each_book[current];
	return max_number_of_repeated_from_all_book;
}

vector<int> Goodreads::find_books_with_most_repeated(int max_number_of_repeated_from_all_book, vector<int> number_of_repetitions_for_each_book)
{
	vector<int> books_with_most_repeated;
	for (int current = 0;current < number_of_repetitions_for_each_book.size();current++)
		if (number_of_repetitions_for_each_book[current] == max_number_of_repeated_from_all_book)
			books_with_most_repeated.push_back(current);
	return books_with_most_repeated;
}

int Goodreads::find_book_with_most_repeated(vector<int> books_with_most_repeated)
{
	int book_id = books_class_info.size() + 1;
	for (int current = 0;current < books_with_most_repeated.size();current++)
		if (books_with_most_repeated[current] < book_id)
			book_id = books_with_most_repeated[current];
	return book_id;
}


vector<Book*> Goodreads::find_books_by_author_id(int id)
{
	vector<Book*> books;
	for (int current = 0; current < books_class_info.size(); current++)
		if (books_class_info[current].get_author_id() == id)
			books.push_back(&books_class_info[current]);
	return books;
}