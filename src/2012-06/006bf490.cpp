// from server: 3% by 41k
extern "C" int __stdcall getLocalScope();

struct S
{
    int f();
};

int S::f()
{
    int result = getLocalScope();
    return result;
}
