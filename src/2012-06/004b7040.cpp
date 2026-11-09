// from server: 57% by Intel
extern "C" int __stdcall function(int a, int b);

struct S
{
    int f();
};

int S::f()
{
    int a = *(int*)((char*)this + 8);
    int b = *(int*)((char*)this + 4);
    if (a == 0)
        return function(0x80004003, 0);
    *(int*)a = *(int*)((char*)this + 0x10);
    return function(0, 0);
}
