// from server: 100% by atomic.potato
extern "C" int __cdecl sub_00632470();

struct S
{
    bool f();
};

bool S::f()
{
    int* p = (int*)sub_00632470();
    return p == (int*)this;
}
