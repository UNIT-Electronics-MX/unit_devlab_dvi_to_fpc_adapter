// Double-buffered 8-bit Adafruit_GFX-compatible framebuffer for PicoDVI
// Flicker-free animation with palette-based rendering

#include <upicodvi.h>

static const struct dvi_serialiser_cfg devlab_dvi_cfg = {
  .pio = pio0,
  .sm_tmds = {0, 1, 2},
  .pins_tmds = {8, 12, 14},
  .pins_clk = 10,
  .invert_diffpairs = false
};

DVIGFX8 display(DVI_RES_320x240p60, true, devlab_dvi_cfg);

#define N_BALLS 100
#define BALL_RADIUS 20

struct Ball {
  int16_t x;
  int16_t y;
  int8_t vx;
  int8_t vy;
};

Ball ball[N_BALLS];

void setup() {
  if (!display.begin()) {
    pinMode(LED_BUILTIN, OUTPUT);
    for (;;) {
      digitalWrite(LED_BUILTIN, (millis() / 500) & 1);
    }
  }

  randomSeed(millis());

  for (int i = 0; i < N_BALLS; i++) {
    display.setColor(i + 1,
                     64 + random(192),
                     64 + random(192),
                     64 + random(192));

    ball[i].x = BALL_RADIUS + random(display.width() - 2 * BALL_RADIUS);
    ball[i].y = BALL_RADIUS + random(display.height() - 2 * BALL_RADIUS);

    do {
      ball[i].vx = 2 - random(5); // range: -2 to +2
      ball[i].vy = 2 - random(5);
    } while ((ball[i].vx == 0) && (ball[i].vy == 0));
  }

  display.setColor(255, 255, 255, 255); // palette entry 255 = white
  display.swap(false, true);
}

void loop() {
  display.fillScreen(0);

  for (int i = 0; i < N_BALLS; i++) {
    display.fillCircle(ball[i].x, ball[i].y, BALL_RADIUS, i + 1);

    ball[i].x += ball[i].vx;
    ball[i].y += ball[i].vy;

    if (ball[i].x <= BALL_RADIUS) {
      ball[i].x = BALL_RADIUS;
      ball[i].vx *= -1;
    } else if (ball[i].x >= (display.width() - 1 - BALL_RADIUS)) {
      ball[i].x = display.width() - 1 - BALL_RADIUS;
      ball[i].vx *= -1;
    }

    if (ball[i].y <= BALL_RADIUS) {
      ball[i].y = BALL_RADIUS;
      ball[i].vy *= -1;
    } else if (ball[i].y >= (display.height() - 1 - BALL_RADIUS)) {
      ball[i].y = display.height() - 1 - BALL_RADIUS;
      ball[i].vy *= -1;
    }
  }

  display.swap();
}