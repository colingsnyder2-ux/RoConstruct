// from server: 83% by atomic.potato
struct W4PacketReliability_EnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int) const;
};

extern "C" int* __cdecl sub_4dd210(int);

int W4PacketReliability_EnumDesc::lookup(int a) const {
    int idx = *sub_4dd210(a);
    if (idx < 0)
        return 0;
    if ((unsigned)idx >= (unsigned)((end - begin)))
        return 0;
    return begin[idx];
}
