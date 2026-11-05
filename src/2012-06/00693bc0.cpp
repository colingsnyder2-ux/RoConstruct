// from server: 19% by tester
struct S {
    char pad[0x28];
    void* field28;
    bool method(void* a, void* b);
};

extern "C" void __stdcall string_ctor(void*);
extern "C" void __stdcall string_dtor(void*);
extern "C" void* __cdecl getLocalScope();
extern "C" bool __cdecl compare(void*, void*);

bool S::method(void* a, void* b)
{
    char buf[0x20];
    string_ctor(buf);
    void* scope = getLocalScope();
    bool result = compare(scope, a);
    if (result) {
        void* p = field28;
        void** vtbl = *(void***)p;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl[3];
        fn(p, a, buf);
        string_dtor(buf);
        return true;
    }
    string_dtor(buf);
    return false;
}
