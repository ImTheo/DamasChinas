#ifndef LOGIN_H 
#define LOGIN_H 

#include "Include.h"

typedef std::map<std::string, std::string> Map;

class UserCredenciales
{
public:
	int login();
	/**
	 * @brief 
	 * 
	 * @return int 
	 */
	int logearse();
	/**
	 * @brief 
	 * 
	 * @param pass 
	 * @param user 
	 * @return int 
	 */
	int encriptar(std::string& pass, std::string& user);
	/**
	 * @brief 
	 * 
	 * @return Map 
	 */
	Map abrirFile();
	/**
	 * @brief 
	 * 
	 */
	void generar_usuario(std::string, std::string);
	/**
	 * @brief 
	 * 
	 * @return true 
	 * @return false 
	 */
	bool comprobar(std::string, std::string);

private:

};

#endif