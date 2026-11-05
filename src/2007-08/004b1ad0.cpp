// from server: 57% by colin
struct VReplicator {
    char pad[0x108];
    double field_108;
    char pad2[0x1db4 - 0x110];
    unsigned char field_1db4;
    char pad3[0x1e0c - 0x1db5];
    int field_1e0c;
    char pad4[0x1e14 - 0x1e10];
    void* field_1e14;
    int field_1e18;
    int field_1e1c;
    bool method();
};

struct Arg0 {
    char data[0x30];
    Arg0();
    ~Arg0();
};

struct Arg1 {
    char data[0x30];
    Arg1();
    ~Arg1();
};

struct Arg2 {
    char data[0x30];
    Arg2();
    ~Arg2();
};

extern "C" {
    void __cdecl sub_457F30(Arg0* self, int a, int b);
    void __cdecl sub_457F90(Arg0* self);
    void* __cdecl sub_48E0D0(VReplicator* self);
    void __cdecl sub_4A4F50(Arg1* self, VReplicator* a, void* b);
    void __cdecl sub_4A4FA0(Arg1* self);
    void __cdecl sub_4A5000(Arg2* self, int a);
    void* __cdecl sub_4A6810(VReplicator* self);
    void __cdecl sub_4A9540(Arg2* self, void* a);
    void __cdecl sub_4AA0E0(void* self, Arg1* a, void* b, void* c);
    double __cdecl sub_4FFF30();
    void __cdecl sub_5A9130(void* self);
    void __cdecl sub_630A1E();
}

extern double dbl_79DBC8;

bool VReplicator::method() {
    if (field_1db4 == 0) {
        return false;
    }
    void* p = field_1e14;
    int (*fn)(void*, int, int) = *(int (**)(void*, int, int))(*(int*)p + 0x108);
    if (!fn(p, field_1e18, field_1e1c)) {
        return false;
    }
    Arg0 a0;
    sub_457F30(&a0, field_1e0c, 0);
    Arg1 a1;
    sub_4A4F50(&a1, this, field_1e14);
    void* r = sub_48E0D0(this);
    bool result = false;
    if (r) {
        sub_5A9130(*(void**)((char*)r + 0x27c));
        void* edi = sub_4A6810(this);
        if (edi) {
            double t = sub_4FFF30();
            double sum = field_108 + dbl_79DBC8;
            if (!(t > sum)) {
                edi = 0;
            } else {
                Arg2 a2;
                sub_4A5000(&a2, 1);
                sub_4A9540(&a2, edi);
                sub_4A5000(&a2, 2);
                field_108 = t;
            }
        }
        sub_4AA0E0(*(void**)((char*)r + 0x27c), &a1, &field_108, edi);
    }
    sub_4A4FA0(&a1);
    sub_457F90(&a0);
    return result;
}
