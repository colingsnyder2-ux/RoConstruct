// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0048d530  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d530
//
// 0048d530  6aff                 push -1
// 0048d532  6811637c00           push 0x7c6311
// 0048d537  64a100000000         mov eax, dword ptr fs:[0]
// 0048d53d  50                   push eax
// 0048d53e  64892500000000       mov dword ptr fs:[0], esp
// 0048d545  51                   push ecx
// 0048d546  56                   push esi
// 0048d547  c744240400000000     mov dword ptr [esp + 4], 0
// 0048d54f  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048d553  8d44241c             lea eax, [esp + 0x1c]
// 0048d557  50                   push eax
// 0048d558  8bce                 mov ecx, esi
// 0048d55a  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0048d562  e8c9f2ffff           call 0x48c830
// 0048d567  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048d56b  c744240401000000     mov dword ptr [esp + 4], 1
// 0048d573  c644241000           mov byte ptr [esp + 0x10], 0
// 0048d578  85c0                 test eax, eax
// 0048d57a  7415                 je 0x48d591
// 0048d57c  8b00                 mov eax, dword ptr [eax]
// 0048d57e  85c0                 test eax, eax
// 0048d580  740f                 je 0x48d591
// 0048d582  8d4c2424             lea ecx, [esp + 0x24]
// 0048d586  6a01                 push 1
// 0048d588  51                   push ecx
// 0048d589  8bd1                 mov edx, ecx
// 0048d58b  52                   push edx
// 0048d58c  ffd0                 call eax
// 0048d58e  83c40c               add esp, 0xc
// 0048d591  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0048d595  8bc6                 mov eax, esi
// 0048d597  5e                   pop esi
// 0048d598  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d59f  83c410               add esp, 0x10
// 0048d5a2  c3                   ret 

union FunctionBuffer {
    double alignment;
    char storage[24];
};

struct FunctionTable {
    void (__cdecl *manager)(FunctionBuffer*, FunctionBuffer*, int);
};

struct Function {
    FunctionTable* table;
    FunctionBuffer buffer;

    Function(const Function&);
    ~Function();
};

__forceinline Function::~Function()
{
    if (table) {
        void (__cdecl *manager)(FunctionBuffer*, FunctionBuffer*, int) =
            table->manager;
        if (manager)
            manager(&buffer, &buffer, 2);
    }
}

Function __cdecl copyFunction(Function value)
{
    return value;
}
