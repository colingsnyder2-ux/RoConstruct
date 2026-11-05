// from server: 30% by colin
struct Name;

struct Creator {
    char pad[0x130];
    void* vec_begin;
    void* vec_end;
    void* vec_cap;
    void* create();
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void* __cdecl sub_40ce80();
extern "C" void* __cdecl sub_40ce00();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0(void*, void*);
extern "C" void __cdecl sub_492360(void*);
extern "C" void __cdecl sub_402a60(void*, void*);
extern "C" void __cdecl sub_40e470(void*, int, void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

extern unsigned char byte_8baf90;
extern unsigned int dword_8baf94;
extern void* dword_8baf88;
extern void* dword_8baf8c;

void* Creator::create()
{
    void* result;
    void* local;
    int idx;
    void* p;

    sub_725520(&dword_8baf8c, (void*)0x40d330);
    result = sub_40ce80();

    idx = (int)result + 1;

    if (this->vec_begin == 0) {
        p = 0;
    } else {
        p = (void*)(((char*)this->vec_end - (char*)this->vec_begin) >> 3);
    }

    if ((unsigned int)idx > (unsigned int)p) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_40e470(&this->vec_begin, idx, tmp);
    } else {
        if (this->vec_begin == 0) {
            _invalid_parameter_noinfo();
        } else {
            p = (void*)(((char*)this->vec_end - (char*)this->vec_begin) >> 3);
            if ((unsigned int)result >= (unsigned int)p) {
                _invalid_parameter_noinfo();
            }
        }
        p = (void*)((char*)this->vec_begin + (int)result * 8);
        if (*(void**)p != 0) {
            return *(void**)p;
        }
    }

    if ((dword_8baf94 & 1) == 0) {
        dword_8baf94 |= 1;
        sub_725520(&dword_8baf88, (void*)0x40d290);
        local = 0;
        void* a = sub_40ce00();
        void* b = sub_52cb30();
        byte_8baf90 = (a == b) ? 1 : 0;
    }

    if (byte_8baf90 == 0) {
        void* tmp;
        sub_725520(&dword_8baf88, (void*)0x40d290);
        void* a = sub_40ce00();
        sub_554de0(this, &tmp);
        if (tmp != 0) {
            void* slot = (void*)((char*)this->vec_begin + (int)result * 8);
            *(void**)slot = tmp;
            sub_402a60((char*)slot + 4, &tmp);
            sub_492360(&tmp);
            return (void*)this;
        }
        sub_492360(&tmp);
    }

    return 0;
}
