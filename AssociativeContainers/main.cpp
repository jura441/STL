#include<iostream>
#include<set>
#include<string>
#include<map>
#include<list>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Kitten
{
	std::string name;
public:
	Kitten(const std::string& name) :name(name){}
	bool operator<(const Kitten& other) const
	{
		return this->name < other.name;
	}
	bool operator>(const Kitten& other) const
	{
		return this->name > other.name;
	}
	friend std::ostream& operator<<(std::ostream& os, const Kitten& obj)
		{
			return os << obj.name;
		}
};

//#define STL_SET
//#define STL_MAP

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_SET
	std::multiset<int> i_set = { 50, 25, 75, 16, 16, 16, 32, 64, 64, 64, 88, 22 };
	for (int i : i_set)cout << i << tab; cout << endl;
	for (std::set<int>::reverse_iterator it = i_set.rbegin(); it != i_set.rend(); ++it)
		cout << *it << tab;
	cout << endl;

	std::set<std::string> s_set = { "??????", "?????", "??", "?????", "?????-???" };
	for (std::string i : s_set)cout << i << tab; cout << endl;

	std::set<Kitten> k_set = { Kitten("Tom"),  Kitten("Garfield"), Kitten("Tiger") };
	for (Kitten i : k_set)cout << i << tab; cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string > week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
	{2, "Tuesday"},
	{3, "Wednesday"},
	{4, "Thursday"},
	{5, "Friday"},
	{6, "Saturday"},
	{7, "Sunday"},
	{0, "Sunday"},
	{0, "Sunday"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		cout << it->first << tab << it->second << endl;
	}
#endif // STL_MAP

	std::map <std::string, std::list < std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("clutter", {"??????????", "????"}),
		{"space", {"????????????", "??????", "??????"}},
		{"plural", {"????????????? ?????", ""}},
		{"worth", {"????????", "????????", "??????????"}}
	};
	/*for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ":\t";
		for (std::list<std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			cout << *it2 << ", ";
		}
		cout << ":\n";
	}*/

		for (std::pair<std::string, std::list<std::string>> i : dictionary)
		{
			cout << i.first << ":\t";
			for (std::string j : i.second)
			{
				cout << j << ", ";
			}
			cout << ";\n";
		}
	
}