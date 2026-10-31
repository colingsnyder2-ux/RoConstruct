// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057c670  unit: RBX::VInstance::?$SignalDesc  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057c670
//
// 0057c670  56                   push esi
// 0057c671  8bf1                 mov esi, ecx
// 0057c673  8b4604               mov eax, dword ptr [esi + 4]
// 0057c676  83f809               cmp eax, 9
// 0057c679  750f                 jne 0x57c68a
// 0057c67b  dd4608               fld qword ptr [esi + 8]
// 0057c67e  8b442408             mov eax, dword ptr [esp + 8]
// 0057c682  dd18                 fstp qword ptr [eax]
// 0057c684  b001                 mov al, 1
// 0057c686  5e                   pop esi
// 0057c687  c20400               ret 4
// 0057c68a  57                   push edi
// 0057c68b  83f807               cmp eax, 7
// 0057c68e  750b                 jne 0x57c69b
// 0057c690  d94608               fld dword ptr [esi + 8]
// 0057c693  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0057c697  dd1f                 fstp qword ptr [edi]
// 0057c699  eb1c                 jmp 0x57c6b7
// 0057c69b  83f802               cmp eax, 2
// 0057c69e  752f                 jne 0x57c6cf
// 0057c6a0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0057c6a4  8b4e08               mov ecx, dword ptr [esi + 8]
// 0057c6a7  57                   push edi
// 0057c6a8  51                   push ecx
// 0057c6a9  e8d21f0400           call 0x5be680
// 0057c6ae  83c408               add esp, 8
// 0057c6b1  84c0                 test al, al
// 0057c6b3  741a                 je 0x57c6cf
// 0057c6b5  8bce                 mov ecx, esi
// 0057c6b7  e814fcffff           call 0x57c2d0
// 0057c6bc  dd07                 fld qword ptr [edi]
// 0057c6be  5f                   pop edi
// 0057c6bf  dd5e08               fstp qword ptr [esi + 8]
// 0057c6c2  c7460409000000       mov dword ptr [esi + 4], 9
// 0057c6c9  b001                 mov al, 1
// 0057c6cb  5e                   pop esi
// 0057c6cc  c20400               ret 4
// 0057c6cf  5f                   pop edi
// 0057c6d0  32c0                 xor al, al
// 0057c6d2  5e                   pop esi
// 0057c6d3  c20400               ret 4

extern "C" bool __cdecl parseNumber(const char *, double *);

struct S {
    int reserved;
    int type;
    union {
        double number;
        float single;
        const char *text;
    } value;

    void clear();
    bool toNumber(double *);
};

bool S::toNumber(double *result)
{
    if (type == 9) {
        *result = value.number;
        return true;
    }

    if (type == 7) {
        *result = value.single;
        clear();
    } else {
        if (type != 2 || !parseNumber(value.text, result))
            return false;
        clear();
    }

    value.number = *result;
    type = 9;
    return true;
}
