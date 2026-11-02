// from server: 57% by Intel
struct S
{
    int f();
};

struct T
{
    int v[2];
};

extern "C" int __cdecl sub_686620(S*, int);

int S::f()
{
    T* p = *(T**)((char*)this + 12);
    int (__cdecl *fn)(T*) = (int (__cdecl *)(T*))(*(int**)((char*)p + 336));
    int r = fn((T*)((char*)p + 336));
    return sub_686620((S*)r, 1);
}
