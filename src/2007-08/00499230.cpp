// from server: 48% by colin
struct RBX_Name;

struct CreatorBase {
    static void* getCreators();
};

struct NetworkSettingsCreator {
    static int isConstructed;
    static int isConstructedTrue();
    const RBX_Name& getClassNameUnconstructed() const;
    NetworkSettingsCreator();
};

int NetworkSettingsCreator::isConstructed = 0;

int NetworkSettingsCreator::isConstructedTrue() { return 666; }

extern "C" void* __cdecl sub_499080();
extern "C" void __cdecl sub_630D23(void*);
extern "C" void __cdecl sub_570C00(void*, void*);

const RBX_Name& NetworkSettingsCreator::getClassNameUnconstructed() const {
    return *reinterpret_cast<const RBX_Name*>(sub_499080());
}

NetworkSettingsCreator::NetworkSettingsCreator() {
    if (!(isConstructed & 1)) {
        isConstructed |= 1;
        void* name = sub_499080();
        sub_570C00(reinterpret_cast<void*>(0x8be420), name);
        sub_630D23(reinterpret_cast<void*>(0x7786a0));
    }
}
