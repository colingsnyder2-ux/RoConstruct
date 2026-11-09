// from server: 90% by atomic.potato
struct ActionStation
{
    char padding_168[0x168];
    void f(int value);
};

extern "C" void __cdecl sub_637500(int);
extern "C" void __cdecl sub_677980(int, int);

void ActionStation::f(int value)
{
    sub_637500(value);
    sub_677980(*(int *)((char *)this + 0x168), 2);
}
