#ifndef SDLCONFIG_H_
#define SDLCONFIG_H_
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "cases.h"
#include "structures.h"

#ifdef _WIN32
    #include <GL/glew.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif


/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 800;
static const char WINDOW_TITLE[] = "Insect Tower";

/* Espace fenetre virtuelle */
static const float GL_VIEW_WIDTH = 200.;
static const float GL_VIEW_HEIGHT = 150.;

/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void sdlConfig_initSDL();
void sdlConfig_reshape(SDL_Surface** surface, unsigned int width, unsigned int height);

#endif //SDLCONFIG_H_
