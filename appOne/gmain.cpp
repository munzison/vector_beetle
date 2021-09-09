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
	int mesuImg = loadImage("assets\\mesu.png");//�I�X�̉摜
	int backImg = loadImage("assets\\green.png");//�w�i�摜
//�I�X�f�[�^
	struct BEETLE osu;
	osu.pos.x = width / 2 + 500;//x���W
	osu.pos.y = height / 2;//y���W
	osu.advSpeed = 10;
	//���X�f�[�^
	struct BEETLE mesu;
	mesu.pos.x = width / 2 - 500;
	mesu.pos.y = height / 2;
	mesu.advSpeed = 10;
	float advAngle = 0;//�i�s�����̊p�x
	//���
	const int WALK = 0;
	const int ROTATE = 1;
	int state = WALK;
	int rotateCnt = 0;
	//���C�����[�v
	while (notQuit) {
		if (state == WALK) {
			struct VEC a, b;
			if (isPress(KEY_D))b.x = 1;
			if (isPress(KEY_A))b.x = -1;
			if (isPress(KEY_W))b.y = -1;
			if (isPress(KEY_S))b.y = 1;
			if (b.x != 0 || b.y != 0) {
				//�I�X�̈ړ�
				b = normalize(&b);
				osu.pos.x += b.x * osu.advSpeed;
				osu.pos.y += b.y * osu.advSpeed;
				//�I�X�̉�]
				a = vecFromAngle(osu.angle);
				osu.angSpeed = angleBetweenTwoVecs(&a, &b) / 4;
				osu.angle += osu.angSpeed;
			}
			//���X�̓�������
			b.x = sin(advAngle);
			b.y = -cos(advAngle) * 0.3;
			advAngle += 0.02;
			//���X�̈ړ�
			mesu.pos.x += b.x * mesu.advSpeed;
			mesu.pos.y += b.y * mesu.advSpeed;
			//���X�̉�]
			a = vecFromAngle(mesu.angle);
			mesu.angSpeed = angleBetweenTwoVecs(&a, &b) / 4;
			mesu.angle += mesu.angSpeed;

			if (isTrigger(KEY_SPACE)) {
				//�I�X
				b.x = mesu.pos.x - osu.pos.x;//���X�ւ̕����x�N�g��
				b.y = mesu.pos.y - osu.pos.y;
				if (magnitude(&b) < 300) {
					a = vecFromAngle(osu.angle);
					osu.angSpeed = angleBetweenTwoVecs(&a, &b) / 30;
					//���X
					b.x = -b.x;
					b.y = -b.y;
					a = vecFromAngle(mesu.angle);
					mesu.angSpeed = angleBetweenTwoVecs(&a, &b) / 30;
					//��Ԑ؂�ւ�
					rotateCnt = 0;
					state = ROTATE;
				}
			}
		}
		else if (state == ROTATE) {
			if (rotateCnt < 30) {
				osu.angle += osu.angSpeed;
				mesu.angle += mesu.angSpeed;
				rotateCnt++;
			}
			else {
				 if (isTrigger(KEY_W)||
					isTrigger(KEY_A) ||
					isTrigger(KEY_S) ||
					isTrigger(KEY_D)) {
					state = WALK;
				}
			}
		}
		clear();
		rectMode(CORNER);
		image(backImg, 0, 0);
		fill(255, 255, 255, 128);
		noStroke();//�֊s��������
		circle(mesu.pos.x, mesu.pos.y, 600);
		rectMode(CENTER);
		image(osuImg, osu.pos.x, osu.pos.y, osu.angle);
		image(mesuImg, mesu.pos.x, mesu.pos.y, mesu.angle);
	}
}