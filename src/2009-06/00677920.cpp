// from server: 28% by atomic.potato
struct Hint {
    char pad0[0x14];
    int field14;
    int field18;
    int field1c;
    int field20;
    Hint(int);
};

extern "C" void __stdcall sub_5d2a60(int);
extern "C" int __stdcall sub_4d7520();

int g_a4a744;

Hint::Hint(int a) {
    sub_5d2a60(a);
    *(int*)((char*)this + 0x00) = 0x8c60bc;
    *(int*)((char*)this + 0x14) = 0x8c60ac;
    *(int*)((char*)this + 0x18) = 0x8c60a4;
    *(int*)((char*)this + 0x20) = 0x8c609c;
    field1c = sub_4d7520();
    g_a4a744++;
}
