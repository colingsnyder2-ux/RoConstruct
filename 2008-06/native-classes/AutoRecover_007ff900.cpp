// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers available, so the types are minimal local stand-ins.
// INFERRED: vptr at +0, a member with a destructor at +0x1c that frees a heap pointer.
// INFERRED: nothrow destructor chain, since the original has no EH frame.
namespace RBX {
class TextureId {};
namespace Reflection {
class PropDescriptor {
public:
    int pad[6];
    PropDescriptor() { pad[0] = 0; }
    virtual ~PropDescriptor() throw() {}
    virtual void f() {}
};
struct Holder {
    char* p;
    Holder() : p(0) {}
    ~Holder() throw() { if (p) delete p; }
};
template<class T, int N>
class BoundProp : public PropDescriptor {
public:
    Holder storage; // INFERRED: member at +0x1c, destroyed before the base vptr reset
    virtual ~BoundProp() throw() {}
    virtual void f() {}
};
}
class Sky {
public:
    static Reflection::BoundProp<TextureId, 1> prop_SkyRt;
};
Reflection::BoundProp<TextureId, 1> Sky::prop_SkyRt;
}
