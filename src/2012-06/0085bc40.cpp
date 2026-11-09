// from server: 45% by atomic.potato
struct S {
    char pad[8];
    void* field8;
    void* fieldC;
    void __cdecl rdbuf(void*);
};

void S::rdbuf(void* p) {
    void* a = fieldC;
    if (*(void**)((char*)a + 8) == 0) {
        void* b = field8;
        void* d = *(void**)((char*)b + 4);
        void* self = (char*)this + 8;
        void* arg = 0;
        ((void (__stdcall*)(void*, void*))*(void**)0xb223f4)((char*)d + (int)self, arg);
    } else {
        void* b = *(void**)((char*)a + 4);
        void* d = *(void**)b;
        void* e = *(void**)((char*)d + 8);
        void* f = field8;
        void* g = *(void**)((char*)f + 4);
        void* self = (char*)this + 8;
        ((void (__stdcall*)(void*, void*))*(void**)0xb223f4)((char*)g + (int)self, e);
    }
}
