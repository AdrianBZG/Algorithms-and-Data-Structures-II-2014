#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Numero{

public:

	//Escribe un Numero al flujo sout
	virtual ostream& toStream(ostream& sout) const = 0;
	
	//Lee un Numero desde flujo sin
	virtual istream& fromStream(istream& sin) = 0;	
	//
};
