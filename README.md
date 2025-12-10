# SaveTheFinn - Script Archive

본 저장소는 **DirectX 기반 C++ 프로젝트 SaveTheFinn** 개발 과정에서  
제가 직접 구현한 **게임 시스템 핵심 소스코드만 선별하여 정리한 포트폴리오용 저장소**입니다.

※ 전체 프로젝트는 팀 자산 및 저작권 문제로 인해 업로드하지 않았습니다.  
   게임의 전체 동작은 시연 영상을 통해 확인 가능합니다.

---

## 핵심 구현 내용 

### Block System

- 블록 파괴 / 재생성 로직 구현
- 위치·좌표 기반 이동 흐름 구성

### Item & Inventory System

- 아이템 획득 처리
- 효과 적용 구조 
- 인벤토리 내부 데이터 관리 및 출력

### Trap System

- 맵 내 트랩 배치
- 트랩 효과

### Minimap System

- 현재 맵 상태를 기반으로 미니맵 2D 출력
- 플레이어 위치 갱신 반영

---


## Script Reference
아래는 주요 스크립트를 기능별로 정리한 참조 목록입니다. 


---

### Block
- [Block.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Block/Block.cpp)
- [Block.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Block/Block.h)

### Inventory
- [Inventory.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Inventory/Inventory.cpp)
- [Inventory.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Inventory/Inventory.h)

### Item
- [Item.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Item/Item.cpp)
- [Item.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Item/Item.h)

### MiniMap
- [MiniMap.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/MiniMap/MiniMap.cpp)
- [MiniMap.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/MiniMap/MiniMap.h)

### Score
- [Score.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Score/Score.cpp)
- [Score.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Score/Score.h)

### Trap
- [Trap.cpp](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Trap/Trap.cpp)
- [Trap.h](https://github.com/hambbo/SaveTheFinn/blob/master/Script/Trap/Trap.h)

---

## 📁 폴더 구조
```
SaveTheFinn/
│
├─ Block/
│   ├─ Block.cpp
│   └─ Block.h
│
├─ Item/
│   ├─ Item.cpp
│   └─ Item.h
│
├─ Inventory/
│   ├─ Inventory.cpp
│   └─ Inventory.h
│
├─ MiniMap/
│   ├─ MiniMap.cpp
│   └─ MiniMap.h
│
├─ Trap/
│   ├─ Trap.cpp
│   └─ Trap.h
│
└─ Score/
    ├─ Score.cpp
    └─ Score.h


```


## 👤 담당 역할 요약
- 블록 / 트랩 / 아이템 / 미니맵 시스템 구현

