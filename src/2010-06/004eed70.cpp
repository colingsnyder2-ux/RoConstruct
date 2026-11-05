// from server: 51% by atomic.potato
extern "C" int __cdecl sub_446e40(int);
extern "C" int __cdecl sub_4e1b00(int, int, int, int);

int f(int a, int b, int c, int d)
{
    int x = sub_446e40(a);
    int y = *(int *)x;
    return sub_4e1b00(d, (int)&y, y, b);
}
