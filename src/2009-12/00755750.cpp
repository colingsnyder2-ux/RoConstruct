// from server: 83% by atomic.potato
struct S_func_00755750 {
    int __cdecl f(int);
};

extern "C" int __stdcall sub_007b7e50(int, int*);

int S_func_00755750::f(int value)
{
    return sub_007b7e50(value, &value);
}
