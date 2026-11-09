// from server: 30% by colin
extern "C" void __stdcall _invalid_parameter_noinfo(void);

void __cdecl sub_725520(void* a, void* b);
int  __cdecl sub_5578c0(void);
void __cdecl sub_40e470(void* a, int b);
void __cdecl sub_438f20(void);
void __cdecl sub_52cb30(void);
void __cdecl sub_554de0(void* a, void* b);
void __cdecl sub_492360(void* a);
void __cdecl sub_402a60(void* a, void* b);

extern unsigned char byte_8C1F28;
extern unsigned int  dword_8C1F2C;

struct VecEntry {
    void* field0;
    void* field4;
};

struct Vec {
    VecEntry* begin;
    VecEntry* end;
    VecEntry* capacity;
};

struct Creator {
    char pad_000[0x130];
    Vec  vec_130;
    char pad_after[4];

    void* method();
};

void* Creator::method()
{
    sub_725520((void*)0x8C1F1C, (void*)0x5588D0);

    int idx = sub_5578c0();

    Vec* v = &this->vec_130;

    unsigned int count;
    if (v->end == 0) {
        count = 0;
    } else {
        count = (unsigned int)(((char*)v->end - (char*)v->begin) >> 3);
    }

    unsigned int need = (unsigned int)(idx + 1);
    if (need > count) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_40e470(v, (int)need);
    } else {
        if (v->begin == 0) {
            _invalid_parameter_noinfo();
        } else {
            unsigned int sz = (unsigned int)(((char*)v->end - (char*)v->begin) >> 3);
            if ((unsigned int)idx >= sz) {
                _invalid_parameter_noinfo();
            }
        }
        VecEntry* e = &v->begin[idx];
        if (e->field0 != 0) {
            return e->field0;
        }
    }

    if ((dword_8C1F2C & 1) == 0) {
        dword_8C1F2C |= 1;
        sub_725520((void*)0x8BB97C, (void*)0x439830);
        sub_438f20();
        void* r = (void*)0;
        sub_52cb30();
        byte_8C1F28 = (r == 0) ? 1 : 0;
    }

    if (byte_8C1F28 == 0) {
        sub_725520((void*)0x8BB97C, (void*)0x439830);
        sub_438f20();
        void* out = 0;
        sub_554de0(this, &out);
        if (out == 0) {
            sub_492360(&out);
            return 0;
        }
        VecEntry* slot = &v->begin[idx];
        slot->field0 = out;
        sub_402a60(&slot->field4, &out);
        sub_492360(&out);
        return out;
    }

    return 0;
}
