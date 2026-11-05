// from server: 100% by atomic.potato
struct S {
    void* vtbl;
    void* field4;
    void* ptr;
    void f();
};

extern "C" void __cdecl sub_80a304(void* p);

void S::f() {
    this->vtbl = (void*)0xa857d4;
    sub_80a304(this->ptr);
    this->ptr = 0;
}
