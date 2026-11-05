// from server: 47% by colin
extern "C" void __stdcall _invalid_parameter_noinfo();

struct CRobloxDoc {
    char pad[0x64];
    void* vec_begin;
    void* vec_end;
    void* vec_cap;
    char pad2[0x74 - 0x70];
    void* ptr74;
    void* ptr78;
    void destroy();
};

void CRobloxDoc::destroy() {
    void** begin = (void**)this->vec_begin;
    void** end = (void**)this->vec_end;

    if (begin > end) {
        _invalid_parameter_noinfo();
    }

    void** cap = (void**)this->vec_cap;
    if (this->vec_end > (void*)cap) {
        _invalid_parameter_noinfo();
    }

    if (begin != end) {
        while (begin != end) {
            if (begin >= (void**)this->vec_cap) {
                _invalid_parameter_noinfo();
            }
            void* obj = *begin;
            if (obj) {
                void** vtbl = *(void***)obj;
                void (*fn)(void*, int) = (void (*)(void*, int))vtbl[1];
                fn(obj, 1);
            }
            if (begin >= (void**)this->vec_cap) {
                _invalid_parameter_noinfo();
            }
            begin++;
        }
    }

    void** cap2 = (void**)this->vec_cap;
    if (this->vec_end > (void*)cap2) {
        _invalid_parameter_noinfo();
    }
    void** b2 = (void**)this->vec_begin;
    if (b2 > (void**)this->vec_cap) {
        _invalid_parameter_noinfo();
    }

    extern void __stdcall sub_5cdca0(void*, void*, void*, void*, void*);
    sub_5cdca0(&this->vec_begin, &this->vec_begin, b2, cap2, &this->vec_begin);

    void* p74 = this->ptr74;
    this->ptr74 = 0;
    if (p74) {
        extern void __stdcall sub_44d9f0(void*);
        sub_44d9f0(p74);
        extern void __cdecl sub_62fc62(void*);
        sub_62fc62(p74);
    }

    void* p78 = this->ptr78;
    if (p78) {
        extern void __stdcall sub_467470(void*);
        sub_467470(p78);
        void** vtbl = *(void***)p78;
        void (*fn)(void*) = (void (*)(void*))vtbl[2];
        fn(p78);
        this->ptr78 = 0;
    }

    extern void* g_8bae2c;
    if (g_8bae2c == this) {
        extern void __stdcall sub_4061f0(int, void*);
        sub_4061f0(1, this);
    }

    extern void __stdcall sub_62ff98(void*);
    sub_62ff98(this);
}
