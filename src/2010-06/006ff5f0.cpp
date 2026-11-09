// from server: 65% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" char __cdecl sub_6cfb90(int, int, int, int, void*);

struct Slot {
    void* vtbl;
    char pad1[1];
    char flag;
    char pad2[2];
    int field8;
    int fieldC;
    int field10;
    char pad3[4];
    int field18;
    char pad4[0x1C];
    int field38;
    int field3C;
    int field40;
    int field44;
    void* ctor(int a, int b, int c, int d, int e);
};

void* Slot::ctor(int a, int b, int c, int d, int e)
{
    InterlockedIncrement((long volatile*)0xc007ac);
    this->vtbl = (void*)0xa0399c;
    this->flag = 1;
    this->field8 = 0;
    this->fieldC = *(int*)0xa54060;
    this->field10 = e;
    this->vtbl = (void*)0xa4b618;
    char r = sub_6cfb90(a, b, c, d, (void*)((char*)this + 0x20));
    this->field18 = r ? 0xbdff78 : 0;
    this->field38 = 0;
    this->field3C = 0;
    this->field40 = 0;
    this->field44 = 0;

    return this;
}
