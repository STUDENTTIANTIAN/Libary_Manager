#include "mainwindow.h"
#include <direct.h>
MainWindow::MainWindow()
{
}

void MainWindow::show(int showid)
{
	string tmp_input[2];
	int no;
	switch (showid)
	{
	case 1://系统界面
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
	case 2://登录输入界面
		system("cls");
		cout << "******************************" << endl;
		cout << "图书管理系统" << endl;
		cout << "您选择了登录，请输入用户名与密码" << endl;
		cout << "用户名：" << endl;
		cin >> tmp_input[0];
		cout << "密码：" << endl;
		cin >> tmp_input[1];
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		recallAction(1, tmp_input);
	case 3://登录验证成功后选择的功能页面
		system("cls");
		cout << "1添加图书" << endl;
		cout << "2图书列表 / 查找" << endl;
		cout << "3借书" << endl;
		cout << "4还书" << endl;
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		cin >> no;
		recallAction(10+no, tmp_input);
	case 4://添加图书功能
		system("cls");
		cout << "1添加图书" << endl;
		cout << "2图书列表 / 查找" << endl;
		cout << "3借书" << endl;
		cout << "4还书" << endl;
		cout << "版权@天天工作室" << endl;
		cout << "******************************" << endl;
		cout << "请输入数字进行接下来操作：" << endl;
		cin >> no;
		recallAction(10 + no, tmp_input);
	default:
		break;
	}

}
void MainWindow::recallAction(int action, string temp_input[])
{
	switch(action)
	{ 
	case 1:
		bool isPasswordCorrect;
		bool isUserNameCorrect;
		returnfilepath();
		load_user_data();
		isUserNameCorrect = checkUserName(temp_input[0]);
		isPasswordCorrect=checkPassword(temp_input[1]);
		if (isUserNameCorrect && isPasswordCorrect)
		{
			show(3);
		}
		else
		{
			
			int i = 0;
			string tmp_pwd;
			while (i < 3)
			{
				cout << "密码输入错误请重新输入" << endl;
				cin >> tmp_pwd;
				if (checkUserName(tmp_pwd))
				{
					show(3);
					break;
				}
				i++;
			}
			exit(0);

		}

		
		break;
	case 11:


		break;
	default:
		return ;
	}


}
//密码有关
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
		if (pos != std::string::npos)
		{
			data.name = line.substr(pos + 5);
		}
		pos = line.find("pwd:");
		if (pos != std::string::npos)
		{
			data.password = line.substr(pos + 4);
		}
	}
	return 0;
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
bool MainWindow::checkPassword(string input_password)
{
	return data.password == input_password;
}
bool MainWindow::checkUserName(string input_userneme)
{
	if (input_userneme == data.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MainWindow::showMainwindow()
{
	show(1);
}

//book相关
string MainWindow::getBookfilepath()
{
	char buf[1024];
	_getcwd(buf, 1024);
	file_path = std::string(buf) + "\\book.txt";
	return file_path;
}
void MainWindow::init_book()
{

}