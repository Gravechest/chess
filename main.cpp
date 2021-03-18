#include "hooft.h"
#include <iostream>
#include <windows.h>
int inp, inp2, choice;
char turn = 0;
bool castl[2] = { 0,0 };
char id[64] = {
    4,3,2,5,6,2,3,4,
    1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    7,7,7,7,7,7,7,7,
    10,9,8,11,12,8,9,10
};
char idwrite[64] = {
    4,3,2,5,6,2,3,4,
    1,1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    7,7,7,7,7,7,7,7,
    10,9,8,11,12,8,9,10
};
void pcs() {
    std::cin >> choice;
    switch (choice) {
    case 1:
        idwrite[inp2] == 3;
        break;
    case 2:
        idwrite[inp2] == 2;
        break;
    case 3:
        idwrite[inp2] == 4;
        break;
    case 4:
        idwrite[inp2] == 5;
        break;
    }
}
void los(char x,char t,bool c) {
    if ((inp2 - inp) % x == 0 && ((inp2 - inp < 0 && x < 0 )||( inp2 - inp > 0 && x > 0))) {
        if (c == 0) {
            if (id[inp2] != 0 && id[inp2] < 7) {
                return;
            }
        }
        else {
            if (id[inp2] > 6) {
                return;
            }
        }
        for (int i = inp2 - x; i > inp; i -= x) {
            if (id[i] != 0) {   
                return;
            }
        }
        idwrite[inp2] = t;
        idwrite[inp] = 0;
    }
}
int main()
{
    window();
  while(true){
  piece:
      printf("\x1b[2J");
      printf("\x1b[H");
      for (char i = 0;i < 64;i++){
          switch(id[i]){
              case 0:
                  printf(".");
              break;
              case 1:
                  printf("O");
              break;
              case 2:
                  printf("b");
              break;
              case 3:
                  printf("k");
              break;
              case 4:
                  printf("r");
              break;
              case 5:
                  printf("q"); 
              break;
              case 6:
                  printf("a");
              break;    
              case 7:
                  printf("*");
              break;
              case 8:
                  printf("B");
              break;
              case 9:
                  printf("K");
              break;
              case 10:
                  printf("R");
              break;
              case 11:
                  printf("Q");
              break;
              case 12:
                  printf("A");
              break;
          }
          printf(" ");
          if ((i + 1) % 8 == 0) {
              printf("      ");
              for (char i2 = 0; i2 < 8; i2++) {
                  printf("%d", i - 7 + i2);
                  if (i - 7 + i2 < 10) {
                      printf("   ");
                  }
                  else {
                      printf("  ");
                  }
              }
              printf("\n");
          }
      }
      if (turn == 1) {
          std::cin >> inp;
          std::cin >> inp2;
      }
      else {
          memcpy(idwrite, id, 64);
          inp = comp();
          id[ans2] = inp;
          id[ans] = 0;
          turn = 1;
          printf("\x1b[2J");
          printf("\x1b[H");
          goto piece;
      }
      memcpy(idwrite, id, 64);
      if (turn == 0) {
          if (id[inp] > 6) {
              goto piece;
          }
      }
      else {
          if (id[inp] < 7) {
              goto piece;
          }
      }
      switch (id[inp]) {
      case 1:
          if (inp + 8 == inp2 || inp + 16 == inp2) {
              if (inp < 16 && inp > 7) {
                  if (id[inp + 8] != 0 || id[inp + 16] != 0) {
                      goto piece;
                  }
                  idwrite[inp2] = 1;
                  idwrite[inp] = 0;
              }
              else if (inp < 56 && inp > 48 && inp + 8 == inp2) {
                  if (id[inp2] != 0) {
                      goto piece;
                  }
                  pcs();
                  idwrite[inp] = 0;
              }
              else if (inp + 8 == inp2) {
                  if (id[inp2] != 0) {
                      goto piece;
                  }
                  idwrite[inp2] = 1;
                  idwrite[inp] = 0;
              }
          }
          else if ((inp + 9 == inp2 || inp + 7 == inp2) && id[inp2] > 6) {
              if (inp < 56 && inp > 48) {
                  pcs();
              }
              else {
                  idwrite[inp2] = 1;
              }
              idwrite[inp] = 0;
          }
          else {
              goto piece;
          }
          break;
      case 2:
          los(9, 2, 0);
          los(7, 2, 0);
          los(-9, 2, 0);
          los(-7, 2, 0);
          break;
      case 3:
          for (char i = 0; i < 8; i++) {
              if (inp - inp2 == horsemv[i]) {
                  if (id[inp2] != 0 && id[inp2] < 7) {
                      goto piece;
                  }
                  idwrite[inp2] = 3;
                  idwrite[inp] = 0;
              }
          }
          break;
      case 4:
          los(8, 4, 0);
          los(-8, 4, 0);
          los(1, 4, 0);
          los(-1, 4, 0);
          break;
      case 5:
          los(8, 5, 0);
          los(-8, 5, 0);
          los(1, 5, 0);
          los(-1, 5, 0);
          los(9, 5, 0);
          los(7, 5, 0);
          los(-9, 5, 0);
          los(-7, 5, 0);
          break;
      case 6:
          if (inp2 == 1 && inp == 4 && id[0] == 4 && id[1] == 0 && id[2] == 0 && id[3] == 0) {
              idwrite[inp2] = 6;
              idwrite[inp] = 0;
              idwrite[2] = 4;
              idwrite[0] = 0;
          }
          if (inp2 == 6 && inp == 4 && id[7] == 4 && id[5] == 0 && id[6] == 0) {
              idwrite[inp2] = 6;
              idwrite[inp] = 0;
              idwrite[5] = 4;
              idwrite[7] = 0;
          }
          for (char i = 0; i < 8; i++) {
              if (inp - inp2 == kingmv[i]) {
                  if (id[inp2] != 0 && id[inp2] < 7) {
                      goto piece;
                  }
                  idwrite[inp2] = 6;
                  idwrite[inp] = 0;
              }
          }
          break;
      case 7:
          if (inp - 8 == inp2 || inp - 16 == inp2) {
              if (inp < 56 && inp > 47) {
                  if (id[inp - 8] != 0 || id[inp - 16] != 0) {
                      goto piece;
                  }
                  idwrite[inp2] = 7;
                  idwrite[inp] = 0;
              }
              else if (inp < 16 && inp > 7 && inp - 8 == inp2) {
                  if (id[inp2] != 0) {
                      goto piece;
                  }
                  pcs();
                  idwrite[inp] = 0;
              }
              else if (inp - 8 == inp2) {
                  if (id[inp2] != 0) {
                      goto piece;
                  }
                  idwrite[inp2] = 7;
                  idwrite[inp] = 0;
              }
          }
          else if ((inp - 9 == inp2 || inp - 7 == inp2) && id[inp2] < 7 && id[inp2] != 0) {
              if (inp < 16 && inp > 7) {
                  pcs();
              }
              else {
                  idwrite[inp2] = 7;
              }
              idwrite[inp] = 0;
          }
          else {
              goto piece;
          }
          break;
      case 8:
          los(9, 8,1);
          los(7, 8,1);
          los(-9, 8,1);
          los(-7, 8,1);
          break;
      case 9:
          for (char i = 0; i < 8; i++) {
              if (inp - inp2 == horsemv[i]) {
                  if (id[inp2] > 6) {
                      goto piece;
                  }
                  idwrite[inp2] = 9;
                  idwrite[inp] = 0;
              }
          }
          break;
      case 10:
          los(8, 10,1);
          los(-8, 10,1);
          los(1, 10,1);
          los(-1, 10,1);
          break;
      case 11:
          los(8, 11,1);
          los(-8, 11,1);
          los(1, 11,1);
          los(-1, 11,1);
          los(9, 11,1);
          los(7, 11,1);
          los(-9, 11,1);
          los(-7, 11,1);
          break;
      case 12:
          for (char i = 0; i < 8; i++) {
              if (inp - inp2 == kingmv[i]) {
                  if (id[inp2] > 6) {
                      goto piece;
                  }
                  idwrite[inp2] = 12;
                  idwrite[inp] = 0;
              }
          }
          break;
      default:
          goto piece;
      }
      if (cfc() == 1 && memcmp(id,idwrite,64) != 0) {
          memcpy(id, idwrite, 64);
          if (id[inp2] == 6) {
              castl[0] = 1;
          }
          if (id[inp2] == 12) {
              castl[1] = 1;
          }
          if (turn == 0) {
              turn = 1;
          }
          else {
              turn = 0;
          }
      }
  }
}
