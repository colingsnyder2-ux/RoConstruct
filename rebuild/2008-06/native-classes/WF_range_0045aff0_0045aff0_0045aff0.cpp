// native-flags: /O2 /Oy- /GS- /EHsc
#include <afxwin.h>

// NEEDS-DECL: BYTE m_flagA8; // at offset 0xa8 of CRobloxWnd
// NEEDS-DECL: LRESULT sub_0045aff0(UINT nMsg);

class CRobloxWnd : public CWnd
{
public:
    char m_pad[0xa8 - sizeof(CWnd)];
    BYTE m_flagA8;
    LRESULT sub_0045aff0(UINT nMsg);
};

LRESULT CRobloxWnd::sub_0045aff0(UINT)
{
    if (m_flagA8 != 0)
    {
        return Default();
    }
    return 1;
}
