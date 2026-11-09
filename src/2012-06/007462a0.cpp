// from server: 90% by atomic.potato
extern "C" int __stdcall func_00827450(int);

struct S
{
    int value;
    int f(int);
};

int S::f(int arg)
{
    int result = func_00827450(arg) & value;
    return result != 0;
}
