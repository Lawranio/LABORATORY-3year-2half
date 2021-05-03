#ifndef ENGINEER_H
#define ENGINEER_H

#include "Reader.h"

class Engineer : public Reader {

public:
	Engineer(const string& name, const string& position)
		: Reader(name), _position(position) {};
	virtual ~Engineer() {};

	// Занимаемая должность
	string GetPosition() { return _position; };

private:

	string _position;
};

#endif // !ENGINEER_H
