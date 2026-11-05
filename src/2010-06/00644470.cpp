// from server: 27% by atomic.potato
struct CStr {
    void destroy();
};

struct Inner {
    void* vtbl;
    void method(void* a, void* b);
};

struct Outer {
    char pad[0x1c];
    Inner* inner;
    void func(void* a, void* b);
};

void Outer::func(void* a, void* b)
{
    CStr tmp;
    Inner* in = this->inner;
    void* r = ((void* (__thiscall*)(void*, void*, void*))0)(0, 0, 0);
    (void)r;
    in->method(a, b);
    tmp.destroy();
}
