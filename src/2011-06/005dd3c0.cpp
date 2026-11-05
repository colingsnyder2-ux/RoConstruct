// from server: 78% by atomic.potato
struct W4SurfaceTypeEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int* p);
};

extern "C" int* __stdcall sub_5c7e10(int* p);

int W4SurfaceTypeEnumDesc::get(int* p)
{
    int* r = sub_5c7e10(p + 1);
    int v = *r;
    if (v < 0)
        return 0;
    int n = (int)((end - begin) >> 2);
    if ((unsigned)v >= (unsigned)n)
        return 0;
    return begin[v];
}
