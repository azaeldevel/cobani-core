#ifndef OCTETOS_COBANI_CONTEXTS_HH
#define OCTETOS_COBANI_CONTEXTS_HH




#include "core.hh"


namespace octetos::cobani
{



class DECLSPCE_DLL Test : public Screen
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

class DECLSPCE_DLL Room : public Screen
{

};

class DECLSPCE_DLL School : public Screen
{


};

class DECLSPCE_DLL Social : public Screen
{

};


}

#endif // CONTEXTS_HH
