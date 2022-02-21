#include "Include.h"

Map Login::read_file()
{ 
	Map a;
	std::string data = "";
	std::string user = "";
	std::string pass = "";
	std::ifstream file;
	file.open("C:\\DamasChinas\\credentials.csv");
	if (!file)
		return a;

	while (std::getline(file,data))
	{
		std::stringstream data1(data);

		std::getline(data1, data,';');
		user = data;
		std::getline(data1, data, ';');
		pass = data;
		a.insert(Map::value_type(user, pass));
	}
	
	return  a;
}
void Login::write_user(std::string user, std::string pass)
{
	std::ofstream users;
	_mkdir("C:\\DamasChinas\\");
	users.open("C:\\DamasChinas\\credentials.csv", std::ios::app);

	users << user << ";"<<pass<<"\n";

}
bool Login::check_user(std::string user,std::string pass) 
{ 
	Map m = read_file();
	MD5 crypto(pass);
	auto r = m.find(user);
	return (r != m.end() && r->second == crypto.toString()) ? true : false;
}


int Login::login()
{
	system("cls");
	char a = 32;
	std::string user;
	std::string pass;

	std::cout << "Usuario: ";
	std::cin >> user;
	std::cout << "Contrase" << (char)164 << "a: ";
	while (a != 13) {
		if (a < 123 && a > 96) {
			pass.push_back(a);
			std::cout << "*";
		}
		a = _getch();
	}

	return (check_user(user, pass)) ? 1 : 0;

}

int Login::sigin()
{
	system("cls");

	char a = 32;
	std::string user;
	std::string pass;

	std::cout << "Usuario: ";
	std::cin >> user;
	std::cout << "Contrase" << (char)164 << "a: ";
	while (a != 13) {
		if (a < 123 && a > 96) {
			pass.push_back(a);
			std::cout << a;
		}
		a = _getch();
	}

	MD5 crypto(pass);

	if (!check_user(user, pass)) 
	{
		write_user(user, crypto.toString());
		return 1;
	}

	return 0;
}