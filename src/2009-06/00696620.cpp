// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct GuidItemX { virtual ~GuidItemX(); int g[4]; };
struct ObjectX { virtual ~ObjectX(); };
struct DescribedX { virtual ~DescribedX(); void* descriptor; };
struct DebugableX { virtual ~DebugableX(); };
struct Instance : GuidItemX, ObjectX, DescribedX, DebugableX { virtual ~Instance(); int rest[0x20]; };
struct VirtualUser;
template<class T> struct FactoryProduct : Instance { virtual ~FactoryProduct() {} };
template struct FactoryProduct<VirtualUser>;
}
