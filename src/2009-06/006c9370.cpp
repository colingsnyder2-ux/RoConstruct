// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00658a00  unit: RBX::ArrowButton  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00658a00
//
// 00658a00  56                   push esi
// 00658a01  8b742408             mov esi, dword ptr [esp + 8]
// 00658a05  57                   push edi
// 00658a06  8bf9                 mov edi, ecx
// 00658a08  8bce                 mov ecx, esi
// 00658a0a  e8c1f8e1ff           call 0x4782d0
// 00658a0f  8d4e30               lea ecx, [esi + 0x30]
// 00658a12  e859b7fbff           call 0x614170
// 00658a17  8b442410             mov eax, dword ptr [esp + 0x10]
// 00658a1b  56                   push esi
// 00658a1c  50                   push eax
// 00658a1d  57                   push edi
// 00658a1e  e89d07f4ff           call 0x5991c0
// 00658a23  83c40c               add esp, 0xc
// 00658a26  5f                   pop edi
// 00658a27  8bc6                 mov eax, esi
// 00658a29  5e                   pop esi
// 00658a2a  c20800               ret 8

struct Triple {
    float x, y, z;
};

struct Six {
    float a, b, c, d, e, f;
    void initialize();
};

struct Data {
    char reserved[0x24];
    Triple input;
    Six output;
    void initialize();
};

struct S {
    Data* f(Data* result, const Triple* input);
};

Six* __cdecl compute(S* object, const Triple* input, Data* result);

Data* S::f(Data* result, const Triple* input)
{
    result->initialize();
    result->output.initialize();
    compute(this, input, result);
    return result;
}
