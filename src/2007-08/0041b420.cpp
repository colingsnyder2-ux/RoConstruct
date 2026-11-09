// from server: 49% by colin
struct RBXName {
    static const RBXName& declare(const char* s);
};

struct CreatorBase {
    virtual void v0();
    virtual void v1();
};

struct CreatorImpl {
    void construct();
};

struct FactoryProduct {
    void FactoryProduct_ctor();
};

struct Creator : CreatorBase {
    void construct();
};

struct CreatorsMap {
    void insert(const RBXName* name, Creator* creator);
};

struct CreatableFactory {
    static CreatorsMap& getCreators();
};

extern "C" void __cdecl sub_49D670(void*, void*);
extern "C" void __cdecl sub_4157E0(void*, void*, void*);
extern "C" void __cdecl sub_417750(void*);
extern "C" void __cdecl sub_41B2A0(void*);

extern const char* g_name_42bf90;
extern void* g_creator_414a90;
extern void* g_global_8bafcc;

void Creator::construct()
{
    char buf[12];
    void* p = buf;
    void* q = buf;
    sub_49D670(&q, &g_name_42bf90);
    sub_4157E0(&p, &g_creator_414a90, 0);
    sub_41B2A0(buf);
    sub_417750(g_global_8bafcc);
}
