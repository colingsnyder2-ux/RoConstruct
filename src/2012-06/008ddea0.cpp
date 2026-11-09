// from server: 65% by atomic.potato
extern "C" int __cdecl sub_983448(int, int, int, int, int);
extern "C" int __cdecl sub_983144(int, int);
extern "C" void* __cdecl sub_b22a20();

struct S
{
    void __cdecl f(int a);
};

void S::f(int a)
{
    if (sub_983448(a, 0, 0xd603ac, 0xdf71b4, 0) == 0)
    {
        void* p = sub_b22a20();
        sub_983144((int)&p, 0xcdd5c0);
    }
}
