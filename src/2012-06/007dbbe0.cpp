// from server: 42% by atomic.potato
struct S
{
    void f(int);
};

extern "C" void __cdecl call_7db230(float, float, float);

void S::f(int value)
{
    float args[3];

    args[0] = *(float *)((char *)this + 0x80);
    args[1] = *(float *)((char *)this + 0x84);
    args[2] = *(float *)((char *)this + 0x88);
    call_7db230(args[0], args[1], args[2]);
}
