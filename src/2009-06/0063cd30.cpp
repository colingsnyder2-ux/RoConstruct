// from server: 82% by EspClaude
// from server: 100% by Espeon
// roc 2008-06 005b10a0  unit: RBX::Accoutrement  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b10a0
//
// 005b10a0  56                   push esi
// 005b10a1  57                   push edi
// 005b10a2  8bf1                 mov esi, ecx
// 005b10a4  e8f7f7ffff           call 0x5b08a0
// 005b10a9  85c0                 test eax, eax
// 005b10ab  7504                 jne 0x5b10b1
// 005b10ad  33ff                 xor edi, edi
// 005b10af  eb3e                 jmp 0x5b10ef
// 005b10b1  56                   push esi
// 005b10b2  e81923ffff           call 0x5a33d0
// 005b10b7  83c404               add esp, 4
// 005b10ba  84c0                 test al, al
// 005b10bc  7507                 jne 0x5b10c5
// 005b10be  bf01000000           mov edi, 1
// 005b10c3  eb2a                 jmp 0x5b10ef
// 005b10c5  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005b10cb  50                   push eax
// 005b10cc  e84f890200           call 0x5d9a20
// 005b10d1  83c404               add esp, 4
// 005b10d4  85c0                 test eax, eax
// 005b10d6  7507                 jne 0x5b10df
// 005b10d8  b802000000           mov eax, 2
// 005b10dd  eb0e                 jmp 0x5b10ed
// 005b10df  8bc8                 mov ecx, eax
// 005b10e1  e82a7a0200           call 0x5d8b10
// 005b10e6  f7d8                 neg eax
// 005b10e8  1bc0                 sbb eax, eax
// 005b10ea  83e004               and eax, 4
// 005b10ed  8bf8                 mov edi, eax
// 005b10ef  56                   push esi
// 005b10f0  e8db87edff           call 0x4898d0
// 005b10f5  83c404               add esp, 4
// 005b10f8  50                   push eax
// 005b10f9  57                   push edi
// 005b10fa  8bce                 mov ecx, esi
// 005b10fc  e80f140000           call 0x5b2510
// 005b1101  5f                   pop edi
// 005b1102  5e                   pop esi
// 005b1103  c3                   ret 

// from server: 85% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S;

struct Controller {
    int check();
};

extern bool __cdecl validate(S*);
extern Controller* __cdecl resolve(void*);
extern void* __cdecl context(S*);

struct S {
    char padding[0x104];
    void* parent;

    void* find();
    void update(int, void*);
    inline int desired();
    void f();
};

inline int desiredParent(void* parent){Controller* controller=resolve(parent);if(!controller)return 2;return controller->check()?4:0;}
inline int S::desired(){if(!find())return 0;if(!validate(this))return 1;return desiredParent(parent);}
void S::f(){int result=desired();update(result,context(this));}
