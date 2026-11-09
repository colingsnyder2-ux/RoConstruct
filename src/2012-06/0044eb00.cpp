// from server: 69% by tester
struct S {
    char pad[0x40];
    int f(int);
};

void sub_44D970(void*, int);

int S::f(int a) {
    sub_44D970(this, a);
    *(int*)((char*)this + 0x3c) = 0xb43c34;
    *(int*)((char*)this) = 0xb531ec;
    *(int*)((char*)this + 0x28) = 0xb531e4;
    *(int*)((char*)this + 0x3c) = 0xb531d4;
    return (int)this;
}
