#include "mainwindow.h"
MainWindow::MainWindow()
{
}

void MainWindow::show()
{
	system("cls");
	cout<<"******************************"<<endl;
	cout<<"图书管理系统" << endl;
	cout << "1登录" << endl;
	cout << "2退出" << endl;
	cout << "版权@天天工作室" << endl;
	cout << "******************************" << endl;
}
void MainWindow::recallAction(int action)
{
	switch(action)
	{ 
	case 1:
		break;
	case 2:
		break;
	default:
		return ;
	}


}
void MainWindow::load_user_data()
{
	// Implement the logic to load user data here
}