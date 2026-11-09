// from server: 100% by colin
struct S {
    char pad[0x20];
    S* f(int);
};

extern "C" void __stdcall sub_599c50();
extern "C" void __cdecl sub_7a799a(void*);

S* S::f(int arg) {
    *(int*)((char*)this + 0x00) = 0xa00d94;
    *(int*)((char*)this + 0x04) = 0xa00d88;
    *(int*)((char*)this + 0x18) = 0xa00d7c;
    *(int*)((char*)this + 0x1c) = 0xa00d70;
    sub_599c50();
    if (arg & 1) {
        sub_7a799a(this);
    }
    return this;
}
