#include "hooft.h"
#include <iostream>
bool ray = 0;
bool cfc() {
    for (int i = 0; i < 64; i++) {
        if ((turn == 0 && idwrite[i] == 6) || (turn == 1 && idwrite[i] == 12)) {
            for (char i2 = 0; i2 < 8; i2++) {
                if (i + horsemv[i2] < 0 || i + horsemv[i2] > 63) {
                    continue;
                }
                if ((idwrite[i + horsemv[i2]] == 9 && turn == 0) || (idwrite[i + horsemv[i2]] == 3 && turn == 1)) {
                    return 0;
                }
            }
            for (char i2 = 0; i2 < 8; i2++) {
                ray = 0;
                for (int i3 = kingmv[i2]; i3 + i > 0; i3 += kingmv[i2]) {
                    if (i3 + i > 63) {
                        break;
                    }
                    if (turn == 0) {

                        switch (idwrite[i3 + i]) {
                        case 0:
                            break;
                        case 7:
                            if (i3 == 7 || i3 == 9) {

                                return 0;
                            }
                            break;
                        case 8:
                            if (abs(kingmv[i2]) == 7 || abs(kingmv[i2]) == 9) {
                                return 0;
                            }
                            break;
                        case 10:
                            if (abs(kingmv[i2]) == 1 || abs(kingmv[i2]) == 8) {
                                return 0;
                            }
                            break;
                        case 11:
                            if (abs(kingmv[i2]) == 1 || abs(kingmv[i2]) == 8 || abs(kingmv[i2]) == 7 || abs(kingmv[i2]) == 9) {
                                return 0;
                            }
                            break;
                        default:
                            ray = 1;
                        }
                    }
                    if (turn == 1) {
                        switch (idwrite[i3 + i]) {
                        case 0:
                            break;
                        case 1:
                            if (i3 == -7 || i3 == -9) {
                                return 0;
                            }
                            break;
                        case 2:
                            if (abs(kingmv[i2]) == 7 || abs(kingmv[i2]) == 9) {
                                return 0;
                            }
                            break;
                        case 4:
                            if (abs(kingmv[i2]) == 1 || abs(kingmv[i2]) == 8) {
                                return 0;
                            }
                            break;
                        case 5:
                            if (abs(kingmv[i2]) == 1 || abs(kingmv[i2]) == 8 || abs(kingmv[i2]) == 7 || abs(kingmv[i2]) == 9) {
                                return 0;
                            }
                            break;
                        default:
                            ray = 1;
                        }
                    }
                    if (((i3 + i) % 8 == 0 && abs(kingmv[i2] == 7)) || (i3 + i + 1 % 8 == 0 && abs(kingmv[i2] == 9)) || ray == 1) {
                        break;
                    }
                }
            }
        }
    }
    return 1;
}
