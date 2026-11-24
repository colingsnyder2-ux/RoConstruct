// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided. This is a minimal local hierarchy
// where ControllerService has a primary base of 20 bytes (vptr + 16 bytes)
// and a secondary polymorphic base at offset 20 with a virtual destructor.
// The compiler then emits the `vector deleting destructor'`adjustor{20}'
// thunk (sub ecx,0x14 ; jmp real vector deleting dtor) for the secondary
// base's vtable slot. An out-of-line constructor is defined so the vtables
// (and therefore the deleting destructor and its adjustor thunk) are emitted.

namespace RBX {

class ControllerServicePrimaryBase {
public:
    virtual ~ControllerServicePrimaryBase() {}
    int pad[4];
};

class ControllerServiceSecondaryBase {
public:
    virtual ~ControllerServiceSecondaryBase() {}
};

class ControllerService : public ControllerServicePrimaryBase,
                          public ControllerServiceSecondaryBase {
public:
    ControllerService();
    virtual ~ControllerService();
};

// INFERRED: constructor present only to force vtable emission in this TU.
ControllerService::ControllerService()
{
}

ControllerService::~ControllerService()
{
}

} // namespace RBX
