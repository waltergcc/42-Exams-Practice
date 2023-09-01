#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::SpellBook(SpellBook const &other){*this = other;}
SpellBook::~SpellBook()
{
	std::vector<ASpell*>::iterator it;
	for(it = this->spells.begin(); it != this->spells.end(); it++)
	{
		delete *it;
	}
	this->spells.clear();
}

SpellBook &SpellBook::operator=(SpellBook const &other)
{
	if(this == &other)
		return(*this);
	return(*this);
}

void SpellBook::learnSpell(ASpell *spell)
{
	if(spell)
	{
		std::vector<ASpell*>::iterator it;
		for(it = this->spells.begin(); it != this->spells.end(); it++)
		{
			if((*it)->getName() == spell->getName())
			{
				return;
			}
		}
		this->spells.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(std::string const &spell)
{
	std::vector<ASpell*>::iterator it;
	for(it = this->spells.begin(); it != this->spells.end(); it++)
	{
		if((*it)->getName() == spell)
		{
			delete *it;
			this->spells.erase(it);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	std::vector<ASpell*>::iterator it;
	for(it = this->spells.begin(); it != this->spells.end(); it++)
	{
		if((*it)->getName() == spell)
		{
			return (*it)->clone();
		}
	}
	return NULL;
}
