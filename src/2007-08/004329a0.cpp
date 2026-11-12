// from server: 77% by EspClaude
// from server: 53% by colin
// roc 2007-08 004329a0  unit: CMainFrame  size: 521 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004329a0
//
// 004329a0  6aff                 push -1
// 004329a2  6835de7300           push 0x73de35
// 004329a7  64a100000000         mov eax, dword ptr fs:[0]
// 004329ad  50                   push eax
// 004329ae  81ec20010000         sub esp, 0x120
// 004329b4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004329b9  33c4                 xor eax, esp
// 004329bb  8984241c010000       mov dword ptr [esp + 0x11c], eax
// 004329c2  53                   push ebx
// 004329c3  55                   push ebp
// 004329c4  56                   push esi
// 004329c5  57                   push edi
// 004329c6  a188518b00           mov eax, dword ptr [0x8b5188]
// 004329cb  33c4                 xor eax, esp
// 004329cd  50                   push eax
// 004329ce  8d842434010000       lea eax, [esp + 0x134]
// 004329d5  64a300000000         mov dword ptr fs:[0], eax
// 004329db  8bf1                 mov esi, ecx
// 004329dd  89742428             mov dword ptr [esp + 0x28], esi
// 004329e1  e85a812300           call 0x66ab40
// 004329e6  33db                 xor ebx, ebx
// 004329e8  8dbedc000000         lea edi, [esi + 0xdc]
// 004329ee  899c243c010000       mov dword ptr [esp + 0x13c], ebx
// 004329f5  c70710a77800         mov dword ptr [edi], 0x78a710
// 004329fb  8d8ef0000000         lea ecx, [esi + 0xf0]
// 00432a01  c706fcb47800         mov dword ptr [esi], 0x78b4fc
// 00432a07  c707f0b47800         mov dword ptr [edi], 0x78b4f0
// 00432a0d  889ee0000000         mov byte ptr [esi + 0xe0], bl
// 00432a13  889ee1000000         mov byte ptr [esi + 0xe1], bl
// 00432a19  899ee4000000         mov dword ptr [esi + 0xe4], ebx
// 00432a1f  899ee8000000         mov dword ptr [esi + 0xe8], ebx
// 00432a25  889eec000000         mov byte ptr [esi + 0xec], bl
// 00432a2b  889eed000000         mov byte ptr [esi + 0xed], bl
// 00432a31  ff15acdd7700         call dword ptr [0x77ddac]
// 00432a37  8d8ef4000000         lea ecx, [esi + 0xf4]
// 00432a3d  c684243c01000002     mov byte ptr [esp + 0x13c], 2
// 00432a45  e866b12300           call 0x66dbb0
// 00432a4a  8dae20010000         lea ebp, [esi + 0x120]
// 00432a50  8bcd                 mov ecx, ebp
// 00432a52  e879d22300           call 0x66fcd0
// 00432a57  8d8e6c020000         lea ecx, [esi + 0x26c]
// 00432a5d  c684243c01000003     mov byte ptr [esp + 0x13c], 3
// 00432a65  e856822500           call 0x68acc0
// 00432a6a  899e90030000         mov dword ptr [esi + 0x390], ebx
// 00432a70  899e94030000         mov dword ptr [esi + 0x394], ebx
// 00432a76  899e98030000         mov dword ptr [esi + 0x398], ebx
// 00432a7c  8d8e9c030000         lea ecx, [esi + 0x39c]
// 00432a82  c684243c01000007     mov byte ptr [esp + 0x13c], 7
// 00432a8a  e8f1f32500           call 0x691e80
// 00432a8f  8d8ec8030000         lea ecx, [esi + 0x3c8]
// 00432a95  c684243c01000008     mov byte ptr [esp + 0x13c], 8
// 00432a9d  e85e002600           call 0x692b00
// 00432aa2  8d442418             lea eax, [esp + 0x18]
// 00432aa6  50                   push eax
// 00432aa7  6819000200           push 0x20019
// 00432aac  53                   push ebx
// 00432aad  6880ba7800           push 0x78ba80
// 00432ab2  6801000080           push 0x80000001
// 00432ab7  c684245001000009     mov byte ptr [esp + 0x150], 9
// 00432abf  895c2428             mov dword ptr [esp + 0x28], ebx
// 00432ac3  895c2430             mov dword ptr [esp + 0x30], ebx
// 00432ac7  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00432acb  ff1510d07700         call dword ptr [0x77d010]
// 00432ad1  3bc3                 cmp eax, ebx
// 00432ad3  752c                 jne 0x432b01
// 00432ad5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00432ad9  8d4c2420             lea ecx, [esp + 0x20]
// 00432add  51                   push ecx
// 00432ade  8d542418             lea edx, [esp + 0x18]
// 00432ae2  52                   push edx
// 00432ae3  8d4c242c             lea ecx, [esp + 0x2c]
// 00432ae7  51                   push ecx
// 00432ae8  53                   push ebx
// 00432ae9  6864ba7800           push 0x78ba64
// 00432aee  50                   push eax
// 00432aef  89442434             mov dword ptr [esp + 0x34], eax
// 00432af3  c744243804000000     mov dword ptr [esp + 0x38], 4
// 00432afb  ff1520d07700         call dword ptr [0x77d020]
// 00432b01  837c241401           cmp dword ptr [esp + 0x14], 1
// 00432b06  0f94c0               sete al
// 00432b09  a215b98b00           mov byte ptr [0x8bb915], al
// 00432b0e  a2f5308c00           mov byte ptr [0x8c30f5], al
// 00432b13  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00432b17  3bc3                 cmp eax, ebx
// 00432b19  7407                 je 0x432b22
// 00432b1b  50                   push eax
// 00432b1c  ff1508d07700         call dword ptr [0x77d008]
// 00432b22  8d54242c             lea edx, [esp + 0x2c]
// 00432b26  52                   push edx
// 00432b27  685cba7800           push 0x78ba5c
// 00432b2c  53                   push ebx
// 00432b2d  53                   push ebx
// 00432b2e  681a800000           push 0x801a
// 00432b33  53                   push ebx
// 00432b34  ff15c4eb7700         call dword ptr [0x77ebc4]
// 00432b3a  85c0                 test eax, eax
// 00432b3c  751a                 jne 0x432b58
// 00432b3e  8d44242c             lea eax, [esp + 0x2c]
// 00432b42  50                   push eax
// 00432b43  8d86f0000000         lea eax, [esi + 0xf0]
// 00432b49  6848ba7800           push 0x78ba48
// 00432b4e  50                   push eax
// 00432b4f  ff1594dd7700         call dword ptr [0x77dd94]
// 00432b55  83c40c               add esp, 0xc
// 00432b58  57                   push edi
// 00432b59  b920288a00           mov ecx, 0x8a2820
// 00432b5e  e8dd06ffff           call 0x423240
// 00432b63  e868b42100           call 0x64dfd0
// 00432b68  83c004               add eax, 4
// 00432b6b  50                   push eax
// 00432b6c  ff15ecd27700         call dword ptr [0x77d2ec]
// 00432b72  e859b42100           call 0x64dfd0
// 00432b77  50                   push eax
// 00432b78  8bcd                 mov ecx, ebp
// 00432b7a  e801b52300           call 0x66e080
// 00432b7f  8bc6                 mov eax, esi
// 00432b81  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 00432b88  64890d00000000       mov dword ptr fs:[0], ecx
// 00432b8f  59                   pop ecx
// 00432b90  5f                   pop edi
// 00432b91  5e                   pop esi
// 00432b92  5d                   pop ebp
// 00432b93  5b                   pop ebx
// 00432b94  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 00432b9b  33cc                 xor ecx, esp
// 00432b9d  e87cde1f00           call 0x630a1e
// 00432ba2  81c42c010000         add esp, 0x12c
// 00432ba8  c3                   ret 

typedef void *HKEY;
typedef unsigned long DWORD;

extern "C" {
__declspec(dllimport) long __stdcall RegOpenKeyExA(HKEY, const char *, DWORD, DWORD, HKEY *);
__declspec(dllimport) long __stdcall RegQueryValueExA(HKEY, const char *, DWORD *, DWORD *, unsigned char *, DWORD *);
__declspec(dllimport) long __stdcall RegCloseKey(HKEY);
__declspec(dllimport) long __stdcall SHGetFolderPathAndSubDirA(void *, int, void *, DWORD, const char *, char *);
__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile *);
}

struct __declspec(dllimport) String {
    char *data;
    String() throw();
    ~String() throw();
    void __cdecl Format(const char *format, ...);
};

struct FrameBase {
    FrameBase();
    virtual ~FrameBase();
    char pad[0xdc - 4];
};

struct Listener {
    virtual ~Listener() {}
};

struct Member0f4 {
    Member0f4();
    char pad[0x2c];
};

struct Shared {
    long pad;
    long volatile refs;
};
Shared *getShared();

struct Member120 {
    Member120();
    ~Member120();
    void attach(Shared *);
    char pad[0x14c];
};

struct Member26c {
    Member26c();
    ~Member26c();
    char pad[0x124];
};

template <class T> struct Ptr {
    T *p;
    Ptr() : p(0) {}
    ~Ptr();
};

struct Member39c {
    Member39c();
    ~Member39c();
    char pad[0x2c];
};

struct Member3c8 {
    Member3c8();
    ~Member3c8();
    int pad;
};

struct ListenerRegistry {
    void add(Listener *);
};
extern ListenerRegistry g_registry;

extern bool g_lockViewA;
extern bool g_lockViewB;

struct CMainFrame : FrameBase, Listener {
    bool m_e0;
    bool m_e1;
    int m_e4;
    int m_e8;
    bool m_ec;
    bool m_ed;
    String m_settingsPath;
    Member0f4 m_f4;
    Member120 m_120;
    Member26c m_26c;
    Ptr<int> m_390;
    Ptr<int> m_394;
    Ptr<int> m_398;
    Member39c m_39c;
    Member3c8 m_3c8;
    CMainFrame();
};

CMainFrame::CMainFrame()
    : m_e0(false), m_e1(false), m_e4(0), m_e8(0), m_ec(false), m_ed(false)
{
    DWORD value = 0;
    HKEY hOpen = 0;
    HKEY hKey = 0;
    if (RegOpenKeyExA((HKEY)0x80000001, "Software\\ROBLOX Corporation\\Roblox", 0, 0x20019, &hOpen) == 0) {
        hKey = hOpen;
        DWORD type;
        DWORD size = 4;
        RegQueryValueExA(hKey, "OverrideLockViewGamelayout", 0, &type, (unsigned char *)&value, &size);
    }
    bool lock = value == 1;
    g_lockViewA = lock;
    g_lockViewB = lock;
    if (hKey)
        RegCloseKey(hKey);

    char path[260];
    if (SHGetFolderPathAndSubDirA(0, 0x801a, 0, 0, "\\ROBLOX", path) == 0)
        m_settingsPath.Format("%s\\IDESettings.xml", path);

    g_registry.add(this);
    InterlockedIncrement(&getShared()->refs);
    m_120.attach(getShared());
}
