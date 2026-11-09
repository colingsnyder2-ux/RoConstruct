// from server: 100% by atomic.potato
extern "C" int __stdcall Function007e6640(unsigned int, unsigned int);

int __stdcall Function007e77c0(unsigned int value)
{
    return Function007e6640(value, 0x10) & 0x10;
}
