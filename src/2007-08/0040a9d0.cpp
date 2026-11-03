// from server: 100% by EspClaude
// roc 2007-08 0040a9d0  unit: CBrowserView
namespace ATL {
template<class T, bool b> class CSimpleStringT {
public:
    __declspec(dllimport) bool IsEmpty() const throw();
    T* m_pszData;
};
}
class CCmdUI {
public:
    virtual void Enable(int bOn = 1);
};
class CBrowserView {
    char pad[0x2b8];
    ATL::CSimpleStringT<char, true> m_url;
public:
    void OnUpdateCmd(CCmdUI* pCmdUI);
};
void CBrowserView::OnUpdateCmd(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(!m_url.IsEmpty());
}
