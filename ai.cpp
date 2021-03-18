#include "hooft.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::vector<std::vector<int>> compmove;

char ans2,ans = 0;

int gr,sm = 0;

char idcomp[64];
int calcpoint = 0;

int rand(int x) {
	std::uniform_int_distribution<int> dist(0, x);
	int time = std::chrono::high_resolution_clock().now().time_since_epoch().count();
	std::default_random_engine rand(time);
	int randf = dist(rand);
	return randf;
}

int piece2(int p) {
	std::cout << p <<  "piece" << std::endl;
	switch (p) {
	case 7:
		return 1;
	case 8:
		return 3;
	case 9:
		return 3;
	case 10:
		return 5;
	case 11:
		return 9;
	case 12:
		return 200;
	}
}
void piece(int p) {
	switch (p) {
	case 1:
		if (calcpoint < 1) {
			calcpoint = 1;
		}
		break;
	case 2:
		if (calcpoint < 3) {
			calcpoint = 3;
		}
		break;
	case 3:
		if (calcpoint < 3) {
			calcpoint = 3;
		}
		break;
	case 4:
		if (calcpoint < 5) {
			calcpoint = 5;
		}
		break;
	case 5:
		if (calcpoint < 9) {
			calcpoint = 9;
		}
		break;
	case 6:
		if (calcpoint < 200) {
			calcpoint = 200;
		}
		break;
	}
}
void los(int c,int t) {
	t += c;
	for (;t < 64;t += c) {
		if (t < 0) {
			break;
		}
		if ((t % 8 == 0 && abs(c) == 9) || ((t - 1) % 8 == 0 && abs(c) == 7)) {
			break;
		}
		if (idcomp[t] > 6) {
			break;
		}
		if (idcomp[t] != 0) {
			piece(idcomp[t]);
		}
	}
}
char comp2() {
	calcpoint = 0;
	for (int i = 0; i < 64; i++) {
		if (idcomp[i] > 6) {
			switch (idcomp[i]) {
			case 7:
				if (idcomp[i - 7] < 7 && idcomp[i - 7] != 0) {
					piece(idcomp[i - 7]);
				}
				else if (idcomp[i - 9] < 7 && idcomp[i - 9] != 0) {
					piece(idcomp[i - 9]);
				}
				break;
				std::cout << calcpoint << std::endl;
			case 8:
				los(7, i);
				los(9, i);
				los(-7, i);
				los(-9, i);
				
				break;
			case 9:
				for (int i2 = 0; i2 < 8; i2++) {
					if (i + horsemv[i2] >= 0 && i + horsemv[i2] < 64) {
						if (idcomp[i + horsemv[i2]] < 7 && idcomp[i + horsemv[i2]] != 0) {
							piece(idcomp[i + horsemv[i2]]);
						}
					}
				}
				break;
			case 10:
				los(8, i);
				los(1, i);
				los(-8, i);
				los(-1, i);
				break;
			case 11:
				los(8, i);
				los(1, i);
				los(-8, i);
				los(-1, i);
				los(7, i);
				los(9, i);
				los(-7, i);
				los(-9, i);
				break;
			case 12:
				for (int i2 = 0; i2 < 8; i2++) {
					if (idcomp[i + kingmv[i2]] < 7 && idcomp[i + kingmv[i2]] != 0) {
						piece(idcomp[i + kingmv[i2]]);
					}
				}
				break;
			}
		}
	}
	memcpy(idcomp, idwrite, 64);
	return calcpoint;
}
void los2(int c, int t, int p) {
	int o = t;
	t += c;
	for (; t < 64; t += c) {
		if (t < 0) {
			break;
		}
		if ((t % 8 == 0 && abs(c == 9)) || ((t + 1) % 8 == 0 && abs(c == 7))) {
			break;
		}
		if (idwrite[t] < 7 && idwrite[t] != 0) {
			break;
		}
		if (idwrite[t] == 0) {
			idcomp[o] = 0;	
			idcomp[t] = p; 
			compmove.push_back({ o,t,0 - comp2(),p});
		}
		else {
			idcomp[o] = 0;
			idcomp[t] = p;
			compmove.push_back({ o,t,piece2(idwrite[t]) - comp2() ,p });
			break;
		}
	}
}

char comp() {
	memcpy(idcomp, idwrite, 64);
	for (int i = 0; i < 64; i++) {
		if (idwrite[i] != 0 && idwrite[i] < 7) {
			switch (idwrite[i]) {
			case 1:
				if (i < 16 && i > 7) {
					if (idwrite[i + 8] == 0) {
						idcomp[i] = 0;
						idcomp[i + 8] = 1;
						compmove.push_back({ i,i + 8,0 - comp2(),idcomp[i] });
						if (idwrite[i + 16] == 0) {
							idcomp[i] = 0;
							idcomp[i + 16] = 1;
							compmove.push_back({ i,i + 16,0 - comp2(),idcomp[i] });
						}
					}
				}
				if (idwrite[i + 8] == 0) {
					idcomp[i] = 0;
					idcomp[i + 8] = 1;
					compmove.push_back({ i,i + 8,0 - comp2(),idcomp[i] });
					if (idwrite[i + 7] > 6) {
						idcomp[i] = 0;
						idcomp[i + 7] = 1;
						compmove.push_back({ i,i + 7,piece2(idwrite[i + 7]) - comp2(),idcomp[i] });
					}
					else if (idwrite[i + 9] > 6) {
						idcomp[i] = 0;
						idcomp[i + 9] = 1;
						compmove.push_back({ i,i + 9,piece2(idwrite[i + 9]) - comp2(),idcomp[i] });

					}
					break;
			case 2:
				los2(7, i, 2);
				los2(-7, i, 2);
				los2(9, i, 2);
				los2(-9, i, 2);
				break;
			case 3:
				for (int i2 = 0; i2 < 8; i2++) {
					if (i + horsemv[i2] >= 0 && i + horsemv[i2] < 64) {
						if (idwrite[i] % 8 == 0 && (idwrite[i + horsemv[i2]] - 1) % 8 == 0) {
							break;
						}
						if ((idwrite[i] - 1) % 8 == 0 && idwrite[i + horsemv[i2]] % 8 == 0) {
							break;
						}
						if (idwrite[i + horsemv[i2]] == 0) {
							idcomp[i] = 0;
							idcomp[i + horsemv[i2]] = 3;
							compmove.push_back({ i,i + horsemv[i2],0 - comp2() ,idcomp[i] });
						}
						else if (idwrite[i + horsemv[i2]] > 6) {
							idcomp[i] = 0;
							idcomp[i + horsemv[i2]] = 3;
							compmove.push_back({ i,i + horsemv[i2],piece2(idwrite[i + horsemv[i2]]) - comp2() ,idcomp[i] });
						}
					}
				}
				break;
			case 4:
				los2(8, i, 4);
				los2(-8, i, 4);
				los2(1, i, 4);
				los2(-1, i, 4);
				break;
			case 5:
				los2(8, i, 5);
				los2(-8, i, 5);
				los2(1, i, 5);
				los2(-1, i, 5);
				los2(7, i, 5);
				los2(-7, i, 5);
				los2(9, i, 5);
				los2(-9, i, 5);
				break;
				}
			}
		}
	}
	gr = -1000;
	sm = 0;
	for (int i = 0; i < compmove.size();i++) {
		if (gr < compmove[i][2]) {
			gr = compmove[i][2];
		}
	}
	std::cout << gr << std::endl;
	for (int i = 0; i < compmove.size(); i++) {
		if (gr != compmove[i][2]) {
			compmove.erase(compmove.begin() + i);
			i--;
		}
		else {
			sm++;
		}
	}
	int ran = rand(sm - 1);
	ans = compmove[ran][0];
	ans2 = compmove[ran][1];
	char ans3 = compmove[ran][3];
	compmove.clear();
	return ans3; 
}
