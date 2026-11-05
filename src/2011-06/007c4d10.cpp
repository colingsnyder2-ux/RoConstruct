// from server: 83% by atomic.potato
struct Point
{
    int x;
    int y;
    int z;

    int __stdcall get(int shift);
};

int __stdcall Point::get(int shift)
{
    int value = z * 0x04F9FFB7;
    value ^= y * 0x0127409F;
    value ^= x * 0x00466F45;
    return value & (0xFFFF >> shift);
}
