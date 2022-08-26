#include "User.h"

int User::MAX_ID = 0;

User::User(std::string name, int age) :
	_id{ MAX_ID++ },
	_name{ name },
	_age{ age }
{}

int User::getAge() const
{
	return this->_age;
}

int User::getId() const
{
	return this->_id;
}

std::string User::getName() const
{
	return this->_name;
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << user._id << '\n' << user._name << '\n' << user._age << '\n';
	return out;
}
