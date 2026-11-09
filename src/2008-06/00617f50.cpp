// from server: 100% by king_originala
struct CursorString {
    char storage[0x1c];
};

typedef CursorString& (__thiscall *AssignCursor)(CursorString*, const char*);
extern AssignCursor assignCursor;

extern "C" bool __cdecl testTarget(void*, float, int);

struct S {
    char padding[0x1c];
    CursorString cursor;
    bool active;
    char padding39[3];
    float position[3];

    void* findTarget(void*, float*);
    float distance(float*);
    bool canDrag(float*);
    bool blocked();
    void update(void*);
};

void S::update(void* event)
{
    void* target = findTarget(event, position);
    bool nearTarget = testTarget(target, distance(position), 0);

    if (target) {
        if (nearTarget) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x843a60));
            active = false;
            return;
        }

        if (canDrag(position) && !blocked()) {
            assignCursor(&cursor, reinterpret_cast<const char*>(0x833850));
            active = true;
            return;
        }
    }

    assignCursor(&cursor, reinterpret_cast<const char*>(0x843c14));
    active = false;
}
