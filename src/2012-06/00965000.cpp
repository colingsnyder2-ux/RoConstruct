// from server: 31% by atomic.potato
extern "C" int __stdcall sub_00964a50(int);

struct S_func_00965000
{
    int f(int);
};

int S_func_00965000::f(int value)
{
    sub_00964a50(value);
    return 0;
}
