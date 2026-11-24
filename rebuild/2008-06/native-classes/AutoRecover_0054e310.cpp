// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was supplied, so this is a minimal local
// reconstruction of Wml::AxisAlignedBox2 with only what XMin needs.
namespace Wml {

template <class Real>
class AxisAlignedBox2 {
public:
    Real& XMin();
private:
    Real m_fXMin, m_fXMax, m_fYMin, m_fYMax;
};

template <class Real>
Real& AxisAlignedBox2<Real>::XMin()
{
    return m_fXMin;
}

// Force emission of the float instantiation of XMin.
template float& AxisAlignedBox2<float>::XMin();

}
