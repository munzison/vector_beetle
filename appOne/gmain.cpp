#include "VEC.h"
#include "libOne.h"

struct BEETLE {
	struct VEC pos;    //�ʒu
	float advSpeed = 0;//�i�ރX�s�[�h
	float angle = 0;   //�p�x
	float angSpeed = 0;//��]�X�s�[�h
};

void gmain() {
	window(1920, 1080, full);
	int osuImg = loadImage("assets\\osu.png");//�I�X�̉摜
	//�I�X�f�[�^
	struct BEETLE osu;
	osu.pos.x = width / 2;
	osu.pos.y = height / 2;
	osu.advSpeed = 10;
	//���C�����[�v
	while (notQuit) {
		clear();
		image(osuImg, osu.pos.x, osu.pos.y, osu.angle);
	}
}