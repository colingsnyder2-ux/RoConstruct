// from server: 43% by atomic.potato
struct Sub {
    char pad[0x38];
    double d;
};

struct VFaces {
    void* p0;
    void* p4;
    void* p8;
    void* pC;
    int f10;
    char pad14[4];
    int f18;
    int f1C;
    int f20;
    int f24;
    double f28;
    double f30;
    double f38;
    double f40;
    char f48;
    char pad49[7];
    Sub sub50;
};

extern "C" void* __stdcall sub_7548B0(int);
extern "C" void __stdcall sub_62D950(Sub*);
extern double g_b78230;

VFaces* __fastcall ctor(VFaces* self, int);

VFaces* __fastcall ctor(VFaces* self, int)
{
    void* v;
    self->f10 = 0;
    v = sub_7548B0(0);
    self->p0 = v;
    self->p4 = v;
    self->pC = v;
    self->p8 = v;
    self->f18 = 5;
    self->f1C = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = g_b78230;
    self->f48 = 1;
    self->f30 = 0.0;
    self->f38 = 0.0;
    self->f40 = 0.0;
    sub_62D950(&self->sub50);
    self->sub50.d = 0.0;
    return self;
}
