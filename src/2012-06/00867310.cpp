// from server: 50% by atomic.potato
struct P_func_00751730 { void g(); };
struct S_func_00751730 {
    char pad[408];
    P_func_00751730* m_p;
    void f();
};

extern "C" void* __cdecl sub_0079aa30(void*);

struct S {
    char pad[0x20];
    void* m_field20;
    bool f(void* arg);
};

bool S::f(void* arg)
{
    if (sub_0079aa30(m_field20) == 0)
        return false;
    void* p = sub_0079aa30(m_field20);
    if (p == 0)
        return false;
    S_func_00751730* s = (S_func_00751730*)p;
    s->f();
    float* a = (float*)((char*)s + 0x24);
    float* b = (float*)arg;
    float dx = a[0] - b[0];
    float dy = a[1] - b[1];
    float dz = a[2] - b[2];
    float dist = dx*dx + dy*dy + dz*dz;
    dist = dist;
    float sq = 0.0f;
    (void)sq;
    float result = dist;
    {
        float tmp = result;
        result = tmp;
    }
    return result > *(double*)0xb5ef30;
}
