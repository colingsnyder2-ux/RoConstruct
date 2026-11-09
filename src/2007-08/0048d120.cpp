// from server: 38% by colin
// roc 2007-08 0048d120  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 439 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048d120

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RBXName {
    void* data;
};

struct CreatorEntry {
    RBXName* name;
    void* creator;
};

struct CreatorVector {
    CreatorEntry* begin;
    CreatorEntry* end;
    CreatorEntry* capacity;
};

struct CreatorMap {
    void* tree;
    unsigned int size;
};

struct FactoryProductCreator {
    void* vtable;
    CreatorVector creators;
    unsigned int isConstructed;
};

extern "C" void __stdcall sub_725520(void* a, void* b);
extern "C" void* __stdcall sub_487510();
extern "C" void* __stdcall sub_4871f0();
extern "C" void* __stdcall sub_52cb30();
extern "C" void __stdcall sub_40e470(void* a, int b, void* c);
extern "C" void __stdcall sub_554de0(void* a, void* b, void* c);
extern "C" void __stdcall sub_492360(void* a);
extern "C" void __stdcall sub_402a60(void* a, void* b);

extern unsigned char g_8bdcec;
extern unsigned int g_8bdcf0;
extern void* g_8bdcbc;
extern void* g_8bdcd0;
extern void* g_8b5188;

void* __fastcall FactoryProductCreator_ctor(FactoryProductCreator* self, void* edx);

void* __fastcall FactoryProductCreator_ctor(FactoryProductCreator* self, void* edx)
{
    void* result;
    void* name;
    void* creators;
    unsigned int count;
    unsigned int idx;
    CreatorEntry* entry;
    void* temp;

    sub_725520(&g_8bdcd0, (void*)0x487c00);
    result = sub_487510();
    idx = (unsigned int)result;

    count = 0;
    if (self->creators.end != 0) {
        count = (unsigned int)((char*)self->creators.end - (char*)self->creators.begin) >> 3;
    }

    if (idx + 1 > count) {
        temp = 0;
        sub_40e470(&self->creators, idx + 1, &temp);
    } else {
        if (self->creators.begin == 0 ||
            idx >= (unsigned int)((char*)self->creators.end - (char*)self->creators.begin) >> 3) {
            _invalid_parameter_noinfo();
        }
        entry = &self->creators.begin[idx];
        if (entry->creator != 0) {
            return entry->creator;
        }
    }

    if ((g_8bdcf0 & 1) == 0) {
        g_8bdcf0 |= 1;
        sub_725520(&g_8bdcbc, (void*)0x4879b0);
        name = sub_4871f0();
        creators = sub_52cb30();
        g_8bdcec = (name == creators) ? 1 : 0;
    }

    if (g_8bdcec == 0) {
        sub_725520(&g_8bdcbc, (void*)0x4879b0);
        name = sub_4871f0();
        sub_554de0(self, &name, name);
        if (name != 0) {
            if (self->creators.begin == 0 ||
                idx >= (unsigned int)((char*)self->creators.end - (char*)self->creators.begin) >> 3) {
                _invalid_parameter_noinfo();
            }
            entry = &self->creators.begin[idx];
            entry->name = (RBXName*)name;
            sub_402a60(&entry->creator, &name);
            sub_492360(&name);
            return (void*)name;
        }
        sub_492360(&name);
    }

    return 0;
}
