// from server: 59% by atomic.potato
struct Vbad_lexical_cast_error_info_injector {
    char pad0[0x14];
    void* field14;
    char pad18[0x10];
    void* field28;
    void destroy();
};

extern "C" void __stdcall bad_cast_dtor(void*);

void Vbad_lexical_cast_error_info_injector::destroy()
{
    field28 = (void*)0xa5bee8;
    *(void**)this = (void*)0xa94814;
    field14 = (void*)0xa9480c;
    field14 = (void*)0xa5bfdc;
    void* p = *(void**)((char*)this + 0x18);
    if (p != 0) {
        void** vtbl = *(void***)p;
        void (*fn)(void*) = (void (*)(void*))vtbl[4];
        fn(p);
    }
    *(void**)this = (void*)0xa94524;
    bad_cast_dtor(this);
}
