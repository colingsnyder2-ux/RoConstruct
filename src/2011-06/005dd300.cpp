// from server: 65% by atomic.potato
struct W4VisualStyleEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __stdcall sub_5c7600(int*);

int W4VisualStyleEnumDesc::lookup(int a) {
    int* p = sub_5c7600(&a + 1);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
