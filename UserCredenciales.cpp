#include "Include.h"

Map UserCredenciales::abrirFile()
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
void UserCredenciales::generar_usuario(std::string user, std::string pass)
{
	std::ofstream users;
	_mkdir("C:\\DamasChinas\\");
	users.open("C:\\DamasChinas\\credentials.csv", std::ios::app);

	users << user << ";"<<pass<<"\n";

}
bool UserCredenciales::comprobar(std::string user,std::string pass) 
{ 
	Map m = abrirFile();
	MD5 crypto(pass);
	auto r = m.find(user);
	return (r != m.end() && r->second == crypto.toString()) ? true : false;
}


int UserCredenciales::login()
{
	system("cls");
	char a = 32;
	std::string user;std::string pass;
	std::cout << "User: ";
	std::cin >> user;
	std::cout << "password: ";
	while (a != 13) {
		if (a < 123 && a > 96) {
			pass.push_back(a);
			std::cout << "#";
		}
		a = _getch();
	}

	return (comprobar(user, pass)) ? 1 : 0;

}

int UserCredenciales::logearse()
{
	system("cls");

	char a = 32;
	std::string user;
	std::string pass;

	std::cout << "User : ";
	std::cin >> user;
	std::cout << "password: ";
	while (a != 13) {
		if (a < 123 && a > 96) {
			pass.push_back(a);
			std::cout << a;
		}
		a = _getch();
	}

	return encriptar(pass, user);
}

int UserCredenciales::encriptar(std::string& pass, std::string& user)
{
	MD5 crypto(pass);

	if (!comprobar(user, pass))
	{
		generar_usuario(user, crypto.toString());
		return 1;
	}

	return 0;
}
