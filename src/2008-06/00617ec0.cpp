// from server: 100% by king_originala
struct CursorString {
    char storage[28];
};

struct Position {
    float x, y, z;
};

extern CursorString& (__thiscall *assignCursor)(CursorString*, const char*);
extern "C" bool __cdecl checkTarget(void*, float, int);

struct S {
    char padding[0x1c];
    CursorString cursor;
    char gap[4];
    Position position;

    void* findTarget(void*, Position*);
    float getDistance(Position*);
    bool checkPosition(Position*);
    bool getValue();
    void updateCursor(void*);
};

void S::updateCursor(void* argument)
{
    void* target = findTarget(argument, &position);
    bool valid = checkTarget(target, getDistance(&position), 0);

    if (target) {
        if (valid) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x843a60));
            return;
        }
        if (checkPosition(&position) && !getValue()) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x833850));
            return;
        }
    }
    assignCursor(&cursor, reinterpret_cast<const char*>(0x843c14));
}
