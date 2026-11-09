// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Caller { void sub_557920(int); };

struct CRobloxWnd {
    char pad[0x68];
    int field_68;
    char pad2[0x94 - 0x6c];
    void* field_94;
    char pad3[0xa4 - 0x98];
    int field_a4;
    void func();
};

extern void* g_8bd0d8;
extern void sub_557920();

void CRobloxWnd::func() {
    void* p = field_94;
    if (g_8bd0d8 != p) {
        (*(void (__thiscall**)(void*))((*(int*)p) + 0x98))(p);
        g_8bd0d8 = p;
    }
    ((struct Caller*)(void*)field_68)->sub_557920(field_a4);
}
