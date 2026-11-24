// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: the target bytes use the unoptimized frame style (push ebp, local
// copy of this at [ebp-4]), so optimization is turned off for this file with
// #pragma optimize. The pragma is deliberately never restored, so the
// compiler-generated scalar deleting destructor is emitted unoptimized too.
// INFERRED: no native header for WmlConvexHull3 was shown, so a minimal
// Triangle declaration is defined here.
#pragma optimize("", off)

namespace Wml {

template <class Real>
class ConvexHull3 {
public:
    class Triangle {
    public:
        Triangle() : m_iV0(0), m_iV1(0), m_iV2(0) {}
        // INFERRED: destructor is out-of-line in the original (the deleting
        // destructor calls it; the linker folded it with RbxSubMesh::~RbxSubMesh).
        __declspec(noinline) virtual ~Triangle();
        int m_iV0, m_iV1, m_iV2;
    };
};

template <class Real>
ConvexHull3<Real>::Triangle::~Triangle()
{
}

// Explicit instantiation forces emission of the vtable and the
// scalar deleting destructor for ConvexHull3<float>::Triangle.
template class ConvexHull3<float>;
template class ConvexHull3<float>::Triangle;

}
