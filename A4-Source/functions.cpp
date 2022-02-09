#include "functions.hpp"
using namespace std;

vector<string> read_file_lines(string address)
{
	vector<string> read_file_lines;
	ifstream file(address.c_str());
	string line;
	while (getline(file, line))
		read_file_lines.push_back(line);
	return read_file_lines;
}

vector<Author> read_authors_info(string assets_address)
{
	vector<Author> authors_class_info;
	vector<string> file_lines = read_file_lines(assets_address + AUTHORS_FILE_NAME);
	for (int current_line = FIRST_VALID_LINE; current_line < file_lines.size(); current_line++)
		authors_class_info.push_back(create_new_author_class(file_lines[current_line]));
	return authors_class_info;
}

Author create_new_author_class(string line)
{
	stringstream string_stream(line);
	vector<int> int_line(3);
	int_line[LINE_COUNT] = AUTHOR_ID;
	vector<string> string_line(5);
	vector<string> genres;
	while (getline(string_stream, string_line[LINE_ELEMENT], MAIN_SEPARATOR))
	{
		if (int_line[LINE_COUNT] == AUTHOR_ID)
			int_line[ID] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == AUTHOR_NAME)
			string_line[NAME] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == AUTHOR_GENDER)
			string_line[GENDER] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == AUTHOR_MEMBER_SINCE)
			string_line[MEMBER_SINCE] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == AUTHOR_YEAR_OF_BIRTH)
			int_line[YEARS_OF_BIRTH] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == AUTHOR_PLACE_OF_BIRTH)
			string_line[PLACE_OF_BIRTH] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == AUTHOR_GENRES)
			genres = create_genres_vector(string_line[LINE_ELEMENT]);
		int_line[LINE_COUNT]++;
	}
	return Author(int_line[AUTHOR_ID], string_line[NAME], string_line[GENDER], string_line[MEMBER_SINCE], int_line[YEARS_OF_BIRTH], string_line[PLACE_OF_BIRTH], genres);
}

int convert_number_string_to_int(string line_element)
{
	int number = 0;
	for (int current = 0; current < line_element.size(); current++)
	{
		if (current > 0)
			number *= 10;
		number += (int(line_element[current]) - 48);
	}
	return number;
}

vector<string> create_genres_vector(string genres)
{
	vector<string> genres_vector;
	string genres_details;
	stringstream string_stream(genres);
	while (getline(string_stream, genres_details, SPECIAL_SEPARATOR))
		genres_vector.push_back(genres_details);
	return genres_vector;
}

vector<Book> read_books_info(string assets_address, vector<Author> &authors_class_info)
{
	vector<Book> books_class_info;
	vector<string> file_lines = read_file_lines(assets_address + BOOKS_FILE_NAME);
	for (int current_line = FIRST_VALID_LINE; current_line < file_lines.size(); current_line++)
		books_class_info.push_back(create_new_book_class(file_lines[current_line], authors_class_info));
	return books_class_info;
}

Book create_new_book_class(string line, vector<Author> &authors_class_info)
{
	stringstream string_stream(line);
	vector<int> int_line(2);
	int_line[LINE_COUNT] = ID;
	vector<string> string_line(3);
	Author* author;
	while (getline(string_stream, string_line[LINE_ELEMENT], MAIN_SEPARATOR))
	{
		if (int_line[LINE_COUNT] == ID)
			int_line[ID] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == TITLE)
			string_line[TITLE - 1] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == AUTHOR)
			author = &authors_class_info[convert_number_string_to_int(string_line[LINE_ELEMENT])];
		if (int_line[LINE_COUNT] == GENRE)
			string_line[GENRE - 2] = string_line[LINE_ELEMENT];
		int_line[LINE_COUNT]++;
	}
	return Book(int_line[ID], string_line[TITLE - 1], author, string_line[GENRE - 2]);
}

vector<User> read_user_info(string assets_address, vector<Author> &authors_class_info, vector<Book> &books_class_info)
{
	vector<User> users_class_info;
	vector<string> file_lines = read_file_lines(assets_address + USERS_FILE_NAME);
	for (int current_line = FIRST_VALID_LINE; current_line < file_lines.size(); current_line++)
		users_class_info.push_back(create_new_user_class(file_lines[current_line], authors_class_info, books_class_info));
	return users_class_info;
}

User create_new_user_class(string line, vector<Author> &authors_class_info, vector<Book> &books_class_info)
{
	stringstream string_stream(line);
	vector<int> int_line(2);
	int_line[LINE_COUNT] = AUTHOR_ID;
	vector<string> string_line(4);
	vector<string> genres;
	vector<Author*> favorite_authors;
	vector<Book*> want_to_read;
	vector<Book*> currently_reading;
	vector<Book*> read;
	while (getline(string_stream, string_line[LINE_ELEMENT], MAIN_SEPARATOR))
	{
		if (int_line[LINE_COUNT] == ID)
			int_line[ID] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == USER_NAME)
			string_line[NAME] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == USER_PLACE_OF_BIRTH)
			string_line[USER_PLACE_OF_BIRTH - 1] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == USER_MEMBER_SINCE)
			string_line[MEMBER_SINCE] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == USER_FAVORITE_AUTHORS)
			favorite_authors = find_authors_by_id(string_line[LINE_ELEMENT], authors_class_info);
		if (int_line[LINE_COUNT] == USER_FAVOROTE_GENRES)
			genres = create_genres_vector(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == USER_WANT_TO_READ)
			want_to_read = find_book_by_id(string_line[LINE_ELEMENT], books_class_info);
		if (int_line[LINE_COUNT] == USER_CURRENTLY_READING)
			currently_reading = find_book_by_id(string_line[LINE_ELEMENT], books_class_info);
		if (int_line[LINE_COUNT] == USER_READ)
			read = find_book_by_id(string_line[LINE_ELEMENT], books_class_info);
		int_line[LINE_COUNT]++;
	}
	return User(int_line[ID], string_line[NAME], string_line[USER_PLACE_OF_BIRTH - 1], string_line[MEMBER_SINCE], favorite_authors, genres, want_to_read, currently_reading, read);
}

vector<Author*> find_authors_by_id(string favorite_authors, vector<Author> &authors_class_info)
{
	vector<Author*> authors;
	string author_id;
	stringstream string_stream(favorite_authors);
	while (getline(string_stream, author_id, SPECIAL_SEPARATOR))
		authors.push_back(&authors_class_info[convert_number_string_to_int(author_id)]);
	return authors;
}

vector<Book*> find_book_by_id(string books, vector<Book> &books_class_info)
{
	vector<Book*> book;
	string book_id;
	stringstream string_stream(books);
	while (getline(string_stream, book_id, SPECIAL_SEPARATOR))
		book.push_back(&books_class_info[convert_number_string_to_int(book_id)]);
	return book;
}

vector<Review> read_reviews_info(string assets_address, vector<User> &users_class_info, vector<Book> &books_class_info)
{
	vector<Review> read_reviews_info;
	vector<string> file_lines = read_file_lines(assets_address + REVIEWS_FILE_NAME);
	for (int current_line = FIRST_VALID_LINE; current_line < file_lines.size(); current_line++)
		read_reviews_info.push_back(create_new_review_class(file_lines[current_line], users_class_info, books_class_info));
	return read_reviews_info;
}

Review create_new_review_class(string line, vector<User> &users_class_info, vector<Book> &books_class_info)
{
	stringstream string_stream(line);
	vector<int> int_line(4);
	int_line[LINE_COUNT] = ID;
	vector<string> string_line(2);
	Book* book;
	User* user;
	while (getline(string_stream, string_line[LINE_ELEMENT], MAIN_SEPARATOR))
	{
		if (int_line[LINE_COUNT] == ID)
			int_line[ID] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == BOOK)
			book = &books_class_info[convert_number_string_to_int(string_line[LINE_ELEMENT])];
		if (int_line[LINE_COUNT] == USER)
			user = &users_class_info[convert_number_string_to_int(string_line[LINE_ELEMENT])];
		if (int_line[LINE_COUNT] == RATING)
			int_line[RATING - 2] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		if (int_line[LINE_COUNT] == DATE)
			string_line[DATE - 4] = string_line[LINE_ELEMENT];
		if (int_line[LINE_COUNT] == NUMBER_OF_LIKES)
			int_line[NUMBER_OF_LIKES - 3] = convert_number_string_to_int(string_line[LINE_ELEMENT]);
		int_line[LINE_COUNT]++;
	}
	return Review(int_line[ID], book, user, int_line[RATING - 2], string_line[DATE - 4], int_line[NUMBER_OF_LIKES - 3]);
}

vector<Follow_edges> read_follow_edges_info(string assets_address, vector<User> &users_class_info)
{
	vector<Follow_edges> follow_edges_class_info;
	vector<string> file_lines = read_file_lines(assets_address + FOLLOW_EDGES_FILE_NAME);
	for (int current_line = FIRST_VALID_LINE; current_line < file_lines.size(); current_line++)
		follow_edges_class_info.push_back(create_new_follow_edges_class(file_lines[current_line], users_class_info));
	return follow_edges_class_info;
}

Follow_edges create_new_follow_edges_class(string line, vector<User> &users_class_info)
{
	stringstream string_stream(line);
	int line_count = ID;
	User* user;
	vector<User*> user_followings;
	vector<User*> user_followers;
	string line_element;
	while (getline(string_stream, line_element, MAIN_SEPARATOR))
	{
		if (line_count == ID)
			user = &users_class_info[convert_number_string_to_int(line_element)];
		if (line_count == FOLLOWINGS)
			user_followings = find_user_by_id(line_element, users_class_info);
		if (line_count == FOLLOWERS)
			user_followers = find_user_by_id(line_element, users_class_info);
		line_count++;
	}
	return Follow_edges(user, user_followings, user_followers);
}

vector<User*> find_user_by_id(string users_id, vector<User> &users_class_info)
{
	vector<User*> users;
	string user_id;
	stringstream string_stream(users_id);
	while (getline(string_stream, user_id, SPECIAL_SEPARATOR))
		users.push_back(&users_class_info[convert_number_string_to_int(user_id)]);
	return users;
}

void cheak_command(Goodreads goodreas_info)
{
	string command;
	while (cin >> command)
	{
		if (command == SHOW_AUTHOR_INFO)
		{
			int author_id;
			cin >> author_id;
			goodreas_info.show_author_info_by_author_id(author_id);
		}
		if (command == SHOW_SORTED_SHELF)
		{
			int user_id;
			cin >> user_id;
			string user_shelf_type;
			cin >> user_shelf_type;
			string genre;
			string input_genre;
			getline(cin, input_genre);
			for (int current = 1;current < input_genre.size(); current++)
				genre.push_back(input_genre[current]);
			goodreas_info.show_arranged_shelf_book_by_user_id_and_genre(user_id, user_shelf_type, genre);
		}
		if (command == CREDIT)
		{
			int user_id;
			cin >> user_id;
			cout << fixed << setprecision(ROUND_UP_TO_SIX_DECIMAL_PLACES) << goodreas_info.user_credit(user_id) << endl;
		}
		if (command == BEST_BOOK)
			goodreas_info.best_book();
		if (command == BEST_REVIEWER)
			goodreas_info.find_best_reviewer();
		if (command == RECOMMEND_FIRST_APPROACH)
		{
			int user_id;
			cin >> user_id;
			goodreas_info.recommend_first_approach(user_id);
		}
		if (command == RECOMMEND_SECOND_APPROACH)
		{
			int user_id;
			cin >> user_id;
			goodreas_info.recommend_second_approach(user_id);
		}
	}
}