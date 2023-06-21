#include "ansi_S.h"

void collision(int a,int b,int SS) {

switch (a) {
		case 4:
			a=0;
			switch(b) {
			case 1:
				Broken(2,1,2,27+SS);
				if (Bup){
				break;
				}
			case 2:
				Broken(2,2,2,27+SS);
				if (Bdown){
				break;
				}
			case 3:
				Broken(2,3,2,27+SS);
				if (Bcanon){
				break;
				}
			case 4:
				Broken(2,4,2,27+SS);
				if (Bship1) {
				break;
				}
			case 5:
				Broken(2,5,2,27+SS);
				if (Bship2) {
				break;
				}
			case 6:
				Broken(2,6,2,27+SS);
				if (Bship3) {
				break;
				}
			default: //timer - 10
				break;
			}
		default:
			a>4 ? a=0:a++;
		switch(b) {
			case 1:
				Broken(1,1,2,27+SS);
				if (Bup){
				break;
				}
			case 2:
				Broken(1,2,2,27+SS);
				if (Bdown){
				break;
				}
			case 3:
				Broken(1,3,2,27+SS);
				if (Bcanon){
				break;
				}
			case 4:
				Broken(1,4,2,27+SS);
				if (Bship1) {
				break;
				}
			case 5:
				Broken(1,5,2,27+SS);
				if (Bship2) {
				break;
				}
			case 6:
				Broken(1,6,2,27+SS);
				if (Bship3) {
				break;
				}
			default: //timer - 10
				break;
			}
		}
}
