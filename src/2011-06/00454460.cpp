// from server: 83% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __cdecl sub_453C90(int);

int S::get(int idx) {
    int* p = sub_453C90(idx);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
