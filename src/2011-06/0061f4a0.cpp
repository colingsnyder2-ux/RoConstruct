// from server: 56% by atomic.potato
extern "C" void __stdcall sub_00966fe0(void*, void*, int, int, int, int);
extern "C" void __stdcall sub_00640060(void*, int, void*);

struct S {
    char pad0[4];
    void* begin;
    void* end;
    void* cap;
    void insert(void* arg);
};

void S::insert(void* arg)
{
    char* b = (char*)begin;
    char* e = (char*)end;
    int capCount = cap ? (int)(((char*)cap - b) >> 3) : 0;
    int curCount = (int)((e - b) >> 3);
    if (curCount < capCount) {
        char tmp = 0;
        sub_00966fe0(e, arg, 1, *(int*)&tmp, (int)arg, (int)this);
        end = e + 8;
    } else {
        sub_00640060(this, 1, arg);
    }
}
