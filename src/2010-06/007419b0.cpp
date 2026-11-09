// from server: 42% by atomic.potato
extern "C" void __cdecl sub_740f10(int, int, int, int);

void f(int **p)
{
    int a = **p;
    int b = 0;
    sub_740f10(a + 8, b, (int)&b, 0);
}
