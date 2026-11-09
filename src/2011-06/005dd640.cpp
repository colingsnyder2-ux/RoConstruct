// from server: 82% by atomic.potato
struct GuiButtonW4StyleEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int* key);
};

extern "C" int* __cdecl sub_5c9b00(int* p);

int GuiButtonW4StyleEnumDesc::lookup(int* key)
{
    int* p = sub_5c9b00(key + 1);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)((end - begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
