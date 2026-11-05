// from server: 63% by atomic.potato
struct CRenderSettings {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __stdcall sub_4539C0(int* p);

int CRenderSettings::get(int index)
{
    int* p = sub_4539C0(&index + 1);
    int v = *p;
    if (v < 0)
        return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2))
        return 0;
    return begin[v];
}
