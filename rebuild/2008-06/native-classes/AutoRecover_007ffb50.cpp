// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: standalone stand-in types. The static's atexit destructor deletes the
// pointer at +0x18 (0x97ad8c - 0x97ad74) and then resets the vptr to the base vtable.
// INFERRED: operator delete is throw() as in the MSVC 2008 <new> header, so no EH frame is emitted.
void __cdecl operator delete(void*) throw();

namespace RBX {
namespace Reflection {

class PropBase {
public:
    int fields[5]; // INFERRED: pads the layout so the owned pointer lands at +0x18
    PropBase() {}
    virtual ~PropBase() {}
    virtual void anchor();
};

template <class T, int B>
class BoundProp : public PropBase {
public:
    T* owned; // INFERRED: heap-owned member freed in the destructor (operator delete)
    BoundProp() : owned(new T) {}
    virtual ~BoundProp() { delete owned; }
};

} // namespace Reflection

class Sky {
public:
    static Reflection::BoundProp<int, 1> prop_StarCount;
};

Reflection::BoundProp<int, 1> Sky::prop_StarCount;

} // namespace RBX
