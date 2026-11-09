// from server: 84% by atomic.potato
struct CRenderSettings {
    char pad_0000[0x68];
    int* begin;
    int* end;
    int getQualityLevel(int* p);
};

extern "C" int* __cdecl sub_453D20(int* p);

int CRenderSettings::getQualityLevel(int* p)
{
    int v = *sub_453D20(p + 1);
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned int)v >= (unsigned int)count)
        return 0;
    return begin[v];
}
