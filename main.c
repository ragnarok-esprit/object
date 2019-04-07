#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"score.h"

int main()
   {

int c=1;
int go = 1;
int test1=0,test2=0,test3=0;
int test=0;
SDL_Color noir = {18,18,255}, rouge = {0,255,0};


TTF_Font *font;

  TTF_Font *police;
  int vies, etoiles;

//On crée une varuiable qui contiendra notre texte (jusqu'à 200 caractères, y'a de la marge ;) ).
    char text[200];
  /* On initialise les variables du jeu */
    vies = 5;
    etoiles = 0;
       

  
SDL_Surface *background;
SDL_Surface *detective;
SDL_Surface *harbouch,*enemyjdid;
SDL_Rect positionback,positiondet;
SDL_Rect positionharba;

SDL_Rect posen ;
SDL_Surface *HUD_vie,*HUD_etoiles;
SDL_Surface *HUD_obj; 
SDL_Rect destobj;

char nomphoto[20]="harbouch.bmp";

char chrono[16] ;
 SDL_Event event ;
        Uint32 t1 ,t2,ok=1 ;
    SDL_Surface *ecran=NULL,*texte=NULL ;
  


 // initialisation(  );

 if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    ecran = SDL_SetVideoMode(1600, 400, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
    if (ecran== NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", 640,800, SDL_GetError());
            exit(1);
        }

    SDL_WM_SetCaption("gestion temp", NULL);

 //SDL_ShowCursor(SDL_DISABLE);





  
  TTF_Init();
  police = TTF_OpenFont("DFTEH.ttf", 50);


background=SDL_LoadBMP("background-det.bmp");
detective = SDL_LoadBMP("detective.bmp");
positionback.x=0;
positionback.y=0;
SDL_BlitSurface(background,NULL,ecran,&positionback);
                

    positiondet.x=300;
    positiondet.y=250;
    
    

    SDL_SetColorKey(detective,SDL_SRCCOLORKEY,SDL_MapRGB(detective->format,255,255,255));


    harbouch=SDL_LoadBMP("harbouch.bmp");
char objet_nom[15]="harbouch.bmp" ;
char objet_nom_live[15]="life.png" ;
char objet_nom_star[15]="stars.png";
char objet_nom_enemy[15]="enemy.png";


    //SDL_SetColorKey(harbouch,SDL_SRCCOLORKEY,SDL_MapRGB(harbouch->format,255,255,255));

int s=0;

int colli=0;


SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */

       /* Règle le rectangle à blitter selon la taille de l'image source */

      destobj.x = 1000;
     destobj.y = 200;



  t1 = SDL_GetTicks();

 
  while(ok){
    SDL_PollEvent(&event);
  switch(event.type)
            {
                case SDL_QUIT:
                    ok = 0;
                case SDL_KEYUP:
                  switch(event.key.keysym.sym)
                  {
                    case SDLK_ESCAPE:
                      ok = 0;
                  
                case SDLK_UP:

                        positiondet.y--;

                        break;

                case SDLK_DOWN:

                        positiondet.y++;

                        break;

                 case SDLK_RIGHT:

                        positiondet.x++;

                        break;

                    case SDLK_LEFT:

                        positiondet.x--;

                        break;
    break;
                  

                  }
                                    break;
            }

        SDL_BlitSurface(background,NULL,ecran,&positionback);
               SDL_BlitSurface(detective,NULL,ecran,&positiondet);
 // collision avec object 
//colli variable de retour de la fonction colliz     
    colli=0;
positionharba.x=1000 ;
positionharba.y=200;
    

colli=colliz (positiondet, positionharba);
      
if(colli==1){
test2=1;
etoiles+=5;
}


    
if(test2==0){

HUD_obj= afficher_objetx(  destobj.x , destobj.y ,nomphoto ,ecran);

}

//s variable de retour de la fonction collize    
   s=0;
posen.x=500 ;
posen.y=150;;
    

s=collize (positiondet, posen);
      
if(s==1){
test=1;
 vies-=1;
}


    
if(test==0){

          enemyjdid= afficher_objetpng(  posen.x , posen.y  ,objet_nom_enemy ,ecran);

}
//chrono
    t2 = SDL_GetTicks() - t1;         //Minute       //Seconde   //Dixieme
    sprintf(chrono, "%02u:%02u.%u  ", t2/1000/60%60, t2/1000%60, t2%1000/100);
    texte = TTF_RenderText_Shaded(police, chrono, rouge,noir);
    SDL_BlitSurface(texte, NULL, ecran, 0);
   


       SDL_Rect destlive  ,destnejma;
//image vie
       destlive.x = 1400;
       destlive.y = 300;
HUD_vie=afficher_objetpng( destlive.x, destlive.y ,objet_nom_live ,ecran);

//image score
       destnejma.x = 200;
       destnejma.y = 20;              

HUD_etoiles=afficher_objetpng( destnejma.x, destnejma.y ,objet_nom_star ,ecran);


 
     /* Initialise SDL_TTF */

    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

        exit(1);
    }

    /* Charge la police en 32 points (taille) */

    font = loadFont("DFTEH.ttf", 32);

     //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    sprintf(text, "%d", vies);
    //Puis on utilise notre fonction créée précédemment
    drawString(text, 1470, 300, font,ecran);

    /* Affiche le nombre d'étoiles en haut à gauche */
 
    sprintf(text, "%d", etoiles);
    drawString(text, 260, 20, font,ecran);


   /* Close the font */

        TTF_CloseFont(font);

    /* Close SDL_TTF */

    TTF_Quit();

    SDL_Flip(ecran);

  }


 TTF_CloseFont (police);

      SDL_FreeSurface(texte) ;
      /*
                SDL_FreeSurface(enemyjdid) ;

                        SDL_FreeSurface(HUD_obj) ;
*/

      SDL_Quit();      
    }

