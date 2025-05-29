
/******************************************************************************\
    lololololololololololololololololololololololololololololololololololololol

	Title:
		BLACK HOLE

	Description:
		Este es el código para un videojuego realizado para evaluar el tercer 
        parcial para la materia de Programación I con el profesor Aldo Guzmán
        Sáenz, en la Escuela Superior de Física y Matemáticas (ESFM). Se trata 
        de una nave que dispara balas y destruye asteroides en el espacio.

	Author:
		José Arturo Barrera González
        :D
        
	Date:
		9 de noviembre - 6 diciembre de 2011

	Note:
		Este código puede o no generar el juego con todas las características
        que se solicitaron en clase XDDDDDD
		
	lololololololololololololololololololololololololololololololololololololol
\******************************************************************************/

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

// SDL_gfx
#include <SDL/SDL_rotozoom.h>		// SDL_gfx Rotozoom
#include <SDL/SDL_gfxPrimitives.h>	// SDL_gfx Primitives
#include <SDL/SDL_framerate.h>		// SDL_gfx Framerate Manager


// For more information about SDL_gfx, please visit their website at
// http://www.ferzkopp.net/~aschiffler/Software/SDL_gfx-2.0/


int main(int argc, char *argv[]){
    
    int x1,x2,x3,y1,y2,y3,h1=30,h2=15,ir,k=0,ax=0,ay=0,No_disp = 0,Vastx=5,Vasty=5,d,cursory=180,cont_chi=0, ablending=255,ast_med=0,ast_chi=0, contast,contast1 = 0,contast2=0, vert1, vert2, creast_x, creast_y,cont_bala, cont_a=0, puntos=0,vidas=2,cont_med=0;
    int gx[4], gy[4], mx[4], my[4], cx[4], cy[4], balas[30], psx[30], psy[30], vx[30], vy[30], vagx[8], vagy[8];
    char puntaje[10], puntaje_acum[10], vidas1[8],vidas2[3];
    Uint32 t0, t_recuperacion=0;
    Uint32 tbala[30], tasteroide[20], tasteroide_chi[16];
    float m = 0,n = 0,theta=0,alpha=0,velx = 0,vely = 0,beta = 0;
    Sint16 astrgx[8][4], astrgy[8][4], astrmx[16][4], astrmy[16][4], astrcx[32][4], astrcy[32][4];          //habrá a lo más 8 asterides grandes dentro del juego al mismo tiempo
    
    
    	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) == -1){
		fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	atexit(SDL_Quit);

	// Initilize the screen
	SDL_Surface *screen = SDL_SetVideoMode(640, 420, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen == NULL){
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		exit(1);
	}
    
    /*  a continuación tenemos las coordenadas iniciales de los asteroides dependiendo de 
        su tamaño y posteriormente les sumaremos un valores constantes dependiendo del 
        asteroide con respecto a X y Y para que el asteroide no modifique su forma además se usan
        apuntadores para que se facilite la creación de estos y no ocupar tanto espacio           */
        
    gx[0]=0;          //Coordenadas "primarias" en el eje X de un asteroide grande
    gx[1]=100;
    gx[2]=100;
    gx[3]=0;

    gy[0]=0;         //Coordenadas "primarias" en el eje Y de un asteroide grande
    gy[1]=0;
    gy[2]=100;
    gy[3]=100;
    
    mx[0]=0;          //Coordenadas "primarias" en el eje X de un asteroide mediano
    mx[1]=50;
    mx[2]=50;
    mx[3]=0;

    
    my[0]=0;         //Coordenadas "primarias" en el eje Y de un asteroide mediano
    my[1]=0;
    my[2]=100;
    my[3]=100;
    
    cx[0]=0;          //Coordenadas "primarias" en el eje X de un asteroide chico
    cx[1]=50;
    cx[2]=50;
    cx[3]=0;
    
    cy[0]=0;         //Coordenadas "primarias" en el eje Y de un asteroide chico
    cy[1]=0;
    cy[2]=50;
    cy[3]=50;
    
    for (creast_x=0; creast_x < 4; creast_x ++)
        {                                                         //Más abajo se vera que la superficie donde se dibujarán los asteroides es el doble de ancho y largo
        astrgx[0][creast_x] = gx[creast_x] + (screen->w)/2;       //que screen, y que ésta última quedará en el medio de la superficie "astros", por tanto para que al
        astrgy[0][creast_x] = gy[creast_x] - (screen->h)/2;      //momento de blittear las superficies se vea lo que queremos entonces se le agrega la mitad del tamaño
        }                                                         //de screen tanto en el eje X como en el eje Y
    
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[1][creast_x] = gx[creast_x] + 200 + (screen->w)/2;
        astrgy[1][creast_x] = gy[creast_x] - (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[2][creast_x] = gx[creast_x] + 400 + (screen->w)/2;
        astrgy[2][creast_x] = gy[creast_x] - (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[3][creast_x] = gx[creast_x] + 600 + (screen->w)/2;
        astrgy[3][creast_x] = gy[creast_x] - (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[4][creast_x] = gx[creast_x] + 600 + (screen->w)/2;
        astrgy[4][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[5][creast_x] = gx[creast_x] + 500 + (screen->w)/2;
        astrgy[5][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[6][creast_x] = gx[creast_x] + 270 + (screen->w)/2;
        astrgy[6][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
    for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[7][creast_x] = gx[creast_x] +(screen->w)/2;
        astrgy[7][creast_x] = gy[creast_x] + 470 + (screen->h)/2;
        }

    vagx[0]=Vastx;
    vagx[1]=Vastx*(0.8);
    vagx[2]=Vastx*(-0.5);
    vagx[3]=-Vastx*(1.2);
    vagx[4]=Vastx*(-1.1);
    vagx[5]=Vastx*(-0.9);
    vagx[6]=Vastx*(0.7);
    vagx[7]=Vastx*(0.6);
    
    vagy[0]=Vasty*(0.9);
    vagy[1]=Vasty*(0.7);
    vagy[2]=Vasty;
    vagy[3]=Vasty*(0.8);
    vagy[4]=-Vasty*(0.7);
    vagy[5]=-Vasty*(1.1);
    vagy[6]=-Vasty*(0.4);
    vagy[7]=-Vasty*(0.8);
    

    SDL_Surface *estrellas = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,5000,5000,32,0,0,0,0);    //estrellas
    
    SDL_Surface *nave = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,640,420,32,0,0,0,0);           //nave
    
    SDL_Surface *astros = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF, 1280, 840,32,0,0,0,0);         //disparos
    
    	// Ponemos el espacio
	SDL_Surface* image = SDL_LoadBMP("espacio2.bmp");
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
	
	SDL_Surface* menu = SDL_LoadBMP("menu.bmp");                           //cargamos el menú inicial
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
    
    SDL_Surface* nivel1 = SDL_LoadBMP("nivel 1.bmp");                      //cargamos la imagen del primer nivel
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
		
	SDL_Surface* nivel2 = SDL_LoadBMP("nivel 2.bmp");                      //cargamos la imagen del segundo nivel
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
		
	SDL_Surface* nivel3 = SDL_LoadBMP("nivel 3.bmp");                      //cargamos la imagen del tercer nivel
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());
		
	SDL_Surface* nivel4 = SDL_LoadBMP("nivel 4.bmp");                      //cargamos la imagen del cuarto nivel
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());

	SDL_Surface* nivel5 = SDL_LoadBMP("nivel 5.bmp");                      //cargamos la imagen del quinto nivel
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError()); 

	SDL_Surface* cursor = SDL_LoadBMP("seleccion.bmp");                    //cargamos el puntero del menú inicial
	if(image == NULL)
		fprintf(stderr, "Unable to load image: %s\n", SDL_GetError());

	// FRAME RATE MANAGER EXAMPLE
	// Initialize Frame Rate Manager
	FPSmanager fpsm;
	SDL_initFramerate(&fpsm);
	SDL_setFramerate(&fpsm, 60); // 60 Frames Per Second


	bool isRunning = true;
	
	//Ciclo donde se blitea el dibujo del menu sobre la superficie
	bool MENU = true;
	while(MENU){
        
        SDL_FillRect(screen, NULL, 0);
        
        SDL_Rect menu2;
        menu2.x = 400;
        menu2.y=cursory;
        menu2.w=screen->w; 
        menu2.h=screen->h;
        
        SDL_Rect menu1;
        menu1.x=0;
        menu1.y=0;
        menu1.w=screen->w;
        menu1.h=screen->h;
        
        SDL_BlitSurface(menu,&menu1,screen,NULL);
        SDL_BlitSurface(cursor,NULL,screen,&menu2);

        SDL_Flip(screen);
        SDL_framerateDelay(&fpsm);
        
        SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				{MENU = false; 
                isRunning= false;}
				break;
			case SDL_KEYDOWN:                                    
				if(event.key.keysym.sym == SDLK_ESCAPE)
                {
					MENU = false; 
                    isRunning = false; 
                }
				if(event.key.keysym.sym == SDLK_DOWN)            //Movimiento hacia arriba del puntero
				    {
                        if (cursory==180)
                        cursory=280;
                        else
                        cursory=280;
                    }
				if(event.key.keysym.sym == SDLK_UP)              //Movimiento hacia abajo del puntero
				    {
                        if (cursory==280)
                        cursory=180;
                        else
                        cursory=180;
                    }
				if(event.key.keysym.sym == SDLK_a)
				    {
                        if (cursory==280)                                     //si está en la posición de salir se terminan los dos ciclos
                        {                                                     //pero si está en JUGAR se acaba solamente el ciclo de MENU
                            MENU = false; 
                            isRunning = false; 
                        }
                        else
                        MENU = false;
                    }
			break;
            }
        }
    }


    t0=SDL_GetTicks();                                                        //obtendremos los ticks para poder descenter el nivel de alpha-blending de la imagen que nos indica el nivel que se jugará
	while(isRunning){
	 
		// Clear the screen
		SDL_FillRect(screen, NULL, 0);
        SDL_FillRect(estrellas, NULL, 0);
		SDL_FillRect(nave, NULL, 0);
		SDL_FillRect(astros, NULL, 0); 
		
		if (vidas < 0)                   //Este condicional impedirá que se ejecute de nuevo el ciclo si vidas es menor que 0
		isRunning = false;
		
		
		if(ablending>0)             //ablending serán las unidades de alpha que tendrá la imagen Nivel 1
		{
            if (SDL_GetTicks()-t0 > 40)        //Cada 40 ticks transcurridos se reducirán 5 unidades el alpha para volver transparente 
            {                                  //la imagen que nos indica el nivel por empezar
                t0=SDL_GetTicks();
                ablending -=5;
            }
            SDL_SetAlpha(nivel1,SDL_SRCALPHA|SDL_RLEACCEL,ablending); 
        }
       
       else                               //Mientras no se haya terminado de volver transparente la imagen, no saldrán los asteroides
            {
             for (vert1=0; vert1<=contast1; vert1++)                            // Aqui tenemos que se le aumentará la velocidad a la cantidad de asteroides que vayan a
             {                                                                  //   aparecer en ese momento, esto se realiza principalmente para que al estar iniciando el
                 for (vert2=0; vert2<=3; vert2 ++)                              //   nivel aparezcan todos los asteroides en un momento, si no para que su salida sea retrasada
                 {                                                              //   con respecto al anterior
                     astrgx[vert1][vert2] += vagx[vert1] - beta*m;
                     astrgy[vert1][vert2] += vagy[vert1] + beta*n;
                     if (t_recuperacion ==0)                                    //si el tiempo de recuperación es igual a cero, entonces los asteroides le pueden dañar
                     {
                     if ((astrgx[vert1][vert2] - (astros->w)/2)*(astrgx[vert1][vert2] - (astros->w)/2) < (31*31) && (astrgy[vert1][vert2] - (astros->h)/2)*(astrgy[vert1][vert2] - (astros->h)/2) < (31*31))
                     {                                                          //La condición de arriba nos dice que si la distancia del eje X y eje Y de cualquier verticé de un cuadrado es menor que el radio del círculo,
                         vidas--;                                               //   entonces se bajará una vida   
                         t_recuperacion = SDL_GetTicks();}                      //Si es que es atacado por un asteroide, entonces se contará el tiempo, para que sea inmune
                     }
                 }
             } 
            }
            
            if (t_recuperacion != 0)                                            //esta condición se cumplirá solamente si es que chocó un asteroide con el anteriormente
            {
                 if (SDL_GetTicks()- t_recuperacion < 3000)                     // cantidad de "ticks" que tendrá inmunidad la nave
                 filledCircleRGBA(nave, 320, 210, 40, 200,200,200,150);         //" Escudo protector"
                 else
                 t_recuperacion = 0;
            }
            

            for (cont_bala = cont_a; cont_bala >= 0; cont_bala --)
            {
             if (SDL_GetTicks() - tbala[cont_bala] < 3500)        //Dentro de este IF se preguntará si la bala esta activa o no,
             {                                                    //si sigue activa entonces la dibujará y además se preguntará si
             psx[cont_bala] += vx[cont_bala] - beta*m;            //ha impactado a un asteroide :D
             psy[cont_bala] += vy[cont_bala] + beta*n;		
             filledCircleRGBA(astros, psx[cont_bala], psy[cont_bala], 5, 250,0,150,150);
             for (ir = contast1; ir >= 0; ir --)                  //Este ciclo nos indicará que asteroides GRANDES han sido impactados
             {                                                    //La siguiente condición se cumplirá cuando una bala esté entre los ejes Y y X de un asteroide
                 if (((astrgx[ir][0] - psx[cont_bala]) < 0 && (astrgx[ir][2] - psx[cont_bala])>0 ) && ((astrgy[ir][0] - psy[cont_bala])<0 && (astrgy[ir][2] - psy[cont_bala])>0))
                 {
                 for (creast_x = 0; creast_x <=3; creast_x ++)               //Se crean dos asteroides medianos con las coordenadas primarias que les corresponden más
                 {                                                           //las coordenadas del asteroide grande para que aparezcan en el mismo lugar
                 astrmx[2*ast_med][creast_x] = mx[creast_x] + astrgx[ir][0];                 
                 astrmy[2*ast_med][creast_x] = my[creast_x] + astrgy[ir][0];
                 }
                 for (creast_x =0; creast_x <=3; creast_x ++)
                 {
                 astrmx[2*ast_med + 1][creast_x] = mx[creast_x] + astrgx[ir][1];
                 astrmy[2*ast_med + 1][creast_x] = my[creast_x] + astrgy[ir][1];
                 }
                 tasteroide[ast_med]= SDL_GetTicks();                        //Se coloca una medida de tiempo para controlar que tanto tiempo queremos que estén dentro del espacio
                 if (ast_med <=7)
                 ast_med ++;
                 else
                 ast_med = 0; //<------colocar otro contador para que a la hora de sacar nuevos asteroides se impriman todos y no se quiten como sucedio con las balas
                 if (cont_med <=7)
                 cont_med ++;
              
                 astrgx[ir][0]=0;        //Se vuelven sus coordenadas cero para que no vuelva a aparecer después el asteroide impactado
                 astrgx[ir][1]=0;
                 astrgx[ir][2]=0;
                 astrgx[ir][3]=0;
                 
                 astrgy[ir][0]=0;
                 astrgy[ir][1]=0;
                 astrgy[ir][2]=0;
                 astrgy[ir][3]=0;
                 
                 tbala[cont_bala] -=3500;     //Se le restan 3500 al tiempo de la bala para que ya no se genere en el siguiente ciclo
                 puntos +=500;                //Puntos que aumenta por destruir un asteroide grande
                 }
             }
             for (ir = cont_med; ir >= 0; ir --)                  //Este ciclo nos indicará que asteroides MEDIANOS han sido impactados
             {                                                    //La siguiente condición se cumplirá cuando una bala esté entre los ejes Y y X de un asteroide
                 if (((astrmx[2*ir][0] - psx[cont_bala]) < 0 && (astrmx[2*ir][2] - psx[cont_bala])>0 ) && ((astrmy[2*ir][0] - psy[cont_bala])<0 && (astrmy[ir][2] - psy[cont_bala])>0))
                 {
                 for (creast_x = 0; creast_x <=3; creast_x ++)               //Se crean dos asteroides medianos con las coordenadas primarias que les corresponden más
                 {                                                           //las coordenadas del asteroide grande para que aparezcan en el mismo lugar
                 astrcx[2*ast_chi][creast_x] = cx[creast_x] + astrmx[ir][0];                 
                 astrcy[2*ast_chi][creast_x] = cy[creast_x] + astrmy[ir][0];
                 }
                 for (creast_x =0; creast_x <=3; creast_x ++)
                 {
                 astrcx[2*ast_chi + 1][creast_x] = cx[creast_x] + astrmx[ir][1];
                 astrcy[2*ast_chi + 1][creast_x] = cy[creast_x] + astrmy[ir][1];
                 }
                 tasteroide_chi[ast_chi]= SDL_GetTicks();                        //Se coloca una medida de tiempo para controlar que tanto tiempo queremos que estén dentro del espacio
                 if (ast_chi <=14)
                 ast_chi ++;
                 else
                 ast_chi = 0; //<------colocar otro contador para que a la hora de sacar nuevos asteroides se impriman todos y no se quiten como sucedio con las balas
                 if (cont_chi <=14)
                 cont_chi ++;
              
                 astrmx[ir][0]=0;        //Se vuelven sus coordenadas cero para que no vuelva a aparecer después el asteroide impactado
                 astrmx[ir][1]=0;
                 astrmx[ir][2]=0;
                 astrmx[ir][3]=0;
                 
                 astrmy[ir][0]=0;
                 astrmy[ir][1]=0;
                 astrmy[ir][2]=0;
                 astrmy[ir][3]=0;
                 
                 tbala[cont_bala] -=3500;     //Se le restan 3500 al tiempo de la bala para que ya no se genere en el siguiente ciclo
                 puntos +=1000;                //Puntos que aumenta por destruir un asteroide grande
                 }
             }
             
             }
            }
        
        
		// theta será la rotación de la figura
        // alpha es la cantidad de radianes que rotará la figura
		theta=theta+alpha;
		
		/*usamos las funciones trigonometricas para encontrar los valores de los vectores,
        asi multiplicamos la hipotenusa correspondiente con la funcion seno o coseno*/
        m=sin(theta);
        n=cos(theta);
        
        x1=h1*m;
        x2=h2*n;
        x3=-h2*n;
        
        y1=-h1*n;
        y2=h2*m;
        y3=-h2*m;
        
        //cambio de coordenadas
        x1=x1+320;
        x2=x2+320;
        x3=x3+320;
        
        y1=y1+210;
        y2=y2+210;
        y3=y3+210;
		

		// ASTEROIDES
		if ((SDL_GetTicks() - t0) > 1000 )              //cada lapso de 1500 tics se creará un asteroide
  {
           if (contast1 < 7)
           contast1 ++;                      //esta función solo me dice que los imprimira despues de cierto tiempo
           else
           {
                   switch (contast2)         //en este switch lo que se analiza es el valor de contast2 para saber que asteroide debe ser reemplazado
                   {                          
                          case 0:
                               {
                               for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[0][creast_x] = gx[creast_x] + (screen->w)/2;            //sumamos la mitad del valor de screen (que es 320) para que
        astrgy[0][creast_x] = gy[creast_x] - (screen->h)/2;
        }
                                        }
                               break;
                          case 1:
                              { 
                              for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[1][creast_x] = gx[creast_x] + 200 + (screen->w)/2;
        astrgy[1][creast_x] = gy[creast_x] - (screen->h)/2;
        }
}
break;
case 2:
{
         for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[2][creast_x] = gx[creast_x] + 400 + (screen->w)/2;
        astrgy[2][creast_x] = gy[creast_x] - (screen->h)/2;
        }
}
break;
case 3:
{   
        for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[3][creast_x] = gx[creast_x] + 600 + (screen->w)/2;
        astrgy[3][creast_x] = gy[creast_x] - (screen->h)/2;
        }
}
break;
case 4:
{
         for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[4][creast_x] = gx[creast_x] + 600 + (screen->w)/2;
        astrgy[4][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
}
break;   
case 5:
{
         for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[5][creast_x] = gx[creast_x] + 500 + (screen->w)/2;
        astrgy[5][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
}
break;
case 6:
{   
        for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[6][creast_x] = gx[creast_x] + 270 + (screen->w)/2;
        astrgy[6][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
        
}
break;
case 7:
{
         for (creast_x=0; creast_x < 4; creast_x ++)
        {
        astrgx[7][creast_x] = gx[creast_x] + 270 + (screen->w)/2;
        astrgy[7][creast_x] = gy[creast_x] + 640 + (screen->h)/2;
        }
} break;                               
                                   }
                                   if (contast2 < 7)
                                   contast2 ++;
                                   else
                                   contast2=0;
                                   }
           t0=SDL_GetTicks();
  }
  
        puntaje[0]='P';
        puntaje[1]='U';
        puntaje[2]='N';
        puntaje[3]='T';
        puntaje[4]='A';
        puntaje[5]='J';
        puntaje[6]='E';
        stringRGBA( astros, 360, 220, puntaje, 200,200,200,200);                 //se imprime PUNTAJE en astros
        stringRGBA( astros, 450, 220, puntaje_acum, 200,200,200,200);            //se imprime el puntaje obtenido
        sprintf(puntaje_acum, "%d", puntos);
        
        vidas1[0]='V';
        vidas1[1]='I';
        vidas1[2]='D';
        vidas1[3]='A';
        vidas1[4]='S';
        stringRGBA( astros, 850, 220,vidas1, 200,200,200,200);                   //se imprime VIDAS en astros
        stringRGBA( astros, 920, 220,vidas2, 200,200,200,200);                   //se imprime el número de vidas restantes
        sprintf(vidas2, "%d%", vidas);
           
  
        if (cont_med > 0)                                                      //se ejecutará este ciclo si es que algúna bala ha impactado un asteroide grande
        {
        for(contast = 0; contast <= cont_med; contast ++)                     //este ciclo imprimirá los asteroides medianos que haya en la pantalla
         {
         if (SDL_GetTicks() - tasteroide[contast] < 3500)                       //si cumple con esto, entonces se cambiarán sus coordenadas y ademas se dibujará el asteroide mediano
         {
               for(creast_x =0; creast_x <=3; creast_x ++)                    //aqui se cambiarán las coordenadas, pero como se crean 2 asteroides medianos de uno grande entonces se tienen que cambiar las coordenadas de ambos al mismo tiempo
               {
               astrmx[2*contast][creast_x] += vagx[contast]*(-1.2) - beta*m;       
               astrmy[2*contast][creast_x] += vagy[contast]*(1.5) + beta*n;
               astrmx[2*contast + 1][creast_x] += vagx[contast]*(1.7) - beta*m;
               astrmy[2*contast + 1][creast_x] += vagy[contast]*(1.8) + beta*n;
               if (t_recuperacion ==0)                                    //si el tiempo de recuperación es igual a cero, entonces los asteroides le pueden dañar
               {
                     if ((astrmx[2*contast][creast_x] - (astros->w)/2)*(astrmx[2*contast][creast_x] - (astros->w)/2) < (31*31) && (astrmy[2*contast][creast_x] - (astros->h)/2)*(astrmy[2*contast][creast_x] - (astros->h)/2) < (31*31))
                     {                                                          //La condición de arriba nos dice que si la distancia del eje X y eje Y de cualquier verticé de un cuadrado es menor que el radio del círculo,
                         vidas--;                                               //   entonces se bajará una vida   
                         t_recuperacion = SDL_GetTicks();                      //Si es que es atacado por un asteroide, entonces se contará el tiempo, para que sea inmune
                     }
                     if ((astrmx[2*contast + 1][creast_x] - (astros->w)/2)*(astrmx[2*contast + 1][creast_x] - (astros->w)/2) < (31*31) && (astrmy[2*contast + 1][creast_x] - (astros->h)/2)*(astrmy[2*contast + 1][creast_x] - (astros->h)/2) < (31*31))
                     {                                                          //La condición de arriba nos dice que si la distancia del eje X y eje Y de cualquier verticé de un cuadrado es menor que el radio del círculo,
                         vidas--;                                               //   entonces se bajará una vida   
                         t_recuperacion = SDL_GetTicks();                      //Si es que es atacado por un asteroide, entonces se contará el tiempo, para que sea inmune
                     }
               }
         filledPolygonRGBA(astros, astrmx[2*contast], astrmy[2*contast], 4, 250, 150, 100, 90);                 //pobemas por aqui, pues se necesitan cadenas :S   
         filledPolygonRGBA(astros, astrmx[2*contast + 1], astrmy[2*contast + 1], 4, 250, 150, 100, 90);
         } 
		}
        }
        }
        
              if (cont_chi > 0)                                                      //se ejecutará este ciclo si es que algúna bala ha impactado un asteroide grande
        {
        for(contast = 0; contast <= cont_chi; contast ++)                     //este ciclo imprimirá los asteroides medianos que haya en la pantalla
         {
         if (SDL_GetTicks() - tasteroide_chi[contast] < 3500)                       //si cumple con esto, entonces se cambiarán sus coordenadas y ademas se dibujará el asteroide mediano
         {
               for(creast_x =0; creast_x <=3; creast_x ++)                    //aqui se cambiarán las coordenadas, pero como se crean 2 asteroides medianos de uno grande entonces se tienen que cambiar las coordenadas de ambos al mismo tiempo
               {
               astrcx[2*contast][creast_x] += vagx[contast]*(-1.2) - beta*m;       
               astrcy[2*contast][creast_x] += vagy[contast]*(1.5) + beta*n;
               astrcx[2*contast + 1][creast_x] += vagx[contast]*(1.7) - beta*m;
               astrcy[2*contast + 1][creast_x] += vagy[contast]*(1.8) + beta*n;
               if (t_recuperacion ==0)                                    //si el tiempo de recuperación es igual a cero, entonces los asteroides le pueden dañar
               {
                     if ((astrcx[2*contast][creast_x] - (astros->w)/2)*(astrcx[2*contast][creast_x] - (astros->w)/2) < (31*31) && (astrcy[2*contast][creast_x] - (astros->h)/2)*(astrcy[2*contast][creast_x] - (astros->h)/2) < (31*31))
                     {                                                          //La condición de arriba nos dice que si la distancia del eje X y eje Y de cualquier verticé de un cuadrado es menor que el radio del círculo,
                         vidas--;                                               //   entonces se bajará una vida   
                         t_recuperacion = SDL_GetTicks();                      //Si es que es atacado por un asteroide, entonces se contará el tiempo, para que sea inmune
                     }
                     if ((astrcx[2*contast + 1][creast_x] - (astros->w)/2)*(astrcx[2*contast + 1][creast_x] - (astros->w)/2) < (31*31) && (astrcy[2*contast + 1][creast_x] - (astros->h)/2)*(astrcy[2*contast + 1][creast_x] - (astros->h)/2) < (31*31))
                     {                                                          //La condición de arriba nos dice que si la distancia del eje X y eje Y de cualquier verticé de un cuadrado es menor que el radio del círculo,
                         vidas--;                                               //   entonces se bajará una vida   
                         t_recuperacion = SDL_GetTicks();                      //Si es que es atacado por un asteroide, entonces se contará el tiempo, para que sea inmune
                     }
               }
         filledPolygonRGBA(astros, astrmx[2*contast], astrmy[2*contast], 4, 250, 150, 100, 90);                 //pobemas por aqui, pues se necesitan cadenas :S   
         filledPolygonRGBA(astros, astrmx[2*contast + 1], astrmy[2*contast + 1], 4, 250, 150, 100, 90);
         } 
		}
        }
        }
        
        for (contast=0; contast <= contast1; contast++)                       //este ciclo nos imprimirá el número de asteroides grandes que hay en pantalla
		  		filledPolygonRGBA(astros,astrgx[contast],astrgy[contast],4,250,150,100,90);

        filledCircleRGBA(nave, 320,210, 31, 100, 200, 0, 150);
		filledTrigonRGBA(nave,x1,y1,x2,y2,x3,y3,200,0,0,100);   // cañon 
		
		 //rectangulo de "estrellas" que se copiará a "screen"
	   
        SDL_Rect psc1;
        psc1.x=0;
        psc1.y=0;
        psc1.w=640;
        psc1.h=320;

	   //coordenada desde donde "screen" imprimirá el rectangulo para blitear de "estrellas"
        SDL_Rect psc2;
        psc2.x=0;
        psc2.y=0;
        psc2.w=640;
        psc2.h=320;
        
        ax += beta*m;
        ay -=beta*n;
		
		SDL_Rect vnave;
        vnave.x = (image->w)/2 - 320 + ax;
        vnave.y = (image->h)/2 -210 + ay;
        vnave.w= screen->w;
        vnave.h= screen->h;
        
		SDL_Rect pscm1;
	    pscm1.x= 320 + beta*m;
	    pscm1.y= 210 - beta*n;
	    pscm1.w=screen->w;
	    pscm1.h=screen->h;
        
        
		SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format, 0,0,0));
		SDL_SetColorKey(nave,SDL_SRCCOLORKEY,SDL_MapRGB(nave->format, 0,0,0));  //hace transparente el color negro en "estrellas"
		SDL_SetColorKey(estrellas,SDL_SRCCOLORKEY,SDL_MapRGB(estrellas->format, 0,0,0));
		SDL_SetColorKey(astros,SDL_SRCCOLORKEY,SDL_MapRGB(astros->format, 0,0,0));
		
		SDL_BlitSurface(image,NULL,estrellas,NULL);
		SDL_BlitSurface(estrellas,&vnave,screen,&psc2);    
		SDL_BlitSurface(nave,&psc1,screen,&psc2);    
		SDL_BlitSurface(astros,&pscm1,screen,&psc2); 
		SDL_BlitSurface(nivel1,NULL,screen,NULL);     //blitting de la imagen que tiene el nivel que se va a jugar
		
		// Output to the screen
		SDL_Flip(screen);

        

		// FRAME RATE MANAGER EXAMPLE
		// Delay using the frame rate manager
		SDL_framerateDelay(&fpsm);


	 
		// Check if user quits
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE)
					isRunning = false; 
				if(event.key.keysym.sym == SDLK_RIGHT)
				    alpha=0.08;                             //rotación a la derecha
				if(event.key.keysym.sym == SDLK_LEFT)
				    alpha=-0.08;                            //rotación a la izquierda
				if(event.key.keysym.sym == SDLK_UP)
				    beta=3;
				if(event.key.keysym.sym == SDLK_DOWN)
				    beta=-3;
				if(event.key.keysym.sym == SDLK_a)
                  {  
                    tbala[No_disp] = SDL_GetTicks(); 
                    psx[No_disp] = x1 + (screen->w)/2;
                    psy[No_disp] = y1 + (screen->h)/2;
                    vx[No_disp] = 7*m;
                    vy[No_disp] = -7*n;
                    if (No_disp <29)
                    No_disp ++;
                    else
                    No_disp = 0;
                    if (cont_a < 29)
                    cont_a ++;
                    }
                  if(event.key.keysym.sym == SDLK_b)
                  puntos += 500;
                  if(event.key.keysym.sym == SDLK_c)
                  vidas --;
			break;
			case SDL_KEYUP:
                switch(event.key.keysym.sym){
                    case SDLK_RIGHT:
                        if (alpha>0)
                        alpha=0;
                        break;
                    case SDLK_LEFT:
                        if (alpha<0)
                        alpha=0;
                        break;
                    case SDLK_UP:
                        if (beta>0)
                        beta=0;
                        break;
                    case SDLK_DOWN:
                        if (beta<0)
                        beta=0;
                        break;
                    }
            break;
			}
		}
		
	}


	return 0;
}
