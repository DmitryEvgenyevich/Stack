#pragma once
#include <iostream>
class User
{
private:
	static int MAX_ID;
	int _id;
	std::string _name;
	int _age;

public:
	User() = default;
	User(std::string name, int age);
	int getAge() const;
	int getId() const;
	std::string getName() const;
	~User() = default;
	friend std::ostream& operator<<(std::ostream& out, const User& user);

};

