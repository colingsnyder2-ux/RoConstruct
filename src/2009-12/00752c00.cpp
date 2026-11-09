// from server: 51% by atomic.potato
struct VSelectionBox_FactoryProduct
{
    void* vtable0;
    void* vtable4;
    char pad08[0x10];
    void* vtable18;
    void* vtable1c;
    void* field20;
    char pad24[0x70];
    void* vtable94;
    void* vtable98;

    VSelectionBox_FactoryProduct* construct(void* arg);
};

extern "C" void __stdcall sub_0075FE90(void*);
extern "C" void* __cdecl sub_00650E90();
extern int dword_B8FEDC;

VSelectionBox_FactoryProduct* VSelectionBox_FactoryProduct::construct(void* arg)
{
    sub_0075FE90(arg);
    vtable0 = (void*)0x9E4474;
    vtable4 = (void*)0x9E4468;
    vtable18 = (void*)0x9E445C;
    vtable1c = (void*)0x9E4454;
    vtable94 = (void*)0x9E4444;
    vtable98 = (void*)0x9E442C;
    field20 = sub_00650E90();
    dword_B8FEDC++;
    return this;
}
