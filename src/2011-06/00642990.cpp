// from server: 59% by atomic.potato
struct Workspace {
    char pad0[0x20];
    void* field20;
    char pad24[0x70];
    void* field94;
    char pad98[0x20];
    void* fieldb8;
    char padbc[0x5c];
    void* field118;
    Workspace(void*);
};

extern void* __stdcall cb_005cd260();
extern void cb_0063dd40(void*);

extern int g_cca4c8;

Workspace::Workspace(void* arg) {
    if (arg) {
        field94 = (void*)0xa9811c;
        fieldb8 = (void*)0xa98114;
    }
    cb_0063dd40(0);
    field20 = cb_005cd260();
    ++g_cca4c8;
    *(void**)this = (void*)0xa980a4;
    *(void**)((char*)this + 4) = (void*)0xa98098;
    *(void**)((char*)this + 0x18) = (void*)0xa9808c;
    *(void**)((char*)this + 0x1c) = (void*)0xa98080;
    *(void**)((char*)this + 0x90) = (void*)0xa98078;
    *(void**)((char*)this + 0xa0) = (void*)0xa98050;
    *(void**)((char*)this + 0xb4) = (void*)0xa98028;
    *(void**)((char*)this + 0x118) = (void*)0xa98010;
    void* p = field94;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x94) = (void*)0xa98008;
    void* r = field94;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0x90) = (void*)((char*)s - 0xac);
}
