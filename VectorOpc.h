#pragma once
#include <iostream>
typedef void (*Menu_Processing_Function_Ptr)();
class VectorMenu 
{

public:
	VectorMenu(unsigned int, const std::string, Menu_Processing_Function_Ptr);
	unsigned int get_number_option_() { return this->number_option_; };
	std::string get_title_() { return this->title_; };
	Menu_Processing_Function_Ptr get_fuction() { return this->p_processing_function_; };
private:
	unsigned int number_option_;
	const std::string title_;
	Menu_Processing_Function_Ptr p_processing_function_;
};

VectorMenu::VectorMenu(unsigned int number, const std::string title, Menu_Processing_Function_Ptr fuction)
	: number_option_(number), title_(title), p_processing_function_(fuction)
{}


