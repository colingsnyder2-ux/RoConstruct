// from server: 26% by atomic.potato
struct P_func_0066cae0 { void g(); };
struct S_func_0066cae0 {
    char pad[360];
    P_func_0066cae0* m_p;
    void f();
};

struct Vec3 { float x, y, z; };

extern "C" void* __stdcall sub_680260(int);
extern "C" int __stdcall sub_78c310(void*, int, void*);
extern "C" void __stdcall sub_78c0e0(void*, void*);
extern "C" void* __stdcall sub_67e1d0();
extern "C" void __stdcall sub_6869b0(void*, void*);
extern "C" void __stdcall sub_67e8c0(void*, void*);

struct RBX_ScriptMouseCommand {
    char pad0[0x28];
    int m_field28;
    void func(int a, int b);
};

void RBX_ScriptMouseCommand::func(int a, int b)
{
    Vec3 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    void* p = sub_680260(m_field28);
    if (p == 0) return;
    if (sub_78c310(&v, 0, (void*)b) != 0) return;
    Vec3 w;
    sub_78c0e0(&w, (void*)b);
    void* q = sub_67e1d0();
    Vec3* src;
    if (q != 0) {
        sub_6869b0(q, 0);
        src = (Vec3*)((char*)q + 0x24);
    } else {
        src = &w;
    }
    v.x = src->x;
    v.y = src->y;
    v.z = src->z;
    if (a != 0) {
        sub_6869b0(p, &v);
    } else {
        sub_67e8c0(p, &v);
    }
}
