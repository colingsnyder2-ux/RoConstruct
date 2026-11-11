// from server: 100% by EspClaude
// from server: 85% by colin
// roc 2007-08 004313c0  unit: CMainFrame  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004313c0
//
// 004313c0  56                   push esi
// 004313c1  8bf1                 mov esi, ecx
// 004313c3  e83aeb1f00           call 0x62ff02
// 004313c8  8b4004               mov eax, dword ptr [eax + 4]
// 004313cb  33c9                 xor ecx, ecx
// 004313cd  388ee0000000         cmp byte ptr [esi + 0xe0], cl
// 004313d3  0f95c1               setne cl
// 004313d6  51                   push ecx
// 004313d7  681cb17800           push 0x78b11c
// 004313dc  6810b17800           push 0x78b110
// 004313e1  8bc8                 mov ecx, eax
// 004313e3  e8b6f11f00           call 0x63059e
// 004313e8  80bee000000000       cmp byte ptr [esi + 0xe0], 0
// 004313ef  7409                 je 0x4313fa
// 004313f1  8bce                 mov ecx, esi
// 004313f3  e808f4ffff           call 0x430800
// 004313f8  eb13                 jmp 0x43140d
// 004313fa  6a00                 push 0
// 004313fc  68b4a77800           push 0x78a7b4
// 00431401  56                   push esi
// 00431402  8d8ef4000000         lea ecx, [esi + 0xf4]
// 00431408  e8d3c72300           call 0x66dbe0
// 0043140d  80beec00000000       cmp byte ptr [esi + 0xec], 0
// 00431414  7409                 je 0x43141f
// 00431416  6a00                 push 0
// 00431418  8bce                 mov ecx, esi
// 0043141a  e8c1faffff           call 0x430ee0
// 0043141f  8bce                 mov ecx, esi
// 00431421  e872f11f00           call 0x630598
// 00431426  8d8e6c020000         lea ecx, [esi + 0x26c]
// 0043142c  5e                   pop esi
// 0043142d  e95ec12500           jmp 0x68d590

struct App {
    int WriteInt(const char*, const char*, int);
};

struct ModState {
    void* vt;
    App* m_pApp;
};

ModState* sub_62ff02();

struct CMainFrame;

struct DropTarget {
    int Register(CMainFrame*, const char*, int);
};

struct StatusBar {
    void sub_68d590();
};

struct CMainFrame {
    char pad[0xe0];
    bool m_bFullScreen;
    char pad2[0xec - 0xe1];
    bool m_bSomething;
    char pad3[0xf4 - 0xed];
    DropTarget m_dropTarget;
    char pad4[0x26c - 0xf5];
    StatusBar m_statusBar;

    void sub_430800();
    void sub_430ee0(int);
    void sub_630598();
    void func_004313c0();
};

extern const char str_78b110[];
extern const char str_78b11c[];
extern const char str_78a7b4[];

void CMainFrame::func_004313c0()
{
    App* app = sub_62ff02()->m_pApp;
    app->WriteInt(str_78b110, str_78b11c, m_bFullScreen ? 1 : 0);
    if (m_bFullScreen) {
        sub_430800();
    } else {
        m_dropTarget.Register(this, str_78a7b4, 0);
    }
    if (m_bSomething) {
        sub_430ee0(0);
    }
    sub_630598();
    m_statusBar.sub_68d590();
}
