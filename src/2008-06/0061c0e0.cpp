// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_luacallguard9bb4950e0e8f22c0.cpp

// Candidate translation unit (score above; library headers required).
namespace RBX {
class Instance {public: virtual ~Instance(); char reserved[0x100]; Instance* parent; Instance* getRootAncestor(); bool isAncestorOf(Instance*);};
namespace Stats {class StatsService:public Instance {};}
class DataModel:public Instance {public: char reserved2[0x114]; Instance* guiRoot; char gap[4]; Instance* guiHooks;};
}
struct Context {unsigned long identity;void report(int,const char*);};
extern "C" Context* __cdecl getContext();
extern bool __cdecl hasPermission(unsigned long,int);
static __declspec(noinline) void checkModification(RBX::Instance* instance) {
 if(hasPermission(getContext()->identity,1)) return;
 if(dynamic_cast<RBX::Stats::StatsService*>(instance)) getContext()->report(1,"modify a StatsService");
 RBX::Instance* root=instance->parent ? instance->parent->getRootAncestor() : instance;
 RBX::DataModel* model=dynamic_cast<RBX::DataModel*>(root);
 if(model){
 if(model->guiRoot==instance || model->guiRoot->isAncestorOf(instance)) getContext()->report(1,"GuiRoot");
 if(model->guiHooks==instance || model->guiHooks->isAncestorOf(instance)) getContext()->report(1,"GuiHooks");
 }
}
void verify(RBX::Instance* instance){checkModification(instance);}

struct String
{
    unsigned int allocator;
    union
    {
        char small[16];
        char* heap;
    } data;
    unsigned int length;
    unsigned int capacity;

    ~String();
    const char* c_str() const;
};

inline const char* String::c_str() const
{
    if (capacity >= 16)
        return data.heap;
    return data.small;
}

struct Name
{
    unsigned int unused;
    String text;
};

struct Instance;
struct Arguments;

struct Descriptor
{
    virtual void reserved() = 0;
    virtual void invoke(Instance*, Arguments*) = 0;

    Name* name;
    unsigned int unused[2];
    void* context;

    bool accepts(Instance*);
};

struct Instance
{
    unsigned int unused[2];
    Descriptor* descriptor;
};

struct Shared
{
    Instance* object;
    void* control;

    ~Shared();
};

struct Owned
{
    virtual void destroy(unsigned int) = 0;
};

struct Pair
{
    unsigned int first;
    Owned* second;

    Pair();
};

extern void* argumentsTable[];

struct Arguments
{
    void** table;
    Pair values;
    int first;
    void* state;

    Arguments(void*);
    ~Arguments();
};

inline Arguments::Arguments(void* s)
{
    table = argumentsTable;
    first = 1;
    state = s;
}

inline Arguments::~Arguments()
{
    if (values.second)
        values.second->destroy(1);
}

struct Error
{
    void* table;
    char* message;
    unsigned int owned;
    String text;

    Error(const String&);
    Error(const Error&);
    ~Error();
};

struct Notification
{
    void finish();
};

extern Descriptor* __cdecl lookup(void*, int);
extern Notification* __stdcall notify(void*, const char*);
extern bool __cdecl getObject(void*, int, Shared*);
extern void* __cdecl dynamicCastObject(void*, int, const void*, const void*, int);
extern void __cdecl prepare();
extern String __cdecl format(const char*, ...);
extern int __cdecl pushValues(Pair*, void*);

extern char describedType;
extern char instanceType;

int __cdecl f(void* state)
{
    Descriptor* descriptor = lookup(state, -10003);
    if (descriptor->context)
        notify(descriptor->context, descriptor->name->text.c_str())->finish();

    Shared object = { 0, 0 };
    if (!getObject(state, 1, &object) || !object.object)
    throw Error(format(
        "Did you forget a semicolon?  The first argument of member function %s must be an Object",
        descriptor->name->text.c_str()));

        Instance* instance = object.object;
        void* castResult = dynamicCastObject(
            instance, 0, &describedType, &instanceType, 0);
        checkModification(static_cast<RBX::Instance*>(castResult));

        if (!descriptor->accepts(instance))
        {
            Descriptor* type = instance->descriptor;
            throw Error(format(
                "The function %s is not a member of \"%s\"",
                descriptor->name->text.c_str(),
                type->name->text.c_str()));
        }

        Arguments arguments(state);
        descriptor->invoke(instance, &arguments);
        return pushValues(&arguments.values, arguments.state);
    
}
