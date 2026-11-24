// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no G3D header was provided, so the class layout below is a guess.
// Order of operations in the original:
//   1. store the derived vtable (0x826fec) and set EH state 0
//   2. call zeroPointer (0x4f0840, shared/folded code)
//   3. store the base vtable (0x826e94) via the inlined base destructor
//   4. call operator delete if bit 0 of the flag is set

namespace RBX { namespace RenderBase { class Chunk; } }

// INFERRED: zeroPointer is shared (identical code folding) at 0x004f0840 and takes only ecx.
extern "C" void __fastcall fn_004f0840(void* self);

namespace G3D {

// INFERRED: polymorphic base with a virtual destructor, which produces the second vtable store.
class WeakReferenceCountedPointerBase {
public:
    WeakReferenceCountedPointerBase() {}
    virtual ~WeakReferenceCountedPointerBase() {}
};

template <class T>
class WeakReferenceCountedPointer : public WeakReferenceCountedPointerBase {
private:
    void* m_weakProxy;   // INFERRED: member layout
    T*    m_pointer;     // INFERRED: member layout

    void zeroPointer() {
        fn_004f0840(this);
    }

public:
    WeakReferenceCountedPointer() : m_weakProxy(0), m_pointer(0) {}

    virtual ~WeakReferenceCountedPointer() {
        zeroPointer();
    }
};

// Explicit instantiation emits the vftable and the deleting destructor.
template class WeakReferenceCountedPointer<RBX::RenderBase::Chunk>;

} // namespace G3D
