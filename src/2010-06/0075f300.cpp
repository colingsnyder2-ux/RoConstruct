// from server: 34% by atomic.potato
struct RBX_Assembly {
    char pad[0x24];
    void* field_24;
    void* get();
};

struct Obj80 {
    char pad[0x80];
    unsigned char flag80;
};

struct ObjF4 {
    char pad[0x2c];
    void* field_2c;
};

struct Obj34 {
    char pad[0x8];
    unsigned char flag8;
    char pad2[0x78];
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;
    float fa0;
    float fa4;
    float fa8;
    float fac;
    float fb0;
};

struct ObjF4b {
    char pad[0x2c];
    Obj34* field_2c;
};

struct Obj80b {
    char pad[0x80];
    unsigned char flag80;
};

struct SleepStage {
    char pad[0x100];
    char field_100[0x40];
    char field_140[0x40];
    void func(void* arg);
};

extern "C" void* __stdcall sub_676790(void* p);
extern "C" void __stdcall sub_746780(void* p);
extern "C" void __stdcall sub_7637e0(void* p, void* arg);
extern "C" void __stdcall sub_676230(void* p, int n);
extern "C" void __stdcall sub_6760d0(void* p);
extern "C" void __stdcall sub_4362e0(void* p, void* a, void* b);

void SleepStage::func(void* arg) {
    void* a = sub_676790(arg);
    ObjF4* f4 = (ObjF4*)((char*)a + 0xf4);
    Obj34* o = (Obj34*)f4->field_2c;
    o = (Obj34*)((char*)o + 0x34);
    if (o != 0) {
        if (o->flag8 != 0) {
            sub_746780(o);
        }
        float x = o->f80;
        o->f84 = 0.0f;
        o->f88 = x;
        o->f8c = 0.0f;
        o->f90 = 0.0f;
        o->f94 = 0.0f;
        o->f98 = 0.0f;
    }
    void* b = sub_676790(arg);
    ObjF4b* f4b = (ObjF4b*)((char*)b + 0xf4);
    Obj34* o2 = f4b->field_2c;
    o2 = (Obj34*)((char*)o2 + 0x34);
    if (o2 != 0) {
        if (o2->flag8 != 0) {
            sub_746780(o2);
        }
        o2->f9c = 0.0f;
        o2->fa0 = 0.0f;
        o2->fa4 = 0.0f;
        o2->fa8 = 0.0f;
        o2->fac = 0.0f;
        o2->fb0 = 0.0f;
    }
    sub_7637e0(arg, this);
    void* c = sub_676790(arg);
    Obj80b* ob = (Obj80b*)((char*)c + 0x80);
    if (ob->flag80 != 0) {
        sub_676230(arg, 4);
        sub_4362e0(this->field_140, (void*)0, (void*)0);
    } else {
        sub_676230(arg, 2);
        sub_6760d0(arg);
        sub_4362e0(this->field_100, (void*)0, (void*)0);
    }
}
