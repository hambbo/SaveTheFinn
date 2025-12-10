#include "Include.h"

Score score;

extern FmodSound ScoreSound;	//@14-2	사운드 추가

Score::Score()
{
	/*	// 나중에 그림 여러개 쓸 때 사용할 변수 //
	m_ScoreAniTime = 0;
	m_ScoreCount = 0;
	*/

}

Score::~Score() {}

void Score::Init()
{
	char FileName[256];

	sprintf_s(FileName, "./resource/Img/Score/Finn_ice.png");
	Scoreimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Score/Bimoo.png");		//@7-2 비모 이미지
	Bmos.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Score/Showscore.png");		//@10-7 먹은 핀 개수
	Showscore.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i < 16; i++)	//@10-7
	{
		sprintf_s(FileName, "./resource/Img/Score/FinnNum/%02d.png", i);
		ShowscoreNum[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	}

	bmo.x = 1150;
	bmo.y = 620;
	bmo.show = false;
	bmo.win = false;
}

void Score::FinnFunction(double x, double y, int num)
{
	finn[num].Finn_x = x;
	finn[num].Finn_y = y;
	finn[num].eat = false;		//처음 만들 땐, 안 먹은 상태니까
}

void Score::Reset()	//@5-2 놓아야 하는 위치 : 가로(0~1280), 세로(0~768) 이내에. rand()로 표현할 수도 있긴 함~
{
	FinnFunction(100, 100, 0);
	FinnFunction(200, 100, 1);
	FinnFunction(300, 100, 2);
	FinnFunction(400, 200, 3);
	FinnFunction(500, 200, 4);
	FinnFunction(600, 200, 5);
	FinnFunction(100, 500, 6);
	FinnFunction(200, 500, 7);
	FinnFunction(300, 500, 8);
	FinnFunction(400, 500, 9);

	FinnNumber = 10;	//0번부터 n번까지니까 n+1개
	GetFinnNumber = 0;

	bmo.show = false;	//@7-2 리셋!
	bmo.win = false;
}

void Score::Update()
{
	if (Gmanager.m_GameStart == true)
	{
		//(만약 핀 안 먹은 상태&& 타겟(제리) 살아있으면) - 거리 계산 후 거리 가까우면 - 핀 먹은 상태로 변경(cheese[num].eat = true)
		for (int i = 0; i < FinnNumber; i++)
		{

			if ((finn[i].eat == false) && (target.Target_Life == true))
			{
				float distance = (float)sqrt((finn[i].Finn_x - target.t_x) * (finn[i].Finn_x - target.t_x) +
					(finn[i].Finn_y - target.t_y) * (finn[i].Finn_y - target.t_y));

				if (distance < 40)
				{
					finn[i].eat = true;	//치즈 먹었다!
					GetFinnNumber++;

					inventory.AddItem(2);

					ScoreSound.EffectPlay(Gmanager.GetScoreSound);	//@14-2 점수 먹을 때 효과음
				}
			}
		}

		if (GetFinnNumber == FinnNumber)	//치즈 다 먹으면 비모 나타나도록
		{
			bmo.show = true;

			//타겟과 아기 쥐의 거리
			float distance = (float)sqrt((bmo.x - target.t_x) * (bmo.x - target.t_x) +
				(bmo.y - target.t_y) * (bmo.y - target.t_y));

			if ((score.GetFinnNumber == score.FinnNumber) && (distance < 60))	//치즈 다 먹고 && 비모한테 다다르면 게임 WIN
			{
				bmo.win = true;	//GameManger.cpp 에서 승리조건에 적용됨
			}

		}
	}
}

void Score::Draw()
{
	for (int i = 0; i < FinnNumber; i++)
	{
		if ((Gmanager.m_GameStart == true) && (finn[i].eat == false))	//치즈 아직 안 먹힌 상태이면 그림 띄운다.
		{
			Scoreimg.SetColor(255, 255, 255, 255);
			Scoreimg.Render(finn[i].Finn_x, finn[i].Finn_y, 0, 1, 1);
		}
	}

	if (bmo.show == true)
	{
		Bmos.SetColor(255, 255, 255, 255);
		Bmos.Render(bmo.x, bmo.y, 0, 0.3, 0.3);
	}
		
	Showscore.Render(1000, 25, 0, 0.5, 0.5);						//@10-7
	ShowscoreNum[GetFinnNumber].Render(1130, 20, 0, 0.5, 0.5);	//@10-7 먹은 치즈 개수만큼 숫자 띄우기
}

