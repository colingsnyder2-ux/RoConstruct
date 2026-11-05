// from server: 17% by atomic.potato
extern "C" void* __stdcall make_desc_005b3f50(const char*, int);
extern "C" int __cdecl func_00618710();
extern "C" int __cdecl func_00618780();
extern "C" int __cdecl func_006187a0();
extern "C" void __cdecl func_0067a200();
extern "C" void __cdecl func_00594140();
extern "C" void __cdecl func_005a5740();

struct VDebrisService_BoundFuncDesc {
    void construct(int a, int b, int c, int d, int e);
};

void VDebrisService_BoundFuncDesc::construct(int a, int b, int c, int d, int e) {
    char pad0[0x14];
    int field14;
    char pad1[0x24];
    int field38;
    int field3c;
    char pad2[0x40];
    int field40;
    char pad3[0x44];
    int field44;

    void* p = make_desc_005b3f50((const char*)a, b);
    func_0067a200();
    field38 = c;
    field3c = d;
    func_00618780();
    field14 = func_00618710();
    func_005a5740();
    func_00594140();
    func_006187a0();
}
