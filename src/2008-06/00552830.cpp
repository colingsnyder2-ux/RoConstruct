// from server: 100% by king_originala
struct S_func_00442cd0
{
    char pad0[4];
    int m_x;
    int f();
};

struct S_func_0071f210
{
    int m_x;
    int f();
};

struct S
{
    void func_00552830(int, S_func_0071f210*);
    void func_00552860(int, int, int);
};

#pragma optimize("", off)
void S::func_00552830(int a, S_func_0071f210* p)
{
    func_00552860(a, ((S_func_00442cd0*)p)->f(), p->f());
}
