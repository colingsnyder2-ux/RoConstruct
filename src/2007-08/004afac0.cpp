// from server: 30% by colin
struct Name {
    static const Name& declare(const char* const& s);
};

struct ICreator {
    virtual ~ICreator();
    virtual void* create() const = 0;
};

struct CreatorBase {
    void* vec_begin;
    void* vec_end;
    void* vec_cap;
};

struct FactoryProduct {
    char pad[0x130];
    CreatorBase creators;
};

struct Creator : public ICreator {
    void* create() const;
    Creator();
    ~Creator();
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __cdecl sub_725520(void*, void*);
extern "C" void* __cdecl sub_4a5c40();
extern "C" void __cdecl sub_40e470(void*, int, void*, void*);
extern "C" void* __cdecl sub_4a5770();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0(void*, void*, void*);
extern "C" void __cdecl sub_492360(void*);
extern "C" void __cdecl sub_402a60(void*, void*);

extern char byte_8bea18;
extern char byte_8bea14;
extern char byte_8be97c;
extern char byte_8be95c;
extern void* dword_77e6d8;

void* Creator::create() const {
    return 0;
}

Creator::Creator() {
    sub_725520(&byte_8be97c, (void*)0x4a74d0);
    void* p = sub_4a5c40();
    int idx = (int)p;
    FactoryProduct* self = (FactoryProduct*)((char*)this - 0x130);
    CreatorBase* cb = &self->creators;
    int count;
    if (cb->vec_begin != 0) {
        count = 0;
    } else {
        count = ((char*)cb->vec_end - (char*)cb->vec_begin) >> 3;
    }
    if ((unsigned)(idx + 1) > (unsigned)count) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_40e470(cb, idx + 1, tmp, tmp);
    } else {
        if (cb->vec_begin == 0 || idx >= (int)(((char*)cb->vec_end - (char*)cb->vec_begin) >> 3)) {
            _invalid_parameter_noinfo();
        }
        void* slot = (char*)cb->vec_begin + idx * 8;
        if (*(void**)slot != 0) {
            return;
        }
    }
    if (!(byte_8bea18 & 1)) {
        byte_8bea18 |= 1;
        sub_725520(&byte_8be95c, (void*)0x4a7140);
        void* a = sub_4a5770();
        void* b = sub_52cb30();
        byte_8bea14 = (a == b);
    }
    if (byte_8bea14 == 0) {
        sub_725520(&byte_8be95c, (void*)0x4a7140);
        void* n = sub_4a5770();
        void* tmp = 0;
        sub_554de0(this, &tmp, n);
        if (tmp != 0) {
            void* slot;
            if (cb->vec_begin == 0 || idx >= (int)(((char*)cb->vec_end - (char*)cb->vec_begin) >> 3)) {
                _invalid_parameter_noinfo();
            }
            slot = (char*)cb->vec_begin + idx * 8;
            *(void**)slot = tmp;
            sub_402a60((char*)slot + 4, &tmp);
            sub_492360(&tmp);
            return;
        }
        sub_492360(&tmp);
    }
}

Creator::~Creator() {
}
