// from server: 58% by atomic.potato
struct S {
    char pad[8];
    void* field8;
    char pad2[4];
    void* field10;
    void* f(void*);
};

extern "C" void* __stdcall rdbuf_impl(void*, void*);

void* S::f(void* arg)
{
    void* p = field10;
    if (*(void**)((char*)p + 8) == 0) {
        void* q = field8;
        void* r = *(void**)((char*)q + 4);
        return rdbuf_impl((char*)this + (int)r + 8, 0);
    } else {
        void* q = *(void**)((char*)p + 4);
        void* r = *(void**)q;
        void* s = *(void**)((char*)r + 8);
        void* t = field8;
        void* u = *(void**)((char*)t + 4);
        return rdbuf_impl((char*)this + (int)u + 8, s);
    }
}
