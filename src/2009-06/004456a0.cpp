// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
struct MSG { void* hwnd; unsigned int message; };
class CWinThread {
public:
    virtual int IsIdleMessage(MSG* pMsg);
};
class CApp : public CWinThread {
public:
    virtual int IsIdleMessage(MSG* pMsg);
};
int CApp::IsIdleMessage(MSG* pMsg)
{
    if (!CWinThread::IsIdleMessage(pMsg))
        return 0;
    if (pMsg->message == 0x484)
        return 0;
    static unsigned long lastTick = GetTickCount();
    if (GetTickCount() <= lastTick)
        return 0;
    lastTick = GetTickCount() + 333;
    return 1;
}
