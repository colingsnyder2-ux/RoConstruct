// from server: 82% by colin
struct S {
    char pad[0x40];
    int f(int);
};

extern "C" void __stdcall sub_40DC90(int);

int S::f(int a) {
    sub_40DC90(a);
    *(int*)((char*)this + 0x3c) = 0xb43c34;
    *(int*)((char*)this + 0x00) = 0xb442d8;
    *(int*)((char*)this + 0x28) = 0xb442d0;
    *(int*)((char*)this + 0x3c) = 0xb442c0;
    return (int)this;
}
