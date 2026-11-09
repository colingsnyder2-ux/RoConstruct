// from server: 90% by atomic.potato
extern "C" int __stdcall sub_6ec520(int, int);

struct Primitive
{
    int f(int);
};

int Primitive::f(int value)
{
    return sub_6ec520(value, *(unsigned char *)((char *)this + 0x100));
}
