#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct 
{
	SDL_Surface *image;
	SDL_Rect pous;
}objet ;

//fonction pour afficher les images .bmp
SDL_Surface* afficher_objetx( int x,int y,char nomphoto[] ,SDL_Surface *ecran);
//fonction pour afficher les images .png
SDL_Surface* afficher_objetpng( int x,int y,char nomphoto[] ,SDL_Surface *ecran);
//fonction pour telecharger la police
TTF_Font *loadFont(char *name, int size);
//fermer police
void closeFont(TTF_Font *font);
//affciher texte
void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface *ecran);
//bounding box objet et hero
int colliz (SDL_Rect detective, SDL_Rect harboucha);
//bounding box ennemi et hero
int collize (SDL_Rect detective, SDL_Rect ennemi);

#endif /* FONCTIONS_H_ */
