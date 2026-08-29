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
    void recallAction(int action);
    string getPwdpath();
    string returnfilepath();
    bool checkPassword();
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