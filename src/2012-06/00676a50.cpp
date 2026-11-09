// from server: 9% by atomic.potato
extern "C" int __stdcall sub_972290(int, const char*);
extern "C" int (__stdcall *g_assertHook)(int, const char*, const char*);

struct IndexArray {
    char pad0[4];
    int count;
    void removeAt(int*);
};

struct XVGfxBinding {
    void removeItem(int*);
};

void XVGfxBinding::removeItem(int* item) {
    if (*(unsigned char*)0xe580b3 != 0 && item == 0) {
        if (g_assertHook != 0) {
            if (g_assertHook(0x3c, (const char*)0xb8d8b8, (const char*)0xb4e9a4)) {
                goto skip1;
            }
        }
        sub_972290(*(unsigned char*)0xe580b3, (const char*)0xb8d850);
    }
skip1:
    if (*(unsigned char*)0xe580b3 != 0 && item[2] != -1) {
        if (g_assertHook != 0) {
            if (g_assertHook(0x3d, (const char*)0xb8d8b8, (const char*)0xb8d838)) {
                goto skip2;
            }
        }
        sub_972290(*(unsigned char*)0xe580b3, (const char*)0xb8d7c0);
    }
skip2:
    int v = *(int*)((char*)this + 4);
    item[2] = v;
    ((IndexArray*)this)->removeAt(item);
}
