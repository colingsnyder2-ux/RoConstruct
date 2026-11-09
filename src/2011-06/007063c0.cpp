// from server: 34% by colin
struct Callback {
    void* field0;
    int field4;
    int field8;
    void __cdecl invoke(void* arg);
};

void Callback::invoke(void* arg) {
    void* local;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))field0;
    fn((char*)this + field4 + field8, arg);
}
