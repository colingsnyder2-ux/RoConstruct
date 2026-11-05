// from server: 65% by atomic.potato
struct CRenderSettings {
    char pad0[0x68];
    int* begin;
    int* end;
    int getMaterialQuality(int index);
};

extern "C" int* __stdcall sub_453DB0(int* p);

int CRenderSettings::getMaterialQuality(int index) {
    int* p = sub_453DB0(&index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
