// from server: 58% by colin
// roc 2007-08 005e9e00  unit: RBX::VFlagStand::?$FactoryProduct  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e9e00

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Name;

struct CreatorMap {
    void* pad0;
    void* begin;
    void* end;
};

struct FactoryProduct {
    char pad[0xc0];
    CreatorMap* creators;
    void* find(Name* name);
};

void* FactoryProduct::find(Name* name) {
    CreatorMap* m = creators;
    if (m) {
        void* first = m->begin;
        void* last = m->end;
        if (m->begin > m->end) {
            _invalid_parameter_noinfo();
        }
        CreatorMap* m2 = creators;
        void* it = m2->begin;
        if (it > m2->end) {
            _invalid_parameter_noinfo();
        }
        if (m2 != m) {
            _invalid_parameter_noinfo();
        }
        while (it != last) {
            if (it >= m2->end) {
                _invalid_parameter_noinfo();
            }
            void* v = *(void**)it;
            void* r = ((void* (__cdecl*)(void*, void*, void*, void*, void*))0x630d36)(
                v, 0, (void*)0x881f4c, (void*)0x8a1bd0, 0);
            if (r != 0) {
                return r;
            }
            if (it >= m2->end) {
                _invalid_parameter_noinfo();
            }
            it = (char*)it + 8;
        }
    }
    return 0;
}
