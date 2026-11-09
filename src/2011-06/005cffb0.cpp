// from server: 83% by atomic.potato
struct W4SurfaceTypeEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int) const;
};

extern "C" int* __cdecl sub_5c7e10(int);

int W4SurfaceTypeEnumDesc::lookup(int a) const {
    int idx = *sub_5c7e10(a);
    if (idx < 0)
        return 0;
    if ((unsigned)idx >= (unsigned)((end - begin)))
        return 0;
    return begin[idx];
}
