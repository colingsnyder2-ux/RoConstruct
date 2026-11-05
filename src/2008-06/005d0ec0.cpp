// from server: 100% by colin
struct String;

extern void (__thiscall* stringDestroy)(String*);
extern String* (__cdecl* stringConcat)(String*, const String&, const char*);

struct String {
    unsigned long allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned long length;
    unsigned long capacity;

    __declspec(dllimport) String(const String&);
    String(const String&, const char*);
    ~String();
};

inline String::String(const String& other, const char* suffix)
{
    stringConcat(this, other, suffix);
}

inline String::~String()
{
    stringDestroy(this);
}

namespace RBX {
    struct Instance {
        virtual ~Instance();
        char padding[0x100];
        Instance* next;

        Instance* getRootAncestor();
    };

    struct ServiceProvider : Instance {
        char padding2[0x2a0];
        void* service;
    };
}

extern RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);

struct Result {
    virtual void slot0();
    virtual void slot1();
    virtual bool available();
    virtual void slot3();
    virtual void apply(void*);
};

struct Property {
    Result* find(String);
};

struct Enumeration {
    String lookup(const int&);
};

extern void __cdecl callback();
extern char registrationData;
extern void __cdecl registerType(void (__cdecl*)(), const void*);
extern Enumeration* __cdecl enumeration();

struct S : RBX::Instance {
    char padding2[0x98];
    int key;
    char padding3[0x24];
    Property property;

    void f();
};

void S::f()
{
    S* root;
    if (next)
        root = static_cast<S*>(next->getRootAncestor());
    else
        root = this;

    registerType(callback, &registrationData);
    Enumeration* values = enumeration();
    String name(values->lookup(key), "Tool");
    Result* result = root->property.find(name);
    if (result->available()) {
        RBX::ServiceProvider* provider = func_00491e50(this);
        if (provider) {
            void* service = provider->service;
            result->apply(service);
        }
    }
}
