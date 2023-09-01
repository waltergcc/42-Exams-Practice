#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		ASpell(ASpell const &other);
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();

		ASpell &operator=(ASpell const &other);
		
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;

		void launch(ATarget const &target);
};