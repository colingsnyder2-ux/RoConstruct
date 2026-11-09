// from server: 44% by atomic.potato
extern "C" void __stdcall f_72ad70(void*);
extern "C" void __stdcall f_69db90(void*);
extern "C" void __stdcall f_6c2820(void*);
extern "C" void __cdecl f_80a058(void*);

struct S {
    char pad0[4];
    void* field4;
    char pad8[0x14];
    char field1c[8];
    void destroy();
};

void S::destroy() {
    f_72ad70(this);
    f_69db90(&field1c);
    f_6c2820(&field1c);
    f_72ad70(this);
    f_80a058(field4);
    field4 = 0;
}
