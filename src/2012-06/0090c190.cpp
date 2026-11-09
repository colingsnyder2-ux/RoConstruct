// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_90bfb0(int*, int);
extern "C" void __cdecl sub_982114(int*);

void S::f()
{
    int* p = *(int**)((char*)this + 12);
    if (p)
    {
        sub_90bfb0(p, p[5]);
        sub_982114(p);
    }
}
