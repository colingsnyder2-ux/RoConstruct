// from server: 84% by atomic.potato
struct Job {
    char pad[0x68];
    int* begin;
    int* end;
    int getIndex(int);
};

extern "C" int* __cdecl sub_58e890(int*);

int Job::getIndex(int a) {
    int* p = sub_58e890((int*)((char*)a + 4));
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
