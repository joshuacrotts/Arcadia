#include "../include/main.h"

#define S_WIDTH  800
#define S_HEIGHT 800

static void init_scene( void );
static void cleanup_scene( void );

static void update( void );

static void draw( void );

int
main( int argc, char *argv[] ) {
  Stds_InitGame( "Arcadia", S_WIDTH, S_HEIGHT, 0, 0 );
  Stds_InitAppStructures();

  init_scene();

  Stds_GameLoop();
  atexit( cleanup_scene );
  return 0;
}

/*
 *
 */
static void
init_scene( void ) {
  g_app.delegate.update = update;
  g_app.delegate.draw   = draw;
  g_app.game_state      = PREGAME;
}

/*
 *
 */
static void
update( void ) {}

/*
 *
 */
static void
draw( void ) {
  struct circle_t c;
  c.center_x = 500;
  c.center_y = 500;
  c.radius = 50;
  SDL_Color color = {0xff, 0, 0, 0xff};
  Stds_DrawCircle(&c, &color, true);
}

/*
 *
 */
static void
cleanup_scene( void ) {}