#include "Include.h"

Inventory inventory;
extern Score score;
extern Item item;
extern std::list<Trap*> targetTrap;	//@10-3 벡터 extern 선언. 트랩 모두 없애는 효과 사용하기 위함

Inventory::Inventory() // 생성자 
{

}


Inventory::~Inventory() {} //소멸자 

void Inventory::Init()//초기화
{
	char FileName[256];
	sprintf_s(FileName, "./resource/Img/Inventory/Inventory1.png"); // 인벤토리 슬롯 이미지
	Inventoryimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	x = 510;
	y = 670;

	sprintf_s(FileName, "./resource/Img/Inventory/Item4.png"); // 나팔 이미지
	Hornimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Inventory/ItemDie.png"); // 나팔 불투명 이미지
	HornDieimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	sprintf_s(FileName, "./resource/Img/Inventory/finn_ice1.png"); // 핀 이미지 
	Finnimg.Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	for (int i = 0; i < 11; i++) // 아이템 개수 
	{
		sprintf_s(FileName, "./resource/Img/Inventory/InventoryNum/%02d.png", i); // 숫자이미지
		ItemNumberimg[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
	}

	inventory.key = 0;


	Items[0].ItemIndex = 1; // 나팔
	Items[0].Use = true; // 사용 가능 
	Items[0].name = "Horn"; //아이템 이름 
	Items[0].eatItem = false; // 아이템 먹었는지 (처음은 false) 시작 
	Items[0].m_itemNumber = 0;  // 아이템 개수 0 초기화 
	Items[0].usedCount = 0;//  아이템 사용횟수 초기화

	Items[1].ItemIndex = 2; // 핀 
	Items[1].Use = false; // 사용 가능 
	Items[1].name = "Finn"; //아이템 이름 
	Items[1].eatItem = false; // 아이템 먹었는지 (처음은 false) 시작 
	Items[1].m_itemNumber = 0;  // 아이템 개수 0 초기화 

	Items[2].ItemIndex = 3; // 빈 칸 
	Items[2].Use = false; // 사용 가능 
	Items[2].name = "N"; //아이템 이름 
	Items[2].eatItem = false; // 아이템 먹었는지 (처음은 false) 시작 
	Items[2].m_itemNumber = 0;  // 아이템 개수 0 초기화 

}

void Inventory::Update()//업데이트
{
	if (inventory.key == VK_F1 && Items[0].eatItem == true)
	{
		UseItem(1);
		inventory.key = 0;
	}
}

void Inventory::Draw()     //그리기 
{
	Inventoryimg.Render(x, y, 0, 1.5, 1.5); // 인벤토리 이미지 그리기 

	if (Gmanager.m_GameStart == true)
	{
		if (Items[0].eatItem == true && Items[0].ItemIndex == 1 && Items[0].m_itemNumber > 0) // 나팔 먹었다 
		{
			Hornimg.SetColor(255, 255, 255, 255); // 나팔 이미지 
			Hornimg.Render(x + 7, y + 45, 0, 0.35, 0.35);

			if (Items[0].m_itemNumber < 11)
			{
				ItemNumberimg[Items[0].m_itemNumber].SetColor(255, 255, 255, 255); // 숫자 이미지 
				ItemNumberimg[Items[0].m_itemNumber].Render(x + 43, y + 67, 0, 0.2, 0.2);
			}
		}
		else if (Items[0].eatItem == true && Items[0].ItemIndex == 1 && Items[0].m_itemNumber == 0) // 나팔을 다 썻을 때 
		{
			HornDieimg.SetColor(255, 255, 255, 255); // 0일 경우 불투명 
			HornDieimg.Render(x + 7, y + 45, 0, 0.35, 0.35);

			ItemNumberimg[Items[0].m_itemNumber].SetColor(255, 255, 255, 255); // 숫자 이미지 
			ItemNumberimg[Items[0].m_itemNumber].Render(x + 43, y + 67, 0, 0.2, 0.2);
		}



		if (Items[1].eatItem == true && Items[1].ItemIndex == 2) // 핀 먹었다 
		{
			Finnimg.SetColor(255, 255, 255, 255); // 핀 이미지 
			Finnimg.Render(x + 66, y + 40, 0, 0.85, 0.85);

			if (Items[1].m_itemNumber < 11)
			{
				ItemNumberimg[Items[1].m_itemNumber].SetColor(255, 255, 255, 255); // 숫자 이미지 
				ItemNumberimg[Items[1].m_itemNumber].Render(x + 100, y + 67, 0, 0.2, 0.2);
			}
		}
	}
}

void Inventory::UseItem(int itemIndex) // 아이템 사용함수 
{
	if (itemIndex == 1)
	{
		//아이템 효과 발생
		if (Items[0].m_itemNumber > 0)
		{
			for (int i = 0; i < monster.MonsterCount; i++)	//고양이들 모두 기절				
			{
				monster.IceKing[i].life = false;

				monster.IceKing[i].m_SleepSecond = 5;
			}
			targetTrap.clear();	//나와있는 트랩 모두 사라짐
			Items[0].m_itemNumber--; // 아이템 사용 시 갯수 감소 
			Items[0].usedCount++; // 사용 횟수 증가 
		}
	}
}


void Inventory::AddItem(int itemType) // 아이템 먹는 함수 
{
	if (itemType == 1)//나팔 
	{
		Items[0].eatItem = true;
		Items[0].m_itemNumber++; // 나팔 아이템 개수 증가 
	}
	else if (itemType == 2) // 핀
	{
		Items[1].eatItem = true;
		Items[1].m_itemNumber++; // 핀 아이템 개수 증가 
	}

}

void Inventory::Reset()
{
	for (int i = 0; i < INVENTORY_SLOT_COUNT; i++) //인벤토리 초기화
	{
		Items[i].eatItem = false;
		Items[i].m_itemNumber = 0;
	}
	inventory.key = 0;
}