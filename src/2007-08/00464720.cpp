// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00464720  unit: DxUserInput  size: 294 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464720
//
// 00464720  6aff                 push -1
// 00464722  68b62f7400           push 0x742fb6
// 00464727  64a100000000         mov eax, dword ptr fs:[0]
// 0046472d  50                   push eax
// 0046472e  83ec18               sub esp, 0x18
// 00464731  56                   push esi
// 00464732  57                   push edi
// 00464733  a188518b00           mov eax, dword ptr [0x8b5188]
// 00464738  33c4                 xor eax, esp
// 0046473a  50                   push eax
// 0046473b  8d442424             lea eax, [esp + 0x24]
// 0046473f  64a300000000         mov dword ptr fs:[0], eax
// 00464745  8bf1                 mov esi, ecx
// 00464747  8d4634               lea eax, [esi + 0x34]
// 0046474a  8d4c2414             lea ecx, [esp + 0x14]
// 0046474e  89442414             mov dword ptr [esp + 0x14], eax
// 00464752  c644241800           mov byte ptr [esp + 0x18], 0
// 00464757  e81491fbff           call 0x41d870
// 0046475c  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00464762  85c0                 test eax, eax
// 00464764  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0046476c  0f84b0000000         je 0x464822
// 00464772  807e6800             cmp byte ptr [esi + 0x68], 0
// 00464776  0f84a6000000         je 0x464822
// 0046477c  8b08                 mov ecx, dword ptr [eax]
// 0046477e  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00464781  50                   push eax
// 00464782  ffd2                 call edx
// 00464784  8d44241c             lea eax, [esp + 0x1c]
// 00464788  50                   push eax
// 00464789  8bce                 mov ecx, esi
// 0046478b  e8f0f9ffff           call 0x464180
// 00464790  d9442420             fld dword ptr [esp + 0x20]
// 00464794  e8c7c51c00           call 0x630d60
// 00464799  d944241c             fld dword ptr [esp + 0x1c]
// 0046479d  8bf8                 mov edi, eax
// 0046479f  e8bcc51c00           call 0x630d60
// 004647a4  8944240c             mov dword ptr [esp + 0xc], eax
// 004647a8  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 004647ae  8d4c240c             lea ecx, [esp + 0xc]
// 004647b2  897c2410             mov dword ptr [esp + 0x10], edi
// 004647b6  8b5020               mov edx, dword ptr [eax + 0x20]
// 004647b9  51                   push ecx
// 004647ba  52                   push edx
// 004647bb  ff15f0ed7700         call dword ptr [0x77edf0]
// 004647c1  8b442410             mov eax, dword ptr [esp + 0x10]
// 004647c5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004647c9  50                   push eax
// 004647ca  51                   push ecx
// 004647cb  ff155ced7700         call dword ptr [0x77ed5c]
// 004647d1  f605d4c08b0001       test byte ptr [0x8bc0d4], 1
// 004647d8  7523                 jne 0x4647fd
// 004647da  830dd4c08b0001       or dword ptr [0x8bc0d4], 1
// 004647e1  c644242c01           mov byte ptr [esp + 0x2c], 1
// 004647e6  e817b71c00           call 0x62ff02
// 004647eb  68007f0000           push 0x7f00
// 004647f0  6a00                 push 0
// 004647f2  ff1520ec7700         call dword ptr [0x77ec20]
// 004647f8  a3d0c08b00           mov dword ptr [0x8bc0d0], eax
// 004647fd  8b15d0c08b00         mov edx, dword ptr [0x8bc0d0]
// 00464803  52                   push edx
// 00464804  ff1560ed7700         call dword ptr [0x77ed60]
// 0046480a  8b8680010000         mov eax, dword ptr [esi + 0x180]
// 00464810  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00464813  6a01                 push 1
// 00464815  6a00                 push 0
// 00464817  51                   push ecx
// 00464818  ff15dcec7700         call dword ptr [0x77ecdc]
// 0046481e  c6466800             mov byte ptr [esi + 0x68], 0
// 00464822  807c241800           cmp byte ptr [esp + 0x18], 0
// 00464827  740b                 je 0x464834
// 00464829  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046482d  52                   push edx
// 0046482e  ff15f8d27700         call dword ptr [0x77d2f8]
// 00464834  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00464838  64890d00000000       mov dword ptr fs:[0], ecx
// 0046483f  59                   pop ecx
// 00464840  5f                   pop edi
// 00464841  5e                   pop esi
// 00464842  83c424               add esp, 0x24
// 00464845  c3                   ret 

typedef struct HWND__* HWND;
typedef struct HICON__* HCURSOR;
typedef struct HINSTANCE__* HINSTANCE;
typedef int BOOL;
typedef const char* LPCSTR;
struct POINT { long x; long y; };
struct RECT { long left, top, right, bottom; };
struct CRITICAL_SECTION { void* DebugInfo; long LockCount; long RecursionCount; void* OwningThread; void* LockSemaphore; unsigned long SpinCount; };

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) BOOL __stdcall ClientToScreen(HWND, POINT*);
extern "C" __declspec(dllimport) BOOL __stdcall InvalidateRect(HWND, const RECT*, BOOL);
extern "C" __declspec(dllimport) HCURSOR __stdcall LoadCursorA(HINSTANCE, LPCSTR);
extern "C" __declspec(dllimport) HCURSOR __stdcall SetCursor(HCURSOR);
extern "C" __declspec(dllimport) BOOL __stdcall SetCursorPos(int, int);

struct CWinApp {
    HCURSOR LoadStandardCursor(LPCSTR lpszCursorName) const { return ::LoadCursorA(0, lpszCursorName); }
};
CWinApp* AfxGetApp();

struct CWnd {
    char pad[0x20];
    HWND m_hWnd;
    void ClientToScreen(POINT* lpPoint) const { ::ClientToScreen(m_hWnd, lpPoint); }
    void Invalidate(BOOL bErase = 1) { ::InvalidateRect(m_hWnd, 0, bErase); }
};

struct IDirectInputDevice8A {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCapabilities(void*) = 0;
    virtual long __stdcall EnumObjects(void*, void*, unsigned long) = 0;
    virtual long __stdcall GetProperty(const void*, void*) = 0;
    virtual long __stdcall SetProperty(const void*, const void*) = 0;
    virtual long __stdcall Acquire() = 0;
    virtual long __stdcall Unacquire() = 0;
};

struct CPoint : public POINT {
    CPoint(int initX, int initY) { x = initX; y = initY; }
};

struct Vector2 { float x; float y; };

class ScopedLock {
public:
    CRITICAL_SECTION* cs;
    bool locked;
    ScopedLock(CRITICAL_SECTION& c) : cs(&c), locked(false) { lock(); }
    ~ScopedLock() { if (locked) LeaveCriticalSection(cs); }
    void lock();
};

struct DxUserInput {
    char pad0[0x34];
    CRITICAL_SECTION mutex;
    char pad4c[0x68 - 0x4c];
    bool mouseCaptured;
    char pad69[0x180 - 0x69];
    CWnd* wnd;
    char pad184[0x18c - 0x184];
    IDirectInputDevice8A* mouse;

    Vector2 getWindowCenter();
    void releaseMouse();
};

void DxUserInput::releaseMouse()
{
    ScopedLock lock(mutex);
    if (mouse && mouseCaptured) {
        mouse->Unacquire();
        Vector2 center = getWindowCenter();
        CPoint pt((int)center.x, (int)center.y);
        wnd->ClientToScreen(&pt);
        SetCursorPos(pt.x, pt.y);
        static HCURSOR arrow = AfxGetApp()->LoadStandardCursor((LPCSTR)0x7f00);
        SetCursor(arrow);
        wnd->Invalidate();
        mouseCaptured = false;
    }
}
