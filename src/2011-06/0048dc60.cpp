// from server: 100% by Yeetserama
// roc 2011-06 0048dc60  unit: CScriptEditor  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048dc60
//
// 0048dc60  6aff                 push -1
// 0048dc62  68395f9d00           push 0x9d5f39
// 0048dc67  64a100000000         mov eax, dword ptr fs:[0]
// 0048dc6d  50                   push eax
// 0048dc6e  64892500000000       mov dword ptr fs:[0], esp
// 0048dc75  51                   push ecx
// 0048dc76  53                   push ebx
// 0048dc77  56                   push esi
// 0048dc78  57                   push edi
// 0048dc79  e872d3ffff           call 0x48aff0
// 0048dc7e  8bf0                 mov esi, eax
// 0048dc80  6a01                 push 1
// 0048dc82  8bce                 mov ecx, esi
// 0048dc84  e877c0ffff           call 0x489d00
// 0048dc89  8bf8                 mov edi, eax
// 0048dc8b  6a01                 push 1
// 0048dc8d  57                   push edi
// 0048dc8e  8bce                 mov ecx, esi
// 0048dc90  e89bcbffff           call 0x48a830
// 0048dc95  6a01                 push 1
// 0048dc97  57                   push edi
// 0048dc98  8bce                 mov ecx, esi
// 0048dc9a  8bd8                 mov ebx, eax
// 0048dc9c  e8cfc8ffff           call 0x48a570
// 0048dca1  8d4c240c             lea ecx, [esp + 0xc]
// 0048dca5  8bf0                 mov esi, eax
// 0048dca7  ff15b42da400         call dword ptr [0xa42db4]
// 0048dcad  57                   push edi
// 0048dcae  56                   push esi
// 0048dcaf  53                   push ebx
// 0048dcb0  8d442418             lea eax, [esp + 0x18]
// 0048dcb4  68c7000000           push 0xc7
// 0048dcb9  50                   push eax
// 0048dcba  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0048dcc2  ff153423a400         call dword ptr [0xa42334]
// 0048dcc8  8b742434             mov esi, dword ptr [esp + 0x34]
// 0048dccc  8b3e                 mov edi, dword ptr [esi]
// 0048dcce  83c414               add esp, 0x14
// 0048dcd1  8d4c240c             lea ecx, [esp + 0xc]
// 0048dcd5  ff15c82da400         call dword ptr [0xa42dc8]
// 0048dcdb  8b570c               mov edx, dword ptr [edi + 0xc]
// 0048dcde  50                   push eax
// 0048dcdf  8bce                 mov ecx, esi
// 0048dce1  ffd2                 call edx
// 0048dce3  8d4c240c             lea ecx, [esp + 0xc]
// 0048dce7  ff15082ea400         call dword ptr [0xa42e08]
// 0048dced  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048dcf1  5f                   pop edi
// 0048dcf2  5e                   pop esi
// 0048dcf3  5b                   pop ebx
// 0048dcf4  64890d00000000       mov dword ptr fs:[0], ecx
// 0048dcfb  83c410               add esp, 0x10
// 0048dcfe  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX000005@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX000005 {
// from server: 100% by colin
struct Text;

extern void (__cdecl *formatText)(Text*, unsigned int, ...);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) const char* get() const;
};







struct Control {
    int query(int);
    int column(int, int);
    int line(int, int);
};

struct Target;

struct TargetTable {
    void (__thiscall *slot0)(Target*);
    void (__thiscall *slot1)(Target*);
    void (__thiscall *slot2)(Target*);
    void (__thiscall *setText)(Target*, const char*);
};

struct Target {
    TargetTable* table;
};

struct S {
    int* f();
    void update(Target*);
};

void S::update(Target* target)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->query(1);
    int column = control->column(position, 1);
    int line = control->line(position, 1);
    Text text;
    formatText(&text, 199, column, line, position);
    TargetTable* table = target->table;
    const char* value = text.get();
    table->setText(target, value);
}
}
