// from server: 100% by king_originala
void __cdecl operator delete(void*);

struct B_func_00465a80 {
    virtual ~B_func_00465a80();
};

struct S_func_00465a80 : B_func_00465a80 {
    ~S_func_00465a80();
};

struct Interface;

struct InterfaceTable {
    void* slot0;
    void* slot1;
    unsigned long (__stdcall *release)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

struct CWebToolbox : S_func_00465a80 {
    char padding[248];
    Interface* object;
    virtual ~CWebToolbox();
    void* destroy(unsigned int flags);
};

__forceinline CWebToolbox::~CWebToolbox()
{
    if (object)
        object->table->release(object);
}

void* CWebToolbox::destroy(unsigned int flags)
{
    this->CWebToolbox::~CWebToolbox();
    if (flags & 1)
        operator delete(this);
    return this;
}
