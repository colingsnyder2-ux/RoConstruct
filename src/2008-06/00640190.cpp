// from server: 100% by king_originala
struct Input {
    char padding[16];
    short x;
    short y;
};

struct Vector3 {
    float x, y, z;
};

struct Object;
struct String {
    char storage[28];
};

extern String& (__thiscall *assignString)(String*, const char*);

struct GameTool {
    char padding[28];
    String cursor;

    Object* pick(Input*, Vector3*);
    bool canDrag(Object*, Vector3*);
    void updateCursor(Input*);
};

void GameTool::updateCursor(Input* input)
{
    if (input->x != 0 && input->y != 0) {
        Vector3 position = { 0.0f, 0.0f, 0.0f };
        Object* object = pick(input, &position);
        if (!object) {
            assignString(&cursor, "ArrowFarCursor");
            return;
        }
        if (!canDrag(object, &position)) {
            assignString(&cursor, "ArrowCursor");
            return;
        }
        assignString(&cursor, "DragCursor");
    }
}
