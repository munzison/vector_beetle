#pragma once
struct VEC
{
	float x = 0;
	float y = 0;
};

float magnitude(struct VEC* v);        //�x�N�g���̑傫��
struct VEC normalize(struct VEC* v);   //���K���x�N�g��
struct VEC vecFromAngle(float angle);  //�p�x
float angleBetweenTwoVecs(struct VEC* a, struct VEC* b); //���� �O�� �Ȃ��p
