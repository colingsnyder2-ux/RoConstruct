// from server: 21% by colin
extern "C" {
    void __stdcall _invalid_parameter_noinfo();
}

struct Name {
    void* p;
};

struct CreatorEntry {
    Name* name;
    void* creator;
};

struct CreatorVec {
    CreatorEntry* begin;
    CreatorEntry* end;
    CreatorEntry* cap;
};

struct ICreator {
    virtual void v0();
    virtual void v1();
};

struct Creator : ICreator {
    static int isConstructed;
    static bool constructedFlag;
    static bool initFlag;
    static CreatorVec creators;
    static void* nameHolder;
    static void* nameHolder2;

    static void* getName();
    static void* getCreators();
    static void* getClassNameUnconstructed();
    static void* getClassName();
    static void* findByName(void*);
    static void* createByName(void*);
    static void* getClass();
    static void* getNameStatic();

    Creator();
};

int Creator::isConstructed;
bool Creator::constructedFlag;
bool Creator::initFlag;
CreatorVec Creator::creators;
void* Creator::nameHolder;
void* Creator::nameHolder2;

extern "C" void* __cdecl sub_725520(void*, void*);
extern "C" void* __cdecl sub_4873c0();
extern "C" void* __cdecl sub_486b70();
extern "C" void* __cdecl sub_52cb30();
extern "C" void* __cdecl sub_40e470();
extern "C" void* __cdecl sub_554de0();
extern "C" void* __cdecl sub_492360();
extern "C" void* __cdecl sub_402a60();

void* g_8bdcc4;
void* g_487bd0;
void* g_4878e0;
void* g_8bdc88;

Creator::Creator()
{
    sub_725520(&g_8bdcc4, &g_487bd0);
    void* cls = sub_4873c0();

    CreatorEntry* begin = creators.begin;
    CreatorEntry* end = creators.end;
    unsigned int count = 0;
    if (end != begin)
        count = (unsigned int)(end - begin);

    unsigned int idx = (unsigned int)cls + 1;
    if (idx > count) {
        CreatorEntry tmp;
        tmp.name = 0;
        tmp.creator = 0;
        sub_40e470();
    } else {
        if (begin == 0 || (unsigned int)cls >= count)
            _invalid_parameter_noinfo();
        CreatorEntry* e = &begin[(unsigned int)cls];
        if (e->name != 0)
            return;
    }

    if (!initFlag) {
        initFlag = true;
        sub_725520(&g_8bdc88, &g_4878e0);
        void* a = sub_486b70();
        void* b = sub_52cb30();
        constructedFlag = (a == b);
    }

    if (!constructedFlag) {
        sub_725520(&g_8bdc88, &g_4878e0);
        void* a = sub_486b70();
        void* tmp;
        sub_554de0();
        if (tmp != 0) {
            CreatorEntry* base = creators.begin;
            if (base == 0 || (unsigned int)cls >= (unsigned int)(creators.end - base))
                _invalid_parameter_noinfo();
            CreatorEntry* e = &base[(unsigned int)cls];
            e->name = (Name*)tmp;
            sub_402a60();
            sub_492360();
            return;
        }
        sub_492360();
    }
}
