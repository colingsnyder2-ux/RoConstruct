// from server: 100% by king_originala
struct CursorString;

extern CursorString& (__thiscall *assignCursor)(
    CursorString*, const char*);

extern const char cursorUnavailable[];
extern const char cursorBlocked[];
extern const char cursorDraggable[];
extern const char typeDescriptor[];

struct Part {
    char padding[0x1f0];
    unsigned char blocked;
};

extern Part* __stdcall findPart(void*, const void*);

struct CursorString {
    char storage[28];
};

struct GrabTool {
    char padding[0x1c];
    CursorString cursor;
    void updateCursor(void*);
};

void GrabTool::updateCursor(void* object)
{
    Part* part = findPart(object, typeDescriptor);
    if (!part) {
        assignCursor(&cursor, cursorUnavailable);
        return;
    }
    if (part->blocked) {
        assignCursor(&cursor, cursorBlocked);
        return;
    }
    assignCursor(&cursor, cursorDraggable);
}
