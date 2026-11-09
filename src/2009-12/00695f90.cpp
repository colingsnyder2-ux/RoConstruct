// from server: 62% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_6de490(int);

int S::f()
{
    int *p = *reinterpret_cast<int **>(
        reinterpret_cast<char *>(this) + 0x120);
    int v = reinterpret_cast<int (__thiscall *)(int *, int *)>(p[1])(
        reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x120),
        reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x130));
    return sub_6de490(v);
}
