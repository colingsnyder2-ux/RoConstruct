// from server: 100% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl sub_533260(byte*, byte*);

byte* __cdecl sub_533300(byte* a, byte* b)
{
    sub_533260(a, b);
    b += 8;
    sub_533260(a, b);
    return a;
}
