// from server: 34% by colin
extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void* __cdecl sub_44d180();
extern "C" void* __cdecl sub_44d070();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_492360(void*);
extern "C" void __cdecl sub_402a60(void*, void*);
extern "C" void __cdecl sub_40e470(void*, int, void*);
extern "C" void __cdecl sub_554de0(void*, void*, void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

struct Vec8 {
    void* a;
    void* b;
};

struct VecContainer {
    Vec8* begin;
    Vec8* end;
    Vec8* cap;
};

struct CRobloxDoc {
    char pad[0x130];
    VecContainer vec;
    void* method();
};

void* CRobloxDoc::method()
{
    sub_725520((void*)0x8bbeec, (void*)0x44de20);
    int idx = (int)sub_44d180();
    Vec8* b = this->vec.begin;
    Vec8* e = this->vec.end;
    int n = 0;
    if (b != 0) {
        n = (int)((char*)e - (char*)b) >> 3;
    }
    if ((unsigned)(idx + 1) > (unsigned)n) {
        Vec8 tmp;
        tmp.a = 0;
        tmp.b = 0;
        sub_40e470(&this->vec, idx + 1, &tmp);
    } else {
        Vec8* b2 = this->vec.begin;
        if (b2 != 0 || idx >= (int)((char*)this->vec.end - (char*)b2) >> 3) {
            _invalid_parameter_noinfo();
        }
        void* p = this->vec.begin[idx].a;
        if (p != 0) {
            return p;
        }
    }
    if ((*(unsigned char*)0x8bbef4 & 1) == 0) {
        *(unsigned int*)0x8bbef4 |= 1;
        sub_725520((void*)0x44de00, (void*)0x8bbee4);
        void* a = sub_44d070();
        void* c = sub_52cb30();
        *(unsigned char*)0x8bbef0 = (a == c);
    }
    if (*(unsigned char*)0x8bbef0 == 0) {
        sub_725520((void*)0x8bbee4, (void*)0x44de00);
        void* a = sub_44d070();
        void* tmp = 0;
        sub_554de0(this, &tmp, a);
        if (tmp != 0) {
            Vec8* b3 = this->vec.begin;
            if (b3 == 0 || idx >= (int)((char*)this->vec.end - (char*)b3) >> 3) {
                _invalid_parameter_noinfo();
            }
            Vec8* slot = &this->vec.begin[idx];
            slot->a = tmp;
            sub_402a60(&slot->b, &tmp);
            sub_492360(&tmp);
            return this;
        }
        sub_492360(&tmp);
    }
    return 0;
}
