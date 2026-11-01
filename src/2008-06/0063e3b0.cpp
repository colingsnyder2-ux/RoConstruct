// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstructor)(String *, const char *);
extern const char GunWaitCursor[];
extern const char GunCursor[];

struct String {
    char storage[28];
    String(const char *);
};

inline String::String(const char *text) {
    stringConstructor(this, text);
}

struct SlingshotTool {
    char pad[0x28];
    int field28;
    int field2c;
    String func();
};

String SlingshotTool::func() {
    volatile int state = 0;
    if (field2c && field28 > 10)
        return String(GunWaitCursor);
    return String(GunCursor);
}
