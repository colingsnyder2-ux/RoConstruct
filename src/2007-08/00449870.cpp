// from server: 100% by colin
// roc 2007-08 00449870  unit: CRobloxModule  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00449870
//
// 00449870  e8336f1e00           call 0x6307a8
// 00449875  e888661e00           call 0x62ff02
// 0044987a  8b4034               mov eax, dword ptr [eax + 0x34]
// 0044987d  c3                   ret

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD

struct Inner {
    char pad[0x34];
    int value;
};

extern "C" Inner* __cdecl sub_6307A8();
extern "C" Inner* __cdecl sub_62FF02();

struct CRobloxModule {
    int getValue();
};

int CRobloxModule::getValue()
{
    sub_6307A8();
    Inner* p = sub_62FF02();
    return p->value;
}
