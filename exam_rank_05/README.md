# Exam Rank 05

In this folder you will find my resolutions for the exercises that I have been doing to prepare for the Exam Rank 05. I have used the [grademe](https://grademe.fr/) plataform to prepare myself.

This `cpp_modules` resolution were used by me during the Exam and passed with 100%.

## Disclaimer
During the grademe execution, when using the code exactly as it's, it will have failures in `cpp_module01` and `cpp_module02` exercises, but during the Exam this code passed with 100%.

The specific scene that generates this is this: during the cpp_module01 exercise, the Subject says the following during the addition of new functions to Warlock class:

```
Add to the Warlock the following member functions:

* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.

```
Subject makes it clear that a `string` and a `reference to ATarget` should be used, not a `constant reference to ATarget`.

In this case, the prototype of the function should be this:

```cpp
void launchSpell(std::string spell, ATarget &target);

void Warlock::launchSpell(std::string spell, ATarget &target)
{
	ATarget *check = &target;
	...
}
```

But when I use this prototype, the grademe will fail, as it expects the prototype to be this:

```cpp
void launchSpell(std::string spell, ATarget const &target);

void Warlock::launchSpell(std::string spell, ATarget const &target)
{
	ATarget const *check = &target;
	...
}
```
My recommendation is as follows, to avoid problems with the grademe, use the prototype that the grademe expects during the moment of study, but during the real Exam uses the prototype that is passed on the subject, because I don't know the way the grademe test works, and I don't know if this way will work on the Exam because I've only tested the way the subject says and it worked.

Good study! :smile: