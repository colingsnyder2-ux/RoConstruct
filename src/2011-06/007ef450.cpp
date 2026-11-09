// from server: 61% by atomic.potato
struct SpatialFilter {
};

extern "C" void __stdcall sub_7b4cd0(void*, void*);

void __cdecl f(void* a) {
    void* local1;
    void* local2;
    sub_7b4cd0(&local1, &local2);
    void* p = local1;
    int i = 0;
    if (*(int*)((char*)p + 0x10) > 0) {
        do {
            void* e = *(void**)(*(char**)((char*)p + 0xc) + i * 4);
            f(e);
            i++;
        } while (i < *(int*)((char*)p + 0x10));
    }
}
