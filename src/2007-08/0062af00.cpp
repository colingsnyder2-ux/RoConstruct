// from server: 100% by colin
struct MouseCommand {
    char pad[0x2c];
    bool dragging;
};

struct GroupDragTool : MouseCommand {
    void* getCursorName(void* result);
};

typedef void* (__thiscall *StringCtorFn)(void*, const char*);
extern StringCtorFn g_stringCtor;

void* GroupDragTool::getCursorName(void* result) {
    volatile int zero = 0;
    const char* cursor = dragging ? "GrabRotateCursor" : "DragCursor";
    g_stringCtor(result, cursor);
    return result;
}
