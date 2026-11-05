// from server: 35% by atomic.potato
extern "C" int __cdecl func_00618710();

struct Inner
{
    int m_value;
    int m_unused;
    Inner();
};

struct Outer
{
    int f(int);
};

int __stdcall sub_00467390(int, int);

int Outer::f(int a)
{
    Inner tmp;
    sub_00467390(*(int*)&tmp, a);
    if (*(int*)&tmp)
    {
        void** vt = *(void***)&tmp;
        ((void (__stdcall*)(int))vt[0])(1);
    }
    return (int)this;
}
