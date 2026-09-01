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
		}
	}
	file.close();

}
bool BookManger::add_book(int no, string name, int state)
{
	
}
bool BookManger::search_book(int no, string name, int state)
{
	
}