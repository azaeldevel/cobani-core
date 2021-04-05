
/*
 * main.cc
 * Copyright (C) 2021 Azael Reyes <azael.devel@gmail.com>
 * 
 * octetos-cobani is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-cobani is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "contexts.hh"

int main()
{
	std::cout << "Testing Graphics.. " << std::endl;
	
    octetos::cobani::Test* context = NULL;
    try
    {
        context = new octetos::cobani::Test(SDL_INIT_VIDEO | SDL_INIT_TIMER );
		context->setWindowSize (640, 340);
    }
    catch(const octetos::core::Exception& ex)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error detectado.", ex.what(),NULL);
    }
    catch(const std::exception& ex)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Error detectado.", ex.what(),NULL);
    }


	
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
			if(e.type == SDL_KEYDOWN and e.key.keysym.sym == SDLK_UP)
			{
				math::Vector<int> offset(0,1);
				octetos::cobani::Circle& circle = context->getCircle();
				circle.move(offset);
				//std::cout << "up\n";
			}
			else if(e.type == SDL_KEYDOWN and e.key.keysym.sym == SDLK_DOWN)
			{
				math::Vector<int> offset(0,-1);
				octetos::cobani::Circle& circle = context->getCircle();
				circle.move(offset);
				//std::cout << "down\n";
			}
			else if(e.type == SDL_KEYDOWN and e.key.keysym.sym == SDLK_LEFT)
			{
				math::Vector<int> offset(-1,0);
				octetos::cobani::Circle& circle = context->getCircle();
				circle.move(offset);
				//std::cout << "left\n";
			}
			else if(e.type == SDL_KEYDOWN and e.key.keysym.sym == SDLK_RIGHT)
			{
				math::Vector<int> offset(1,0);
				octetos::cobani::Circle& circle = context->getCircle();
				circle.move(offset);
				//std::cout << "right\n";
			}
			else if(e.type == SDL_QUIT)
			{
                quit = true;
                std::cout << "Cerrando..\n";
			}				
        }
	  	context->displayTest();		
	  	context->cleanRender();
    }
	
    delete context;
	return 0;
}

