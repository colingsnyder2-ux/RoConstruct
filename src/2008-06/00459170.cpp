// from server: 100% by king_originala
struct Rect {
    int left, top, right, bottom;
};

extern "C" int (__stdcall *GetClientRect)(void*, Rect*);

struct Window;

struct WindowTable {
    void* unused[23];
    int (__thiscall *create)(Window*, void*, const char*, unsigned int,
                            Rect*, void*, int, int);
};

struct Window {
    WindowTable* table;
};

struct HelpCommand {
    char padding0[0x20];
    void* window;
    char padding1[0x8c];
    Window child;

    int initialize(int arg);
    int method(int arg);
};

int HelpCommand::method(int arg) {
    Rect rect;
    if (initialize(arg) == -1)
        return -1;

    GetClientRect(window, &rect);
    return (child.table->create(&child, 0, "Roblox", 0x50000000,
                                &rect, this, 1, 0) != 0) - 1;
}
