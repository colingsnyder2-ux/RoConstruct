// from server: 77% by atomic.potato
extern "C" int __cdecl sub_4ed680(int);
extern "C" int __cdecl sub_4e15b0(int, int, int);

int sub_4eeba0(int a, int b, int c, int d)
{
    int v[2];
    int *p = (int *)sub_4ed680(a);
    v[0] = p[0];
    v[1] = p[1];
    return sub_4e15b0(b, c, (int)v);
}
