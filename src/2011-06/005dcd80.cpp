// from server: 80% by atomic.potato
struct W4FontEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int* p);
};

extern "C" int* __stdcall sub_5c3900(int* p);

int W4FontEnumDesc::lookup(int* p) {
    int* r = sub_5c3900(p + 1);
    int v = *r;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
