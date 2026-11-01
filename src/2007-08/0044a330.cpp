// from server: 100% by Yeetserama
// roc 2007-08 0044a330  unit: CRobloxModule  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a330
//
// 0044a330  6aff                 push -1
// 0044a332  6815fe7300           push 0x73fe15
// 0044a337  64a100000000         mov eax, dword ptr fs:[0]
// 0044a33d  50                   push eax
// 0044a33e  51                   push ecx
// 0044a33f  56                   push esi
// 0044a340  57                   push edi
// 0044a341  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044a346  33c4                 xor eax, esp
// 0044a348  50                   push eax
// 0044a349  8d442410             lea eax, [esp + 0x10]
// 0044a34d  64a300000000         mov dword ptr fs:[0], eax
// 0044a353  8bf1                 mov esi, ecx
// 0044a355  8974240c             mov dword ptr [esp + 0xc], esi
// 0044a359  c70694077900         mov dword ptr [esi], 0x790794
// 0044a35f  8bbe0c010000         mov edi, dword ptr [esi + 0x10c]
// 0044a365  85ff                 test edi, edi
// 0044a367  c744241802000000     mov dword ptr [esp + 0x18], 2
// 0044a36f  7410                 je 0x44a381
// 0044a371  8bcf                 mov ecx, edi
// 0044a373  e868e5ffff           call 0x4488e0
// 0044a378  57                   push edi
// 0044a379  e8e4581e00           call 0x62fc62
// 0044a37e  83c404               add esp, 4
// 0044a381  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0044a387  c644241801           mov byte ptr [esp + 0x18], 1
// 0044a38c  ff15ace67700         call dword ptr [0x77e6ac]
// 0044a392  8d8ea4000000         lea ecx, [esi + 0xa4]
// 0044a398  c644241800           mov byte ptr [esp + 0x18], 0
// 0044a39d  e8cee9fdff           call 0x428d70
// 0044a3a2  8bce                 mov ecx, esi
// 0044a3a4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044a3ac  e80f641e00           call 0x6307c0
// 0044a3b1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044a3b5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a3bc  59                   pop ecx
// 0044a3bd  5f                   pop edi
// 0044a3be  5e                   pop esi
// 0044a3bf  83c410               add esp, 0x10
// 0044a3c2  c3                   ret 
// copied from an identical function in another client (function ??1CRobloxModule@@UAE@XZ)

// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);

void __cdecl operator delete(void *);

struct Base
{
    virtual ~Base();
    char storage[0xa0];
};

struct Member
{
    char storage[0x4c];
    ~Member();
};

struct String
{
    char storage[0x1c];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct Document
{
    ~Document();
};

struct CRobloxModule : Base
{
    Member member;
    String text;
    Document *document;

    virtual ~CRobloxModule();
};

CRobloxModule::~CRobloxModule()
{
    delete document;
}