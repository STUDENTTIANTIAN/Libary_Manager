#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class MainWindow {
public:
    MainWindow();
    void show();
    void recallAction(int action);
private:
    struct user_data {
        string name;
        string password;
	};
    int load_user_data();
    static int sigAct;
};