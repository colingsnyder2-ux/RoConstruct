// from server: 30% by atomic.potato
extern "C" void __stdcall sub_8011e0(const char*);

struct S {
    void f(int);
};

void S::f(int) {
    sub_8011e0((const char*)0xcb3954);
    sub_8011e0((const char*)0xcd525c);
    *(int*)((char*)this + 0) = 0xab71b4;
    void (*fn)(void*, int) = (void (*)(void*, int))0x771b80;
    fn((char*)this + 0xc, 0);
}
