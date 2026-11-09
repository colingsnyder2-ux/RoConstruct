// from server: 100% by colin
struct Inner {
    void method();
};

struct CSettingsExplorer {
    char pad[0x190];
    Inner field_190;
    void func();
};

extern "C" void* __cdecl sub_40F060();
extern "C" void __cdecl sub_447790();
extern "C" void __cdecl sub_683E40();

void CSettingsExplorer::func()
{
    Inner* p = (Inner*)sub_40F060();
    p->method();
    field_190.method();
}
