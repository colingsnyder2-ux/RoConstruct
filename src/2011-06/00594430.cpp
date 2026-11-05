// from server: 68% by atomic.potato
extern "C" void __cdecl helper(void*, void*, void*, void*);

struct S {
    char pad0[4];
    void* begin;
    void* end;
    void __cdecl erase(void* p);
};

void S::erase(void* p) {
    void* e = end;
    if ((char*)e - (char*)begin) {
        helper(begin, (char*)e - 8, this, p);
        end = (char*)end - 8;
    }
}
