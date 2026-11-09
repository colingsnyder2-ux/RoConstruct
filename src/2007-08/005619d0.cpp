// from server: 20% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RBXName {
    void* rep;
};

struct NameRef {
    void* ptr;
};

struct CreatorEntry {
    void* key;
    void* value;
};

struct CreatorList {
    CreatorEntry* begin;
    CreatorEntry* end;
};

struct ICreator {
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
};

struct Creator : public ICreator {
    void* field4;
    void* field8;
};

struct FactoryProduct {
    char pad[0x134];
    CreatorEntry* creatorsBegin;
    CreatorEntry* creatorsEnd;

    void* getCreators();
    void* getClassNameUnconstructed();
    void* getClassName();
    void registerCreator(Creator* c);
};

extern "C" void* __cdecl sub_560510(void*);
extern "C" void* __cdecl sub_560FE0(void*);
extern "C" void* __cdecl sub_55E820();
extern "C" void* __cdecl sub_725520(void*, void*, void*);
extern "C" void* __cdecl sub_402A60(void*, void*);
extern "C" void* __cdecl sub_541630(void*, void*);
extern "C" void* __cdecl sub_77E6D8();

void* FactoryProduct::getCreators() {
    return 0;
}

void* FactoryProduct::getClassNameUnconstructed() {
    return 0;
}

void* FactoryProduct::getClassName() {
    return 0;
}

void FactoryProduct::registerCreator(Creator* c) {
    void* name = getClassNameUnconstructed();
    CreatorEntry* begin = creatorsBegin;
    CreatorEntry* end = creatorsEnd;
    unsigned int count = 0;
    if (begin != 0) {
        count = (unsigned int)((char*)end - (char*)begin) >> 3;
    }
    unsigned int idx = (unsigned int)sub_55E820();
    if (begin == 0 || idx >= count) {
        sub_77E6D8();
    }
    CreatorEntry* slot = &creatorsBegin[idx];
    slot->key = name;
    sub_402A60(&slot->value, &c);
    sub_541630(c, this);
    if (c != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)c + 4), -1) == 1) {
            void** vt = *(void***)c;
            ((void (__thiscall*)(void*))vt[1])(c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1) {
                void** vt2 = *(void***)c;
                ((void (__thiscall*)(void*))vt2[2])(c);
            }
        }
    }
}
