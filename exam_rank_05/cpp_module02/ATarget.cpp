#include "ATarget.hpp"

ATarget::ATarget() : type(){}
ATarget::ATarget(ATarget const &other){*this = other;}
ATarget::ATarget(std::string const &type) : type(type){}
ATarget::~ATarget(){}

ATarget &ATarget::operator=(ATarget const &other)
{
	if(this == &other)
		return(*this);
	this->type = other.getType();
	return(*this);
}

std::string const &ATarget::getType() const{return(this->type);}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
