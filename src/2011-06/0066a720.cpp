// from server: 83% by atomic.potato
extern "C" void* __stdcall sub_5c2030(void*);
extern "C" void __stdcall sub_66a110(void*, void*);

struct S_0066a720 {
    char pad_0[0x24];
    int f_24;
    void method(void* a, void* b);
};

void S_0066a720::method(void* a, void* b) {
    int* p = (int*)a;
    int off = p ? (int)((char*)p - 0x1c) : 0;
    int* base = (int*)(f_24 + off);
    void* r = sub_5c2030(*(void**)((char*)b + 4));
    sub_66a110(base, *(void**)r);
}
