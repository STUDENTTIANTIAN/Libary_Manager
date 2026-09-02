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


private:
    struct user_data {
        string name;
        string password;
	};

    int acttype;
    struct user_data data;
    int load_user_data();
    string file_path;
    static int sigAct;
};