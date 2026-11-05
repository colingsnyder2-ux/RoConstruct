// from server: 15% by atomic.potato
extern "C" int __stdcall sub_7a7d84(int, int, int, int);

struct VerbBinder
{
    int f(int, int, int, int);
};

int VerbBinder::f(int a, int b, int c, int d)
{
    return sub_7a7d84(a, b, c, d);
}
