// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_8A9250(int, int);
extern "C" void __cdecl sub_982114(int);

void S::f()
{
    int* p = *(int**)((char*)this + 12);
    if (p)
    {
        sub_8A9250((int)p, p[3]);
        sub_982114((int)p);
    }
}
