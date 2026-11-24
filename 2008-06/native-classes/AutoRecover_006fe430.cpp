// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afx.h>

// INFERRED: minimal XTP layouts; offsets from the disassembly (m_bLoading +0x28, m_pArchive +0x44).
class CXTPPropExchange
{
public:
    CXTPPropExchange();
    virtual ~CXTPPropExchange();

    char m_pad04[0x24];
    BOOL m_bLoading;
    char m_pad2C[0x18];
};

class CXTPPropExchangeArchive : public CXTPPropExchange
{
public:
    CXTPPropExchangeArchive(CArchive& ar);
    virtual ~CXTPPropExchangeArchive();

    CArchive* m_pArchive;
};

CXTPPropExchangeArchive::CXTPPropExchangeArchive(CArchive& ar)
{
    m_pArchive = &ar;
    m_bLoading = ar.IsLoading();
}
