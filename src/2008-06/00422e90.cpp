// from server: 100% by king_originala
struct S {
    char padding[32];
    void* handle;
    void f(void* unused, long* result);
};

extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);
extern "C" S* __stdcall FromHandle(void*);

void S::f(void* unused, long* result)
{
    long (__stdcall *send)(void*, unsigned int, unsigned int, long) = SendMessageA;
    S* control = FromHandle((void*)send(handle, 0x110F, 0, 0));
    send(control->handle, 0xC5, 0x20, 0);
    *result = 0;
}
