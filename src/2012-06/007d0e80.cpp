// from server: 80% by atomic.potato
extern "C" int __cdecl sub_798700(int);

struct S
{
    int value;
    int (__thiscall *func)(S *, int);
    void f();
};

void S::f()
{
    int result = sub_798700(*(int *)((char *)this + 0x38));
    if (result)
        ((int (__thiscall *)(S *, int))(*(int **)(*(int **)this + 0x58)))(this, result);
}
