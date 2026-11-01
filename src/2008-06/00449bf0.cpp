// from server: 100% by EspClaude
// from server: 60% by colin
// roc 2008-06 00449bf0  unit: CIDEDocManager  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449bf0
//
// 00449bf0  6aff                 push -1
// 00449bf2  681afa7b00           push 0x7bfa1a
// 00449bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00449bfd  50                   push eax
// 00449bfe  64892500000000       mov dword ptr fs:[0], esp
// 00449c05  51                   push ecx
// 00449c06  57                   push edi
// 00449c07  8bf9                 mov edi, ecx
// 00449c09  8b4720               mov eax, dword ptr [edi + 0x20]
// 00449c0c  85c0                 test eax, eax
// 00449c0e  7437                 je 0x449c47
// 00449c10  8b4020               mov eax, dword ptr [eax + 0x20]
// 00449c13  50                   push eax
// 00449c14  ff153c2d8000         call dword ptr [0x802d3c]
// 00449c1a  85c0                 test eax, eax
// 00449c1c  750c                 jne 0x449c2a
// 00449c1e  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 00449c21  51                   push ecx
// 00449c22  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00449c25  e89648feff           call 0x42e4c0
// 00449c2a  8b5720               mov edx, dword ptr [edi + 0x20]
// 00449c2d  33c0                 xor eax, eax
// 00449c2f  394220               cmp dword ptr [edx + 0x20], eax
// 00449c32  5f                   pop edi
// 00449c33  0f95c0               setne al
// 00449c36  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00449c3a  64890d00000000       mov dword ptr fs:[0], ecx
// 00449c41  83c410               add esp, 0x10
// 00449c44  c20400               ret 4
// 00449c47  56                   push esi
// 00449c48  68b4040000           push 0x4b4
// 00449c4d  e8ce6c2500           call 0x6a0920
// 00449c52  83c404               add esp, 4
// 00449c55  89442408             mov dword ptr [esp + 8], eax
// 00449c59  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00449c61  85c0                 test eax, eax
// 00449c63  740b                 je 0x449c70
// 00449c65  8bc8                 mov ecx, eax
// 00449c67  e88485feff           call 0x4321f0
// 00449c6c  8bf0                 mov esi, eax
// 00449c6e  eb02                 jmp 0x449c72
// 00449c70  33f6                 xor esi, esi
// 00449c72  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00449c7a  85f6                 test esi, esi
// 00449c7c  741e                 je 0x449c9c
// 00449c7e  8b06                 mov eax, dword ptr [esi]
// 00449c80  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 00449c86  6a00                 push 0
// 00449c88  6a00                 push 0
// 00449c8a  680080cf00           push 0xcf8000
// 00449c8f  6880000000           push 0x80
// 00449c94  8bce                 mov ecx, esi
// 00449c96  ffd2                 call edx
// 00449c98  85c0                 test eax, eax
// 00449c9a  7515                 jne 0x449cb1
// 00449c9c  5e                   pop esi
// 00449c9d  33c0                 xor eax, eax
// 00449c9f  5f                   pop edi
// 00449ca0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00449ca4  64890d00000000       mov dword ptr fs:[0], ecx
// 00449cab  83c410               add esp, 0x10
// 00449cae  c20400               ret 4
// 00449cb1  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00449cb6  8bce                 mov ecx, esi
// 00449cb8  7407                 je 0x449cc1
// 00449cba  e8316dfeff           call 0x4309f0
// 00449cbf  eb07                 jmp 0x449cc8
// 00449cc1  6a00                 push 0
// 00449cc3  e88872feff           call 0x430f50
// 00449cc8  8b4620               mov eax, dword ptr [esi + 0x20]
// 00449ccb  6a01                 push 1
// 00449ccd  50                   push eax
// 00449cce  ff15082b8000         call dword ptr [0x802b08]
// 00449cd4  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 00449cd7  51                   push ecx
// 00449cd8  8bce                 mov ecx, esi
// 00449cda  e8e147feff           call 0x42e4c0
// 00449cdf  6683bf9000000000     cmp word ptr [edi + 0x90], 0
// 00449ce7  897720               mov dword ptr [edi + 0x20], esi
// 00449cea  7511                 jne 0x449cfd
// 00449cec  6683bf9200000000     cmp word ptr [edi + 0x92], 0
// 00449cf4  7507                 jne 0x449cfd
// 00449cf6  8bcf                 mov ecx, edi
// 00449cf8  e83b752500           call 0x6a1238
// 00449cfd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00449d01  5e                   pop esi
// 00449d02  b801000000           mov eax, 1
// 00449d07  5f                   pop edi
// 00449d08  64890d00000000       mov dword ptr fs:[0], ecx
// 00449d0f  83c410               add esp, 0x10
// 00449d12  c20400               ret 4

typedef struct HWND__* HWND;
extern "C" __declspec(dllimport) int __stdcall IsWindowVisible(HWND hwnd);
extern "C" __declspec(dllimport) void __stdcall DragAcceptFiles(HWND hwnd, int accept);

class CMainFrame {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual int LoadFrame(unsigned int id, unsigned long style, void* parent, void* context);
    char pad[0x1c];
    HWND m_hWnd;
    char pad2[0x4b4 - 0x24];
    CMainFrame();
    void restore(int state);
    void show();
    void showNormal(int flag);
    void DragAcceptFiles(int accept = 1) { ::DragAcceptFiles(m_hWnd, accept); }
    int IsWindowVisible() const { return ::IsWindowVisible(m_hWnd); }
};

class CIDEApp {
public:
    unsigned char padding[0x20];
    CMainFrame* m_pMainWnd;
    unsigned char pad24[0x28];
    int m_state;
    unsigned char pad50[0x40];
    unsigned short m_a;
    unsigned short m_b;

    void finish();
    int create(bool maximized);
};

int CIDEApp::create(bool maximized)
{
    if (m_pMainWnd != 0) {
        if (!m_pMainWnd->IsWindowVisible())
            m_pMainWnd->restore(m_state);
        return m_pMainWnd->m_hWnd != 0;
    }

    CMainFrame* frame = new CMainFrame;
    if (!frame)
        return 0;
    if (!frame->LoadFrame(0x80, 0xcf8000, 0, 0))
        return 0;

    if (maximized)
        frame->show();
    else
        frame->showNormal(0);

    frame->DragAcceptFiles();
    frame->restore(m_state);
    m_pMainWnd = frame;

    if (m_a == 0 && m_b == 0)
        finish();

    return 1;
}
