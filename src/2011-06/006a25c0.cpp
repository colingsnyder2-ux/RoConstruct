// from server: 47% by atomic.potato
struct Assembly {
    char pad0[0x14];
    int count;
    char pad1[4];
    void** items;
    void recurse(void*, void*, void*);
};

void Assembly::recurse(void* a, void* b, void* c) {
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)this + 0x18);
    fn(a, b);
    int i = 0;
    if (count > 0) {
        do {
            void* p = items[i];
            void* q;
            if (p == 0) {
                q = 0;
            } else {
                q = (char*)p - 8;
                if (q != 0) {
                    void* r = *(void**)((char*)q + 0x24);
                    if (r != 0) {
                        void* s = *(void**)((char*)r + 0x1c);
                        if (s != 0) {
                            s = (char*)s - 8;
                            if (s != 0) {
                                i++;
                                continue;
                            }
                        }
                    }
                }
            }
            recurse(a, b, q);
            i++;
        } while (i < count);
    }
}
