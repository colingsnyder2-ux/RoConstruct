// from server: 83% by atomic.potato
struct TextServiceW4XAlignmentEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __cdecl sub_5c30f0(int);

int TextServiceW4XAlignmentEnumDesc::lookup(int a) {
    int* p = sub_5c30f0(a);
    int v = *p;
    if (v < 0) return 0;
    int n = (int)((end - begin));
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
