#pragma once
#include "Include.h"
#include <string>

class Inventory
{
    int x, y; // 인벤토리 위치 좌표
    typedef struct Inven {
        int ItemIndex; //아이템 인덱스 (1: 나팔, 2:핀, 3: 빈 칸)
        bool Use; //사용 여부 
        std::string name; //아이템 이름 
        bool eatItem; // 아이템 먹었는지 여부 
        int m_itemNumber; // 아이템 개수 
        int usedCount; //사용 횟수
    };
    Inven Items[INVENTORY_SLOT_COUNT]; // 인벤토리 아이템 배열 (나팔, 핀 갯수, 빈 칸) 

public:
    Inventory(); // 생성자 
    ~Inventory();  // 초기화 

    int key; //아이템 사용 키 (

    Sprite Inventoryimg; // 인벤토리 이미지 
    Sprite Finnimg;       // 핀 이미지
    Sprite Hornimg;     // 나팔 이미지
    Sprite HornDieimg; //나팔 불투명 이미지 
    Sprite ItemNumberimg[10]; // 아이템 개수 이미지 

    void Init();    //초기화
    void Update();   //업데이트
    void Draw();      //그리기 
    void UseItem(int itemIndex); // 아이템 사용함수 (아이템 인덱스 전달)
    void AddItem(int itemType); // 아이템 먹는 함수 
    void Reset(); //인벤토리 초기화 함수 
};

extern Inventory inventory; // 전역변수로 선언