// from server: 20% by atomic.potato
extern "C" void* __stdcall make_desc_0059ab70(const char*, int);
extern "C" int __cdecl func_00618710();
extern "C" int __cdecl func_00618780();
extern "C" int __cdecl func_006187a0();
extern "C" int __cdecl func_005a5580();
extern "C" int __cdecl func_00594140();
extern "C" int __cdecl func_0067a200();

struct VSelection_BoundFuncDesc {
    char pad0[0x14];
    int field14;
    char pad18[0x24];
    int field3c;
    int field40;
    char pad44[0x40];
    int field84;

    void ctor(int a, int b, int c, int d, int e);
};

void VSelection_BoundFuncDesc::ctor(int a, int b, int c, int d, int e) {
    int* p = (int*)make_desc_0059ab70((const char*)a, b);
    ((void(__thiscall*)(void*, int*))func_0067a200)(this, p);
    this->field3c = c;
    this->field40 = d;
    *(int*)this = 0xa2a040;
    ((void(__cdecl*)(void*))func_00618780)((char*)this + 0x40);
    ++*(int*)0xc18314;
    this->field14 = func_00618710();
    ++*(int*)0xc18300;
    int r = func_005a5580();
    int s = ((int(__cdecl*)(int, int, void*))func_00594140)(e, r, (char*)this + 0x40);
    ((void(__thiscall*)(void*, int))func_006187a0)((char*)this + 0x14, s);
}
