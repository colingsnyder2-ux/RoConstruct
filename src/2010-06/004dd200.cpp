// from server: 89% by atomic.potato
extern "C" void* __stdcall sub_B94F78(unsigned int);
extern "C" void __cdecl sub_7A8E26(void*, void*, unsigned int);

struct S {
    unsigned int size;
    char pad[8];
    void* ptr;
    void alloc(void** out);
};

void S::alloc(void** out) {
    unsigned int n = (this->size + 7) >> 3;
    void* p = sub_B94F78(n);
    *out = p;
    unsigned int m = (this->size + 7) >> 3;
    sub_7A8E26(p, this->ptr, m);
}
