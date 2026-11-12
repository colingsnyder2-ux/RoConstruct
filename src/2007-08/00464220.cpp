// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 00464220  unit: DxUserInput  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464220
//
// 00464220  83ec10               sub esp, 0x10
// 00464223  56                   push esi
// 00464224  8bf1                 mov esi, ecx
// 00464226  8d4634               lea eax, [esi + 0x34]
// 00464229  8d4c2404             lea ecx, [esp + 4]
// 0046422d  89442404             mov dword ptr [esp + 4], eax
// 00464231  c644240800           mov byte ptr [esp + 8], 0
// 00464236  e83596fbff           call 0x41d870
// 0046423b  8d4c240c             lea ecx, [esp + 0xc]
// 0046423f  51                   push ecx
// 00464240  ff1554ec7700         call dword ptr [0x77ec54]
// 00464246  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 0046424c  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0046424f  8d54240c             lea edx, [esp + 0xc]
// 00464253  52                   push edx
// 00464254  51                   push ecx
// 00464255  ff1550ec7700         call dword ptr [0x77ec50]
// 0046425b  db44240c             fild dword ptr [esp + 0xc]
// 0046425f  807c240800           cmp byte ptr [esp + 8], 0
// 00464264  8b742418             mov esi, dword ptr [esp + 0x18]
// 00464268  d91e                 fstp dword ptr [esi]
// 0046426a  db442410             fild dword ptr [esp + 0x10]
// 0046426e  d95e04               fstp dword ptr [esi + 4]
// 00464271  740b                 je 0x46427e
// 00464273  8b542404             mov edx, dword ptr [esp + 4]
// 00464277  52                   push edx
// 00464278  ff15f8d27700         call dword ptr [0x77d2f8]
// 0046427e  8bc6                 mov eax, esi

struct _RTL_CRITICAL_SECTION;
struct tagPOINT { long x; long y; };
struct HWND__;
extern "C" {
    __declspec(dllimport) int __stdcall GetCursorPos(tagPOINT* lpPoint);
    __declspec(dllimport) int __stdcall ScreenToClient(HWND__* hWnd, tagPOINT* lpPoint);
    __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* cs);
}

class Vector2 {
public:
    float x, y;
    Vector2(float _x, float _y) : x(_x), y(_y) {}
};

class ScopedLock {
public:
    _RTL_CRITICAL_SECTION* cs;
    bool locked;
    ScopedLock(_RTL_CRITICAL_SECTION* c) : cs(c), locked(false) { lock(); }
    ~ScopedLock() { if (locked) LeaveCriticalSection(cs); }
    void lock();
};

struct Window {
    char pad[0x20];
    HWND__* hwnd;
};

class DxUserInput {
public:
    char pad[0x34];
    char cs[0x180 - 0x34];
    Window* wnd;
    Vector2 getCursorPos();
};

Vector2 DxUserInput::getCursorPos()
{
    ScopedLock lock((_RTL_CRITICAL_SECTION*)cs);
    tagPOINT pt;
    GetCursorPos(&pt);
    ScreenToClient(wnd->hwnd, &pt);
    return Vector2((float)pt.x, (float)pt.y);
}
