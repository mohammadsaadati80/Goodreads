#include "Author.hpp"
using namespace std;

Author::Author(int id, string name, string gender, string member_since, int year_of_birth, string place_of_birth, vector<string> genres)
{
	author_id = id;
	author_name = name;
	author_gender = gender;
	author_member_since = member_since;
	author_year_of_birth = year_of_birth;
	author_place_of_birth = place_of_birth;
	author_genres = genres;
}

string Author::get_name() { return author_name; };

int Author::get_id() { return author_id; };

void Author::show_author_info()
{
	cout << PRINT_ID << author_id << endl;
	cout << PRINT_NAME << author_name << endl;
	cout << PRINT_YEAR_OF_BIRTH << author_year_of_birth << endl;
	cout << PRINT_PLACE_OF_BIRTH << author_place_of_birth << endl;
	cout << PRINT_MEMBER_SINCE << author_member_since << endl;
	cout << PRINT_GENRES;
	author_genres = sort_author_genres(author_genres);
	for (int current = 0;current < author_genres.size();current++)
	{
		if (current > 0)
			cout << PRINT_COMMA;
		cout << author_genres[current];
	}
	cout << endl;
}

vector<string> Author::sort_author_genres(vector<string> author_genres)
{
	for (int current = 0; current < author_genres.size(); current++)
	{
		string genres = author_genres[current];
		int swap_element = current;
		for (int current_author_genres_for_compare = current + 1; current_author_genres_for_compare < author_genres.size(); current_author_genres_for_compare++)
			if (genres > author_genres[current_author_genres_for_compare])
			{
				genres = author_genres[current_author_genres_for_compare];
				swap_element = current_author_genres_for_compare;
			}
		author_genres = author_genres_swap(author_genres, current, swap_element);
	}
	return author_genres;
}

vector<string> Author::author_genres_swap(vector<string> author_genres, int current, int swap_element)
{
	string temp = author_genres[current];
	author_genres[current] = author_genres[swap_element];
	author_genres[swap_element] = temp;
	return author_genres;
}