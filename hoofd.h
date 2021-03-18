#pragma once
extern char idwrite[64];
extern char turn,ans,ans2;
const char horsemv[8] = {
    15,-15,
    17,-17,
    6,-6,
    10,-10
};
const char kingmv[8] = {
    7,8,9,
    1,-1,
    -7,-8,-9
};
bool cfc();
void window();
char comp();
