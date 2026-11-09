// from server: 31% by atomic.potato
extern "C" int rand();
extern float g_float_00bd0390;

struct P_00751730 { void g(); };
struct P_00751770 { void g(); };
struct P_00752120 { void g(); };

struct S_00751730 {
    char pad[408];
    P_00751730* m_p;
    void f();
};

struct S_00751770 {
    char pad[408];
    P_00751770* m_p;
    void f();
};

struct S_00752120 {
    char pad[408];
    P_00752120* m_p;
    void f();
};

struct Vec3 { float x, y, z; };

struct Obj {
    char pad0[0xc4];
    int m_field_c4;
    char pad1[0x1a4 - 0xc8];
    int m_field_1a4;
};

struct BallBlockContact {
    char pad0[4];
    char pad1[0x10 - 4];
    void* m_p10;
    char pad2[0x18 - 0x14];
    float m_f18;
    char pad3[0x1a4 - 0x1c];
    int m_field_1a4;

    void func_0082fdf0(Obj* a, Obj* b);
};

void S_00751730::f() { m_p->g(); }
void S_00751770::f() { m_p->g(); }
void S_00752120::f() { m_p->g(); }

extern "C" void* __stdcall func_00752120();
extern "C" void __stdcall func_00751730();
extern "C" void __stdcall func_00751770();
extern "C" void __stdcall func_0082fcf0(void*, void*);
extern "C" bool __stdcall func_0082f960(void*, void*);
extern "C" void __stdcall func_0082fa10(void*, void*, void*, float);

void BallBlockContact::func_0082fdf0(Obj* a, Obj* b)
{
    Obj* pa = (Obj*)func_00752120();
    Obj* pb = (Obj*)func_00752120();
    int ca = pa->m_field_1a4;
    int cb = pb->m_field_1a4;
    int ebp;
    if (ca > cb) {
        ebp = ((ca & 0xffffff0f) << 16) | (cb & 0xff0f);
    } else {
        ebp = ((cb & 0xffffff0f) << 16) | (ca & 0xff0f);
    }
    int r = rand();
    int rem = r % 3;
    int val = rem + ebp;
    int out;
    func_0082fcf0(&out, &val);
    int idx = out;
    if (idx == *(int*)((char*)this + 8)) return;
    Vec3 v1;
    func_00751730();
    v1 = *(Vec3*)0;
    Vec3 v2;
    func_00751730();
    v2 = *(Vec3*)0;
    float s1;
    func_00751770();
    s1 = 0.0f;
    float s2;
    func_00751770();
    s2 = 0.0f;
    float d1 = v1.x*v1.x + v1.y*v1.y + v1.z*v1.z;
    float d2 = v2.x*v2.x + v2.y*v2.y + v2.z*v2.z;
    Vec3 chosen;
    if (d1 > d2) chosen = v1; else chosen = v2;
    if (s2 >= s1) {
        if (func_0082f960(this, pa)) return;
        if (a->m_field_c4 > 1) return;
        float f = s1;
        func_0082fa10(m_p10, (void*)this, &chosen, (f - m_f18) * g_float_00bd0390);
    } else {
        if (func_0082f960(this, pb)) return;
        if (b->m_field_c4 > 1) return;
        float f = s2;
        func_0082fa10(m_p10, (void*)this, &chosen, (f - m_f18) * g_float_00bd0390);
    }
}
