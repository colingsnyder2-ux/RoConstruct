// from server: 100% by atomic.potato
struct seg_00890000 {
    char pad0[16];
    int value;

    int f();
};

int seg_00890000::f()
{
    return value == 0x114;
}
