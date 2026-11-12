// from server: 100% by EspClaude
// from server: 49% by tester
// roc 2007-08 0040c710  unit: CBrowserView  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c710
//
// 0040c710  6aff                 push -1
// 0040c712  681a9c7300           push 0x739c1a
// 0040c717  64a100000000         mov eax, dword ptr fs:[0]
// 0040c71d  50                   push eax
// 0040c71e  83ec0c               sub esp, 0xc
// 0040c721  56                   push esi
// 0040c722  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040c727  33c4                 xor eax, esp
// 0040c729  50                   push eax
// 0040c72a  8d442414             lea eax, [esp + 0x14]
// 0040c72e  64a300000000         mov dword ptr fs:[0], eax
// 0040c734  8bf1                 mov esi, ecx
// 0040c736  89742410             mov dword ptr [esp + 0x10], esi
// 0040c73a  e8d1fcffff           call 0x40c410
// 0040c73f  8d44240c             lea eax, [esp + 0xc]
// 0040c743  50                   push eax
// 0040c744  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0040c74c  c706b4617800         mov dword ptr [esi], 0x7861b4
// 0040c752  e8d9dfffff           call 0x40a730
// 0040c757  68a4617800           push 0x7861a4
// 0040c75c  50                   push eax
// 0040c75d  8d4c2414             lea ecx, [esp + 0x14]
// 0040c761  51                   push ecx
// 0040c762  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040c767  e894e2ffff           call 0x40aa00
// 0040c76c  83c410               add esp, 0x10
// 0040c76f  50                   push eax
// 0040c770  8d8eb8020000         lea ecx, [esi + 0x2b8]
// 0040c776  c644242002           mov byte ptr [esp + 0x20], 2
// 0040c77b  ff1534d47700         call dword ptr [0x77d434]
// 0040c781  8d4c2408             lea ecx, [esp + 8]
// 0040c785  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040c78b  8d4c240c             lea ecx, [esp + 0xc]
// 0040c78f  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040c795  8bc6                 mov eax, esi
// 0040c797  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040c79b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040c7a2  59                   pop ecx
// 0040c7a3  5e                   pop esi
// 0040c7a4  83c418               add esp, 0x18
// 0040c7a7  c3                   ret 

struct String {
    char* data;
    String(const String&);
    __declspec(dllimport) ~String() throw();
    __declspec(dllimport) String& operator=(const String&);
};
struct BaseString {
    char* data;
    __declspec(dllimport) ~BaseString() throw();
};
BaseString __cdecl getBaseUrl();
String __cdecl operator+(const BaseString&, const char*);

struct CBrowserView {
    CBrowserView();
    virtual ~CBrowserView();
    char pad[0x2b4];
    String m_url;
};

struct CHomePageView : CBrowserView {
    CHomePageView();
    virtual ~CHomePageView();
};

CHomePageView::CHomePageView()
{
    m_url = getBaseUrl() + "/Start.aspx";
}
