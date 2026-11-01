// from server: 100% by colin
struct G3D_Log {
    void construct(int a, int b, int c);
    char pad0[4];
    int field4;
    int field8;
    int fieldC;
    int field10;
};

extern "C" {
    void __stdcall sub_504660();
    void* __cdecl sub_500670(int size, int flag);
}

void G3D_Log::construct(int a, int b, int c) {
    sub_504660();
    field8 = a;
    fieldC = b;
    field10 = c;
    field4 = (int)sub_500670(a * b * c, 1);
}
