// from server: 100% by Xemicl
// roc 2012-06 0046d2a0  unit: CRobloxApp  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d2a0
//
// 0046d2a0  56                   push esi
// 0046d2a1  8b742408             mov esi, dword ptr [esp + 8]
// 0046d2a5  56                   push esi
// 0046d2a6  e8b75a5100           call 0x982d62
// 0046d2ab  85c0                 test eax, eax
// 0046d2ad  7506                 jne 0x46d2b5
// 0046d2af  33c0                 xor eax, eax
// 0046d2b1  5e                   pop esi
// 0046d2b2  c20400               ret 4
// 0046d2b5  817e0484040000       cmp dword ptr [esi + 4], 0x484
// 0046d2bc  74f1                 je 0x46d2af
// 0046d2be  f60574a2e10001       test byte ptr [0xe1a274], 1
// 0046d2c5  8b357422b200         mov esi, dword ptr [0xb22274]
// 0046d2cb  750e                 jne 0x46d2db
// 0046d2cd  830d74a2e10001       or dword ptr [0xe1a274], 1
// 0046d2d4  ffd6                 call esi
// 0046d2d6  a370a2e100           mov dword ptr [0xe1a270], eax
// 0046d2db  ffd6                 call esi
// 0046d2dd  3b0570a2e100         cmp eax, dword ptr [0xe1a270]
// 0046d2e3  76ca                 jbe 0x46d2af
// 0046d2e5  ffd6                 call esi
// 0046d2e7  054d010000           add eax, 0x14d
// 0046d2ec  a370a2e100           mov dword ptr [0xe1a270], eax
// 0046d2f1  b801000000           mov eax, 1
// 0046d2f6  5e                   pop esi
// 0046d2f7  c20400               ret 4
// copied from an identical function in another client (function ?IsIdleMessage@CApp@@UAEHPAUMSG@@@Z)

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