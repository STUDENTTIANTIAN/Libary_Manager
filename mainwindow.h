#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class MainWindow {
public:
    MainWindow();
    void show();
    void recallAction(int action);
	void load_user_data();
private:
    static int sigAct;
};