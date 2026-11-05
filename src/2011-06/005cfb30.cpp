// from server: 83% by atomic.potato
struct W4JointTypeEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int index);
};

extern "C" int* __cdecl sub_5c4bd0(int index);

int W4JointTypeEnumDesc::get(int index)
{
    int* p = sub_5c4bd0(index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned int)v >= (unsigned int)count)
        return 0;
    return begin[v];
}
