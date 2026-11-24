// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace Wml {

// INFERRED: no class header was provided. The real layout is unknown, so this
// declares only what the function needs: an int member at offset 0x1c
// (likely the hull's quantity, m_iHQuantity), with padding before it.
template <class Real>
class ConvexHull2 {
public:
    int GetQuantity() const { return m_iHQuantity; }

private:
    char m_pad[0x1c];
    int m_iHQuantity;
};

template int ConvexHull2<float>::GetQuantity() const;

} // namespace Wml
