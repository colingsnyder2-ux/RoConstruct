// from server: 100% by Intel
struct S {
    int field0;
    int field4;
    void f(int);
};

void S::f(int)
{
    field4 = *reinterpret_cast<int*>(field4 + 4);
}
