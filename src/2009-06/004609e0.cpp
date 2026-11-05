// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class CWnd { public: long Default(); };
class CRobloxWnd : public CWnd {
public:
    char pad[0xb0]; int mode;
    void apply(unsigned int nType, int cx, int cy);
    void resize(unsigned int nType, int cx, int cy);
    void OnSize(unsigned int nType, int cx, int cy);
};
void CRobloxWnd::OnSize(unsigned int nType, int cx, int cy)
{
    if (cx > 0 && cy > 0 && cx <= 0x2000 && cy <= 0x2000) {
        Default();
        if (mode == 2)
            apply(nType, cx, cy);
        else
            resize(nType, cx, cy);
    }
}
