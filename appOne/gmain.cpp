#include "VEC.h"
#include "libOne.h"

struct BEETLE {
	struct VEC pos;    //位置
	float advSpeed = 0;//進むスピード
	float angle = 0;   //角度
	float angSpeed = 0;//回転スピード
};

void gmain() {
	window(1920, 1080, full);
	int osuImg = loadImage("assets\\osu.png");//オスの画像
	//オスデータ
	struct BEETLE osu;
	osu.pos.x = width / 2;
	osu.pos.y = height / 2;
	osu.advSpeed = 10;
	//メインループ
	while (notQuit) {
		clear();
		image(osuImg, osu.pos.x, osu.pos.y, osu.angle);
	}
}