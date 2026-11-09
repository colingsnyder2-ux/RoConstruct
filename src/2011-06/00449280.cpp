// from server: 80% by atomic.potato
struct Vector3Item {
    char pad0[0x1c];
    void* items[3];
    void destroy(void*);
};

void __stdcall sub_447410(void*);

void Vector3Item::destroy(void* arg) {
    sub_447410(arg);
    for (int i = 0; i < 3; i++) {
        if (items[i]) {
            void** p = (void**)((char*)items[i] + 0x10c);
            void* obj = *p;
            void (*fn)(void*) = *(void (**)(void*))obj;
            fn(arg);
        }
    }
}
