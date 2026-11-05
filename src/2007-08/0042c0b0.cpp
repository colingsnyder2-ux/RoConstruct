// from server: 100% by colin
struct S
{
    bool flag;
    void f();
};

void S::f()
{
    if (flag)
        flag = false;
}
