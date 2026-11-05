// from server: 65% by atomic.potato
struct CRenderSettings {
    char pad0[0x68];
    int* begin;
    int* end;
    int getMode(int);
};

extern "C" int* __stdcall sub_453AE0(int*);

int CRenderSettings::getMode(int index)
{
    int* p = sub_453AE0(&index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
