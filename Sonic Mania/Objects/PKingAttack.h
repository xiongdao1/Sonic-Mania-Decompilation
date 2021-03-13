#ifndef OBJ_PKINGATTACK_H
#define OBJ_PKINGATTACK_H

#include "../SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    int value1[8]; //= { 32, 32, 15225048, 15225048, 15225048, 15225048, 32, 32 };
    ushort value2;
    ushort value3;
} ObjectPKingAttack;

// Entity Class
typedef struct {
	RSDK_ENTITY
} EntityPKingAttack;

// Object Struct
extern ObjectPKingAttack *PKingAttack;

// Standard Entity Events
void PKingAttack_Update();
void PKingAttack_LateUpdate();
void PKingAttack_StaticUpdate();
void PKingAttack_Draw();
void PKingAttack_Create(void* data);
void PKingAttack_StageLoad();
void PKingAttack_EditorDraw();
void PKingAttack_EditorLoad();
void PKingAttack_Serialize();

// Extra Entity Functions


#endif //!OBJ_PKINGATTACK_H