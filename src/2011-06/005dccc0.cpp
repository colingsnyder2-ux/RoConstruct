// from server: 65% by atomic.potato
struct TextServiceW4XAlignmentEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __stdcall sub_5c30f0(int* p);

int TextServiceW4XAlignmentEnumDesc::get(int index)
{
    int* p = sub_5c30f0(&index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
