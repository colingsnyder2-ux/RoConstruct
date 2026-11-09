// from server: 69% by atomic.potato
extern "C" int __cdecl f4fd680(int);
extern "C" int __cdecl f5323b0(int, int, int*);

int f005408c0(int a, int b, int c, int d)
{
    int *t = (int *)f4fd680(b);
    return f5323b0(d, a, t);
}
