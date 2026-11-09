// from server: 100% by colin
struct S {
    char pad[0x28];
    int f0;
    int f4;
    S* init(int*);
};

extern "C" void __stdcall sub_4136b0(int*);

S* S::init(int* p) {
    sub_4136b0(p);
    *(int*)this = 0x7a7af4;
    f0 = *(int*)((char*)p + 0x28);
    f4 = *(int*)((char*)p + 0x2c);
    return this;
}
