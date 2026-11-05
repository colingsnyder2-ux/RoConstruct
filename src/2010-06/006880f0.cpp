// from server: 29% by atomic.potato
struct S {
    int f(void*, void*, int);
};
int S::f(void* a, void* b, int c) {
    if (a) {
        void* d = *(void**)((char*)a + 0x38);
        int e = *(int*)((char*)d + 0x38);
        int f = c - 0x1c;
        *(int*)((char*)d + 0x38) = e + f;
        ((char*)b)[4] = 0;
        ((char*)b)[5] = 0;
        return 0;
    } else {
        void* d = *(void**)((char*)a + 0x38);
        int e = *(int*)((char*)d + 0x38);
        int f = c - 0x1c;
        *(int*)((char*)d + 0x38) = e + f;
        ((char*)b)[4] = 0;
        ((char*)b)[5] = 0;
        return 0;
    }
}
