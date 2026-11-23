// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were available, so the layout is a local analog. Bases are
// polymorphic subobjects at the offsets that the vtable stores in the disassembly write to.
namespace RBX {
extern char* sScript;
class Script;
class Instance;

namespace Stats {
class Item {
public:
    Item();
    virtual ~Item();
    char pad[0x0c];
};
}

struct B10 { virtual void f10(); };
struct B14 { virtual void f14(); };
struct B20 { virtual void f20(); };
struct B24 { virtual void f24(); char p[0x1c]; };
struct B44 { virtual void f44(); char p[0x1c]; };
struct B64 { virtual void f64(); char p[0x1c]; };
struct B84 { virtual void f84(); char p[0x1c]; };
struct BA4 { virtual void fa4(); char p[0x1c]; };
struct BC4 { virtual void fc4(); char p[0x1c]; };

template<class T, class Base, char*& Name>
class FactoryProduct : public Stats::Item {
protected:
    FactoryProduct();
    B10 b10; B14 b14; B20 b20; B24 b24; B44 b44; B64 b64; B84 b84; BA4 ba4; BC4 bc4;
};

template<class T, class Base, char*& Name>
FactoryProduct<T, Base, Name>::FactoryProduct() : Stats::Item() {}

template class FactoryProduct<Script, Instance, sScript>;
}
