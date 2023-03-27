/**
 * @file main.c
 * @brief Testing Program.
 * @author C Team
 * @version 0.1
 * @date Apr 01, 2015
 *
 * Testing program for background scrollilng
 *
 */

#include "header.h"

#include "ES.h"

#include "background.h"

#include "enigmetf.h"

#include "enigmeif.h"


int main(int argc, char * argv[])

{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  TTF_Init();

  SDL_EnableKeyRepeat(100, 0);
  SDL_Surface * screen = NULL;
  int gamemode = 1;
  int count = 1;
  int i = 0;

  int meilleurscore;
  char meilleurnom[20];

  int volume = 100;
  bool IsFullscreen = false; // fullscreen or not

  image start, settings, exit, music, gamelogo, score;
  image tabimg[4];
  SDL_Event event;

  int position = 1, settingsverif = 0, playverif = 0, musicverif = 1, scoreverif = 0;

  // load music
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
  }
  Mix_Music * musique = Mix_LoadMUS("1x/musique.mp3");
  Mix_Chunk * chunk = Mix_LoadWAV("1x/CLIC.wav");
  Mix_Chunk * attack = Mix_LoadWAV("1x/sword.wav");

  system("stty -F /dev/ttyUSB0 9600 -parenb cs8 -cstopb");
  char receivedarduino;
  int collisionRightSide = 0;
  int collisionLeftSide = 0;

  //////////////////////////////////////IA

  tic t;
  int coup;
  int joueur;
  initialisation( & t);
  int buttona, buttonb;
  int IA = 0;

  SDL_Surface * win = NULL;

  /////////////////////ES///////////////
  int done = 1;

  PickUp coin;
  // perso p;
  Ennemi e;

  initEnnemi( & e);
  initCoin( & coin);
  // initialiser_perso(&p);
  int scrollingenemie;

  ////////////////////////////////////////BG
  int colpp;
  mouvement M;
  background b;

  init_Mouvement( & M); // appel fonction initialisation des deplacement
  initBack( & b);

  SDL_Surface * brig = IMG_Load("islembackground/birds.png");
  SDL_Rect pos_b, drawbriq = {
    pos_b.x - b.camera.x,
    pos_b.y - b.camera.y,
    pos_b.h - b.camera.h,
    pos_b.w - b.camera.w
  };

  pos_b.x = 90;
  pos_b.y = 50;
  SDL_Surface * sun[2];

  SDL_Rect pos_s;

  pos_s.x = 600;
  pos_s.y = 200;

  int o = 0;
  SDL_Surface * mask;
  SDL_Color Color = {
    255,
    255,
    255
  };
  mask = IMG_Load("backg/masklvl1.png");
  ///////////////////////////////////////

  // ME TESTING WITH BACKGROUND WHEN ANIMATION NEED TO FOLLOW THE BACKGROUND AND COLLISON NEED TO DETECT IT IN THE RIGHT PLACE
  /*

  SDL_Rect drawcoin={coin.pos.x-b.camera.x,coin.pos.y-b.camera.y,coin.pos.h-b.camera.h,coin.pos.w-b.camera.w};
  SDL_Rect drawennemie={e.pos.x-b.camera.x,e.pos.y-b.camera.y,e.pos.h-b.camera.h,e.pos.w-b.camera.w};

  */

  ////////////////////////////////////////ENIGME AZIZ/////////////////////////////
  int enigmetext = 0;
  int scoreenigme = 0;

  char * nomenigmet[600];

  enigmetf enitxt;

  InitEnigme( & enitxt, & nomenigmet[600]);

  /////////////////////////////////////////////ENIGME OUSSAMA/////////////////////////////////////////

  int enigmeimage = 0;

  char nomfichier[100];

  enigmeif ee; //problem
  ee.d = 1;
  genererimage( & ee);

  InitEnigmeimage( & ee, & nomfichier[100]);

  ///////////////////////////////////////////////////////////////////

  screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE); // so it doesnt start with resizale version but the one that is menu hightweight line 201 the resizable one

  TTF_Font * font = TTF_OpenFont("ARIAL.ttf", 80);
  SDL_Color color = {
    255,
    0,
    0
  };

  // bonus
  SDL_WM_SetCaption(" Test menu", NULL);

  // text 2
  TTF_Font * font1 = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 30);
  SDL_Surface * message1 = TTF_RenderText_Solid(font1, "Press p", color);
  SDL_Rect Message_rect1;
  Message_rect1.x = 1350;
  Message_rect1.y = 180;

  // nomaff
  SDL_Surface * messagescore;
  SDL_Rect message02;
  message02.x = 400;
  message02.y = 400;
  TTF_Font * font3 = TTF_OpenFont("SF_TransRobotics_Bold.ttf", 50);

  // scoreaff
  SDL_Surface * messagemeilleur;
  SDL_Rect message01;
  message01.x = 600;
  message01.y = 400;

  // perso init//////////////////////////////////////////////////////////////////////

  int standing, keypressed = 0;
  personne perso, perso2;
  TTF_Init();
  // SDL_Rect drawperso={perso.pos_hero.x-b.camera.x,perso.pos_hero.y-b.camera.y,perso.pos_hero.w-b.camera.w,perso.pos_hero.h-b.camera.h};
  //  fps variable
  Uint32 startt;
  int FPS = 13;

  // INIT SCREEN :
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("TestMenuProjetCadence", NULL);

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Unable to initialize SDL :%s \n", SDL_GetError());
    return 1;
  }

  screen = SDL_SetVideoMode(1500, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
  if (screen == NULL) {
    printf("unable to set video mode:%s\n", SDL_GetError());
    return 1;
  }

  initPerso( & perso);
  // backg = IMG_Load("bg.png");

  // SDL_EnableKeyRepeat(0,500);

  // minimap init
  SDL_Rect camera; /// minimap camerabonhome

  minimap minibackg;
  unsigned int timee = 0;
  char temps[4];
  char temps1[4];
  image A;
  // text

  // sprintf (temps,"%d",time);
  SDL_Surface * message2; // temp postion second
  SDL_Rect Message;
  Message.x = 1640;
  Message.y = 20;
  SDL_Surface * message3; /// temp postion minute
  SDL_Rect Messagem;
  Messagem.x = 1600;
  Messagem.y = 20;

  SDL_Surface * messagenom;
  SDL_Rect Messagen;
  Messagen.x = 800;
  Messagen.y = 500;

  initminimap( & minibackg, & perso);

  A.img = IMG_Load("fond.png");
  if (A.img == NULL) {
    printf("Unable to load : %s\n", SDL_GetError());
    return 0;
  }

  char ch[10];
  A.pos.x = 0;
  A.pos.y = 0;
  int sec = 0;
  int min = 0;
  char nom[20];

  strcpy(nom, "");

  int verif = 0;
  // initialisation
  // initBackground(&backg);
  initButtons( & start, & settings, & exit, & music, & score, & gamelogo);
  initanimation(tabimg);
  Mix_PlayMusic(musique, -1);

  // SDL_putenv("SDL_VIDEODRIVER=directx");
  while (1) {

    if (gamemode == 1) {
      i++;
      SDL_Delay(10);
      if (i == 4)
        i = 0;

      afficher(tabimg[i], screen);
      afficher(start, screen);
      afficher(settings, screen);
      afficher(exit, screen);
      afficher(music, screen);
      afficher(gamelogo, screen);
      afficher(score, screen);

      if ((playverif == 0) && (settingsverif == 0) && (scoreverif == 0)) {
        SDL_BlitSurface(message1, NULL, screen, & Message_rect1); // message press p
      }

      SDL_Flip(screen);

      while (SDL_PollEvent( & event)) {
        switch (event.type) {
        case SDL_QUIT: {

          SDL_FreeSurface(screen);
          libereranimation(tabimg);
          libererButtons(start, settings, exit, music, score, gamelogo);
          closeEverything();
          return 0;

          break;
        }
        case SDL_MOUSEMOTION: {
          int x = 0, y = 0;

          // Get the mouse offsets
          SDL_GetMouseState( & x, & y);

          // If the mouse is over the button
          if ((playverif == 0) && (settingsverif == 0) && (scoreverif == 0)) {

            if ((x > start.pos.x) && (y > start.pos.y) && (x < (start.pos.x + 220)) && (y < (start.pos.y + 62))) {
              position = 1;
              afficherparposition(position, & start, & settings, & score, & exit);
            }
            if ((x > settings.pos.x) && (y > settings.pos.y) && (x < (settings.pos.x + 220)) && (y < (settings.pos.y + 62))) {
              position = 2;
              afficherparposition(position, & start, & settings, & score, & exit);
            }
            if ((x > score.pos.x) && (y > score.pos.y) && (x < (score.pos.x + 220)) && (y < (score.pos.y + 62))) {
              position = 3;
              afficherparposition(position, & start, & settings, & score, & exit);
            }

            if ((x > exit.pos.x) && (y > exit.pos.y) && (x < (exit.pos.x + 220)) && (y < (exit.pos.y + 62))) {
              position = 4;
              afficherparposition(position, & start, & settings, & score, & exit);
            }
          }
          break;
        }

        case SDL_KEYDOWN: {
          switch (event.key.keysym.sym) {
          case SDLK_f:

            count++;
            if (count % 2 == 1) {
              IsFullscreen = false;
            } else {
              IsFullscreen = true;
            }

            if (IsFullscreen == true) {
              screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
            } else {
              screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
            }

            break;

            //////////deactivate sound with p/////////////
          case SDLK_p:

            if (!Mix_PlayingMusic()) {
              Mix_PlayMusic(musique, -1);
              music.img = IMG_Load("1x/Musicon.png");
              musicverif = 1;
            } else if (Mix_PausedMusic()) {
              Mix_ResumeMusic();
              music.img = IMG_Load("1x/Musicon.png");
              musicverif = 1;
            } else {
              Mix_PauseMusic();
              music.img = IMG_Load("1x/Musicoff.png");
              musicverif = 0;
            }

            break;

            ///////////////up and down moving in settings ///////////////

          case SDLK_UP:

            if ((playverif == 0) && (settingsverif == 0) && (scoreverif == 0)) {
              position--;
              if (position == 0) {
                position = 4;
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 3) {
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 2) {
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 1) {
                afficherparposition(position, & start, & settings, & score, & exit);
              }
            }

            break;
          case SDLK_DOWN:

            if ((playverif == 0) && (settingsverif == 0) && (scoreverif == 0)) {
              position++;
              if (position == 5) {
                position = 1;
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 2) {
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 3) {
                afficherparposition(position, & start, & settings, & score, & exit);
              } else if (position == 4) {
                afficherparposition(position, & start, & settings, & score, & exit);
              }
            }
            break;

            /////when clicking in enter for menu after moving with keys exemple//////

          case SDLK_RETURN:
            if (position == 1) {
              Mix_PlayChannel(-1, chunk, 0);
              playverif = 1;
              playverif = paintOptionsScreenagent(screen, & event, chunk, & gamemode); //choose  multiple player de actiavted
              //gamemode = 2; // if bring back playverif this will be gone
              if (gamemode == 3) {

                initBackpartage( & b);
                initPerso( & perso);
                initPerso2( & perso2);
              }
              if (gamemode == 2) {
                initBack( & b);
                initPerso( & perso);

              }

            } else if (position == 2) {
              Mix_PlayChannel(-1, chunk, 0);
              settingsverif = 1;
              settingsverif = paintOptionsScreen(screen, & event, chunk, & volume);
            } else if (position == 3) {
              Mix_PlayChannel(-1, chunk, 0);
              scoreverif = 1;
              meilleur("score.txt", & meilleurscore, meilleurnom);
            } else if (position == 4) {
              Mix_PlayChannel(-1, chunk, 0);
              SDL_FreeSurface(screen);
              libereranimation(tabimg);
              libererButtons(start, settings, exit, music, score, gamelogo);
              closeEverything();
              return 0;
            }
            break;

            ////return to previous screen                                                             //////////////////

          case SDLK_ESCAPE:
            if (playverif == 1) {
              playverif = 0;

              // backg.img = IMG_Load("1x/img.jpg");
              start.img = IMG_Load("1x/Play.png");
              settings.img = IMG_Load("1x/nsettings.png");
              exit.img = IMG_Load("1x/nquit.png");
              if (musicverif == 1)
                music.img = IMG_Load("1x/Musicon.png");
              else
                music.img = IMG_Load("1x/Musicoff.png");
            } else if (settingsverif == 1) {
              settingsverif = 0;
              start.img = IMG_Load("1x/nplay.png");
              settings.img = IMG_Load("1x/Settings.png");
              exit.img = IMG_Load("1x/nquit.png");
              if (musicverif == 1)
                music.img = IMG_Load("1x/Musicon.png");
              else
                music.img = IMG_Load("1x/Musicoff.png");
            } else if (scoreverif == 1) {

              scoreverif = 0;
              start.img = IMG_Load("1x/nplay.png");
              settings.img = IMG_Load("1x/nsettings.png");
              score.img = IMG_Load("1x/Credit.png");
              exit.img = IMG_Load("1x/nquit.png");
              if (musicverif == 1)
                music.img = IMG_Load("1x/Musicon.png");
              else
                music.img = IMG_Load("1x/Musicoff.png");
            } else {
              SDL_FreeSurface(screen);
              libereranimation(tabimg);
              libererButtons(start, settings, exit, music, score, gamelogo);
              closeEverything();
              return 0;
            }
            break;
          }

          break;
        }

        case SDL_MOUSEBUTTONDOWN: {
          int x = 0, y = 0;
          // Get the mouse offsets
          SDL_GetMouseState( & x, & y);
          if ((playverif == 0) && (settingsverif == 0)) {
            if ((position == 1) && (x > start.pos.x) && (y > start.pos.y) && (x < (start.pos.x + 220)) && (y < (start.pos.y + 62))) {
              Mix_PlayChannel(-1, chunk, 0);
              playverif = 1;

              // multi player option or not
              playverif = paintOptionsScreenagent(screen, & event, chunk, & gamemode);

              if (gamemode == 3) {

                initBackpartage( & b);
                initPerso( & perso);
                initPerso2( & perso2);

              }
              if (gamemode == 2) {
                initBack( & b);
                initPerso( & perso);

              }
              //gamemode = 2; // start game for now till we have multiplayer requirement
            } else if ((position == 2) && (x > settings.pos.x) && (y > settings.pos.y) && (x < (settings.pos.x + 220)) && (y < (settings.pos.y + 62))) {
              Mix_PlayChannel(-1, chunk, 0);
              settingsverif = 1;
              settingsverif = paintOptionsScreen(screen, & event, chunk, & volume);
            } else if ((x > score.pos.x) && (y > score.pos.y) && (x < (score.pos.x + 220)) && (y < (score.pos.y + 62))) {
              Mix_PlayChannel(-1, chunk, 0);
              scoreverif = 1;
              meilleur("score.txt", & meilleurscore, meilleurnom);
              scoreverif = rollscore(screen, & event, meilleurnom, meilleurscore); /// show score
            } else if ((position == 4) && (x > exit.pos.x) && (y > exit.pos.y) && (x < (exit.pos.x + 220)) && (y < (exit.pos.y + 62))) {
              Mix_PlayChannel(-1, chunk, 0);
              SDL_FreeSurface(screen);
              libereranimation(tabimg);
              libererButtons(start, settings, exit, music, score, gamelogo);
              closeEverything();
              return 0;
            }
          }
          break;
        }
        }
      }
    }

    // gamemode        start
    if (gamemode == 2) { // write name for score
      if (verif == 0) {
        SDL_BlitSurface(A.img, NULL, screen, & A.pos);
        ajouternom(screen, nom, event);
        messagenom = TTF_RenderText_Solid(font, nom, color);
        SDL_BlitSurface(messagenom, NULL, screen, & Messagen);

        SDL_Flip(screen);
      }

      while (SDL_PollEvent( & event)) {
        switch (event.type) {
        case SDL_QUIT:
          return 0;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
          case SDLK_RETURN:
            verif = 1;
            timee = 0;
            sauvgarder(perso.score, nom, "score.txt", perso); /// scorepage
            break;
          }

          break;
        }
      }

      if (verif == 1) {
        // jeu
        screen = SDL_SetVideoMode(1800, SCREEN_H, 32, SDL_HWSURFACE);
        ////////////AFFICHE TEMP
        timee = SDL_GetTicks();
        min = (timee / 60000);
        sec = (timee / 1000) - 60 * min;

        if (min < 10) {
          sprintf(temps1, "0%d:", min);
        } else {
          sprintf(temps1, "%d:", min);
        }

        if (sec < 10) {
          sprintf(temps, "0%d", sec);
        } else {
          sprintf(temps, "%d ", sec);
        }

        message2 = TTF_RenderText_Solid(font1, temps, color);
        message3 = TTF_RenderText_Solid(font1, temps1, color);
        /////////////////////////////////BG AND MINIMAP ////////////////////////////////////
        initminimap( & minibackg, & perso);

        afficherBack(screen, & b);

        afficherminimap(minibackg, screen);

        SDL_BlitSurface(brig, NULL, screen, & drawbriq);

        drawbriq.x += 150;

        if (pos_b.x > 10000) {
          pos_b.x = 0;
        }

        o++;

        if (o == 2) {
          o = 0;
        }

        SDL_BlitSurface(message2, NULL, screen, & Message);
        SDL_BlitSurface(message3, NULL, screen, & Messagem);

        keypressed = 0;
        /*M.left = 0;
				M.down = 0;
				M.up = 0;*/
        scrollingenemie = 0;
        init_Mouvement( & M);
        // quitter

        while (SDL_PollEvent( & event)) {
          switch (event.type) {
          case SDL_QUIT:
            return 0;
            break;

          case SDL_KEYDOWN:

            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              gamemode = 1;
              break;
            }

            /*if (event.key.keysym.sym == SDLK_ESCAPE)
            {
            	gamemode = 1;
            }*/

            break;
          }

        }

        ///*************************************************************************************************************************************************************///

        //arduinoReadData(&receivedarduino);

        if (receivedarduino == 1) {

          perso.state = walking;

          scrollingenemie = 1;

          perso.direction = 0;
          deplacerPerso( & perso);
          M.right = 1;

        }

        if (receivedarduino == 2) {
          perso.direction = 1;
          perso.state = walking;
          scrollingenemie = 1;
          deplacerPerso( & perso);
          M.left = 1;

        }

        // if we pressed a key= no idle spirit loaded

        switch (perso.direction) {
        case 0:
          if (collisionPP_droite(perso.pos_hero, mask, b.camera) == 0) {
            scrollingright( & b, screen, M, 10, colpp);

          }
          break;

        case 1:
          if (collisionPP_gauche(perso.pos_hero, mask, b.camera) == 0) {
            scrollingleft( & b, screen, M, 10, colpp);

          }
          break;
        }

        if (perso.up == 0 && collisionPP_down(perso.pos_hero, mask, b.camera) == 0) {
          // p.vitesse_saut+=15;
          perso.ground += 20;

        }

        if (collisionPP_down(perso.pos_hero, mask, b.camera) == 1) {
          perso.ground = perso.pos_hero.y;
          //perso.state = jumping;

          //  printf("co\n");
        }
        //pulltrigger(&perso);

        perso.pos_hero.y = perso.pos_hero.y + perso.vitesse_saut;
        perso.vitesse_saut = perso.vitesse_saut + 10;
        if (perso.pos_hero.y >= perso.ground) {
          perso.pos_hero.y = perso.ground;
          perso.jump_count = 0;
          perso.vitesse_saut = 0;
          perso.up = 0;
          srand(time(NULL));
          standing = (rand() % (3));
          randomizer( & perso, standing);
        }

        if (collisionPP_hole(perso.pos_hero, mask, b.camera) == 1) {

          perso.state = hit;
          perso.health -= 10;
          perso.score -= 20;

          /*if(enigmeimage == 0)
          {

          					enigmeimage = 1;

          }*/
          /*
          if( IA==0)
          {

           IA=1;


          }*/

        }

        if (collisionPP_white(perso.pos_hero, mask, b.camera) == 1) {

          perso.score++;

        }

        if (collisionPP_end(perso.pos_hero, mask, b.camera) == 1) {

          SDL_BlitSurface(win, NULL, screen, NULL);
        }

        if (!keypressed) {
          if (perso.state != jumping && perso.state != doublejumping && perso.state != die && perso.state != crouch && perso.pos_hero.y == perso.ground) {
            srand(time(NULL));
            standing = (rand() % (3));
            randomizer( & perso, standing);
          }

        }

        const Uint8 * key = SDL_GetKeyState(NULL); // Gets a snapshot of the current keyboard state

        if (!perso.death) // if the person is not dead
        {

          if (key[SDLK_UP]) // jumping key
          {
            sautt( & perso);

            //perso.state = jumping;
            if ((perso.jump_count >= 0 && perso.jump_count <= 1) && (perso.pos_hero.y <= perso.ground && perso.pos_hero.y >= (perso.ground - 100))) {
              perso.jump_count++;
              saut( & perso);

            }
            M.up = 1;

          }
          // if the person jumped and got down again
          if (perso.jump_count >= 2 && perso.pos_hero.y == perso.ground)
            perso.jump_count = 0;
          // if the person jumped once
          if (perso.pos_hero.y < perso.ground && perso.pos_hero.y >= (perso.ground - 100)) {
            perso.state = jumping;
          }
          // if the person jumped twice
          else if (perso.pos_hero.y < (perso.ground - 100) && perso.pos_hero.y >= (perso.ground - 300)) {
            perso.state = doublejumping;
          }
          if (key[SDLK_RIGHT]) // moving right key
          {
            keypressed = 1;
            if (perso.state != doublejumping && perso.state != doublejumping)

              perso.state = walking;
            perso.direction = 0;
            scrollingenemie = 1;

            deplacerPerso( & perso);
            M.right = 1;

          }
          if (key[SDLK_LEFT]) // moving left key
          {

            keypressed = 1;
            if (perso.state != jumping && perso.state != doublejumping)

              perso.state = walking;
            perso.direction = 1;
            scrollingenemie = 1;
            deplacerPerso( & perso);
            M.left = 1;

          }
          if (key[SDLK_m]) // partage init
          {
            if (perso.acceleration < 20)
              perso.acceleration += 5;

          } else {
            while (perso.acceleration != 0) {
              perso.acceleration -= 20;
            }
          }
          if (key[SDLK_DOWN]) // crouching key
          {
            if (perso.frame_c == 1)
              perso.frame_c = 0;
            perso.state = crouch;
            M.down = 1;

          }
          if (key[SDLK_SPACE]) // attacking key
          {
            Mix_PlayChannel(-1, attack, 0);

            e.col = 1;
            perso.state = attacking;
            if (perso.direction == 0)
              perso.pos_hero.x += 2;
            else if (perso.direction == 1)
              perso.pos_hero.x -= 2;
          }

          if (key[SDLK_h]) // hit key (test)
          {
            perso.state = hit;
            perso.health -= 10;
            perso.score -= 20;
          }

        }

        // if the hero died
        if (key[SDLK_n]) // death key (test)
        {
          perso.state = die;
          perso.death = 1;
          perso.health = 0;
          sauvgarder(perso.score, nom, "score.txt", perso);
        }

        ///*************************************************************************************************************************************************************///

        //////////////////////////// appele fonction scrolling //////////////////////////
        scrollingright( & b, screen, M, 10, colpp);
        scrollingleft( & b, screen, M, 10, colpp);
        scrollingup( & b, screen, M, 4, colpp);

        scrollingdown( & b, screen, M, 4, colpp);

        if (scrollingenemie == 1) {
          scrolling_enemie( & e, perso.direction, 10);

          scrolling_coin( & coin, perso.direction, 10);

        }
        /////////////////////////////////////////////////////////////////////////

        // main fonctions
        //pulltrigger(&perso);
        minibackg.pos_joueur = MAJMinimap(perso.pos_hero, 4, b.camera);
        animerPerso( & perso);
        afficherPerso(perso, screen, b.positionbackground);

        afficherscorevie(perso, screen);
        //////////////////////////////////////////////////////////////////////////////////////////////ES////////////////////////////////////////

        afficherEnnemi(e, screen, b.camera);
        // animerEnnemi(&e);
        updateEnnemiState( & e, perso.pos_hero.x, e.col);
        deplacerIA( & e, perso.pos_hero);
        afficherCoin(coin, screen, b.camera);
        animerCoin( & coin);

        if (collisionRightSide == 1) {
          // printf("\n COLLISION RIGHT SENDING 1 TO SERIAL");
          arduinoWriteData(1);

        } else if (collisionLeftSide == 1) {
          //    printf("\n COLLISION LEFT SENDING 2 TO SERIAL");
          arduinoWriteData(2);

        } else {
          //  printf("\n NO COLLISION SENDING 0 TO SERIAL");
          arduinoWriteData(0);
        }

        if ((collisionBB(perso.pos_hero, e.pos) == 1) && (e.col == 0)) /// perso principale get hit  by ennemie
        {

          perso.state = hit;
          perso.health -= 10;
          perso.score -= 20;
        }

        if ((collisionBB(perso.pos_hero, e.pos) == 1) && (e.col == 1)) /// hitting ennemie
        {

          if (e.death == 0) {
            perso.score += 100;
          }
          e.death = 1; // ennemie dead

          e.animation.spriteSheet[0] = NULL;
          e.animation.spriteSheet[1] = NULL;
          e.animation.spriteSheet[2] = NULL;
          e.animation.spriteSheet[3] = NULL;
          e.animation.spriteSheet[4] = NULL;
        }

        if (collisionBB(perso.pos_hero, coin.pos) == 1) // when there collision image null
        {

          collisionLeftSide = 1;
          coin.animation.spriteSheet[0] = NULL;
          if (coin.col == 0) {
            perso.score += 100;
          }
          coin.col = 1;

          if (enigmetext == 0) {

            enigmetext = 1;

          }

        } else

        {

          collisionLeftSide = 0;
        }

        if (collisionBB(perso.pos_hero, pos_s) == 1) // when there collision with sunn
        {

          collisionRightSide = 1;

          if (enigmeimage == 0) {

            enigmeimage = 1;

          }
          /*
          if( IA==0)
          {

           IA=1;


          }
          */

        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        SDL_Flip(screen);

        // if the person is dead (dead permanently)

        if (perso.health <= 0)
          perso.death = 1;
        if (perso.death == 1) {
          perso.state = die;

          sauvgarder(perso.score, nom, "score.txt", perso);
        }
      }

      //#########################################################################################################################################################################################///
      /*
      if( IA==1)
      {

      affichage(t,screen); 

      if( t.tour<9 &&atilganer(t.tabsuivi)==0)
      {if((t.tour+joueur)%2==0)//tour du PC
                  {calcul_coup(t.tabsuivi);
       t.tour++;}
              else
              {
              SDL_WaitEvent(&event);
              switch(event.type)
              {
              case SDL_QUIT:
      IA=-1;
                  break;
              case SDL_MOUSEBUTTONUP:
                  buttona=event.button.x/190;
                  buttonb=event.button.y/190;
                  coup=3*buttonb+buttona;
                  t.tour++;
                  break;
              }

          t.tabsuivi[coup]=-1;
      }

      }
      else
      { Resultat(t,screen);
      IA=-1;
      printf("%d", t.tour);
      }


      }*/

      if (enigmetext == 1)

      {

        afficherEnigme(enitxt, screen);

        while (SDL_PollEvent( & event)) {

          switch (event.type) {
          case SDL_QUIT: {

            enigmetext = -1;
            break;

          }

          case SDL_MOUSEBUTTONDOWN: {
            if ((event.motion.x > 375 && event.motion.x < 615) && (event.motion.y > 520 && event.motion.y < 610)) {
              enitxt.pos_selected = 1;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            } else if ((event.motion.x > 178 && event.motion.x < 411) && (event.motion.y > 649 && event.motion.y < 734)) {
              enitxt.pos_selected = 2;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            } else if ((event.motion.x > 568 && event.motion.x < 800) && (event.motion.y > 656 && event.motion.y < 731)) {
              enitxt.pos_selected = 3;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            }
          }
          break;
          }
        }

      }

      if (enigmeimage == 1) {

        afficherEnigmeimage( & ee, screen);

        perso.score += ee.score;
        enigmeimage = -1;

      }

      //#########################################################################################################################################################################################///

    }

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    if (gamemode == 3) { // write name for score
      if (verif == 0) {
        SDL_BlitSurface(A.img, NULL, screen, & A.pos);
        ajouternom(screen, nom, event);
        messagenom = TTF_RenderText_Solid(font, nom, color);
        SDL_BlitSurface(messagenom, NULL, screen, & Messagen);

        SDL_Flip(screen);
      }

      while (SDL_PollEvent( & event)) {
        switch (event.type) {
        case SDL_QUIT:
          return 0;
          break;

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
          case SDLK_RETURN:
            verif = 1;
            timee = 0;
            sauvgarder(perso.score, nom, "score.txt", perso); /// scorepage
            break;
          }

          break;
        }
      }

      if (verif == 1) {
        // jeu
        screen = SDL_SetVideoMode(1800, SCREEN_H, 32, SDL_HWSURFACE);
        ////////////AFFICHE TEMP
        timee = SDL_GetTicks();
        min = (timee / 60000);
        sec = (timee / 1000) - 60 * min;

        if (min < 10) {
          sprintf(temps1, "0%d:", min);
        } else {
          sprintf(temps1, "%d:", min);
        }

        if (sec < 10) {
          sprintf(temps, "0%d", sec);
        } else {
          sprintf(temps, "%d ", sec);
        }

        message2 = TTF_RenderText_Solid(font1, temps, color);
        message3 = TTF_RenderText_Solid(font1, temps1, color);
        /////////////////////////////////BG AND MINIMAP ////////////////////////////////////
        initminimap( & minibackg, & perso);

        afficherBack(screen, & b);

        SDL_BlitSurface(brig, NULL, screen, & drawbriq);

        drawbriq.x += 150;

        if (pos_b.x > 10000) {
          pos_b.x = 0;
        }

        keypressed = 0;
        /*M.left = 0;
				M.down = 0;
				M.up = 0;*/
        scrollingenemie = 0;
        init_Mouvement( & M);
        // quitter

        while (SDL_PollEvent( & event)) {
          switch (event.type) {
          case SDL_QUIT:
            return 0;
            break;

          case SDL_KEYDOWN:

            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
              gamemode = 1;
              break;
            }

            /*if (event.key.keysym.sym == SDLK_ESCAPE)
            {
            	gamemode = 1;
            }*/

            break;
          }

        }

        ///*************************************************************************************************************************************************************///

        if (receivedarduino == 1) {
          perso.state = walking;

          scrollingenemie = 1;

          perso.direction = 0;
          deplacerPerso( & perso);
          M.right = 1;

        }

        if (receivedarduino == 2) {
          perso.direction = 1;
          perso.state = walking;
          scrollingenemie = 1;
          deplacerPerso( & perso);
          M.left = 1;

        }

        // if we pressed a key= no idle spirit loaded

        switch (perso.direction) {
        case 0:
          if (collisionPP_droite(perso.pos_hero, mask, b.camera) == 0) {
            scrollingright( & b, screen, M, 10, colpp);

          }
          break;

        case 1:
          if (collisionPP_gauche(perso.pos_hero, mask, b.camera) == 0) {
            scrollingleft( & b, screen, M, 10, colpp);

          }
          break;
        }

        if (perso.up == 0 && collisionPP_down(perso.pos_hero, mask, b.camera) == 0) {
          // p.vitesse_saut+=15;
          perso.ground += 20;

        }

        if (collisionPP_down(perso.pos_hero, mask, b.camera) == 1) {
          perso.ground = perso.pos_hero.y;
          //perso.state = jumping;

          //  printf("co\n");
        }
        //pulltrigger(&perso);

        perso.pos_hero.y = perso.pos_hero.y + perso.vitesse_saut;
        perso.vitesse_saut = perso.vitesse_saut + 10;
        if (perso.pos_hero.y >= perso.ground) {
          perso.pos_hero.y = perso.ground;
          perso.jump_count = 0;
          perso.vitesse_saut = 0;
          perso.up = 0;
          srand(time(NULL));
          standing = (rand() % (3));
          randomizer( & perso, standing);
        }

        perso2.pos_hero.y = perso2.pos_hero.y + perso2.vitesse_saut;
        perso2.vitesse_saut = perso2.vitesse_saut + 10;
        if (perso2.pos_hero.y >= perso2.ground) {
          perso2.pos_hero.y = perso2.ground;
          perso2.jump_count = 0;
          perso2.vitesse_saut = 0;
          perso2.up = 0;
          srand(time(NULL));
          standing = (rand() % (3));
          randomizer( & perso2, standing);
        }

        if (collisionPP_hole(perso.pos_hero, mask, b.camera) == 1) {
          if (enigmeimage == 0) {

            enigmeimage = 1;

          }
          /*
          if( IA==0)
          {

           IA=1;


          }*/

        }

        if (collisionPP_white(perso.pos_hero, mask, b.camera) == 1) {

          perso.score++;

        }

        if (!keypressed) {
          if (perso.state != jumping && perso.state != doublejumping && perso.state != die && perso.state != crouch && perso.pos_hero.y == perso.ground) {
            srand(time(NULL));
            standing = (rand() % (3));
            randomizer( & perso, standing);
          }

          if (perso2.state != jumping && perso2.state != doublejumping && perso2.state != die && perso2.state != crouch && perso2.pos_hero.y == perso2.ground) {
            srand(time(NULL));
            standing = (rand() % (3));
            randomizer( & perso2, standing);
          }

        }

        const Uint8 * key = SDL_GetKeyState(NULL); // Gets a snapshot of the current keyboard state

        if (!perso.death) // if the person is not dead
        {

          if (key[SDLK_UP]) // jumping key
          {
            sautt( & perso);

            //perso.state = jumping;
            if ((perso.jump_count >= 0 && perso.jump_count <= 1) && (perso.pos_hero.y <= perso.ground && perso.pos_hero.y >= (perso.ground - 100))) {
              perso.jump_count++;
              saut( & perso);

            }
            M.up = 1;

          }
          // if the person jumped and got down again
          if (perso.jump_count >= 2 && perso.pos_hero.y == perso.ground)
            perso.jump_count = 0;
          // if the person jumped once
          if (perso.pos_hero.y < perso.ground && perso.pos_hero.y >= (perso.ground - 100)) {
            perso.state = jumping;
          }
          // if the person jumped twice
          else if (perso.pos_hero.y < (perso.ground - 100) && perso.pos_hero.y >= (perso.ground - 300)) {
            perso.state = doublejumping;
          }
          if (key[SDLK_RIGHT]) // moving right key
          {
            keypressed = 1;
            if (perso.state != doublejumping && perso.state != doublejumping)

              perso.state = walking;
            perso.direction = 0;
            scrollingenemie = 1;

            deplacerPerso( & perso);
            M.right = 1;

          }
          if (key[SDLK_LEFT]) // moving left key
          {

            keypressed = 1;
            if (perso.state != jumping && perso.state != doublejumping)

              perso.state = walking;
            perso.direction = 1;
            scrollingenemie = 1;
            deplacerPerso( & perso);
            M.left = 1;

          }
          if (key[SDLK_m]) // partage init
          {
            if (perso.acceleration < 20)
              perso.acceleration += 5;

          } else {
            while (perso.acceleration != 0) {
              perso.acceleration -= 20;
            }
          }
          if (key[SDLK_DOWN]) // crouching key
          {
            if (perso.frame_c == 1)
              perso.frame_c = 0;
            perso.state = crouch;
            M.down = 1;

          }
          if (key[SDLK_SPACE]) // attacking key
          {
            Mix_PlayChannel(-1, attack, 0);

            e.col = 1;
            perso.state = attacking;
            if (perso.direction == 0)
              perso.pos_hero.x += 2;
            else if (perso.direction == 1)
              perso.pos_hero.x -= 2;
          }

          if (key[SDLK_h]) // hit key (test)
          {
            perso.state = hit;
            perso.health -= 10;
            perso.score -= 20;
          }

          if (key[SDLK_d]) // hit key (test)
          {
            keypressed = 1;
            if (perso2.state != doublejumping && perso2.state != doublejumping)

              perso2.state = walking;
            perso2.direction = 0;
            scrollingenemie = 1;

            deplacerPerso2( & perso2);
            M.d = 1;

          }
          if (key[SDLK_q]) // hit key (test)
          {
            keypressed = 1;
            if (perso2.state != jumping && perso2.state != doublejumping)

              perso2.state = walking;
            perso2.direction = 1;
            scrollingenemie = 1;
            deplacerPerso2( & perso2);
            M.q = 1;
          }
          if (key[SDLK_z]) // hit key (test)
          {
            sautt( & perso2);
            //perso.state = jumping;
            if ((perso2.jump_count >= 0 && perso2.jump_count <= 1) && (perso2.pos_hero.y <= perso2.ground && perso2.pos_hero.y >= (perso2.ground - 100))) {
              perso2.jump_count++;
              saut( & perso2);

            }
            M.z = 1;
          }

          // if the person jumped and got down again
          if (perso2.jump_count >= 2 && perso2.pos_hero.y == perso2.ground)
            perso2.jump_count = 0;
          // if the person jumped once
          if (perso2.pos_hero.y < perso2.ground && perso2.pos_hero.y >= (perso2.ground - 100)) {
            perso2.state = jumping;
          }
          // if the person jumped twice
          else if (perso2.pos_hero.y < (perso2.ground - 100) && perso2.pos_hero.y >= (perso2.ground - 300)) {
            perso2.state = doublejumping;
          }

          if (key[SDLK_s]) // hit key (test)
          {
            if (perso2.frame_c == 1)
              perso2.frame_c = 0;
            perso2.state = crouch;
            M.s = 1;

          }

          if (key[SDLK_r]) // hit key (test)
          {
            Mix_PlayChannel(-1, attack, 0);

            e.col = 1;
            perso2.state = attacking;
            if (perso2.direction == 0)
              perso2.pos_hero.x += 2;
            else if (perso2.direction == 1)
              perso2.pos_hero.x -= 2;

          }

        }

        // if the hero died
        if (key[SDLK_n]) // death key (test)
        {
          perso.state = die;
          perso.death = 1;
          perso.health = 0;
          //sauvgarder(perso.score, nom, "score.txt", perso);
        }

        ///*************************************************************************************************************************************************************///

        //////////////////////////// appele fonction scrolling //////////////////////////
        scrollingright( & b, screen, M, 10, colpp);
        scrollingleft( & b, screen, M, 10, colpp);
        scrollingup( & b, screen, M, 4, colpp);
        scrollingdown( & b, screen, M, 4, colpp);
        scrollingrightpartage( & b, screen, M, 10, colpp);
        scrollingleftpartage( & b, screen, M, 10, colpp);
        scrollinguppartage( & b, screen, M, 4, colpp);
        scrollingdownpartage( & b, screen, M, 4, colpp);

        if (scrollingenemie == 1) {
          scrolling_enemie( & e, perso.direction, 10);

          scrolling_coin( & coin, perso.direction, 10);

        }
        /////////////////////////////////////////////////////////////////////////

        // main fonctions
        //pulltrigger(&perso);
        minibackg.pos_joueur = MAJMinimap(perso.pos_hero, 4, b.camera);

        animerPerso( & perso);

        afficherPerso(perso, screen, b.positionbackground);

        //////////////////////////////////////////////////////////////////////////////////////////////ES////////////////////////////////////////

        afficherEnnemi(e, screen, b.camera);
        // animerEnnemi(&e);
        updateEnnemiState( & e, perso.pos_hero.x, e.col);
        deplacerIA( & e, perso.pos_hero);
        afficherCoin(coin, screen, b.camera);
        animerCoin( & coin);

        afficherBackpartage(screen, & b);
        afficherminimap(minibackg, screen);
        animerPerso( & perso2);
        afficherPerso(perso2, screen, b.positionbackground);
        SDL_BlitSurface(message2, NULL, screen, & Message);
        SDL_BlitSurface(message3, NULL, screen, & Messagem);

        afficherscorevie(perso, screen);

        if (collisionRightSide == 1) {
          // printf("\n COLLISION RIGHT SENDING 1 TO SERIAL");
          arduinoWriteData(1);

        } else if (collisionLeftSide == 1) {
          //    printf("\n COLLISION LEFT SENDING 2 TO SERIAL");
          arduinoWriteData(2);

        } else {
          //  printf("\n NO COLLISION SENDING 0 TO SERIAL");
          arduinoWriteData(0);
        }

        if ((collisionBB(perso.pos_hero, e.pos) == 1) && (e.col == 0)) /// perso principale get hit  by ennemie
        {

          perso.state = hit;
          perso.health -= 10;
          perso.score -= 20;
        }

        if ((collisionBB(perso.pos_hero, e.pos) == 1) && (e.col == 1)) /// hitting ennemie
        {

          if (e.death == 0) {
            perso.score += 100;
          }
          e.death = 1; // ennemie dead

          e.animation.spriteSheet[0] = NULL;
          e.animation.spriteSheet[1] = NULL;
          e.animation.spriteSheet[2] = NULL;
          e.animation.spriteSheet[3] = NULL;
          e.animation.spriteSheet[4] = NULL;
        }

        if (collisionBB(perso.pos_hero, coin.pos) == 1) // when there collision image null
        {

          collisionLeftSide = 1;
          coin.animation.spriteSheet[0] = NULL;
          if (coin.col == 0) {
            perso.score += 100;
          }
          coin.col = 1;

          if (enigmetext == 0) {

            enigmetext = 1;

          }

        } else

        {

          collisionLeftSide = 0;
        }

        if (collisionBB(perso.pos_hero, pos_s) == 1) // when there collision with sunn
        {

          collisionRightSide = 1;

          /*
          if(enigmeimage == 0)
          {

          					enigmeimage = 1;

          }*/

          if (IA == 0) {

            IA = 1;

          }

        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        SDL_Flip(screen);

        // if the person is dead (dead permanently)

        if (perso.health <= 0)
          perso.death = 1;
        if (perso.death == 1) {
          perso.state = die;

          //sauvgarder(perso.score, nom, "score.txt", perso);
        }
      }

      //#########################################################################################################################################################################################///
      /*
      if( IA==1)
      {

      affichage(t,screen); 

      if( t.tour<9 &&atilganer(t.tabsuivi)==0)
      {if((t.tour+joueur)%2==0)//tour du PC
                  {calcul_coup(t.tabsuivi);
       t.tour++;}
              else
              {
              SDL_WaitEvent(&event);
              switch(event.type)
              {
              case SDL_QUIT:
      IA=-1;
                  break;
              case SDL_MOUSEBUTTONUP:
                  buttona=event.button.x/190;
                  buttonb=event.button.y/190;
                  coup=3*buttonb+buttona;
                  t.tour++;
                  break;
              }

          t.tabsuivi[coup]=-1;
      }

      }
      else
      { Resultat(t,screen);
      IA=-1;
      printf("%d", t.tour);
      }


      }*/

      if (enigmetext == 1)

      {

        afficherEnigme(enitxt, screen);

        while (SDL_PollEvent( & event)) {

          switch (event.type) {
          case SDL_QUIT: {

            enigmetext = -1;
            break;

          }

          case SDL_MOUSEBUTTONDOWN: {
            if ((event.motion.x > 375 && event.motion.x < 615) && (event.motion.y > 520 && event.motion.y < 610)) {
              enitxt.pos_selected = 1;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            } else if ((event.motion.x > 178 && event.motion.x < 411) && (event.motion.y > 649 && event.motion.y < 734)) {
              enitxt.pos_selected = 2;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            } else if ((event.motion.x > 568 && event.motion.x < 800) && (event.motion.y > 656 && event.motion.y < 731)) {
              enitxt.pos_selected = 3;
              if (event.button.button == SDL_BUTTON_LEFT) {
                verify_enigme( & enitxt, screen);
                perso.score += enitxt.score;
                enigmetext = -1;

              }
            }
          }
          break;
          }
        }

      }

      if (enigmeimage == 1) {

        afficherEnigmeimage( & ee, screen);

        perso.score += ee.score;
        enigmeimage = -1;

      }

    }
    SDL_Delay(20);
  }

  freeEnnemie(e);
  freecoin(coin);

  SDL_FreeSurface(screen);
  SDL_FreeSurface(message1);
  freebackground( & b);

  Liberer( & minibackg);
  SDL_FreeSurface(message1);
  SDL_FreeSurface(message2);
  SDL_FreeSurface(message3);

  free_perso( & perso);
  free_perso( & perso2);
  liberationmemoire(t);

  free_Surface_enigme(enitxt);

  libereranimation(tabimg);
  libererButtons(start, settings, exit, music, score, gamelogo);
  TTF_CloseFont(font);
  Mix_FreeChunk(chunk);
  Mix_FreeMusic(musique);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
  return 0;
}
// gcc main.c -lSDL -lSDL_image -lSDL_mixer -o Game -g