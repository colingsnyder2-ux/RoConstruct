// from server: 58% by atomic.potato
struct EventDesc {
    char pad0[4];
    char pad1[4];
    void init(int);
    int sub_7447f0(int, int);
    int construct(int, int);
};

extern "C" void __stdcall sub_4c1670(void*, int);

int EventDesc::construct(int a, int b) {
    sub_4c1670((char*)this + 4, 1);
    *(int*)((char*)this + 4) = 0;
    sub_7447f0(a, b);
    return a;
}
