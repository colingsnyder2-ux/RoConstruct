// from server: 100% by colin
struct S_func_0057aa50 {
    void f(int a1, int a2);
};

struct S_func_00450d00 {
    int g();
};

struct S_func_0040e590 {
    int h();
};

struct RBX_ScoreHud {
    char pad[0x104];
    int field_104;
    int field_108;
    void func(int a1, int a2);
};

void RBX_ScoreHud::func(int a1, int a2)
{
    S_func_0057aa50* p = (S_func_0057aa50*)this;
    p->f(a1, a2);

    int v;
    if (a2 != 0) {
        S_func_00450d00* q = (S_func_00450d00*)a2;
        v = q->g();
    } else {
        v = 0;
    }
    field_104 = v;

    int w;
    if (a2 != 0) {
        S_func_0040e590* r = (S_func_0040e590*)a2;
        w = r->h();
    } else {
        w = 0;
    }
    field_108 = w;
}
