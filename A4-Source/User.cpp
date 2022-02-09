#include "User.hpp"
using namespace std;

User::User(int id, string name, string place_of_birth, string member_since, vector<Author*> favorite_authors, vector<string> favorite_genres, vector<Book*> want_to_read, vector<Book*> currently_reading, vector<Book*> read)
{
	user_id = id;
	user_name = name;
	user_place_of_birth = place_of_birth;
	user_member_since = member_since;
	user_favorite_authors = favorite_authors;
	user_favorite_genres = favorite_genres;
	user_want_to_read = want_to_read;
	user_currently_reading = currently_reading;
	user_read = read;
}

int User::get_user_id() { return user_id; }

vector<string> User::get_user_favorite_genres() { return user_favorite_genres; }

vector<Book*> User::get_user_want_to_read() { return user_want_to_read; }

vector<Book*> User::get_user_currently_reading() { return user_currently_reading; }

vector<Book*> User::get_user_read() { return user_read; }

void User::show_user_info_by_id()
{
	cout << PRINT_ID << user_id << endl;
	cout << PRINT_NAME << user_name << endl;
	cout << PRINT_PLACE_OF_BIRTH << user_place_of_birth << endl;
	cout << PRINT_MEMBER_SINCE << user_member_since << endl;
	cout << PRINT_FAVORITE_GENRES;
	user_favorite_genres = sort_user_favorite_genres(user_favorite_genres);
	for (int current = 0;current < user_favorite_genres.size();current++)
	{
		if (current > 0)
			cout << PRINT_COMMA;
		cout << user_favorite_genres[current];
	}
	cout << endl << PRINT_FAVORITE_AUTHORS;
	user_favorite_authors = sort_user_favorite_authors_by_id(user_favorite_authors);
	for (int current = 0; current < user_favorite_authors.size(); current++)
	{
		if (current > 0)
			cout << PRINT_COMMA;
		cout << user_favorite_authors[current]->get_name();
	}
	cout << endl << PRINT_NUMBER_OF_BOOKD_IN_READ_SHELF << user_read.size() << endl;
	cout << PRINT_NUMBER_OF_BOOKD_IN_WANT_TO_READ_SHELF << user_want_to_read.size() << endl;
	cout << PRINT_NUMBER_OF_BOOKD_IN_CURRENTLY_READING_SHELF << user_currently_reading.size() << endl;
}

vector<string> User::sort_user_favorite_genres(vector<string> user_favorite_genres)
{
	for (int current = 0; current < user_favorite_genres.size(); current++)
	{
		string genres = user_favorite_genres[current];
		int swap_element = current;
		for (int current_favorite_genres_for_compare = current + 1; current_favorite_genres_for_compare < user_favorite_genres.size(); current_favorite_genres_for_compare++)
			if (genres > user_favorite_genres[current_favorite_genres_for_compare])
			{
				genres = user_favorite_genres[current_favorite_genres_for_compare];
				swap_element = current_favorite_genres_for_compare;
			}
		user_favorite_genres = user_favorite_genres_swap(user_favorite_genres, current, swap_element);
	}
	return user_favorite_genres;
}

vector<string> User::user_favorite_genres_swap(vector<string> user_favorite_genres, int current, int swap_element)
{
	string temp = user_favorite_genres[current];
	user_favorite_genres[current] = user_favorite_genres[swap_element];
	user_favorite_genres[swap_element] = temp;
	return user_favorite_genres;
}

vector<Author*> User::sort_user_favorite_authors_by_id(vector<Author*> user_favorite_authors)
{
	for (int current = 0; current < user_favorite_authors.size(); current++)
	{
		int current_id = user_favorite_authors[current]->get_id();
		int swap_element = current;
		for (int current_favorite_authors_for_compare = current + 1; current_favorite_authors_for_compare < user_favorite_authors.size(); current_favorite_authors_for_compare++)
			if (current_id > user_favorite_authors[current_favorite_authors_for_compare]->get_id())
			{
				current_id = user_favorite_authors[current_favorite_authors_for_compare]->get_id();
				swap_element = current_favorite_authors_for_compare;
			}
		user_favorite_authors = favorite_authors_swap(user_favorite_authors, current, swap_element);
	}
	return user_favorite_authors;
}

vector<Author*> User::favorite_authors_swap(vector<Author*> user_favorite_authors, int current, int swap_element)
{
	Author* temp = user_favorite_authors[current];
	user_favorite_authors[current] = user_favorite_authors[swap_element];
	user_favorite_authors[swap_element] = temp;
	return user_favorite_authors;
}

void User::show_arranged_shelf_book_by_user_id_and_genre(string user_shelf_type, string genre)
{
	if (user_shelf_type == READ)
		sort_shelf_book_by_genre(user_read, genre);
	if (user_shelf_type == WANT_TO_READ)
		sort_shelf_book_by_genre(user_want_to_read, genre);;
	if (user_shelf_type == CURRENTLY_READING)
		sort_shelf_book_by_genre(user_currently_reading, genre);;
}

void User::sort_shelf_book_by_genre(vector<Book*> shelf_books, string genre)
{
	vector<Book*> books_with_input_genre;
	vector<Book*> books_without_input_genre;
	for (int currnet = 0; currnet < shelf_books.size(); currnet++)
		if (shelf_books[currnet]->get_genre() == genre)
			books_with_input_genre.push_back(shelf_books[currnet]);
		else
			books_without_input_genre.push_back(shelf_books[currnet]);
	books_with_input_genre = sort_book_by_name(books_with_input_genre);
	books_without_input_genre = sort_book_by_name(books_without_input_genre);
	books_with_input_genre = sort_book_by_id_for_same_name(books_with_input_genre);
	books_without_input_genre = sort_book_by_id_for_same_name(books_without_input_genre);
	print_sorted_shelf_books(books_with_input_genre);
	print_sorted_shelf_books(books_without_input_genre);
}

vector<Book*> User::sort_book_by_name(vector<Book*> books)
{
	for (int current = 0; current < books.size(); current++)
	{
		string title = books[current]->get_title();
		int swap_element = current;
		for (int current_book_for_compare = current + 1; current_book_for_compare < books.size(); current_book_for_compare++)
			if (title > books[current_book_for_compare]->get_title())
			{
				title = books[current_book_for_compare]->get_title();
				swap_element = current_book_for_compare;
			}
		books = books_swap(books, current, swap_element);
	}
	return books;
}

vector<Book*> User::sort_book_by_id_for_same_name(vector<Book*> books)
{
	for (int start = 0; start < books.size(); start++)
	{
		string title = books[start]->get_title();
		int end;
		for (end = start + 1; end < books.size(); end++)
			if (title != books[end]->get_title())
				break;
		books = sort_book_by_id(books, start, end);
		start = end - 1;
	}

	return books;
}

vector<Book*> User::sort_book_by_id(vector<Book*> books, int start, int end)
{
	for (int current = start; current < end; current++)
	{
		int current_id = books[current]->get_id();
		int swap_element = current;
		for (int id_for_compare = current + 1; id_for_compare < end; id_for_compare++)
			if (current_id > books[id_for_compare]->get_id())
			{
				current_id = books[id_for_compare]->get_id();
				swap_element = id_for_compare;
			}
		books = books_swap(books, current, swap_element);
	}
	return books;
}

vector<Book*> User::books_swap(vector<Book*> books, int current, int swap_element)
{
	Book* temp = books[current];
	books[current] = books[swap_element];
	books[swap_element] = temp;
	return books;
}

void User::print_sorted_shelf_books(vector<Book*> sorted_books)
{
	for (int current = 0; current < sorted_books.size();current++)
	{
		sorted_books[current]->show_full_book_info();
		cout << SEPARATOR_FOR_SHOWING_BOOKS << endl;
	}
}