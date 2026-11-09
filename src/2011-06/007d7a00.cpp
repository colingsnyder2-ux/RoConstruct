// from server: 59% by atomic.potato
extern "C" int __cdecl sub_0077c9d0(int, int);

struct S
{
    int f();
};

int S::f()
{
    return sub_0077c9d0(0, 0) ? -1 : 0;
}
