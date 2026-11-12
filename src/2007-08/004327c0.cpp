// from server: 100% by EspClaude
// roc 2007-08 004327c0  unit: CMainFrame  size: 424 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004327c0
//
// 004327c0  8b442404             mov eax, dword ptr [esp + 4]
// 004327c4  56                   push esi
// 004327c5  50                   push eax
// 004327c6  8bf1                 mov esi, ecx
// 004327c8  e8fbdd1f00           call 0x6305c8
// 004327cd  83f8ff               cmp eax, -1
// 004327d0  7506                 jne 0x4327d8
// 004327d2  0bc0                 or eax, eax
// 004327d4  5e                   pop esi
// 004327d5  c20400               ret 4
// 004327d8  57                   push edi
// 004327d9  6801e80000           push 0xe801
// 004327de  6800820050           push 0x50008200
// 004327e3  8dbec8030000         lea edi, [esi + 0x3c8]
// 004327e9  56                   push esi
// 004327ea  8bcf                 mov ecx, edi
// 004327ec  e8ef042600           call 0x692ce0
// 004327f1  85c0                 test eax, eax
// 004327f3  0f8468010000         je 0x432961
// 004327f9  6a05                 push 5
// 004327fb  68f0698800           push 0x8869f0
// 00432800  8bcf                 mov ecx, edi
// 00432802  e819122600           call 0x693a20
// 00432807  85c0                 test eax, eax
// 00432809  0f8452010000         je 0x432961
// 0043280f  68d4a67800           push 0x78a6d4
// 00432814  8bce                 mov ecx, esi
// 00432816  e825c9ffff           call 0x42f140
// 0043281b  85c0                 test eax, eax
// 0043281d  7508                 jne 0x432827
// 0043281f  5f                   pop edi
// 00432820  83c8ff               or eax, 0xffffffff
// 00432823  5e                   pop esi
// 00432824  c20400               ret 4
// 00432827  6a02                 push 2
// 00432829  8d8e9c030000         lea ecx, [esi + 0x39c]
// 0043282f  e89cf62500           call 0x691ed0
// 00432834  6a04                 push 4
// 00432836  e875b42000           call 0x63dcb0
// 0043283b  83c404               add esp, 4
// 0043283e  6a01                 push 1
// 00432840  8dbe20010000         lea edi, [esi + 0x120]
// 00432846  56                   push esi
// 00432847  8bcf                 mov ecx, edi
// 00432849  e8a2c02300           call 0x66e8f0
// 0043284e  6a09                 push 9
// 00432850  8bcf                 mov ecx, edi
// 00432852  e819cf2300           call 0x66f770
// 00432857  6a00                 push 0
// 00432859  8dbe6c020000         lea edi, [esi + 0x26c]
// 0043285f  56                   push esi
// 00432860  8bcf                 mov ecx, edi
// 00432862  e8e9892500           call 0x68b250
// 00432867  8bcf                 mov ecx, edi
// 00432869  e8d26e2500           call 0x689740
// 0043286e  6a01                 push 1
// 00432870  8bcf                 mov ecx, edi
// 00432872  c7402400000000       mov dword ptr [eax + 0x24], 0
// 00432879  e832732500           call 0x689bb0
// 0043287e  8bbed8000000         mov edi, dword ptr [esi + 0xd8]
// 00432884  85ff                 test edi, edi
// 00432886  0f84d5000000         je 0x432961
// 0043288c  6a00                 push 0
// 0043288e  6891000000           push 0x91
// 00432893  8bcf                 mov ecx, edi
// 00432895  e856f91f00           call 0x6321f0
// 0043289a  8bc8                 mov ecx, eax
// 0043289c  e8efc02100           call 0x64e990
// 004328a1  c7861802000001000000 mov dword ptr [esi + 0x218], 1
// 004328ab  c7861c02000001000000 mov dword ptr [esi + 0x21c], 1
// 004328b5  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 004328b8  6a02                 push 2
// 004328ba  e8a1f21f00           call 0x631b60
// 004328bf  6a02                 push 2
// 004328c1  8bcf                 mov ecx, edi
// 004328c3  e838f91f00           call 0x632200
// 004328c8  8bc8                 mov ecx, eax
// 004328ca  e861242600           call 0x694d30
// 004328cf  e8fcb62100           call 0x64dfd0
// 004328d4  83c004               add eax, 4
// 004328d7  50                   push eax
// 004328d8  ff15ecd27700         call dword ptr [0x77d2ec]
// 004328de  e8edb62100           call 0x64dfd0
// 004328e3  50                   push eax
// 004328e4  8bcf                 mov ecx, edi
// 004328e6  e8f5012000           call 0x632ae0
// 004328eb  6a00                 push 0
// 004328ed  6891000000           push 0x91
// 004328f2  e8d9b62100           call 0x64dfd0
// 004328f7  8bc8                 mov ecx, eax
// 004328f9  e892c02100           call 0x64e990
// 004328fe  6a01                 push 1
// 00432900  8bce                 mov ecx, esi
// 00432902  c686ec00000001       mov byte ptr [esi + 0xec], 1
// 00432909  e892eeffff           call 0x4317a0
// 0043290e  e8bdb62100           call 0x64dfd0
// 00432913  50                   push eax
// 00432914  e857d2ffff           call 0x42fb70
// 00432919  83c404               add esp, 4
// 0043291c  8bce                 mov ecx, esi
// 0043291e  e84de0ffff           call 0x430970
// 00432923  e8dad51f00           call 0x62ff02
// 00432928  8b4004               mov eax, dword ptr [eax + 4]
// 0043292b  6a00                 push 0
// 0043292d  681cb17800           push 0x78b11c
// 00432932  6810b17800           push 0x78b110
// 00432937  8bc8                 mov ecx, eax
// 00432939  e884dc1f00           call 0x6305c2
// 0043293e  83f801               cmp eax, 1
// 00432941  7508                 jne 0x43294b
// 00432943  50                   push eax
// 00432944  8bce                 mov ecx, esi
// 00432946  e835faffff           call 0x432380
// 0043294b  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0043294e  6a00                 push 0
// 00432950  6801810000           push 0x8101
// 00432955  6811010000           push 0x111
// 0043295a  51                   push ecx
// 0043295b  ff15d0ec7700         call dword ptr [0x77ecd0]
// 00432961  5f                   pop edi
// 00432962  33c0                 xor eax, eax
// 00432964  5e                   pop esi
// 00432965  c20400               ret 4

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef void* HWND;
struct CREATESTRUCT;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(HWND, UINT, UINT, long);

class CWnd;

class CStatusBar {
public:
    int Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID);
    int SetIndicators(const UINT* lpIDArray, int nIDCount);
};

struct Settings { int Apply(int, int); };
struct Item { int Apply(int, int); };

struct Shared {
    int f0;
    long refs;                                  // +4 (InterlockedIncrement(eax+4))
    int Apply(int, int);                        // 0x64e990
};
Shared* GetShared();                            // 0x64dfd0
void Publish(Shared*);                          // 0x42fb70

struct Sub74 { void SetMode(int); };
struct Inner { void Activate(int); };

struct Doc {
    char pad0[0x74];
    Sub74* m74;
    Item* GetItem();                            // 0x6321f0
    Inner* GetInner();                          // 0x632200
    void Attach(Shared*);                       // 0x632ae0
};

struct App { int GetProfileIntA(const char*, const char*, int); };
struct ModuleState { int f0; App* m_pCurrentWinApp; };
ModuleState* AfxGetModuleState();
void SetPriority(int);                          // 0x63dcb0

struct Pane120 { void Init(CWnd*, int); void SetStyle(int); };
struct Rec { char pad[0x24]; int m24; };
struct Pane26c { void Init(CWnd*, int); Rec* GetRec(); void Show(int); };
struct Pane39c { void Enable(int); };

struct ResourceTag;
extern const ResourceTag g_mainResource;

class CWnd {
public:
    char pad0[0x20];
    HWND m_hWnd;
    int OnCreate(CREATESTRUCT* lpCreateStruct);
};

static UINT indicators[] = { 0, 187, 190, 188, 189 };

class CMainFrame : public CWnd {
public:
    int OnCreate(CREATESTRUCT* lpCreateStruct);
    int LoadResources(const ResourceTag*);
    void SetMode(int);
    void InitViews();
    void EnterFullScreen(int);

    char pad24[0xd8 - 0x24];
    Doc* m_doc;                 // +0xd8
    char padDC[0xec - 0xdc];
    bool m_ready;               // +0xec
    char padED[0x120 - 0xed];
    Pane120 m_pane120;          // +0x120
    char pad121[0x218 - 0x121];
    int m_flag218;              // +0x218
    int m_flag21c;              // +0x21c
    char pad220[0x26c - 0x220];
    Pane26c m_pane26c;          // +0x26c
    char pad26d[0x39c - 0x26d];
    Pane39c m_pane39c;          // +0x39c
    char pad39d[0x3c8 - 0x39d];
    CStatusBar m_wndStatusBar;  // +0x3c8
};

int CMainFrame::OnCreate(CREATESTRUCT* lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    if (!m_wndStatusBar.Create(this, 0x50008200, 0xe801) ||
        !m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT)))
        return 0;
    if (!LoadResources(&g_mainResource))
        return -1;
    m_pane39c.Enable(2);
    SetPriority(4);
    m_pane120.Init(this, 1);
    m_pane120.SetStyle(9);
    m_pane26c.Init(this, 0);
    m_pane26c.GetRec()->m24 = 0;
    m_pane26c.Show(1);

    Doc* doc = m_doc;
    if (doc == 0)
        return 0;
    doc->GetItem()->Apply(0x91, 0);
    m_flag218 = 1;
    m_flag21c = 1;
    doc->m74->SetMode(2);
    doc->GetInner()->Activate(2);
    InterlockedIncrement(&GetShared()->refs);
    doc->Attach(GetShared());
    GetShared()->Apply(0x91, 0);
    m_ready = true;
    SetMode(1);
    Publish(GetShared());
    InitViews();
    App* app = AfxGetModuleState()->m_pCurrentWinApp;
    int full = app->GetProfileIntA("Settings", "fullscreen", 0);
    if (full == 1)
        EnterFullScreen(full);
    PostMessageA(m_hWnd, 0x111, 0x8101, 0);
    return 0;
}
