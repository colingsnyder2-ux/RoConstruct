// from server: 100% by atomic.potato
struct Elem {
    void* p;
    int pad[9];
};

struct Range {
    Elem* first;
    Elem* last;
};

void destroy_range(Elem* first, Elem* last) {
    while (first != last) {
        void** pp = (void**)first;
        void* obj = *pp;
        if (obj != 0) {
            void* fn = *(void**)obj;
            if (fn != 0) {
                typedef void (__cdecl *Fn)(void*, void*, int);
                ((Fn)fn)((void*)((char*)first + 8), (void*)((char*)first + 8), 2);
            }
            *pp = 0;
        }
        first = (Elem*)((char*)first + 0x28);
    }
}
