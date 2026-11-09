// from server: 83% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __cdecl sub_5c7350(int);

int S::f(int a) {
    int* p = sub_5c7350(a);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
