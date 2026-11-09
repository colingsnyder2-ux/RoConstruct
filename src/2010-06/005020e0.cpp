// from server: 46% by atomic.potato
extern "C" void* __stdcall Alloc(unsigned int);
extern "C" void __stdcall Free(void*);

struct ClientReplicator {
    char pad0[0x10];
    int count;
    bool Init(int a, int b);
};

bool ClientReplicator::Init(int a, int b) {
    unsigned int c = (unsigned int)count;
    unsigned int q = (unsigned int)(((unsigned long long)c * 0xa0a0a0a1ULL) >> 32);
    int n = (int)(q >> 8);
    void* p = Alloc(c);
    int* arr = (int*)p;
    if (arr == 0) {
        return false;
    }
    int* items = (int*)Alloc((unsigned int)(n * 4));
    if (items == 0) {
        Free(arr);
        return false;
    }
    int i = 0;
    if (n > 0) {
        int* cur = arr;
        do {
            *(int*)((char*)cur + 0x194) = (int)items;
            items[i] = (int)cur;
            i++;
            cur = (int*)((char*)cur + 0x198);
        } while (i < n);
    }
    *(int*)((char*)items + 4) = n;
    *(int*)((char*)items + 0xc) = *(int*)((char*)this + 0);
    *(int*)((char*)items + 0x10) = b;
    return true;
}
