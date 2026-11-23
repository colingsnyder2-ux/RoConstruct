// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Wml headers were provided, so Box2 and Vector2 are declared minimally here.
// The layout follows Wild Magic's Box2: center, two axes, then two extents. With doubles
// that puts m_afExtent at offset 0x30, matching the disassembly's "add eax, 0x30".

namespace Wml {

template <class Real>
struct Vector2 {
    Real m_afTuple[2];
};

template <class Real>
class Box2 {
public:
    const Real* Extents() const;

protected:
    Vector2<Real> m_kCenter;
    Vector2<Real> m_akAxis[2];
    Real m_afExtent[2];
};

template <class Real>
const Real* Box2<Real>::Extents() const
{
    return m_afExtent;
}

template class Box2<double>;

} // namespace Wml
