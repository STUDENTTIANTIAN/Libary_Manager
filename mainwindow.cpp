#include "mainwindow.h"
#include <direct.h>
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
int MainWindow::load_user_data()
{
	// Implement the logic to load user data here
	std::ifstream file("data.txt");
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "Failed to open data.txt" << std::endl;
		return 1;
	}
	while (std::getline(file, line))
	{
		user_data data;
		size_t pos = line.find("name:");
		size_t start = pos + 5;
		size_t end = line.find("pwd=");
		data.name = line.substr(start, end - start);
		pos = line.find("pwd=");
		start = pos + 4;
		data.password = line.substr(start);

	}
	return 1;
}
string MainWindow::getPwdpath()
{
	char buf[1024];
	_getcwd(buf, 1024);
	file_path = std::string(buf) + "\\data.txt";
	return file_path;
}
string MainWindow::returnfilepath()
{
	getPwdpath();
	return file_path;
}