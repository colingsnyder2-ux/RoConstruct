// from server: 42% by atomic.potato
// roc 2007-08 004afc80  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 439 bytes

extern "C" int __cdecl _invalid_parameter_noinfo(void);

struct RBX_Name {
    static RBX_Name* declare(const char* const& s);
};

struct ICreator {
    virtual ~ICreator();
    virtual void* create() const;
};

struct CreatorMap {
    void* pad0;
    void* begin;
    void* end;
};

struct Creator : public ICreator {
    void* create() const;
    const RBX_Name& getClassName() const;
    const RBX_Name& getClassNameUnconstructed() const;
    Creator();
    ~Creator();
};

extern const char* const sMotor;
extern CreatorMap* g_creators;
extern int g_isConstructed;
extern char g_constructedFlag;
extern char g_constructedFlag2;

extern "C" void __cdecl sub_725520(void*, void*);
extern "C" void* __cdecl sub_4a5cb0();
extern "C" void __cdecl sub_40e470(void*, int, int, int);
extern "C" void* __cdecl sub_444e70();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0(void*, void*, void*);
extern "C" void __cdecl sub_492360(void*);
extern "C" void __cdecl sub_402a60(void*, void*);
extern "C" void __cdecl sub_77e6d8();

const RBX_Name& Creator::getClassNameUnconstructed() const {
    return *RBX_Name::declare(sMotor);
}

const RBX_Name& Creator::getClassName() const {
    return *RBX_Name::declare(sMotor);
}

Creator::Creator() {
    const RBX_Name& name = getClassNameUnconstructed();
    CreatorMap* creators = g_creators;
    int idx = (int)sub_4a5cb0();
    int count = creators->begin ? (int)(((char*)creators->end - (char*)creators->begin) >> 3) : 0;
    if ((unsigned)(idx + 1) > (unsigned)count) {
        int zero1 = 0;
        int zero2 = 0;
        sub_40e470(creators, idx + 1, zero1, zero2);
    } else {
        if (creators->begin != 0 || (unsigned)idx >= (unsigned)(((char*)creators->end - (char*)creators->begin) >> 3)) {
            sub_77e6d8();
        }
        void* slot = (char*)creators->begin + idx * 8;
        if (*(void**)slot != 0) {
            return;
        }
    }
    if (!(g_constructedFlag & 1)) {
        g_constructedFlag |= 1;
        sub_725520((void*)0x8bbae0, (void*)0x444fb0);
        void* a = sub_444e70();
        void* b = sub_52cb30();
        g_constructedFlag2 = (a == b);
    }
    if (!g_constructedFlag2) {
        sub_725520((void*)0x8bbae0, (void*)0x444fb0);
        void* a = sub_444e70();
        void* tmp = 0;
        sub_554de0(this, &tmp, a);
        if (tmp != 0) {
            void* slot = (char*)creators->begin + idx * 8;
            *(void**)slot = tmp;
            sub_402a60(&tmp, (char*)slot + 4);
            sub_492360(&tmp);
            return;
        }
        sub_492360(&tmp);
    }
}

Creator::~Creator() {
    CreatorMap* creators = g_creators;
    const RBX_Name& name = getClassName();
    int idx = (int)sub_4a5cb0();
    if (creators->begin == 0 || (unsigned)idx >= (unsigned)(((char*)creators->end - (char*)creators->begin) >> 3)) {
        sub_77e6d8();
    }
    void* slot = (char*)creators->begin + idx * 8;
    *(void**)slot = 0;
    sub_402a60((char*)slot + 4, (void*)&name);
}
