// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0045df90  unit: Scintilla::CScintillaFindReplaceDlg  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045df90
//
// 0045df90  6aff                 push -1
// 0045df92  68f8257400           push 0x7425f8
// 0045df97  64a100000000         mov eax, dword ptr fs:[0]
// 0045df9d  50                   push eax
// 0045df9e  51                   push ecx
// 0045df9f  56                   push esi
// 0045dfa0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045dfa5  33c4                 xor eax, esp
// 0045dfa7  50                   push eax
// 0045dfa8  8d44240c             lea eax, [esp + 0xc]
// 0045dfac  64a300000000         mov dword ptr fs:[0], eax
// 0045dfb2  8bf1                 mov esi, ecx
// 0045dfb4  89742408             mov dword ptr [esp + 8], esi
// 0045dfb8  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 0045dfbe  85c0                 test eax, eax
// 0045dfc0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0045dfc8  c786b4000000c0417900 mov dword ptr [esi + 0xb4], 0x7941c0
// 0045dfd2  7409                 je 0x45dfdd
// 0045dfd4  50                   push eax
// 0045dfd5  e84c1f1d00           call 0x62ff26
// 0045dfda  83c404               add esp, 4
// 0045dfdd  8d4e58               lea ecx, [esi + 0x58]
// 0045dfe0  e84bdeffff           call 0x45be30
// 0045dfe5  8bce                 mov ecx, esi
// 0045dfe7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0045dfef  e80e251d00           call 0x630502
// 0045dff4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045dff8  64890d00000000       mov dword ptr fs:[0], ecx
// 0045dfff  59                   pop ecx
// 0045e000  5e                   pop esi
// 0045e001  83c410               add esp, 0x10
// 0045e004  c3                   ret 

void __cdecl operator delete(void*);

struct CDialogBase
{
    char pad[0x58];
    ~CDialogBase();
};

struct FindMember
{
    char pad[0x5c];
    ~FindMember();
};

struct OwnedBuffer
{
    void* p;
    virtual ~OwnedBuffer() throw()
    {
        if (p != 0)
            operator delete(p);
    }
};

struct CScintillaFindReplaceDlg : CDialogBase
{
    FindMember find;
    OwnedBuffer buf;
    ~CScintillaFindReplaceDlg();
};

CScintillaFindReplaceDlg::~CScintillaFindReplaceDlg()
{
}
