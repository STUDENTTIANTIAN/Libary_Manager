#include "bookmanager.h"
#include <direct.h>
BookManger::BookManger(const string& path)
{
	init_book(path);
}
std::string BookManger::getBookfilepath(const string& path)
{
	string file_path = path + "\\book.txt";
	return file_path;
}
void BookManger::init_book(const string& path)
{
	string book_path = getBookfilepath(path);
	ifstream file(book_path);
	if (!file.is_open())
	{
		cerr << "Failed to open book.txt";
		return;
	}
	book.front = 0;
	book.tail = 0;
	int i = 1;
	string line;
	while (getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}
		int no = 0;
		string name;
		bool state = false;
		size_t pos = line.find("NO:");
		if (pos != string::npos)
		{
			no = atoi(line.substr(pos + 3).c_str());
		}
		pos = line.find("NAME:");
		if (pos != string::npos)
		{
			size_t start = pos + 5;
			size_t end = line.find(",state:", start);
			if (end == string::npos)
			{
				end = line.length();
			}
			name = line.substr(start, end - start);
		}
		pos = line.find("state:");
		if (pos != string::npos)
		{
			state = (atoi(line.substr(pos + 6).c_str()) == 1);
		}
		if (book.tail < book.maxsize)
		{
			book.book_info_array[book.tail].book_no = no;
			book.book_info_array[book.tail].book_name = name;
			book.book_info_array[book.tail].book_state = state;
			book.tail++;
			book.capital = i;
			i++;
		}
	}
	file.close();

}
bool BookManger::add_book(int no, string name)
{
	bool isHaving;
	isHaving = search_book(no, name);
	if (isHaving == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool BookManger::search_book(int no, string name)
{
	int temp_no;
	string temp_book_name;
	if (book.capital <= 0)
	{
		return false;
	}
	for (int i = 0; i <= book.capital; i++)
	{
		if ((book.book_info_array[i].book_name == temp_book_name)&& (book.book_info_array[i].book_no == temp_no))
		{
			return i;
		}
		else
		{
			return false;
		}
	}
}
bool BookManger::insert_book(int no, string name)
{
	if (book.capital == book.maxsize)
	{
		return false;
	}
	else
	{
		book.book_info_array[book.tail + 1].book_name = name;
		book.book_info_array[book.tail + 1].book_no = no;
		book.book_info_array[book.tail + 1].book_state = 0;
		book.tail++;
		return true;
	}
}
bool BookManger::del_book(int i)
{
	if (book.capital == 0)
	{
		return false;
	}
	else
	{
		for(int j=i;j<book.capital;j++)
		{ 
			book.book_info_array[j].book_name = book.book_info_array[j+1].book_name;
			book.book_info_array[j].book_no = book.book_info_array[j+1].book_no;
			book.book_info_array[j].book_state = book.book_info_array[j+1].book_state;
		}
		book.tail--;
		return true;
	}
}