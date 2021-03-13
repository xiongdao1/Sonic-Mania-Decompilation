#ifndef OBJ_PROPELLERSHAFT_H
#define OBJ_PROPELLERSHAFT_H

#include "../SonicMania.h"

// Object Class
typedef struct {
	RSDK_OBJECT
} ObjectPropellerShaft;

// Entity Class
typedef struct {
	RSDK_ENTITY
} EntityPropellerShaft;

// Object Struct
extern ObjectPropellerShaft *PropellerShaft;

// Standard Entity Events
void PropellerShaft_Update();
void PropellerShaft_LateUpdate();
void PropellerShaft_StaticUpdate();
void PropellerShaft_Draw();
void PropellerShaft_Create(void* data);
void PropellerShaft_StageLoad();
void PropellerShaft_EditorDraw();
void PropellerShaft_EditorLoad();
void PropellerShaft_Serialize();

// Extra Entity Functions


#endif //!OBJ_PROPELLERSHAFT_H