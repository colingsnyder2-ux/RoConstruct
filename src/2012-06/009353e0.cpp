// from server: 71% by atomic.potato
struct RBX_BallCellContact {
    char pad[8];
    unsigned char field8;
    char pad2[8];
    int field14;
    int __cdecl getIndex(double value);
};

int RBX_BallCellContact::getIndex(double value)
{
    if (value == 0.0)
        return field14;

    unsigned int total = *(unsigned int*)&value + *((unsigned int*)&value + 1);
    unsigned int mask = (1u << field8) - 1u;
    mask |= 1u;
    unsigned int rem = total % mask;
    return field14 + (int)(rem << 5);
}
