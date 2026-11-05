// from server: 65% by atomic.potato
struct W4JointTypeEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __stdcall sub_5c4bd0(int*);

int W4JointTypeEnumDesc::get(int a) {
    int* p = sub_5c4bd0((int*)((char*)&a + 4));
    int v = *p;
    if (v < 0)
        return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
