// from server: 69% by colin
struct S {
    char pad[0x24];
    int f(int);
};

extern "C" void sub_5b1c80(void*, int);

int S::f(int a) {
    sub_5b1c80(this, a);
    *(int*)((char*)this + 0x20) = 0xb43c34;
    *(int*)((char*)this) = 0xb7e604;
    *(int*)((char*)this + 0xc) = 0xb7e5fc;
    *(int*)((char*)this + 0x20) = 0xb7e5ec;
    return (int)this;
}
