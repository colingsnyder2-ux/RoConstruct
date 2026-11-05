// from server: 100% by EspClaude
// from server: 96% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_524751294c2dc6d0.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct String
{
    char storage[28];
    __declspec(dllimport) const char* c_str() const;
};

extern const char* (__thiscall *stringData)(const String&);

struct Name
{
    long reserved;
    String text;
    String& getText() { return text; }
};

struct Named
{
    virtual void reserved();
    virtual Name& getName();
};

struct Instance
{
    char storage[16];
    Named named;
};

typedef boost::shared_ptr<Instance> Shared;

struct Item
{
    virtual ~Item();
    char storage[0x78];
    Item();
    static void* __stdcall operator new(unsigned int);
    static void __stdcall operator delete(void*);
};

struct NameItem : Item
{
    Instance* instance;
    NameItem(Instance*);
    virtual ~NameItem();
};

inline NameItem::NameItem(Instance* p)
    : instance(p)
{
}

struct TextItem : Item
{
    char storage[4];
    TextItem(const char*);
};

struct Record
{
    virtual ~Record();
    char storage[0x50];
    Record();
    Item* addItem(Item*);
};

struct InstanceRecord : Record
{
    Shared instance;
    InstanceRecord(Shared);
    virtual ~InstanceRecord();
};

InstanceRecord::InstanceRecord(Shared p)
    : instance(p)
{
    addItem(new NameItem(p.get()));
    addItem(new TextItem(p.get()->named.getName().getText().c_str()));
}

