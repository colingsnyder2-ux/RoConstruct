// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were available. This is a minimal stand-in layout in which
// FactoryProduct<ScriptContext, Instance, sScriptContext> has a secondary polymorphic base
// at offset 16. The compiler then emits the `vector deleting destructor'`adjustor{16}'
// thunk (sub ecx,0x10; jmp real vector deleting dtor) when the vtable is emitted.
// The thunk cannot be written directly in C++.
// INFERRED: an explicit constructor is provided so the explicit instantiation emits the
// vtable and with it the deleting-destructor thunks.

namespace RBX {

extern char* sScriptContext;

class Instance {
public:
    Instance() {}
    virtual ~Instance() {}
protected:
    int pad[3]; // INFERRED: Instance + ScriptContext occupy 16 bytes up to the second base
};

class ScriptContext : public Instance {
public:
    ScriptContext() {}
    virtual ~ScriptContext() {}
};

// INFERRED: secondary base with a virtual destructor (the factory/creatable interface)
class FactoryBase {
public:
    FactoryBase() {}
    virtual ~FactoryBase() {}
};

template<class T, class B, char*& name>
class FactoryProduct : public T, public FactoryBase {
public:
    FactoryProduct() {}
protected:
    virtual ~FactoryProduct() {}
};

template class FactoryProduct<ScriptContext, Instance, sScriptContext>;

} // namespace RBX
