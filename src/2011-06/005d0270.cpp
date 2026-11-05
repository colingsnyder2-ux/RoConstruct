// from server: 83% by atomic.potato
extern "C" int* __cdecl sub_5C9DB0(int);

struct S {
    char pad_0[0x68];
    int* begin;
    int* end;
    int get(int key);
};

int S::get(int key) {
    int idx = *sub_5C9DB0(key);
    if (idx < 0) return 0;
    unsigned count = (unsigned)(end - begin);
    if ((unsigned)idx >= count) return 0;
    return begin[idx];
}
