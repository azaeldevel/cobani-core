
#ifndef OCTETOS_COBANI_CORE_HH
#define OCTETOS_COBANI_CORE_HH

#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <octetos/core/Object.hh>
#include <SDL.h>
#include <SDL_ttf.h>
#include <octetos/math/Vector.hh>


namespace octetos::cobani
{
class Screen;


class DECLSPCE_DLL Color : public SDL_Color
{
public:
	//contructors
	Color();
	Color(Uint8 red,Uint8 green,Uint8 blue);
	Color(Uint8 red,Uint8 green,Uint8 blue,Uint8 alpha);

	//getter
	Uint8 getReg()const;
	Uint8 getGreen()const;
	Uint8 getBlue()const;
	Uint8 getAlpha()const;

	//setter
	void setRed(Uint8 red);
	void setGreen(Uint8 green);
	void setBlue(Uint8 blue);
	void setAlpha(Uint8 alpha);

	//funtions
	//int getRenderDrawColor(Context& context);
};



namespace colors
{
	static const Color white(255,255,255);
	static const Color black(0,0,0);
}








class DECLSPCE_DLL Drawable
{
	virtual void draw(Screen&) = 0;
};


class DECLSPCE_DLL Shape : public Drawable
{
public:
	//
	Shape();
	Shape(const math::Vector<int>& origin);

	//funtions
	/**
	*\brief asigna una la fugura la nueva posion especificada
	*/
	virtual void move(const math::Vector<int>& p);
	/**
	*\brief aplica la operacion vetorial de translacion
	*/
	virtual void translate(const math::Vector<int>& p);
protected:
	math::Vector<int> origin;
};

class DECLSPCE_DLL Line  : public Shape
{
public:
	//Contructors
	Line();
	Line(const math::Point<int>& origin, const math::Point<int>& end);
	//getter
	const math::Point<int>& getOrigin()const;
	const math::Point<int>& getEnd()const;

	//setter
	void set(const math::Point<int>& origin, const math::Point<int>& end);
	
	//funtions
	virtual void draw(Screen& context);
private:
	//math::Point<int> origin;
	math::Point<int> end;
};

class DECLSPCE_DLL Circle : public Shape
{
public:
	//contructor
	Circle();
	Circle(const math::Vector<int>& center, int radius);
	
	//getter
	const math::Vector<int>& getCenter()const;
	int getRadius()const;
	void set(const math::Vector<int>& center, int radius);
	
	//funtions
	virtual void draw(Screen& context);
	//virtual void move(const math::Vector<int>& v);

private:
	//math::Vector<int> pointcenter;
	int radius;
};

class DECLSPCE_DLL Ellipse :  public Shape
{
public:
	Ellipse();
	Ellipse(const math::Point<int>& center,int radiusX,int radiusY);
	
	//getter
	const math::Vector<int>& getCenter()const;
	int getRadiusX()const;
	int getRadiusY()const;

	//setter
	void set(const math::Vector<int>& center,int radiusX,int radiusY);

	//funtions
	virtual void draw(Screen& context);
private:
	//math::Point<int> center;
	int radiusX;
	int radiusY;
};


class DECLSPCE_DLL Rectangle : public SDL_Rect, public Shape
{
public:
	//contructor
	Rectangle();
	Rectangle(const SDL_Rect&);
	Rectangle(int x, int y , int width, int height);
	Rectangle(const math::Vector<int>& origin, int width, int height);
	/**
	*\brief Case espcial para el cuadrado
	*/
	Rectangle(const math::Vector<int>& origin, int width);
	
	//functions
	virtual void draw(Screen& context);
	virtual void center();
	virtual void move(const math::Vector<int>& v);
	virtual void translate(const math::Vector<int>& v);
};


class Triangle
{
public:
	Triangle(const math::Point<int>& v1,const math::Point<int>& v2, const math::Point<int>& v3);

private:
	math::Point<int> v1;
	math::Point<int> v2;
	math::Point<int> v3;
};

class Camera : public Rectangle
{
public:
	//contructor
	Camera();
	Camera(const SDL_Rect&);
	Camera(int x, int y , int width, int height);
	Camera(const math::Point<int>& origin, int width, int height);
	/**
	*\brief Case espcial para el cuadrado
	*/
	Camera(const math::Point<int>& origin, int width);
	
};

class DECLSPCE_DLL Screen
{
public:
	//contructors
    Screen();
    Screen(Uint32 flags);
    virtual ~Screen();
	
    //getter
    SDL_Renderer* getRenderer()const;
	
	//setter
	
    //funciones
#ifdef COBANI_DEBUG
#endif
	void init(Uint32 flags);
	void cleanBackgraund(const Color& color = colors::white);
	int setRenderDrawColor(const Color& color);
	void getWindowSize(int& w, int& h);
	void renderPresent();
	void cleanRender();
	void setWindowSize(int width,int height);
	int convX(int v);
	int convY(int v);
	void createScreen();

	//
	static const int DEFAULT_WIDTH;
	static const int DEFAULT_HEIGHT;
	

protected:

	//funtions
	void media();

	//
    SDL_Window *window;
    SDL_Renderer *renderer;
	int mediaX;
	int mediaY;
	Camera* camera;

};


}

#endif
