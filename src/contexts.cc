
#include "contexts.hh"


namespace octetos::cobani
{

	
	Circle& Test::getCircle()
	{
		return circle;
	}
	void Test::displayLoading()
	{
		TTF_Font* font;

		#if defined WINDOWS_MINGW
		font = TTF_OpenFont("/msys64/mingw64/share/fonts/TTF/DejaVuSans.ttf", 60);
		#elif defined LINUX
		font = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSans.ttf", 60);
		#elif defined LINUX_DEBIAN
		font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 60);
		#endif
		if ( !font )
		{
		    std::string msg = "Failed to load font : ";
		    msg += TTF_GetError();
		    msg +=  "\n";
		    throw core::Exception(msg,__FILE__,__LINE__);
		}
		SDL_Surface* text;
		// Set color to black
		SDL_Color color = { 0, 0, 0 };

		text = TTF_RenderText_Solid( font, "Cargando componentes!...", color );
		if ( !text )
		{
		    std::string msg = "Failed to render text:";
		    msg += TTF_GetError();
		    msg +=  "\n";
		}
		SDL_Texture* text_texture;
		text_texture = SDL_CreateTextureFromSurface( m_renderer, text );
		SDL_Rect dest = { 0, text->h / 2, text->w / 2, text->h /3 };
		SDL_RenderCopy( m_renderer, text_texture, NULL, &dest );
		SDL_DestroyTexture( text_texture );
		SDL_FreeSurface( text );
		TTF_CloseFont(font);
	}
	void Test::displayPregress2()
	{
		SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
		SDL_RenderClear( m_renderer );
	}
	void Test::displayPregress()
	{
		// Clear the window with a black background
		SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
		SDL_RenderClear( m_renderer );

		// Show the window
		SDL_RenderPresent( m_renderer );

		int rgb[] = { 203, 203, 203, // Gray
		              254, 254,  31, // Yellow
		                0, 255, 255, // Cyan
		                0, 254,  30, // Green
		              255,  16, 253, // Magenta
		              253,   3,   2, // Red
		               18,  14, 252, // Blue
		                0,   0,   0  // Black
		            };

		SDL_Rect colorBar;
		colorBar.x = 0; colorBar.y = 0; colorBar.w = 90; colorBar.h = 480;

		// Render a new color bar every 0.5 seconds
		for ( int i = 0; i != sizeof rgb / sizeof *rgb; i += 3, colorBar.x += 90 )
		{
		    SDL_SetRenderDrawColor( m_renderer, rgb[i], rgb[i + 1], rgb[i + 2], 255 );
		    SDL_RenderFillRect( m_renderer, &colorBar );
		    SDL_RenderPresent( m_renderer );
		    displayLoading();
		    SDL_Delay( 500 );
		}
	}
	void Test::displayObjectTest()
	{
		//std::cout << "Context::displayObjectTest : Step 1\n";		
		setRenderDrawColor(colors::black);
		//crear una porsonaje
		//std::cout << "Context::displayObjectTest : Step 2\n";
		//Entity entity(1);
		//std::cout << "Context::displayObjectTest : Step 3\n";
		//Person homo1(entity,"spok","santel",19.5,7.0,25.0);
		//std::cout << "Context::displayObjectTest : Step 4\n";
		//homo1.draw(*this);
		//std::cout << "Context::displayObjectTest : Step 4\n";

		setRenderDrawColor(colors::white);
		renderPresent();
		//std::cout << "Context::displayObjectTest : Step 5\n";
	}
    Test::Test()
	{
		math::Point<int> O(0,0);
		circle.set(O,30);
	}
    Test::Test(Uint32 flags) : Context(flags)
	{
		math::Point<int> O(0,0);
		circle.set(O,30);
	}
	void Test::displayTest()
	{
		setRenderDrawColor(colors::black);
		
		circle.draw(*this);
		setRenderDrawColor(colors::white);
		renderPresent();
	}



	









}
