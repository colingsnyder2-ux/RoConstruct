// from server: 40% by colin
struct RBXName {
    void* p;
};

struct CreatorEntry {
    RBXName* name;
    void* creator;
};

struct CreatorVec {
    CreatorEntry* begin;
    CreatorEntry* end;
    CreatorEntry* cap;
};

struct FactoryProduct {
    char pad[0x130];
    CreatorVec creators;
    int field134;

    void* getOrCreateCreator();
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void* __stdcall sub_5e62a0();
extern "C" void __stdcall sub_40e470(CreatorVec*, int, void*, void*);
extern "C" void __stdcall sub_77e6d8();
extern "C" void* __stdcall sub_58d830();
extern "C" void* __stdcall sub_52cb30();
extern "C" void __stdcall sub_554de0(void*, void*, void*);
extern "C" void __stdcall sub_492360(void*);
extern "C" void __stdcall sub_402a60(void*, void*);

extern unsigned char byte_8c6f28;
extern unsigned int dword_8c6f2c;

void* FactoryProduct::getOrCreateCreator() {
    sub_725520((void*)0x8c6f24, (void*)0x5e6370);
    int idx = (int)sub_5e62a0();

    CreatorVec* vec = &creators;
    int count;
    if (vec->begin == 0) {
        count = 0;
    } else {
        count = (int)((char*)vec->cap - (char*)vec->begin) >> 3;
    }

    if ((unsigned)(idx + 1) > (unsigned)count) {
        void* tmp1 = 0;
        void* tmp2 = 0;
        sub_40e470(vec, idx + 1, tmp1, tmp2);
    } else {
        if (vec->begin == 0 || (unsigned)idx >= (unsigned)(((char*)vec->cap - (char*)vec->begin) >> 3)) {
            sub_77e6d8();
        }
        void* result = vec->begin[idx].creator;
        if (result != 0) {
            return result;
        }
    }

    if ((dword_8c6f2c & 1) == 0) {
        dword_8c6f2c |= 1;
        sub_725520((void*)0x8c37c4, (void*)0x58dd90);
        void* a = sub_58d830();
        void* b = sub_52cb30();
        byte_8c6f28 = (a == b) ? 1 : 0;
    }

    if (byte_8c6f28 == 0) {
        sub_725520((void*)0x8c37c4, (void*)0x58dd90);
        void* a = sub_58d830();
        void* local = 0;
        sub_554de0(this, &local, a);
        if (local != 0) {
            void* edx = vec->begin;
            if (edx == 0 || (unsigned)idx >= (unsigned)(((char*)vec->cap - (char*)edx) >> 3)) {
                sub_77e6d8();
            }
            CreatorEntry* entry = &vec->begin[idx];
            entry->name = (RBXName*)local;
            sub_402a60(&entry->creator, &local);
            sub_492360(&local);
            return (void*)local;
        }
        sub_492360(&local);
    }

    return 0;
}
