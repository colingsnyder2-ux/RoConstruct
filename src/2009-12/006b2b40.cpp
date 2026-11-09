// from server: 88% by atomic.potato
extern "C" int __stdcall Function_71F670(int);

struct S
{
    int value;
    int f(int);
};

int S::f(int arg)
{
    int result = Function_71F670(arg) & value;
    return result ? 0 : -1;
}
