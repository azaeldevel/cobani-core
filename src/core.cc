
#include <iostream>


#include "core.hh"

namespace octetos::cobani
{



	//contructos
	Color::Color()
	{
	}
	Color::Color(Uint8 red,Uint8 green,Uint8 blue)
	{
		r = red;
		g = green;
		b = blue;
		a = 255;
	}
	Color::Color(Uint8 red,Uint8 green,Uint8 blue,Uint8 alpha)
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;	
	}

	//getter
	Uint8 Color::getReg()const
	{
		return r;
	}
	Uint8 Color::getGreen()const
	{
		return g;
	}
	Uint8 Color::getBlue()const
	{
		return b;
	}
	Uint8 Color::getAlpha()const
	{
		return a;
	}

	//setter	
	void Color::setRed(Uint8 red)
	{
		r = red;
	}
	void Color::setGreen(Uint8 green)
	{
		g = green;
	}
	void Color::setBlue(Uint8 blue)
	{
		b = blue;
	}
	void Color::setAlpha(Uint8 alpha)
	{
		a = alpha;
	}

	


	

	Rectangle::Rectangle()
	{}
	Rectangle::Rectangle(OCTETOS_MATH_INTEGER x, OCTETOS_MATH_INTEGER y , OCTETOS_MATH_INTEGER width, OCTETOS_MATH_INTEGER height)
	{
		this->x = x;
		this->y = y;
		w = width;
		h = height;
	}
	Rectangle::Rectangle(const math::Point<int>& origin, OCTETOS_MATH_INTEGER width, OCTETOS_MATH_INTEGER height)
	{
		x = origin[0];
		y = origin[1];
		w = width;
		h = height;
	}
	Rectangle::Rectangle(const math::Point<int>& origin, OCTETOS_MATH_INTEGER width)
	{
		x = origin[0];
		y = origin[1];
		w = width;
		h = width;
	}

	//getter
	
	//funtions
	void Rectangle::draw(Screen& context)
	{
		int ret = SDL_RenderDrawRect(context.getRenderer(),this);
		if(ret < 0)
        {
            std::string msg = "Fallo al dibuar el rectangulo '";
            msg = msg + "(" + std::to_string(x) + "," + std::to_string(y) + ")" + " : ";
			msg = msg + " width = " + std::to_string(w) + ", " + " height = " + std::to_string(h) + ".";
            throw octetos::core::Exception(msg,__FILE__,__LINE__);
        }
	}
	void Rectangle::center()
	{		
		x = x - w/2;
#if COBANI_DIMENSION >= 2
		y = y - h/2;
#endif
	}






	//contructor
	Ellipse::Ellipse()
	{
	}
	Ellipse::Ellipse(const math::Point<int>& c,OCTETOS_MATH_DECIMAL rx,OCTETOS_MATH_DECIMAL ry)
	{
		center = c;
		radiusX = rx;
		radiusY = ry;
	}

	//getter	
	const math::Point<int>& Ellipse::getCenter()const
	{
		return center;
	}
	OCTETOS_MATH_DECIMAL Ellipse::getRadiusX()const
	{
		return radiusX;
	}
	OCTETOS_MATH_DECIMAL Ellipse::getRadiusY()const
	{
		return radiusY;
	}

	//setter	
	void Ellipse::set(const math::Point<int>& c,OCTETOS_MATH_DECIMAL rx,OCTETOS_MATH_DECIMAL ry)
	{
		center = c;
		radiusX = rx;
		radiusY = ry;		
	}
	//funtions
	void Ellipse::draw(Screen& context)
	{
		OCTETOS_MATH_INTEGER x0 = center[0];
		OCTETOS_MATH_INTEGER y0 = center[1];
		SDL_Renderer* r = context.getRenderer ();
		float pi  = 3.14159265358979323846264338327950288419716939937510;
		float pih = pi / 2.0; //half of pi

		//drew  28 lines with   4x4  circle with precision of 150 0ms
		//drew 132 lines with  25x14 circle with precision of 150 0ms
		//drew 152 lines with 100x50 circle with precision of 150 3ms
		const int prec = 27; // precision value; value of 1 will draw a diamond, 27 makes pretty smooth circles.
		float theta = 0;     // angle that will be increased each loop

		//starting point
		int x  = (float)radiusX * cos(theta);//start point
		int y  = (float)radiusY * sin(theta);//start point
		int x1 = x;
		int y1 = y;

		//repeat until theta >= 90;
		float step = pih/(float)prec; // amount to add to theta each time (degrees)
		for(theta=step;  theta <= pih;  theta+=step)//step through only a 90 arc (1 quadrant)
		{
		    //get new point location
		    x1 = (float)radiusX * cosf(theta) + 0.5; //new point (+.5 is a quick rounding method)
		    y1 = (float)radiusY * sinf(theta) + 0.5; //new point (+.5 is a quick rounding method)

		    //draw line from previous point to new point, ONLY if point incremented
		    if( (x != x1) || (y != y1) )//only draw if coordinate changed
		    {
		        SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
		        SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
		        SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
		        SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
		    }
		    //save previous points
		    x = x1;//save new previous point
		    y = y1;//save new previous point
		}
		//arc did not finish because of rounding, so finish the arc
		if(x!=0)
		{
		    x=0;
		    SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );//quadrant TR
		    SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );//quadrant TL
		    SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );//quadrant BL
		    SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );//quadrant BR
		}
	}




	





	//contructos
	Circle::Circle()
	{

	}
	Circle::Circle(const math::Point<int>& c,OCTETOS_MATH_INTEGER r)
	{
		pointcenter = c;
		radius = r;
	}

	//
	const math::Point<int>& Circle::getCenter()const
	{
		return pointcenter;
	}
	OCTETOS_MATH_INTEGER Circle::getRadius()const
	{
		return radius;
	}
	
	//funtions
	void Circle::draw(Screen& context)
	{
		SDL_Renderer * renderer = context.getRenderer();
		OCTETOS_MATH_INTEGER centreX = context.convX(pointcenter[0]);
		OCTETOS_MATH_INTEGER centreY = context.convX(pointcenter[1]);
		//COBANI_TYPE_INTEGER radius = 30;
		OCTETOS_MATH_INTEGER diameter = (radius * 2);
	   	OCTETOS_MATH_INTEGER x = (radius - 1);
	   	OCTETOS_MATH_INTEGER y = 0;
	   	OCTETOS_MATH_INTEGER tx = 1;
	   	OCTETOS_MATH_INTEGER ty = 1;
	   	OCTETOS_MATH_INTEGER error = (tx - diameter);

	   	while (x >= y)
		{
		  	//  Each of the following renders an octant of the circle
      		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		  	SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		  	SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		  	SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		  	SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
		  	SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		  	SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		  	if (error <= 0)
		  	{
		     	++y;
		     	error += ty;
		     	ty += 2;
		  	}

		  	if (error > 0)
		  	{
		     	--x;
		     	tx += 2;
		     	error += (tx - diameter);
		  	}
		}
	}
	void Circle::set(const math::Point<int>& c, OCTETOS_MATH_INTEGER r)
	{
		pointcenter = c;
		radius = r;
	}
	void Circle::move(const math::Vector<int>& v)
	{
		pointcenter.translate(v);
	}






	
	//Contructors
	Line::Line()
	{
	
	}
	Line::Line(const math::Point<int>& o, const math::Point<int>& e)
	{
		origin = o;
		end = e;
	}
	//getter
	const math::Point<int>& Line::getOrigin()const
	{
		return origin;
	}
	const math::Point<int>& Line::getEnd()const
	{
		return end;
	}

	//setter
	void Line::set(const math::Point<int>& o, const math::Point<int>& e)
	{
		origin = o;
		end = e;		
	}
	
	//funtions
	void Line::draw(Screen& context)
	{
		SDL_RenderDrawLine(context.getRenderer(), origin[0], origin[1], end[0], end[1]);
	}




	Triangle::Triangle(const math::Point<int>& v1,const math::Point<int>& v2, const math::Point<int>& v3)
	{
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}
		







Screen::Screen()
{
    init(SDL_INIT_EVERYTHING);
	cleanBackgraund();
	media();
}
Screen::Screen(Uint32 flags)
{
    init(flags);
	cleanBackgraund();
	media();
}
Screen::~Screen()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
}


//getter
SDL_Renderer* Screen::getRenderer()const
{
    return renderer;
}

//funtions
void Screen::init(Uint32 flags)
{
    if ( SDL_Init( flags ) < 0 )
    {
        throw core::Exception(__FILE__,__LINE__,"Fallo la inicializacion de la venta.");
    }
    if ( TTF_Init() < 0 )
    {
        std::string msg = "Error initializing SDL_ttf: ";
        msg += TTF_GetError();
        msg +=  "\n";
        throw core::Exception(__FILE__,__LINE__,msg);
    }
	createScreen();
}
void Screen::createScreen()
{
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
	if(!window)
	{
        throw core::Exception(__FILE__,__LINE__,"Creatign  winodows fail.");
    }
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
	if(!renderer)
	{
        throw core::Exception(__FILE__,__LINE__,"Creatign  redender fail.");
    }
}
void Screen::cleanBackgraund(const Color& color)
{
	SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
	SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
int Screen::setRenderDrawColor(const Color& color)
{
	return SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
}


void Screen::getWindowSize(int& w, int&h)
{
	SDL_GetWindowSize(window,&w,&h);
}
void Screen::renderPresent()
{
	SDL_RenderPresent(renderer);
}
void Screen::cleanRender()
{
	int ret = SDL_RenderClear(renderer);
	if(ret < 0)
	{
		std::string msg = "Fallo al limpiar el ahre de renderizado : ";
		msg  = msg + SDL_GetError();
		throw octetos::core::Exception(msg,__FILE__,__LINE__);
	}
}
void Screen::setWindowSize(int w,int h)
{
	SDL_SetWindowSize(window,w,h);
}
int Screen::convX(int v)
{
	return v + mediaX;
}

int Screen::convY(int v)
{
	return (-1 * v) + mediaY;
}
void Screen::media()
{
	int w,h;
	getWindowSize(w,h);
	mediaX = w/2;
	mediaY = h/2;
	std::cout << "mediaX = " << mediaX << "\n";
	std::cout << "mediaY = " << mediaY << "\n";
}

}
