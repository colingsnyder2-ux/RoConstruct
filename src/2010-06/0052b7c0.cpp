// from server: 57% by atomic.potato
struct Vbad_lexical_cast_error_info_injector {
    void (__stdcall *vtable_0x28)(void);
    char pad_0x04[0x10];
    void (__stdcall *vtable_0x14)(void);
    void *field_0x18;
    char pad_0x1c[0x0c];
    void (__stdcall *vtable_0x28_2)(void);
    void destroy();
};

extern "C" void __stdcall bad_cast_dtor(void *);
extern "C" void __stdcall boost_function_dtor(void *);

void Vbad_lexical_cast_error_info_injector::destroy()
{
    *(void **)((char *)this + 0x28) = (void *)0xa00920;
    *(void **)this = (void *)0xa1ed44;
    *(void **)((char *)this + 0x14) = (void *)0xa1ed3c;
    *(void **)((char *)this + 0x14) = (void *)0xa00968;

    void *p = *(void **)((char *)this + 0x18);
    if (p != 0) {
        void **vt = *(void ***)p;
        void (__stdcall *fn)(void *) = (void (__stdcall *)(void *))vt[4];
        fn(p);
    }

    *(void **)this = (void *)0xa1eb6c;
    boost_function_dtor(this);
}
