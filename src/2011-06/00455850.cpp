// from server: 63% by atomic.potato
struct CRenderSettings {
    char pad[0x68];
    int* begin;
    int* end;

    int GetBevelMode(int index);
};

extern "C" int* __stdcall sub_453B70(int*);

int CRenderSettings::GetBevelMode(int index) {
    int* p = sub_453B70(&index);
    int v = *p;
    if (v < 0)
        return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2))
        return 0;
    return begin[v];
}
