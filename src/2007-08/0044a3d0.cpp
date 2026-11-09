// from server: 100% by Yeetserama
// from server: 100% by colin
struct Target {
    virtual void invoke(int);
};

struct CRobloxModule {
    void f(Target*);
};

extern "C" void* __cdecl sub_407BE0();
extern "C" bool __cdecl sub_4061e0();

void CRobloxModule::f(Target* target)
{
    switch (*(int*)((char*)sub_407BE0() + 0xec)) {
    case 1:
        if (sub_4061e0())
            target->invoke(1);
        break;
    case 2:
        target->invoke(1);
        break;
    }
}
