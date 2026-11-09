// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Worker { public: void stop(); };
class CWnd { public: virtual void dummy(); long Default(); };
class CView : public CWnd {
public:
    char pad[0xf0 - 4];
    Worker* worker;

    void OnActivate(int bActive);
};
void CView::OnActivate(int bActive)
{
    if (!bActive)
        worker->stop();
    Default();
}
