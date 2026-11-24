// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: The target is a compiler-generated adjustor thunk: it subtracts 20 from
// `this` and jumps to the real vector deleting destructor at 0x5a8e50. C++ cannot
// define a thunk directly, so this file models a class layout that makes MSVC emit it.
// The layout needs a protected virtual destructor in FactoryProduct that overrides
// the virtual destructor of a secondary base placed at offset 20.
// No headers were available, so the layout below is a guess.

namespace RBX {

extern char* sScriptContext;
char* sScriptContext = 0;

// INFERRED: primary base occupying 20 bytes (vptr + 16 bytes of data)
struct InstanceBase1 {
    int pad[4];
    InstanceBase1() {}
    virtual ~InstanceBase1() {}
};

// INFERRED: secondary base at offset 20, whose virtual destructor
// is reached through the adjustor thunk
struct InstanceBase2 {
    int pad2;
    InstanceBase2() {}
    virtual ~InstanceBase2() {}
};

class Instance : public InstanceBase1, public InstanceBase2 {
public:
    Instance() {}
    virtual ~Instance() {}
};

class ScriptContext;

// INFERRED: the mangled name encodes the non-type argument as the address of the
// char* variable sScriptContext ($1?sScriptContext@...), so a pointer parameter is used.
template<class T, class Base, char** Name>
class FactoryProduct : public Base {
public:
    // INFERRED: an explicit constructor forces the vtable to be emitted, and with it
    // the vector deleting destructor and its adjustor{20} thunk.
    FactoryProduct() {}
protected:
    virtual ~FactoryProduct() {}
};

// The explicit instantiation emits the constructor, the vtable, the vector
// deleting destructor and the adjustor{20} thunk.
template class FactoryProduct<ScriptContext, Instance, &sScriptContext>;

} // namespace RBX
