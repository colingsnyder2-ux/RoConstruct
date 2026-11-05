// from server: 33% by colin
struct RBXName {
    static const RBXName& declare(const char* const& s);
};

struct ICreator {
    virtual ~ICreator();
    virtual void* create() const;
    virtual const RBXName& getClassName() const;
};

struct CreatorList {
    void* begin;
    void* end;
    void* cap;
};

struct FactoryProductCreator : public ICreator {
    static int isConstructed;
    static bool constructedFlag;
    static char constructedInit;

    static int isConstructedTrue();
    static const RBXName& getClassNameUnconstructed();
    static CreatorList& getCreators();

    FactoryProductCreator();
    ~FactoryProductCreator();

    void* create() const;
    const RBXName& getClassName() const;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __cdecl sub_725520(void* a, void* b);
extern "C" void* __cdecl sub_557860();
extern "C" void* __cdecl sub_557780();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0(void* a, void* b);
extern "C" void __cdecl sub_492360(void* a);
extern "C" void __cdecl sub_402a60(void* a, void* b);
extern "C" void __cdecl sub_40e470(void* a, void* b);

int FactoryProductCreator::isConstructed = 0;
bool FactoryProductCreator::constructedFlag = false;
char FactoryProductCreator::constructedInit = 0;

int FactoryProductCreator::isConstructedTrue() { return 666; }

const RBXName& FactoryProductCreator::getClassNameUnconstructed() {
    return RBXName::declare(*(const char* const*)0x8c1f18);
}

CreatorList& FactoryProductCreator::getCreators() {
    return *(CreatorList*)0x8c1f10;
}

FactoryProductCreator::FactoryProductCreator() {
    sub_725520((void*)0x5588c0, (void*)0x8c1f18);
    void* p = sub_557860();
    int idx = (int)p;
    CreatorList& creators = getCreators();
    int count = 0;
    if (creators.begin != 0) {
        count = ((char*)creators.cap - (char*)creators.begin) >> 3;
    }
    if ((unsigned)(idx + 1) > (unsigned)count) {
        int zero1 = 0;
        int zero2 = 0;
        sub_40e470(&creators, &zero1);
    } else {
        if (creators.begin != 0 || idx >= (int)(((char*)creators.cap - (char*)creators.begin) >> 3)) {
            _invalid_parameter_noinfo();
        }
        void* slot = (char*)creators.begin + idx * 8;
        if (*(void**)slot != 0) {
            return;
        }
    }
    if (!(*(unsigned char*)0x8c1f24 & 1)) {
        *(unsigned int*)0x8c1f24 |= 1;
        sub_725520((void*)0x5586f0, (void*)0x8c1f10);
        void* a = sub_557780();
        void* b = sub_52cb30();
        constructedFlag = (a == b);
    }
    if (!constructedFlag) {
        sub_725520((void*)0x5586f0, (void*)0x8c1f10);
        void* a = sub_557780();
        void* tmp = 0;
        sub_554de0(this, &tmp);
        if (tmp != 0) {
            CreatorList& creators2 = getCreators();
            if (creators2.begin == 0 || idx >= (int)(((char*)creators2.cap - (char*)creators2.begin) >> 3)) {
                _invalid_parameter_noinfo();
            }
            void* slot = (char*)creators2.begin + idx * 8;
            *(void**)slot = tmp;
            sub_402a60((char*)slot + 4, &tmp);
            sub_492360(&tmp);
        } else {
            sub_492360(&tmp);
        }
    }
}

FactoryProductCreator::~FactoryProductCreator() {
    CreatorList& creators = getCreators();
    const RBXName& name = getClassName();
    int idx = 0;
    if (creators.begin != 0) {
        idx = ((char*)creators.cap - (char*)creators.begin) >> 3;
    }
    (void)idx;
    (void)name;
}

void* FactoryProductCreator::create() const {
    return 0;
}

const RBXName& FactoryProductCreator::getClassName() const {
    return getClassNameUnconstructed();
}
