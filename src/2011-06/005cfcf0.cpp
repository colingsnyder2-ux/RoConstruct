// from server: 83% by atomic.potato
struct EnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __cdecl sub_5c6030(int);

int EnumDesc::get(int index) {
    int* p = sub_5c6030(index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
