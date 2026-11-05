// from server: 50% by colin
extern "C" long __stdcall InterlockedDecrement(long volatile*);
extern "C" long __stdcall InterlockedIncrement(long volatile*);

void __cdecl sub_62FC62(void*);

struct RefCounted {
    void** vtable;
    long refcount;
};

struct SceneManager {
    void __cdecl assignRange(RefCounted** first, RefCounted** last, RefCounted** dest);
};

void SceneManager::assignRange(RefCounted** first, RefCounted** last, RefCounted** dest) {
    if (first == last) return;
    do {
        RefCounted* old = *dest;
        RefCounted* src = *first;
        if (old != src) {
            if (old != 0) {
                if (InterlockedDecrement(&old->refcount) == 0) {
                    RefCounted* node = (RefCounted*)old->vtable[2];
                    while (node != 0) {
                        RefCounted* next = (RefCounted*)node->vtable;
                        void* vt = node->vtable;
                        ((void (__stdcall*)(void*))((void**)vt)[1])(node);
                        sub_62FC62(node);
                        node = next;
                    }
                    if (old != 0) {
                        void* vt = old->vtable;
                        ((void (__stdcall*)(void*, int))((void**)vt)[0])(old, 1);
                    }
                }
            }
            *dest = 0;
        }
        if (src != 0) {
            *dest = src;
            InterlockedIncrement(&src->refcount);
        }
        ++first;
        ++dest;
    } while (first != last);
}
