// from server: 0% by atomic.potato
struct Vec {
    char pad0[0xc];
    void* begin;
    void* end;
    void* cap;
    void* field14;
};

struct Gen {
    char pad0[8];
    Vec vec;
    void grow(int, int, int, int);
    void fill(void*, int, int, int, int, int);
    void* alloc(int, int);
};

extern "C" void __cdecl sub_423df0();
extern "C" void __cdecl sub_7a799a(void*);
extern "C" void* __cdecl sub_8ee9d0(int, int);
extern "C" void __cdecl sub_8f54c0(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_8f6850(void*, void*, int, int);

void Gen::grow(int a, int b, int c, int d) {
    int count;
    if (vec.begin == 0) {
        count = 0;
    } else {
        count = ((char*)vec.end - (char*)vec.begin) / 0x64;
    }
    if (d == 0) return;
    int cap = ((char*)vec.cap - (char*)vec.begin) / 0x64;
    int maxcap = 0x3c3c3c3;
    if (maxcap - cap < (unsigned)d) {
        sub_423df0();
    }
    int newcap = count + d;
    if ((unsigned)count < (unsigned)newcap) {
        int half = count >> 1;
        int lim = 0x3c3c3c3 - half;
        if ((unsigned)lim < (unsigned)count) {
            count = 0;
        } else {
            count += half;
        }
        if ((unsigned)count < (unsigned)newcap) {
            count = newcap;
        }
        void* mem = sub_8ee9d0(count, 0);
        int idx = ((char*)b - (char*)vec.begin) / 0x64;
        void* dst = (char*)mem + idx * 0x64;
        fill(dst, d, c, a, 0, 0);
        void* p1 = (char*)mem + (idx + d) * 0x64;
        fill(p1, (char*)vec.end - (char*)mem, 0, 0, 0, 0);
        void* p2 = (char*)mem + (idx + d) * 0x64;
        fill(p2, (char*)vec.end - (char*)mem, 0, 0, 0, 0);
        int total = ((char*)vec.end - (char*)vec.begin) / 0x64;
        d += total;
        if (vec.begin) {
            sub_7a799a(vec.begin);
        }
        vec.cap = (char*)mem + count * 0x64;
        vec.end = (char*)mem + d * 0x64;
        vec.begin = mem;
    }
}
