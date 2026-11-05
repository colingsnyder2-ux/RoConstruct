// from server: 63% by atomic.potato
struct CRenderSettings {
    char pad0[0x68];
    int* begin;
    int* end;
    int getMode(int);
};

extern "C" int* __stdcall sub_453C00(int*);

int CRenderSettings::getMode(int a)
{
    int* p = sub_453C00(&a);
    int v = *p;
    if (v < 0)
        return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2))
        return 0;
    return begin[v];
}
