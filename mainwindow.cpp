#include "mainwindow.h"
#include <direct.h>
MainWindow::MainWindow()
{
}

void MainWindow::show(int showid)
{
	string tmp_input[2];
	switch (showid)
	{
	case 1:
		system("cls");
		cout << "******************************" << endl;
		cout << "图书管理系统" << endl;
		cout << "1登录" << endl;
		cout << "2退出" << endl;
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		while (!(cin >> acttype))
		{
			cin.clear();              // 清除 fail 状态
			cin.ignore(1024, '\n');   // 丢弃错误输入
			cout << "输入无效，请重新输入数字：" << endl;
		}
	case 2:
		system("cls");
		cout << "******************************" << endl;
		cout << "图书管理系统" << endl;
		cout << "您选择了登录，请输入用户名与密码" << endl;
		cout << "用户名：" << endl;
		cin >> tmp_input[0];
		cout << "密码：" << endl;
		cin >> tmp_input[0];
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		recallAction(1);
	case 3:
		system("cls");
		cout << "1添加图书" << endl;
		cout << "2图书列表 / 查找" << endl;
		cout << "3借书" << endl;
		cout << "4还书" << endl;
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		recallAction(1);
	default:
		break;
	}

}
void MainWindow::recallAction(int action)
{
	switch(action)
	{ 
	case 1:
		bool isPasswordCorrect;
		returnfilepath();
		load_user_data();
		isPasswordCorrect=checkPassword();
		
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
	std::ifstream file(file_path);
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "Failed to open data.txt" << std::endl;
		return 1;
	}
	while (std::getline(file, line))
	{
		size_t pos = line.find("name:");
		size_t start = pos + 5;
		size_t end = line.find("pwd:");
		data.name = line.substr(start, end - start);
		pos = line.find("pwd:");
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
bool MainWindow::checkPassword()
{
	
}
void MainWindow::showMainwindow()
{
	show(3);
}