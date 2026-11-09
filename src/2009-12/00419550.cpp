// from server: 83% by atomic.potato
typedef unsigned char byte;

extern "C" byte __cdecl func_00641090(byte);

int func_00419550(byte value)
{
    unsigned int x = func_00641090(value) ? 0xffffffffu : 0u;
    x &= 0x7fffbffbu;
    x += 0x80004005u;
    return (int)x;
}
