#include"libOne.h"
#include"VEC.h"

float magnitude(struct VEC* v) {
	return sqrt(v->x * v->x + v->y * v->y);//main‚É•Ô‚é
}
struct VEC normalize(struct VEC* v) {
	float mag = magnitude(v);
	struct VEC tmp;
	if (mag > 0) {
		tmp.x = v->x / mag;
		tmp.y = v->y / mag;
	}
	return tmp;
}
struct VEC vecFromAngle(float angle) {
	struct VEC tmp;
	tmp.x = sin(angle);
	tmp.y = -cos(angle);
	return tmp;
}
float angleBetweenTwoVecs(struct VEC* a, struct VEC* b) {
	float dp = a->x * b->x + a->y * b->y;//“àÏ
	float cp = a->x * b->y - a->y * b->x;//ŠOÏ
	return atan2(cp, dp);//cp,dp‚ğ“n‚·
}
