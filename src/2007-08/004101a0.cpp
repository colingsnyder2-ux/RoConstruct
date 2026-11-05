// from server: 58% by colin
struct Verb {
    char pad[8];
    void* container;
};

struct String {
    char pad[0x24];
    ~String();
};

extern "C" void __stdcall invalid_parameter_noinfo();
extern "C" void __stdcall string_dtor(void*);

void* __cdecl func_0040f8c0(void*, void*, void*);

struct CopyVerb {
    char pad[8];
    void* field_8;
    void doIt(void* a, void* b, void* c, void* d, void* e);
};

void CopyVerb::doIt(void* a, void* b, void* c, void* d, void* e)
{
    void* p1 = a;
    void* p2 = b;
    if (p1 != 0 && p1 != c) {
        invalid_parameter_noinfo();
    }
    void* p3 = d;
    void* p4 = e;
    if (p4 != p3) {
        void* r = func_0040f8c0(p3, this->field_8, p4);
        void* end = this->field_8;
        void* it = r;
        while (it != end) {
            string_dtor(it);
            it = (char*)it + 0x24;
        }
        this->field_8 = r;
    }
    *(void**)p2 = p1;
    *(void**)((char*)p2 + 4) = p4;
}
