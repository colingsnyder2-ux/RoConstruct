// from server: 84% by atomic.potato
struct CRenderSettings {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __cdecl sub_453C90(int*);

int CRenderSettings::get(int index)
{
    int v = *sub_453C90((int*)(index + 4));
    if (v < 0)
        return 0;
    int count = end - begin;
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
