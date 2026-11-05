// from server: 68% by atomic.potato
struct IStage;

struct IPipelined
{
    char pad0[4];
    IPipelined* next;
    void removeFromStage(IStage* stage);
};

struct MechToAssemblyStage
{
    char pad0[8];
    IPipelined* field8;
    void func(IStage* stage);
};

extern "C" void __stdcall helper_7daf10(void*, void*);
extern "C" void __stdcall helper_7b8f20(void*, void*);

void MechToAssemblyStage::func(IStage* stage)
{
    IPipelined* p = field8;
    helper_7daf10((char*)stage + 8, (void*)0x7b8f40);
    helper_7b8f20(p, stage);
    p->removeFromStage(stage);
}
