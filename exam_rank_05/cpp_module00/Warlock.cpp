#include "Warlock.hpp"

Warlock::Warlock() : name(), title(){}
Warlock::Warlock(Warlock const &other){*this = other;}
Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

Warlock &Warlock::operator=(Warlock const &other)
{
	if(this == &other)
		return(*this);
	this->name = other.getName();
	this->title = other.getTitle();
	return(*this);
}

std::string const &Warlock::getName() const{return(this->name);}
std::string const &Warlock::getTitle() const{return(this->title);}
void Warlock::setTitle(std::string const &title){this->title = title;}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
