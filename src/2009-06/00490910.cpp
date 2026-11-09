// from server: 40% by atomic.potato
struct S {
    char pad0[4];
    int field4;
    char pad8[0x80];
    char field88[0x18];
    char fieldA0[0x18];
    short fieldB8;
    short fieldBA;
    short fieldBC;
    short fieldBE;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    char fieldCC[0x18];
    S(int a, int b, int c);
};

extern "C" void* __stdcall sub_718a38(int);
extern "C" void __stdcall sub_89e490(int, int);

S::S(int a, int b, int c)
{
    int* p;
    this->field4 = *(int*)((char*)a + 0x874);
    *(int*)this = 0x8bfa84;
    sub_89e490(2, 1);
    p = (int*)sub_718a38(4);
    if (p) *p = (int)(this->field88);
    else *(int*)(this->field88) = 0;
    *(int*)(this->field88 + 0xc) = 0;
    *(int*)(this->field88 + 0x10) = 0;
    *(int*)(this->field88 + 0x14) = 0;
    p = (int*)sub_718a38(4);
    if (p) *p = (int)(this->fieldA0);
    else *(int*)(this->fieldA0) = 0;
    *(int*)(this->fieldA0 + 0xc) = 0;
    *(int*)(this->fieldA0 + 0x10) = 0;
    *(int*)(this->fieldA0 + 0x14) = 0;
    this->fieldB8 = 0;
    this->fieldBA = 0;
    this->fieldBC = 0;
    this->fieldBE = 0;
    this->fieldC0 = b;
    this->fieldC4 = c;
    this->fieldC8 = a;
    p = (int*)sub_718a38(4);
    if (p) *p = (int)(this->fieldCC);
    else *(int*)(this->fieldCC) = 0;
    *(int*)(this->fieldCC + 0xc) = 0;
    *(int*)(this->fieldCC + 0x10) = 0;
    *(int*)(this->fieldCC + 0x14) = 0;
}
