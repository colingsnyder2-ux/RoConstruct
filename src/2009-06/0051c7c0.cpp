// from server: 39% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" int __cdecl sub_5FCFC0(int, int, int, int);

struct S {
    void* vtbl;
    char pad1[4];
    char flag;
    char pad2[2];
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    char pad3[0x1C];
    int field38;
    int field3C;
    int field40;
    int field44;
    void* ctor(int, int, int, int, int);
};

void* S::ctor(int a1, int a2, int a3, int a4, int a5)
{
    InterlockedIncrement((long*)0x00a3a1bc);
    this->vtbl = (void*)0x008afff4;
    this->flag = 1;
    this->field8 = 0;
    this->fieldC = *(int*)0x008ef840;
    this->field10 = a5;
    int r = sub_5FCFC0(a1, a2, a3, a4);
    this->vtbl = (void*)0x008c9e50;
    this->field18 = r ? 0x009faa20 : 0;
    this->field38 = 0;
    this->field3C = 0;
    this->field40 = 0;
    this->field44 = 0;

    return this;
}
