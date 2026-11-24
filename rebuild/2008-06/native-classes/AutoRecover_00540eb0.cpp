// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the callee at 0x00542660 carries the same mangled name as the target.
// It is probably an out-of-line initializer for the same nested type, so it is
// declared here as a fixed-name helper taking the object pointer.
extern "C" void __fastcall fn_00542660(void* self, int unusedEdx);

namespace Wml {

template <class Real>
class ConvexHull2 {
public:
    // INFERRED: member layout is unknown; only the constructor is recovered here.
    class SortedVertex {
    public:
        SortedVertex();
    };
};

template <>
ConvexHull2<float>::SortedVertex::SortedVertex()
{
    fn_00542660(this, 0);
}

} // namespace Wml
