#ifndef AUTHOR_H
#define AUTHOR_H "AUTHOR_H"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>

#define PRINT_ID "id: "
#define PRINT_NAME "Name: "
#define PRINT_YEAR_OF_BIRTH "Year of Birth: "
#define PRINT_PLACE_OF_BIRTH "Place of Birth: "
#define PRINT_MEMBER_SINCE "Member Since: "
#define PRINT_GENRES "Genres: "
#define PRINT_COMMA ", "

class Author {
public:
	Author(int id, std::string name, std::string gender, std::string member_since, int year_of_birth, std::string place_of_birth, std::vector<std::string> genres);
	std::string get_name();
	int get_id();
	void show_author_info();
	std::vector<std::string> sort_author_genres(std::vector<std::string> author_genres);
	std::vector<std::string> author_genres_swap(std::vector<std::string> author_genres, int current, int swap_element);

private:
	int author_id;
	std::string author_name;
	std::string author_gender;
	std::string author_member_since;
	int author_year_of_birth;
	std::string author_place_of_birth;
	std::vector<std::string> author_genres;
};

#endif