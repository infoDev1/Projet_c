#include "../include/bullet.h"
#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>

void Bullet_update_position(Bullet *bullet) {
  if (!bullet) {
    return;
  }

  bullet->x += bullet->dx;
  bullet->y += bullet->dy;

  if (bullet->x < 0 || bullet->x > WIDTH || bullet->y < 0 ||
      bullet->y > HEIGHT) {
    bullet->active = 0;
  }
}

void Bullet_draw(const Bullet *bullet) {
  if (!bullet || !bullet->active) {
    return;
  }

  MLV_draw_image(bullet->image, bullet->x, bullet->y);
}

void Bullet_list_update(Bullet *bullets, int count) {
  if (!bullets) {
    return;
  }

  for (int i = 0; i < count; i++) {
    Bullet_update_position(&bullets[i]);
  }
}

void Bullet_list_draw(const Bullet *bullets, int count) {
  if (!bullets) {
    return;
  }

  for (int i = 0; i < count; i++) {
    Bullet_draw(&bullets[i]);
  }
}

int Bullet_list_get_free_index(const Bullet *bullets, int count) {
  if (!bullets) {
    return -1;
  }

  for (int i = 0; i < count; i++) {
    if (!bullets[i].active) {
      return i;
    }
  }

  return -1;
}