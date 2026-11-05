// from server: 41% by atomic.potato
struct S_func_00513360
{
    int f();
};

extern "C" int __stdcall S_func_00527d20(S_func_00513360*, int);

int S_func_00513360::f()
{
    if (*((int*)((char*)this + 0x128)) != 0)
        return 1;
    if (S_func_00527d20(this, 1) != 0)
        return 1;
    return 0;
}
