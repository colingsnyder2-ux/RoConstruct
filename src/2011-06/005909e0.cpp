// from server: 65% by atomic.potato
struct W4ThreadPoolConfig {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __stdcall sub_58E770(int*);

int W4ThreadPoolConfig::get(int index)
{
    int* p = sub_58E770(&index);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
