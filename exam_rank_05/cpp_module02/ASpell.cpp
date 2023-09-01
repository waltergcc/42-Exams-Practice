#include "ASpell.hpp"

ASpell::ASpell() : name(), effects(){}
ASpell::ASpell(ASpell const &other){*this = other;}
ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects){}
ASpell::~ASpell(){}

ASpell &ASpell::operator=(ASpell const &other)
{
	if(this == &other)
		return(*this);
	this->name = other.getName();
	this->effects = other.getEffects();
	return(*this);
}

std::string ASpell::getName() const{return(this->name);}
std::string ASpell::getEffects() const{return(this->effects);}

void ASpell::launch(ATarget const &target)
{
	target.getHitBySpell(*this);
}
