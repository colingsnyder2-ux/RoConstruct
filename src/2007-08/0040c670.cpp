// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0040c670  unit: CBrowserView  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c670
//
// 0040c670  6aff                 push -1
// 0040c672  681a9c7300           push 0x739c1a
// 0040c677  64a100000000         mov eax, dword ptr fs:[0]
// 0040c67d  50                   push eax
// 0040c67e  83ec0c               sub esp, 0xc
// 0040c681  56                   push esi
// 0040c682  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040c687  33c4                 xor eax, esp
// 0040c689  50                   push eax
// 0040c68a  8d442414             lea eax, [esp + 0x14]
// 0040c68e  64a300000000         mov dword ptr fs:[0], eax
// 0040c694  8bf1                 mov esi, ecx
// 0040c696  89742410             mov dword ptr [esp + 0x10], esi
// 0040c69a  e871fdffff           call 0x40c410
// 0040c69f  8d44240c             lea eax, [esp + 0xc]
// 0040c6a3  50                   push eax
// 0040c6a4  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0040c6ac  c7067c5f7800         mov dword ptr [esi], 0x785f7c
// 0040c6b2  e879e0ffff           call 0x40a730
// 0040c6b7  68645f7800           push 0x785f64
// 0040c6bc  50                   push eax
// 0040c6bd  8d4c2414             lea ecx, [esp + 0x14]
// 0040c6c1  51                   push ecx
// 0040c6c2  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0040c6c7  e834e3ffff           call 0x40aa00
// 0040c6cc  83c410               add esp, 0x10
// 0040c6cf  50                   push eax
// 0040c6d0  8d8eb8020000         lea ecx, [esi + 0x2b8]
// 0040c6d6  c644242002           mov byte ptr [esp + 0x20], 2
// 0040c6db  ff1534d47700         call dword ptr [0x77d434]
// 0040c6e1  8d4c2408             lea ecx, [esp + 8]
// 0040c6e5  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040c6eb  8d4c240c             lea ecx, [esp + 0xc]
// 0040c6ef  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040c6f5  8bc6                 mov eax, esi
// 0040c6f7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040c6fb  64890d00000000       mov dword ptr fs:[0], ecx
// 0040c702  59                   pop ecx
// 0040c703  5e                   pop esi
// 0040c704  83c418               add esp, 0x18
// 0040c707  c3                   ret 

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

struct CStartPageView : CBrowserView {
    CStartPageView();
    virtual ~CStartPageView();
};

CStartPageView::CStartPageView()
{
    m_url = getBaseUrl() + "/IDE/Start.aspx";
}
