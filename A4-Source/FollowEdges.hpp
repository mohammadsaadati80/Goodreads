#ifndef FOLLOWEDGES_H
#define FOLLOWEDGES_H "FOLLOWEDGES_H"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include "User.hpp"

class Follow_edges {
public:
	Follow_edges(User* input_user, std::vector<User*> followings, std::vector<User*>followers);
	std::vector<User*> get_user_followings();

private:
	User* user;
	std::vector<User*> user_followings;
	std::vector<User*> user_followers;
};

#endif