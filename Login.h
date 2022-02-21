#ifndef LOGIN_H 
#define LOGIN_H 

#include "Include.h"

typedef std::map<std::string, std::string> Map;

class Login
{
public:
	int login();
	int sigin();
	Map read_file();
	void write_user(std::string, std::string);
	bool check_user(std::string, std::string);

private:

};

#endif