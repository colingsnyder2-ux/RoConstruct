// from server: 72% by atomic.potato
struct S_func_007ab230 {
    char pad0[8];
    int m_x;
    int f();
};

struct S_func_007d7a40 {
    int f();
};

extern "C" int __stdcall sub_00512420(int, int);
extern "C" int __stdcall sub_006e8e60(int, float);

int S_func_007d7a40::f()
{
    S_func_007ab230 *p = (S_func_007ab230 *)this;
    int v = p->f();
    if (sub_00512420(v, 0))
    {
        float z = 0.0f;
        S_func_007ab230 *q = (S_func_007ab230 *)this;
        int w = q->f();
        sub_006e8e60(w, z);
    }
    return 0;
}
