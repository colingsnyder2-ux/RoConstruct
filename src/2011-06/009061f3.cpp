// from server: 35% by atomic.potato
extern "C" void __cdecl sub_9092d5(int);

struct S_func_009061f3 {
    void f(int a, int b, float c, int d, float e, int f, int g);
};

void S_func_009061f3::f(int a, int b, float c, int d, float e, int f, int g)
{
    sub_9092d5(1);
    typedef void (__stdcall *Fn)(int, int, float, int, float, int, int);
    Fn fn = *(Fn*)0x00c9b6b8;
    fn(a, b, c, d, e, f, g);
}
