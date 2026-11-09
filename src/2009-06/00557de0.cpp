// from server: 45% by atomic.potato
extern "C" int __stdcall sub_556B00(int, int, int);

int __stdcall sub_557DE0(short a, short b, int c, int d)
{
    return sub_556B00(c, d, *(int*)&b);
}
