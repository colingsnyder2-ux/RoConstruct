// from server: 96% by atomic.potato
struct S {
    char pad[0xb8];
    void* arr[4];
    int count;
    bool f();
};

bool S::f() {
    int i = 0;
    if (count > 0) {
        void** p = arr;
        do {
            void* obj = *p;
            void** vt = *(void***)obj;
            bool (__thiscall *fn)(void*) = (bool (__thiscall *)(void*))vt[3];
            if (fn(obj))
                return true;
            i++;
            p++;
        } while (i < count);
    }
    return false;
}
