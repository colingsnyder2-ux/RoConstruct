// from server: 58% by atomic.potato
extern "C" int __cdecl sub_53F530(int);
extern "C" void __cdecl sub_533330(int, int, int, int);

void f(int a, int b, int c, int d)
{
    int value = sub_53F530(b);
    sub_533330(d, a, (int)&value, *(int*)value);
}
