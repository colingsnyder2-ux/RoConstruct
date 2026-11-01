// from server: 65% by atomic.potato
struct S
{
    int f(void*, void*);
};

extern "C" void __cdecl sub_007f3b1e(int, int, int);
extern "C" int sub_00413120();

int S::f(void* a, void* b)
{
    int x = 0;
    if (a)
        x = *(int*)((char*)a + 4);
    sub_007f3b1e(*(int*)((char*)this + 4), x, (int)b);
    return ((int (__thiscall*)())(*(int**)(*(int**)((char*)0 + 0x94))))();
}
