// from server: 65% by atomic.potato
struct KeyframeSequenceW4PriorityEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __stdcall sub_5c6890(int*);

int KeyframeSequenceW4PriorityEnumDesc::lookup(int a) {
    int* p = sub_5c6890(&a + 1);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
