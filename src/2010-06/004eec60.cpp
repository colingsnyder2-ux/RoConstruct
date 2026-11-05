// from server: 69% by atomic.potato
extern "C" int __cdecl Function4ed830(int);
extern "C" int __cdecl Function4e1680(int, int, int);

int Function4eec60(int a, int b, int c, int d)
{
    int value = Function4ed830(b);
    return Function4e1680(d, value, a);
}
