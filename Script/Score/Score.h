#pragma once
#include "Include.h"

class Score                    //@5-1 
{
    //@5-1 각 핀 별로 위치, 점수 지정
    typedef struct Finn
    {
        bool eat;                        //타겟(제이크)이 먹었나. true이면 핀 먹은 거 = 화면에 보이면 안 됨. life와 반대 의미로 작용
        int num;                        //몇 번째 핀이냐    (단 num <= FinnNumber 여야 함)
        double Finn_x, Finn_y;            //각 핀의 위치/ 좌표
    };

    //@7-2
    typedef struct Bmo        //목적지와 같은 역할
    {
        bool show;            //핀 다 먹으면 비모 나타나도록
        bool win;            //핀 다 먹고 && 비모에 다다르면, WIN 조건 - GameManager.cpp에서 이용        
        double x;            //비모 좌표
        double y;
    };

public:
    Score();
    ~Score();

    Finn finn[10];            //@7-2 구조체 배열 설정
    Bmo bmo;                    //@7-2 구조체 객체 설정

    Sprite Scoreimg;            // 점수 이미지 넣을 배열
    Sprite Bmos;            //비모. 핀 다 먹으면 나타남. 핀 다 먹은 상태에서 이 지점에 도달해야 승리
    Sprite Showscore;            //@10-7 현재 먹은 핀 보이도록
    Sprite ShowscoreNum[16];        //@10-7 Showscore과 함께 띄울 숫자 이미지(0부터 15)

    int FinnNumber;                // 총 핀 개수- Reset 함수에서 정해주고 있음 - 1번 키 누르면, 그제서야 핀가 나오도록
    int GetFinnNumber;            // 총 획득한 핀 개수    - Reset 함수에서 0으로 초기화하자


    void FinnFunction(double Cheese_x, double Cheese_y, int num);        //Monster.cpp 와 같은 맥락 - Reset에서 실행하기

    void Init();
    void Update();
    void Draw();

    void Reset();

};

extern Score score;
