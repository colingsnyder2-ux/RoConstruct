// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00434950  unit: CObjectBrowser  size: 373 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434950
//
// 00434950  8b442404             mov eax, dword ptr [esp + 4]
// 00434954  83ec14               sub esp, 0x14
// 00434957  57                   push edi
// 00434958  50                   push eax
// 00434959  8bf9                 mov edi, ecx
// 0043495b  e8e6bc1f00           call 0x630646
// 00434960  83f8ff               cmp eax, -1
// 00434963  7509                 jne 0x43496e
// 00434965  0bc0                 or eax, eax
// 00434967  5f                   pop edi
// 00434968  83c414               add esp, 0x14
// 0043496b  c20400               ret 4
// 0043496e  8b5758               mov edx, dword ptr [edi + 0x58]
// 00434971  8b8240010000         mov eax, dword ptr [edx + 0x140]
// 00434977  56                   push esi
// 00434978  6800e90000           push 0xe900
// 0043497d  6800000050           push 0x50000000
// 00434982  6a02                 push 2
// 00434984  8d7758               lea esi, [edi + 0x58]
// 00434987  6a01                 push 1
// 00434989  57                   push edi
// 0043498a  8bce                 mov ecx, esi
// 0043498c  ffd0                 call eax
// 0043498e  85c0                 test eax, eax
// 00434990  750b                 jne 0x43499d
// 00434992  5e                   pop esi
// 00434993  83c8ff               or eax, 0xffffffff
// 00434996  5f                   pop edi
// 00434997  83c414               add esp, 0x14
// 0043499a  c20400               ret 4
// 0043499d  8b16                 mov edx, dword ptr [esi]
// 0043499f  8b82c8010000         mov eax, dword ptr [edx + 0x1c8]
// 004349a5  53                   push ebx
// 004349a6  6a04                 push 4
// 004349a8  8bce                 mov ecx, esi
// 004349aa  ffd0                 call eax
// 004349ac  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 004349af  8b16                 mov edx, dword ptr [esi]
// 004349b1  33c0                 xor eax, eax
// 004349b3  89442410             mov dword ptr [esp + 0x10], eax
// 004349b7  894c2410             mov dword ptr [esp + 0x10], ecx
// 004349bb  8d5c240c             lea ebx, [esp + 0xc]
// 004349bf  53                   push ebx
// 004349c0  89442410             mov dword ptr [esp + 0x10], eax
// 004349c4  89442418             mov dword ptr [esp + 0x18], eax
// 004349c8  8944241c             mov dword ptr [esp + 0x1c], eax
// 004349cc  89442420             mov dword ptr [esp + 0x20], eax
// 004349d0  b958020000           mov ecx, 0x258
// 004349d5  51                   push ecx
// 004349d6  b8c8000000           mov eax, 0xc8
// 004349db  50                   push eax
// 004349dc  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 004349e2  6814c37800           push 0x78c314
// 004349e7  6a00                 push 0
// 004349e9  6a00                 push 0
// 004349eb  8bce                 mov ecx, esi
// 004349ed  ffd0                 call eax
// 004349ef  85c0                 test eax, eax
// 004349f1  0f8480000000         je 0x434a77
// 004349f7  8b9f70010000         mov ebx, dword ptr [edi + 0x170]
// 004349fd  6a01                 push 1
// 004349ff  81c770010000         add edi, 0x170
// 00434a05  6a00                 push 0
// 00434a07  8bce                 mov ecx, esi
// 00434a09  e8a2bb1f00           call 0x6305b0
// 00434a0e  8b9340010000         mov edx, dword ptr [ebx + 0x140]
// 00434a14  50                   push eax
// 00434a15  6800008050           push 0x50800000
// 00434a1a  6a01                 push 1
// 00434a1c  6a02                 push 2
// 00434a1e  56                   push esi
// 00434a1f  8bcf                 mov ecx, edi
// 00434a21  ffd2                 call edx
// 00434a23  85c0                 test eax, eax
// 00434a25  7450                 je 0x434a77
// 00434a27  8b17                 mov edx, dword ptr [edi]
// 00434a29  8d5c240c             lea ebx, [esp + 0xc]
// 00434a2d  53                   push ebx
// 00434a2e  b9c8000000           mov ecx, 0xc8
// 00434a33  51                   push ecx
// 00434a34  b82c010000           mov eax, 0x12c
// 00434a39  50                   push eax
// 00434a3a  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 00434a40  684cc37800           push 0x78c34c
// 00434a45  6a00                 push 0
// 00434a47  6a00                 push 0
// 00434a49  8bcf                 mov ecx, edi
// 00434a4b  ffd0                 call eax
// 00434a4d  85c0                 test eax, eax
// 00434a4f  7426                 je 0x434a77
// 00434a51  8b17                 mov edx, dword ptr [edi]
// 00434a53  53                   push ebx
// 00434a54  b9be000000           mov ecx, 0xbe
// 00434a59  51                   push ecx
// 00434a5a  b864000000           mov eax, 0x64
// 00434a5f  50                   push eax
// 00434a60  8b8244010000         mov eax, dword ptr [edx + 0x144]
// 00434a66  68f8c27800           push 0x78c2f8
// 00434a6b  6a00                 push 0
// 00434a6d  6a01                 push 1
// 00434a6f  8bcf                 mov ecx, edi
// 00434a71  ffd0                 call eax
// 00434a73  85c0                 test eax, eax
// 00434a75  750c                 jne 0x434a83
// 00434a77  5b                   pop ebx
// 00434a78  5e                   pop esi
// 00434a79  83c8ff               or eax, 0xffffffff
// 00434a7c  5f                   pop edi
// 00434a7d  83c414               add esp, 0x14
// 00434a80  c20400               ret 4
// 00434a83  6a00                 push 0
// 00434a85  6a00                 push 0
// 00434a87  8bce                 mov ecx, esi
// 00434a89  e8c4bb1f00           call 0x630652
// 00434a8e  6a00                 push 0
// 00434a90  6a00                 push 0
// 00434a92  8bcf                 mov ecx, edi
// 00434a94  8bf0                 mov esi, eax
// 00434a96  e8b7bb1f00           call 0x630652
// 00434a9b  6a00                 push 0
// 00434a9d  6a01                 push 1
// 00434a9f  8bcf                 mov ecx, edi
// 00434aa1  8bd8                 mov ebx, eax
// 00434aa3  e8aabb1f00           call 0x630652
// 00434aa8  899ea8000000         mov dword ptr [esi + 0xa8], ebx
// 00434aae  8986ac000000         mov dword ptr [esi + 0xac], eax
// 00434ab4  8983b0000000         mov dword ptr [ebx + 0xb0], eax
// 00434aba  5b                   pop ebx
// 00434abb  5e                   pop esi
// 00434abc  33c0                 xor eax, eax
// 00434abe  5f                   pop edi
// 00434abf  83c414               add esp, 0x14
// 00434ac2  c20400               ret 4

#include <string.h>
struct CRuntimeClass;
struct CWnd;

struct CCreateContext {
    CRuntimeClass* m_pNewViewClass;
    void* m_pCurrentDoc;
    void* m_pNewDocTemplate;
    CWnd* m_pLastView;
    CWnd* m_pCurrentFrame;
    CCreateContext() { memset(this, 0, sizeof(*this)); }
};

struct CSize {
    int cx, cy;
    CSize(int x, int y) { cx = x; cy = y; }
};

struct CSplitterWnd {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual int CreateStatic(CWnd* pParent, int nRows, int nCols, unsigned long dwStyle, unsigned int nID); // +0x140
    virtual int CreateView(int row, int col, CRuntimeClass* pViewClass, CSize sizeInit, CCreateContext* pContext); // +0x144
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v1c8(int); // +0x1c8
    int IdFromRowCol(int row, int col);
    CWnd* GetPane(int row, int col);
};

struct PaneA {
    char pad[0xa8];
    PaneA* fa8;
    PaneA* fac;
    PaneA* fb0;
};

extern CRuntimeClass classView1;
extern CRuntimeClass classView2;
extern CRuntimeClass classView3;

struct CObjectBrowser {
    char pad0[0x54];
    void* m_pDoc;
    CSplitterWnd m_wndSplitter;
    char pad5c[0x170 - 0x5c];
    CSplitterWnd m_wndSplitter2;
    int OnCreateBase(void* lpcs);
    int OnCreate(void* lpcs);
};

int CObjectBrowser::OnCreate(void* lpcs)
{
    if (OnCreateBase(lpcs) == -1)
        return -1;
    if (!m_wndSplitter.CreateStatic((CWnd*)this, 1, 2, 0x50000000, 0xe900))
        return -1;
    m_wndSplitter.v1c8(4);
    CCreateContext ctx;
    ctx.m_pCurrentDoc = m_pDoc;
    if (!m_wndSplitter.CreateView(0, 0, &classView1, CSize(200, 600), &ctx))
        return -1;
    if (!m_wndSplitter2.CreateStatic((CWnd*)&m_wndSplitter, 2, 1, 0x50800000, m_wndSplitter.IdFromRowCol(0, 1)))
        return -1;
    if (!m_wndSplitter2.CreateView(0, 0, &classView2, CSize(300, 200), &ctx))
        return -1;
    if (!m_wndSplitter2.CreateView(1, 0, &classView3, CSize(100, 190), &ctx))
        return -1;
    PaneA* a = (PaneA*)m_wndSplitter.GetPane(0, 0);
    PaneA* b = (PaneA*)m_wndSplitter2.GetPane(0, 0);
    PaneA* c = (PaneA*)m_wndSplitter2.GetPane(1, 0);
    a->fa8 = b;
    a->fac = c;
    b->fb0 = c;
    return 0;
}
