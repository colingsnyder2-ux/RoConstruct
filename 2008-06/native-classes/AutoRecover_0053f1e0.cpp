// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target is a thunk that forwards (this, other) to 0x004d7db0.
// The addModel name in the callee comment looks like a mislabel from identical-code folding.
// INFERRED: SortedVertex has no header, so a minimal layout is declared here.
extern "C" bool __fastcall fn_004d7db0(const void* self, int unusedEdx, const void* other);

namespace Wml {
template <class Real>
class ConvexHull2 {
public:
    class SortedVertex {
    public:
        bool operator==(const SortedVertex& other) const;
    };
};

template <class Real>
bool ConvexHull2<Real>::SortedVertex::operator==(const SortedVertex& other) const
{
    return fn_004d7db0(this, 0, &other);
}

template class ConvexHull2<float>::SortedVertex;
}
