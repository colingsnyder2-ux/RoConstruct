// from server: 90% by atomic.potato
typedef unsigned char BYTE;

extern "C" int __stdcall sub_006ec520(BYTE, int);

struct Primitive
{
    int f(int);
};

int Primitive::f(int value)
{
    return sub_006ec520(*(BYTE *)((char *)this + 0x101), value);
}
