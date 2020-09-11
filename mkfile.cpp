#include <iostream>
#include <vector>
#include <io.h>
#include <fstream>
#include <filesystem>

using namespace std;

const static string DIR_DIVIDER_STRING = "/";
const static char DIR_DIVIDER_CHAR = '/';

bool replace(string &str, const string &from, const string &to)
{
	size_t start_pos = str.find(from);
	if (start_pos == string::npos)
		return false;
	str.replace(start_pos, from.size(), to);
	return true;
}

size_t count(string str, char counted)
{
	size_t counter = 0;
	for (char c : str)
	{
		if (c == counted)
		{
			counter++;
		}
	}
	return counter;
}

string reverseString(string str)
{
	int size = str.size();
	string reversed = "";

	for (int i = size - 1; i >= 0; i--)
	{
		reversed += str[i];
	}

	return reversed;
}

vector<string> dirArray(string path)
{
	vector<string> vec;
	size_t index = 0;

	string pathCopy = path;

	while (index < pathCopy.size())
	{
		if (pathCopy.at(index) == DIR_DIVIDER_CHAR)
		{
			string thisDir = pathCopy.substr(0, index);
			vec.insert(vec.end(), thisDir);
			pathCopy = pathCopy.substr(index + 1, pathCopy.size() - index);

			index = 0;
		}
		else
		{
			index++;
		}
	}
	return vec;
}

void createPath(string path)
{
	vector<string> directories = dirArray(path);

	for (int i = 0; i < directories.size(); i++)
	{
		string fullDir = "";
		for (int j = 0; j <= i; j++)
		{
			fullDir += directories[j] + DIR_DIVIDER_STRING;
			mkdir(fullDir.c_str());
		}
	}
}

void createFile(string path)
{
	ifstream file(path);
	if (file)
	{
		return;
	}
	else
	{
		ofstream file{path};
	}
}

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		cout << "You must inform the name of the file to be created." << endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		string path = argv[i];

		string replaceDivider[] = {"\\"};
		for (string d : replaceDivider)
		{
			replace(path, d, DIR_DIVIDER_STRING);
		}

		while (path.at(0) == DIR_DIVIDER_CHAR)
		{
			path = path.substr(1, path.size());
		}

		string reversePath = reverseString(path);

		createPath(path);
		createFile(path);
	}
}
