// from server: 35% by colin
// roc 2011-06 0092c4a2  unit: Ogre::GfxClustererPart  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092c4a2

struct Material;
struct MaterialManager;

struct MaterialPtr {
    void* p;
    MaterialPtr& operator=(const MaterialPtr&);
};

struct ResourceGroupManager {
    static char AUTODETECT_RESOURCE_GROUP_NAME[];
};

struct Material {
    unsigned short getNumSupportedTechniques() const;
};

struct MaterialManager {
    static MaterialManager& getSingleton();
    MaterialPtr& create(const char*, const char*, bool, void*);
};

struct String {
    char buf[28];
    String();
    String(const String&);
    ~String();
    String& operator=(const String&);
};

extern "C" {
    void* __stdcall sub_a41870();
    void __stdcall sub_a40450(void*, void*, const char*);
    void __stdcall sub_a404d0(void*);
    void __stdcall sub_a41704(void*, void*);
    void __stdcall sub_a41028(void*);
}

struct GfxClustererPart {
    char pad[0x48];
    void func(void* a, void* b);
};

void GfxClustererPart::func(void* a, void* b)
{
    void* mgr = sub_a41870();
    char namebuf[0xd4];
    sub_a40450(namebuf, pad, "RPQP");
    void* mm = *(void**)0xa4176c;
    void** vtbl = *(void***)mgr;
    void* fn = vtbl[0x50/4];
    char tmp[0x30];
    sub_a41704(tmp, namebuf);
    MaterialPtr mp;
    ((void (__stdcall*)(void*, void*, void*, void*))fn)(mgr, mm, namebuf, &mp);
    MaterialPtr* result = &((MaterialManager*)mgr)->create("Shaders", "_Med", false, 0);
    (void)result;
    (void)tmp;
    (void)namebuf;
    (void)a;
    (void)b;
}
