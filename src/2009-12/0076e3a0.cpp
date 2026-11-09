// from server: 77% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void* __stdcall sub_76E0A0(void*, void*, void*);

struct VGuiBase {
    void* vftable0;
    char pad0[4];
    char flag5;
    char pad1[2];
    int field8;
    int fieldC;
    int field10;
    char pad2[4];
    int field18;
    char pad3[0x1C];
    int field38;
    int field3C;
    int field40;
    int field44;
    void* construct(void* a, void* b, void* c);
};

void* VGuiBase::construct(void* a, void* b, void* c)
{
    InterlockedIncrement((long*)0x00b7a224);
    this->vftable0 = (void*)0x009a2cc4;
    this->flag5 = 1;
    this->field8 = 0;
    this->fieldC = *(int*)0x009efd3c;
    this->field10 = (int)c;
    this->vftable0 = (void*)0x009ae384;
    this->field18 = 0;
    sub_76E0A0(&this->field18, a, b);
    this->field38 = 0;
    this->field3C = 0;
    this->field40 = 0;
    this->field44 = 0;

    return this;
}
