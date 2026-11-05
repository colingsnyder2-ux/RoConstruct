// from server: 100% by king_originala
struct S_func_00645830 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct Stage {
    void f(S_func_00645830* object);
};

struct S {
    char pad0[8];
    Stage* stage;
    void f(S_func_00645830* object);
};

void S::f(S_func_00645830* object)
{
    object->f((int)this);
    stage->f(object);
}
