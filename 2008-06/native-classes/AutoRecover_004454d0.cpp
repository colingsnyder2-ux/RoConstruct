// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native header for FactoryProduct/Instance/Script was provided. The
// layout below is a local stand-in. Item is called at the base position and the
// vtable stores at 0x0/0x10/0x14/0x20/0x24/0x44/0x64/0x84/0xa4/0xc4 imply multiple
// inheritance with several interface bases. Neither the bases nor their sizes are proven.

namespace RBX {

extern char* sScript;

class GlobalSettings {
public:
    class Item {
    public:
        Item(); // 0x00409e00, defined elsewhere
        virtual ~Item() {}
        char itemData[0x10 - sizeof(void*)];
    };
};

// INFERRED: interface bases occupying the secondary vtable slots
struct IfaceA { virtual void a() {} };
struct IfaceB { virtual void b() {} };
struct IfaceC { virtual void c() {} char pad[0x20 - 0x18]; };
struct IfaceD { virtual void d() {} char pad[0x20 - sizeof(void*)]; };
struct IfaceE { virtual void e() {} char pad[0x20 - sizeof(void*)]; };
struct IfaceF { virtual void f() {} char pad[0x20 - sizeof(void*)]; };
struct IfaceG { virtual void g() {} char pad[0x20 - sizeof(void*)]; };
struct IfaceH { virtual void h() {} char pad[0x20 - sizeof(void*)]; };

class Instance : public GlobalSettings::Item,
                 public IfaceA, public IfaceB, public IfaceC, public IfaceD,
                 public IfaceE, public IfaceF, public IfaceG, public IfaceH {
};

class Script : public Instance {
};

template<class Product, class Base, char** Name>
class FactoryProduct : public Base {
protected:
    FactoryProduct();
};

template<class Product, class Base, char** Name>
FactoryProduct<Product, Base, Name>::FactoryProduct()
    : Base()
{
}

// Explicit instantiation emits the target constructor.
template class FactoryProduct<Script, Instance, &sScript>;

} // namespace RBX
