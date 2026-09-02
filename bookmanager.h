#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <direct.h>
using namespace std;
class BookManger {
public:
    BookManger(const string& path);
    void init_book(const string& path);
    string getBookfilepath(const string& path);
    bool add_book(int no,string name);
    bool search_book(int no, string name);
    bool insert_book(int no, string name);
    bool del_book(int i);
private:
    struct book_info {
        string book_name;
        int book_no;
        bool book_state;
    };
    struct book_array
    {
        int capital = 0;
        int maxsize = 1024;
        int front=-1;
        int tail=-1;
        book_info* book_info_array = new book_info[maxsize];
    };
    static struct book_array book;
};