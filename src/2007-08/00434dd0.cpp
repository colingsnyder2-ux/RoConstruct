// from server: 82% by EspClaude
// from server: 64% by atomic.potato
// roc 2007-08 00434dd0  unit: CMemberTreeView  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434dd0
//
// 00434dd0  8b442404             mov eax, dword ptr [esp + 4]
// 00434dd4  57                   push edi
// 00434dd5  50                   push eax
// 00434dd6  8bf9                 mov edi, ecx
// 00434dd8  e869b81f00           call 0x630646
// 00434ddd  83f8ff               cmp eax, -1
// 00434de0  742b                 je 0x434e0d
// 00434de2  8b5760               mov edx, dword ptr [edi + 0x60]
// 00434de5  8b4244               mov eax, dword ptr [edx + 0x44]
// 00434de8  8d4f60               lea ecx, [edi + 0x60]
// 00434deb  ffd0                 call eax
// 00434ded  56                   push esi
// 00434dee  8db7a0000000         lea esi, [edi + 0xa0]
// 00434df4  68c4000000           push 0xc4
// 00434df9  e872faffff           call 0x434870
// 00434dfe  83c404               add esp, 4
// 00434e01  85c0                 test eax, eax
// 00434e03  750f                 jne 0x434e14
// 00434e05  5e                   pop esi
// 00434e06  83c8ff               or eax, 0xffffffff
// 00434e09  5f                   pop edi
// 00434e0a  c20400               ret 4
// 00434e0d  83c8ff               or eax, 0xffffffff
// 00434e10  5f                   pop edi
// 00434e11  c20400               ret 4
// 00434e14  85f6                 test esi, esi
// 00434e16  7403                 je 0x434e1b
// 00434e18  8b7604               mov esi, dword ptr [esi + 4]
// 00434e1b  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00434e1e  56                   push esi
// 00434e1f  6a00                 push 0
// 00434e21  6809110000           push 0x1109
// 00434e26  51                   push ecx
// 00434e27  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00434e2d  50                   push eax
// 00434e2e  e869b61f00           call 0x63049c
// 00434e33  5e                   pop esi

// Layout from the target bytes: m_hWnd at +0x20 (mov ecx,[edi+0x20] -> SendMessageA hwnd),
// a polymorphic member at +0x60 (vcall slot +0x44 with ecx=this+0x60),
// an image list at +0xa0 whose handle is at +4 (mov esi,[esi+4]).
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CImageList
{
    void* vptr;
    void* m_hImageList;
    static CImageList* __stdcall FromHandle(void* h);
    int Create(int cx, int cy, unsigned int flags, int nInitial, int nGrow);
    void* GetSafeHandle() const { return this == 0 ? 0 : m_hImageList; }
};

class CMember60
{
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void v17();
};

// 0x434870 receives the image list in esi (mov ecx,esi; call CImageList::Create(16,16,0x19,0,1))
// and the resource id on the stack: a static helper of this unit.
// Proven by 0x434870: push id(word); push 2; push id; call 0x630478 (stdcall, 2 args);
// push eax; call [0x77eda8] (stdcall, 2 args) -> AfxFindResourceHandle / LoadBitmapA.
void* __stdcall AfxFindResourceHandle(const char* lpszName, const char* lpszType);
extern "C" __declspec(dllimport) void* __stdcall LoadBitmapA(void* hInstance, const char* lpBitmapName);

static __declspec(noinline) int LoadImageList(CImageList& il, unsigned int id)
{
    if (!il.Create(16, 16, 0x19, 0, 1))
        return 0;
    const char* res = (const char*)(unsigned short)id;
    void* bmp = LoadBitmapA(AfxFindResourceHandle(res, (const char*)2), res);
    return bmp != 0;
}

struct CTreeViewBase
{
    char pad00[0x20];
    void* m_hWnd;
    int OnCreate(void* lpCreateStruct);
};


struct CMemberTreeView : CTreeViewBase
{
    char pad24[0x60 - 0x24];
    CMember60 m_member;
    char pad64[0xa0 - 0x64];
    CImageList m_imageList;

    int OnCreate(void* lpCreateStruct);
};

int CMemberTreeView::OnCreate(void* lpCreateStruct)
{
    if (CTreeViewBase::OnCreate(lpCreateStruct) != -1)
    {
        m_member.v17();

        if (!LoadImageList(m_imageList, 0xc4))
            return -1;

        CImageList::FromHandle((void*)SendMessageA(m_hWnd, 0x1109, 0, (long)(&m_imageList)->GetSafeHandle()));
        return 0;
    }
    return -1;
}
