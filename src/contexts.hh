#ifndef OCTETOS_COBANI_CONTEXTS_HH
#define OCTETOS_COBANI_CONTEXTS_HH




#include "core.hh"


namespace octetos::cobani
{



class DECLSPCE_DLL Test : public Context
{
public:
	//contructors
    Test();
    Test(Uint32 flags);
	Circle& getCircle();

	//functions
	void displayPregress();
	void displayPregress2();
	void displayObjectTest();
	void displayTest();
    void displayLoading();
private:
	Circle circle;
};

class DECLSPCE_DLL Room : public Context
{

};

class DECLSPCE_DLL School : public Context
{


};

class DECLSPCE_DLL Social : public Context
{

};


}

#endif // CONTEXTS_HH
