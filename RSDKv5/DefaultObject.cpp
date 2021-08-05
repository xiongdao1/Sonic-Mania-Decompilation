#include "RetroEngine.hpp"

ObjectDefaultObject *DefaultObject;

void DefaultObject_Update()
{
    if (controller[0].keyUp.down) {
        if (screens[0].position.y > 0)
            screens[0].position.y -= 4;
    }
    else if (controller[0].keyDown.down) {
        screens[0].position.y += 4;
    }

    if (controller[0].keyLeft.down) {
        if (screens[0].position.x > 0)
            screens[0].position.x -= 4;
    }
    else if (controller[0].keyRight.down) {
        screens[0].position.x += 4;
    }
}

void DefaultObject_LateUpdate() {}
void DefaultObject_StaticUpdate() {}
void DefaultObject_Draw() {}

void DefaultObject_Create(void *data)
{
    EntityDefaultObject *entity = (EntityDefaultObject *)sceneInfo.entity;
    entity->active              = ACTIVE_ALWAYS;
    DefaultObject->active       = ACTIVE_ALWAYS;
}

void DefaultObject_StageLoad() {}
void DefaultObject_EditorDraw() {}
void DefaultObject_EditorLoad() {}
void DefaultObject_Serialize() {}
