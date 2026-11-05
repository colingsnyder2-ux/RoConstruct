// from server: 59% by atomic.potato
extern "C" int __cdecl sub_4ea160(int *);
extern "C" void __cdecl sub_4e1b00(int, int);

void f(int a, int b)
{
    int x;
    sub_4e1b00(b, sub_4ea160(&x));
}
