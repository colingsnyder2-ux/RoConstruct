// from server: 100% by Yeetserama
// hypothesis: 0040ac50 is CXTPCommandBarsSiteBase<TBase>::OnWndMsg for a
// TBase whose command-bars pointer sits at 0xf4, vs 0xd4 in the already exact
// 00430d40 analog. Reproduce the vendor inline method with an explicit layout.
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef int BOOL;

class CXTPCommandBars
{
public:
    BOOL OnFrameWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

struct TBase_func_0040ac50
{
    virtual void dummy();
    char pad0[0xf0];
    BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

struct Site_func_0040ac50 : TBase_func_0040ac50
{
    CXTPCommandBars* m_pCommandBars;
    BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
};

BOOL Site_func_0040ac50::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    if (m_pCommandBars && m_pCommandBars->OnFrameWndMsg(message, wParam, lParam, pResult))
        return 1;
    return TBase_func_0040ac50::OnWndMsg(message, wParam, lParam, pResult);
}
