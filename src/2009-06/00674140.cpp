// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { struct ClassDescriptor; }
struct GuidItemX { virtual ~GuidItemX(); int g[4]; };
struct ObjectX { virtual ~ObjectX(); };
struct DescribedX { virtual ~DescribedX(); Reflection::ClassDescriptor* descriptor; };
struct DebugableX { virtual ~DebugableX(); };
struct Instance : GuidItemX, ObjectX, DescribedX, DebugableX { Instance(); virtual ~Instance(); int rest[(0x8c - 0x24) / 4]; };
struct __declspec(novtable) IModelModifier { virtual ~IModelModifier(); };
struct CharacterAppearance : Instance, IModelModifier { };
template<class Base> struct NonFactoryProductX : Base { NonFactoryProductX() {} };
struct Clothing;
template<class C, class Base> struct __declspec(novtable) DescribedT : Base {
    static long count;
    static Reflection::ClassDescriptor& classDescriptor();
    DescribedT();
};
template<class C, class Base> DescribedT<C, Base>::DescribedT() { this->descriptor = &classDescriptor(); ++count; }
template struct DescribedT<Clothing, NonFactoryProductX<CharacterAppearance> >;
}
