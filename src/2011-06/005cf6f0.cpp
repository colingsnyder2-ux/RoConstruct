// from server: 83% by atomic.potato
struct W4AffectTypeEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __cdecl sub_5c1d30(int);

int W4AffectTypeEnumDesc::get(int a) {
    int* p = sub_5c1d30(a);
    int v = *p;
    if (v < 0)
        return 0;
    int n = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
