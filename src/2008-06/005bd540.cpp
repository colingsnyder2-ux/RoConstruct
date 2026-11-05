// from server: 100% by king_originala
extern "C" void* __stdcall transform(void*, int);
extern "C" void __cdecl consume(void*);
extern const unsigned char property;

struct S {
    unsigned char padding0[0x13c];
    void* handle;
    unsigned char padding1[0x28];
    int state;

    void update();
    void notify(const void*);
    void f();
};

void S::f()
{
    if (handle)
        consume(transform(handle, 1));

    update();

    if (state != 0) {
        state = 0;
        notify(&property);
    }
}
