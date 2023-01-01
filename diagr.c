#include <stdio.h>
#include <math.h>
void txy (float p, float a1, float b1, float c1, float tb1, float a2, float b2, float c2, float tb2);
void pxy (float t, float a1, float b1, float c1, float a2, float b2, float c2);
float antoinep (float tsat, float a, float b, float c);
float antoinet (float psat, float a, float b, float c);

int main() {
	char option;
	char spec1[24], spec2[24];
	float pt, a1, b1, c1, tb1, a2, b2, c2, tb2;
	scanf("%c %f %f\t%f\t%f\t%f %s %f\t%f\t%f\t%f %s", &option, &pt, &a1, &b1, &c1, &tb1, &spec1, &a2, &b2, &c2, &tb2, &spec2);
	switch(option){
	case 'p':
		txy(pt, a1, b1, c1, tb1, a2, b2, c2, tb2);
		return 0;
	case 't':
		pxy(pt, a1, b1, c1, a2, b2, c2);
		return 0;
	default:
		return 1;
	}

}

float antoinep (float tsat, float a, float b, float c) {
	float psat = exp(a - b/(tsat + c));
	return psat;
}

float antoinet (float psat, float a, float b, float c) {
	float tsat = b/(a - log(psat)) - c;
	return tsat;
}

void txy (float p, float a1, float b1, float c1, float tb1, float a2, float b2, float c2, float tb2) {	
	float t, x1, y1, p1sat, p2sat;
	int i = 0;
	float step = (tb2 - tb1)/10;
	printf("x1\ty1\tt\tp1sat\tp2sat\n");
	for (i = 0; i < 11; i++) {
		t  = tb1 + i*step;
		p1sat = antoinep(t, a1, b1, c1);
		p2sat = antoinep(t, a2, b2, c2);
		x1 = (p - p2sat)/(p1sat - p2sat);
		y1 = x1*p1sat/p;
		printf("%1.5f\t%1.5f\t%.3f\t%.3f\t%.3f\n", x1,y1,t,p1sat,p2sat);
	}
}

void pxy (float t, float a1, float b1, float c1, float a2, float b2, float c2) {
	float p1sat = antoinep(t, a1, b1, c1);
	float p2sat = antoinep(t, a2, b2, c2);
	float p, x1, y1;
	int i = 0;
	float step = 0.1;
	printf("x1\ty1\tp\n");
	for (i = 0; i < 11; i++) {
		x1 = i*step;
		p = x1*(p1sat - p2sat) + p2sat;
		y1 = x1*p1sat/p;
		printf("%1.5f\t%1.5f\t%1.5f\n", x1, y1, p);
	}
}
