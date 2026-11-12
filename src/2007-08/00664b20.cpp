// from server: 100% by EspClaude
// from server: 45% by atomic.potato
// roc 2007-08 00664b20  unit: CXTPReportRows  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00664b20
//
// 00664b20  6aff                 push -1
// 00664b22  68f8d87500           push 0x75d8f8
// 00664b27  64a100000000         mov eax, dword ptr fs:[0]
// 00664b2d  50                   push eax
// 00664b2e  83ec58               sub esp, 0x58
// 00664b31  a188518b00           mov eax, dword ptr [0x8b5188]
// 00664b36  33c4                 xor eax, esp
// 00664b38  89442454             mov dword ptr [esp + 0x54], eax
// 00664b3c  56                   push esi
// 00664b3d  a188518b00           mov eax, dword ptr [0x8b5188]
// 00664b42  33c4                 xor eax, esp
// 00664b44  50                   push eax
// 00664b45  8d442460             lea eax, [esp + 0x60]
// 00664b49  64a300000000         mov dword ptr fs:[0], eax
// 00664b4f  8bf1                 mov esi, ecx
// 00664b51  56                   push esi
// 00664b52  8d4c240c             lea ecx, [esp + 0xc]
// 00664b56  e835b9fcff           call 0x630490
// 00664b5b  8b4660               mov eax, dword ptr [esi + 0x60]
// 00664b5e  8b4068               mov eax, dword ptr [eax + 0x68]
// 00664b61  8d4e60               lea ecx, [esi + 0x60]
// 00664b64  6a01                 push 1
// 00664b66  8d54240c             lea edx, [esp + 0xc]
// 00664b6a  52                   push edx
// 00664b6b  c744247000000000     mov dword ptr [esp + 0x70], 0
// 00664b73  ffd0                 call eax
// 00664b75  8d4c2408             lea ecx, [esp + 8]
// 00664b79  c7442468ffffffff     mov dword ptr [esp + 0x68], 0xffffffff
// 00664b81  e804b9fcff           call 0x63048a
// 00664b86  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00664b8a  64890d00000000       mov dword ptr fs:[0], ecx
// 00664b91  59                   pop ecx
// 00664b92  5e                   pop esi
// 00664b93  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00664b97  33cc                 xor ecx, esp
// 00664b99  e880befcff           call 0x630a1e
// 00664b9e  83c464               add esp, 0x64
// 00664ba1  c3                   ret 

// Local object of 0x54 bytes built by thiscall ctor(this) and destroyed after: CPaintDC dc(this)
// (CDC 0x10 + m_hWnd + PAINTSTRUCT 0x40 = 0x54, matches the 0x58 frame with cookie at +0x54).
typedef struct HDC__* HDC;
typedef struct HWND__* HWND;
typedef int BOOL;
struct RECT { long left, top, right, bottom; };
struct PAINTSTRUCT { HDC hdc; BOOL fErase; RECT rcPaint; BOOL fRestore; BOOL fIncUpdate; unsigned char rgbReserved[32]; };
class CObject { public: virtual ~CObject(); };
class CCmdTarget : public CObject { public: char _c[0x1c]; };
class CWnd : public CCmdTarget { public: HWND m_hWnd; };
class CDC : public CObject {
public:
    HDC m_hDC;
    HDC m_hAttribDC;
    BOOL m_bPrinting;
};
class CPaintDC : public CDC {
public:
    CPaintDC(CWnd* pWnd);
    virtual ~CPaintDC();
    HWND m_hWnd;
    PAINTSTRUCT m_ps;
};

class CXTPReportRows : public CWnd {
public:
    char pad[0x60 - sizeof(CWnd)];
    void* field_60;   // object at +0x60, vtable slot +0x68 called with (CDC*, 1)
    void OnPaint();
};

void CXTPReportRows::OnPaint()
{
    CPaintDC dc(this);
    void* fn = *(void**)((char*)field_60 + 0x68);
    ((void (__thiscall*)(void*, CDC*, int))fn)(&field_60, &dc, 1);
}
