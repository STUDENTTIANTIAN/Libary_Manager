#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class MainWindow {
public:
    MainWindow();
    void show(int showid);
    void recallAction(int action, string temp_input[]);
    string getPwdpath();
    string returnfilepath();
    bool checkPassword(string input_password);
    bool checkUserName(string input_password);
    void showMainwindow();
    int getMapOperaton(int no);

    //图书操作相关
    void init_book();
    string getBookfilepath();

private:
    struct user_data {
        string name;
        string password;
	};
    struct book_info {
        string book_name;
        int book_no;
        bool book_state;
    };
    struct book_array
    {
        int maxsize = 1024;
        int front;
        int tail;
        book_info* book_info_array = new book_info[maxsize];
    };
    static struct book_array book;
    int acttype;
    struct user_data data;
    int load_user_data();
    string file_path;
    static int sigAct;
};