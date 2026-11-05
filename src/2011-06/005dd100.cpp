// from server: 80% by atomic.potato
struct EnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int*);
};

extern "C" int* __stdcall sub_5c6030(int*);

int EnumDesc::lookup(int* p) {
    int idx = *sub_5c6030(p + 1);
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
