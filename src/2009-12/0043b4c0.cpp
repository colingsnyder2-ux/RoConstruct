// from server: 80% by atomic.potato
struct FacesItem {
    char pad0[0x24];
    void* slots[6];
    void sub_438200(void*);
    void f(void*);
};

void FacesItem::f(void* a) {
    sub_438200(a);
    for (int i = 0; i < 6; i++) {
        if (slots[i] != 0) {
            void** p = (void**)((char*)slots[i] + 0x10c);
            (*(void(**)(void*, void*))*p)(p, a);
        }
    }
}
