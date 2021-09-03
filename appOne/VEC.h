#pragma once
struct VEC
{
	float x = 0;
	float y = 0;
};

float magnitude(struct VEC* v);        //ベクトルの大きさ
struct VEC normalize(struct VEC* v);   //正規化ベクトル
struct VEC vecFromAngle(float angle);  //角度
float angleBetweenTwoVecs(struct VEC* a, struct VEC* b); //内積 外積 なす角
