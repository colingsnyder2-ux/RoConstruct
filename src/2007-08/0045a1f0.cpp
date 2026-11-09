// from server: 47% by colin
// roc 2007-08 0045a1f0  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045a1f0

extern "C" int __cdecl sub_418690(const char*);
extern "C" void __cdecl sub_570c00();
extern "C" void __cdecl sub_630d23(void*);

struct Name {
    static const Name& declare(const char*);
};

struct Creators {
    void insert(const Name*, void*);
};

struct FactoryProductCreator {
    static int isConstructed;
    static int isConstructedTrue();
    const Name& getClassNameUnconstructed() const;
    static Creators& getCreators();
    FactoryProductCreator();
};

int FactoryProductCreator::isConstructed = 0;

int FactoryProductCreator::isConstructedTrue() { return 666; }

const Name& FactoryProductCreator::getClassNameUnconstructed() const {
    return Name::declare((const char*)0x8a5b04);
}

Creators& FactoryProductCreator::getCreators() {
    return *(Creators*)0x8bbfe0;
}

FactoryProductCreator::FactoryProductCreator() {
    if (!(*(volatile unsigned char*)0x8bc068 & 1)) {
        *(volatile unsigned int*)0x8bc068 |= 1;
        const char* p = (const char*)sub_418690((const char*)0x8a5b04);
        sub_570c00();
        sub_630d23((void*)0x777e30);
    }
    const Name& name = getClassNameUnconstructed();
    Creators& creators = getCreators();
    creators.insert(&name, this);
    isConstructed = isConstructedTrue();
}
