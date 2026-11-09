// from server: 84% by atomic.potato
struct W4KeywordFilterType_EnumDesc {
    int lookup(int*);
    char pad[0x68];
    int* begin;
    int* end;
};

extern "C" int* __cdecl sub_5c4e80(int*);

int W4KeywordFilterType_EnumDesc::lookup(int* arg)
{
    int* p = sub_5c4e80(arg + 1);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
