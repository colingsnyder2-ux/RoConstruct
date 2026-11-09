// from server: 71% by atomic.potato
struct Elem {
    void* p;
    char pad[0x1c];
};

struct VInstance {
    void __cdecl destroy_range(Elem* first, Elem* last);
};

void VInstance::destroy_range(Elem* first, Elem* last)
{
    if (first != last) {
        Elem* it = first;
        while (it != last) {
            void** p = (void**)it->p;
            if (p != 0) {
                void (*fn)(void*, void*, int) = (void (*)(void*, void*, int))p[0];
                if (fn != 0) {
                    fn(&it->p, &it->p, 2);
                }
                it->p = 0;
            }
            it = (Elem*)((char*)it + 0x20);
        }
    }
}
