// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class CWnd {
public:
    virtual ~CWnd();
    void OnSetFocus(CWnd* pOldWnd);
};
class DxUserInput {
public:
    void setFocus(bool focus);
};
class CRobloxWnd : public CWnd {
public:
    void OnSetFocus(CWnd* pOldWnd);
    char pad[0xd4];
    DxUserInput* userInput;
};
void CRobloxWnd::OnSetFocus(CWnd* pOldWnd)
{
    CWnd::OnSetFocus(pOldWnd);
    if (userInput)
        userInput->setFocus(true);
}
