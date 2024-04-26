#include "algoritm.h"

void rem(auto* arr, auto* remel)
{
	(*arr).erase(remove((*arr).begin(), (*arr).end(), (*remel)), (*arr).end());
}

std::vector <std::string> sepstring(std::string& string)
{
	std::vector <std::string> sepsrtingarr;
	std::string word = "";
	for (int i = 0; i < string.size(); i++) {
		if (string[i] == ' ') {
			sepsrtingarr.push_back(word);
			word = "";
		}
		else {
			word += string[i];
		}
	}
	sepsrtingarr.push_back(word);
	return sepsrtingarr;
}

bool isint(std::string integer)
{
	for (int i = 0; i < integer.size(); i++) {
		if ((!isdigit(integer[i])) and (integer[0] != '-') and (integer[0] != '+')) {

			return false;
		}
	}
	return true;
}
