#include "FollowEdges.hpp"

using namespace std;

Follow_edges::Follow_edges(User* input_user, vector<User*> followings, vector<User*>followers)
{
	user = input_user;
	user_followings = followings;
	user_followers = followers;
}

vector<User*> Follow_edges:: get_user_followings() { return user_followings; }