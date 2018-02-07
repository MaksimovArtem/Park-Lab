#pragma once

const int N = 40;

int dx3[3] = {1, 0, -1};
int dy3[3] = {0, -1, 1};

int dx5[5] = {1, 0, -1, 2, -2};
int dy5[5] = { -2, 2, 0, -1, 1};

int dx7[7] = {3, -3, 1, 0, -1, 2, -2};
int dy7[7] = { -2, 2, 0, 3, -3, -1, 1};

int dx9[9] = {3, -3, 1, 0, -4, 4 - 1, 2, -2};
int dy9[9] = { -2, 4, 2, 0, 3, -3, -1, -4, 1};

int grass_max_age = 3;
int grass_reprod_time = 1;
int grass_chance_to_appear = 200;////(%N*N < it = born)

int rab_max_age = 10;
int rab_max_hunger = 4;
int rab_crit_hunger = 1;
int rab_reprod_time = 4;
int rab_chance_to_appear = 80;////(%N*N < it = born)

int fox_max_age = 30;
int fox_max_hunger = 20;
int fox_crit_hunger = 6;
int fox_reprod_time = 20;
int fox_chance_to_appear = 30;////(%N*N < it = born)
