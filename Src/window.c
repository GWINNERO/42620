#include "ansi_s.h"

void windowSmp(int x1, int y1, int x2, int y2) {

		int tl = 218; 	// ┌
		int lsd = 180; 	// ┤
		int bl = 192;	// └
		int wll = 179;	// │
		int btt = 196; 	// ─
		int tr = 191; 	// ┐
		int rsd = 195;	// ├
		int br = 217;	// ┘

		//Top ┌──────┐
		gotoxy(x1, y1);
		printf("%c", tl);
		for (int i=x1+1;i<x2-1;i++){
			printf("%c",btt);
		}


		printf("%c\n", tr);

		//Mid │        │
		for (int i = y1+1; i < y2; i++) {
			gotoxy(x1, i);
			printf("%c", wll);
			gotoxy(x2-1,i);
			printf("%c", wll);
		}

		//Bottom  └─────────┘
		gotoxy(x1,y2);
		printf("%c", bl);
		for (int i=x1; i < x2-2; i++){
			printf("%c", btt);
		}
		printf("%c\n", br);
	}
