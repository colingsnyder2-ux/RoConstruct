// from server: 83% by atomic.potato
extern "C" void __cdecl sub_90F222(int);
extern "C" void __cdecl sub_7F385A(void *);

struct S {
    void f();
    void *member_0C;
};

void S::f()
{
    void *p = member_0C;
    if (p != 0) {
        sub_90F222(*(int *)p);
        sub_7F385A(p);
    }
}
