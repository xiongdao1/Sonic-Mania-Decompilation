#ifndef OBJ_ICEBOMBA_H
#define OBJ_ICEBOMBA_H

#include "../SonicMania.h"

// Object Class
typedef struct {
	RSDK_OBJECT
} ObjectIceBomba;

// Entity Class
typedef struct {
	RSDK_ENTITY
} EntityIceBomba;

// Object Struct
extern ObjectIceBomba *IceBomba;

// Standard Entity Events
void IceBomba_Update();
void IceBomba_LateUpdate();
void IceBomba_StaticUpdate();
void IceBomba_Draw();
void IceBomba_Create(void* data);
void IceBomba_StageLoad();
void IceBomba_EditorDraw();
void IceBomba_EditorLoad();
void IceBomba_Serialize();

// Extra Entity Functions


#endif //!OBJ_ICEBOMBA_H