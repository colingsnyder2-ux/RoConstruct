// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063fba0  unit: RBX::GrabTool  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063fba0
//
// 0063fba0  6aff                 push -1
// 0063fba2  68f8a97d00           push 0x7da9f8
// 0063fba7  64a100000000         mov eax, dword ptr fs:[0]
// 0063fbad  50                   push eax
// 0063fbae  64892500000000       mov dword ptr fs:[0], esp
// 0063fbb5  51                   push ecx
// 0063fbb6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063fbba  56                   push esi
// 0063fbbb  8bf1                 mov esi, ecx
// 0063fbbd  50                   push eax
// 0063fbbe  89742408             mov dword ptr [esp + 8], esi
// 0063fbc2  e8295efdff           call 0x6159f0
// 0063fbc7  6850388300           push 0x833850
// 0063fbcc  8d4e1c               lea ecx, [esi + 0x1c]
// 0063fbcf  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0063fbd7  c70654a48400         mov dword ptr [esi], 0x84a454
// 0063fbdd  c746043ca48400       mov dword ptr [esi + 4], 0x84a43c
// 0063fbe4  ff1558248000         call dword ptr [0x802458]
// 0063fbea  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0063fbee  8bc6                 mov eax, esi
// 0063fbf0  5e                   pop esi
// 0063fbf1  64890d00000000       mov dword ptr fs:[0], ecx
// 0063fbf8  83c410               add esp, 0x10
// 0063fbfb  c20400               ret 4

struct Base {
    char storage[28];
    Base(int);
    ~Base();
};

struct S : Base {
    char cursor[28];
    S(int);
};

extern unsigned long primaryTable[];
extern unsigned long secondaryTable[];

typedef void* (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

S::S(int a1) : Base(a1)
{
    constructString(
        (*(unsigned long**)((char*)this + 0) = primaryTable,
         *(unsigned long**)((char*)this + 4) = secondaryTable,
         cursor),
        "ArrowCursor");
}
