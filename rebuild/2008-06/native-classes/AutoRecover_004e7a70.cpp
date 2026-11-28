// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Unverified draft; byte-exact code generation is not established.

namespace RBX { namespace RenderBase { class AggregateChunk; } }
namespace PlayerNativeMaterial { class MaterialBase; }

namespace G3D {

class WeakReferenceCountedPointerBase {
public:
    virtual ~WeakReferenceCountedPointerBase() {}
};

template<class T>
class WeakReferenceCountedPointer;

template<>
class WeakReferenceCountedPointer<PlayerNativeMaterial::MaterialBase> {
public:
    void zeroPointer();
};

template<class T>
class WeakReferenceCountedPointer : public WeakReferenceCountedPointerBase {
    T* pointer;

public:
    virtual ~WeakReferenceCountedPointer() {
        reinterpret_cast<
            WeakReferenceCountedPointer<PlayerNativeMaterial::MaterialBase>*
        >(this)->zeroPointer();
    }
};

template class WeakReferenceCountedPointer<RBX::RenderBase::AggregateChunk>;

}
