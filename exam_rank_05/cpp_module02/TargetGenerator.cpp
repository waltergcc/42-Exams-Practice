#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::TargetGenerator(TargetGenerator const &other){*this = other;}
TargetGenerator::~TargetGenerator()
{
	this->targets.clear();
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other)
{
	if(this == &other)
		return(*this);
	return(*this);
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if(target)
	{
		std::vector<ATarget*>::iterator it;
		for(it = this->targets.begin(); it != this->targets.end(); it++)
		{
			if((*it)->getType() == target->getType())
			{
				return;
			}
		}
		this->targets.push_back(target);
	}
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	std::vector<ATarget*>::iterator it;
	for(it = this->targets.begin(); it != this->targets.end(); it++)
	{
		if((*it)->getType() == target)
		{
			this->targets.erase(it);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	std::vector<ATarget*>::iterator it;
	for(it = this->targets.begin(); it != this->targets.end(); it++)
	{
		if((*it)->getType() == target)
		{
			return (*it)->clone();
		}
	}
	return NULL;
}
