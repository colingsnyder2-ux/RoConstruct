// from server: 74% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00424510  unit: CSelectionTreeCtrl  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00424510
//
// 00424510  6aff                 push -1
// 00424512  6874ea7b00           push 0x7bea74
// 00424517  64a100000000         mov eax, dword ptr fs:[0]
// 0042451d  50                   push eax
// 0042451e  64892500000000       mov dword ptr fs:[0], esp
// 00424525  51                   push ecx
// 00424526  56                   push esi
// 00424527  8bf1                 mov esi, ecx
// 00424529  89742404             mov dword ptr [esp + 4], esi
// 0042452d  8d8ec4000000         lea ecx, [esi + 0xc4]
// 00424533  c744241002000000     mov dword ptr [esp + 0x10], 2
// 0042453b  e870071700           call 0x594cb0
// 00424540  8d8ebc000000         lea ecx, [esi + 0xbc]
// 00424546  c644241001           mov byte ptr [esp + 0x10], 1
// 0042454b  e8e0e9feff           call 0x412f30
// 00424550  8d8e98000000         lea ecx, [esi + 0x98]
// 00424556  c644241000           mov byte ptr [esp + 0x10], 0
// 0042455b  e820f81200           call 0x553d80
// 00424560  8bce                 mov ecx, esi
// 00424562  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042456a  e851752b00           call 0x6dbac0
// 0042456f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00424573  5e                   pop esi
// 00424574  64890d00000000       mov dword ptr fs:[0], ecx
// 0042457b  83c410               add esp, 0x10
// 0042457e  c3                   ret 

struct Base_00424510 {
    char storage[0x98];
    ~Base_00424510();
};

struct Aggregate_00424510 {
    char storage[0x24];
    ~Aggregate_00424510();
};

struct MemberBase_00424510 {
    virtual ~MemberBase_00424510();
};

struct Member_00424510 : MemberBase_00424510 {
    char storage[4];
    ~Member_00424510();
};

struct Resource_00424510 {
    void *object;
    bool criticalSection;
    ~Resource_00424510();
};

struct S_00424510 : Base_00424510 {
    Aggregate_00424510 aggregate;
    Member_00424510 member;
    Resource_00424510 resource;
    ~S_00424510();
};

S_00424510::~S_00424510()
{
}
