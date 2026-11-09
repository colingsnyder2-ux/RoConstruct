// from server: 69% by colin
struct W4ButtonEnumDesc {
    char pad[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __cdecl sub_5C2030(int* p);

int W4ButtonEnumDesc::get(int index)
{
    int* p = sub_5C2030(&index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned int)v >= (unsigned int)count)
        return 0;
    return begin[v];
}
