// from server: 58% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" void __cdecl sub_515860();

struct S {
    void* vfptr0;
    char pad4;
    char flag5;
    char pad6[2];
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    char pad1C[4];
    char buf20[0x18];
    int field38;
    int field3C;
    int field40;
    int field44;
    void ctor(int a, int b, int c, int d, int e);
};

void S::ctor(int a, int b, int c, int d, int e)
{
    InterlockedIncrement((long*)0xb7a224);
    this->vfptr0 = (void*)0x9a2cc4;
    this->flag5 = 1;
    this->field8 = 0;
    this->fieldC = *(int*)0x9efd3c;
    this->field10 = a;
    int tmp[4];
    tmp[0] = b;
    tmp[1] = c;
    tmp[2] = d;
    tmp[3] = e;
    this->vfptr0 = (void*)0x9b4f94;
    sub_515860();
    this->field18 = 0xb46aa8;
    this->field38 = 0;
    this->field3C = 0;
    this->field40 = 0;
    this->field44 = 0;
}
