// from server: 65% by atomic.potato
struct EThrottleEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int*);
    int get(int);
};

int EThrottleEnumDesc::get(int idx) {
    int* p = (int*)lookup(&idx);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
