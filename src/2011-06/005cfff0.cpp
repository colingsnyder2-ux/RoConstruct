// from server: 83% by atomic.potato
struct PartInstance_W4FormFactor_EnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __cdecl sub_5C80C0(int);

int PartInstance_W4FormFactor_EnumDesc::lookup(int a) {
    int* p = sub_5C80C0(a);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
