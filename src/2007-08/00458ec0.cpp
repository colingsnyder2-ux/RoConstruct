// from server: 100% by EspClaude
// roc 2007-08 00458ec0  unit: CRobloxWnd  size: 279 bytes
// Target disassembly: see roc check 2007-08 00458ec0 --context (no header in stored source).
// Layout evidence (offsets from the target):
//   CRobloxWnd: m_hWnd +0x20, bool flag +0x78
//   params object (ctor 457d30, 0x5c bytes, std::string member at +0x40 destroyed through the IAT)
//     +0x00 a, +0x04 b, +0x14 = 8, +0x18 = flag?8:0, +0x1c = 0x18, +0x20 = 8, +0x24 = global dword
//   dc object (0x14 bytes, ctor(CWnd*) / dtor non-import, handle at +0x04)

#include <string>

struct tagRECT { long left, top, right, bottom; };
struct HWND__;
extern "C" __declspec(dllimport) int __stdcall GetClientRect(HWND__* hWnd, tagRECT* lpRect);

extern int g_888554;

class CRobloxWnd;

struct DrawParams {
    int a;              // +0x00
    int b;              // +0x04
    int pad08[3];
    int f14;            // +0x14
    int f18;            // +0x18
    int f1c;            // +0x1c
    int f20;            // +0x20
    int f24;            // +0x24
    int pad28[6];
    std::string text;   // +0x40
    int f5c;            // +0x5c (frame size 0x88 proves object ends at 0x60)
    DrawParams();
};

struct ClientDC {
    int vptr_;
    void* hdc;          // +0x04
    int rest[3];
    ClientDC(CRobloxWnd* wnd);
    ~ClientDC();
};

void* sub_47f7a0(DrawParams* p, void* hdc);

class CRobloxWnd {
public:
    char pad[0x20];
    HWND__* m_hWnd;     // +0x20
    char pad2[0x78 - 0x24];
    bool flag78;        // +0x78
    void sub_458980(void* p);
    void sub_458ec0(int a, int b);
};

void CRobloxWnd::sub_458ec0(int a, int b)
{
    DrawParams params;
    params.a = a;
    params.b = b;
    params.f20 = 8;
    params.f14 = 8;
    params.f1c = 0x18;
    params.f18 = flag78 ? 8 : 0;
    params.f24 = g_888554;
    ClientDC dc(this);
    tagRECT rc;
    GetClientRect(m_hWnd, &rc);
    sub_458980(sub_47f7a0(&params, dc.hdc));
}
