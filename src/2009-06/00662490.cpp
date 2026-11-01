// from server: 100% by EspClaude
// roc 2009-06 00662490  unit: DxUserInput  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00662490
//
// 00662490  53                   push ebx
// 00662491  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00662495  56                   push esi
// 00662496  57                   push edi
// 00662497  8bf1                 mov esi, ecx
// 00662499  8d7e04               lea edi, [esi + 4]
// 0066249c  53                   push ebx
// 0066249d  57                   push edi
// 0066249e  e8cd67f7ff           call 0x5d8c70
// 006624a3  83c408               add esp, 8
// 006624a6  84c0                 test al, al
// 006624a8  7442                 je 0x6624ec
// 006624aa  53                   push ebx
// 006624ab  8bcf                 mov ecx, edi
// 006624ad  ff1564e48900         call dword ptr [0x89e464]
// 006624b3  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 006624b6  89471c               mov dword ptr [edi + 0x1c], eax
// 006624b9  8b4624               mov eax, dword ptr [esi + 0x24]
// 006624bc  85c0                 test eax, eax
// 006624be  742c                 je 0x6624ec
// 006624c0  83c004               add eax, 4
// 006624c3  50                   push eax
// 006624c4  ff15a4e18900         call dword ptr [0x89e1a4]
// 006624ca  85c0                 test eax, eax
// 006624cc  7517                 jne 0x6624e5
// 006624ce  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 006624d1  e8aa28deff           call 0x444d80
// 006624d6  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 006624d9  85c9                 test ecx, ecx
// 006624db  7408                 je 0x6624e5
// 006624dd  8b11                 mov edx, dword ptr [ecx]
// 006624df  8b02                 mov eax, dword ptr [edx]
// 006624e1  6a01                 push 1
// 006624e3  ffd0                 call eax
// 006624e5  c7462400000000       mov dword ptr [esi + 0x24], 0
// 006624ec  5f                   pop edi
// 006624ed  5e                   pop esi
// 006624ee  5b                   pop ebx
// 006624ef  c20800               ret 8
// copied from an identical function in another client (function ?setValue@DxUserInput@ns_ROCX00001d@@QAEXHABUValue@2@@Z)

namespace ns_ROCX00001d {
struct String {
    char data[0x1c];
};

struct Value {
    String text;
    int extra;
};

struct Reference {
    virtual ~Reference();
    volatile long count;
    void release();
};

extern bool __cdecl different(const Value*, const Value*);

extern "C" {
    extern String& (__thiscall *assignString)(String*, const String*);
    extern long (__stdcall *InterlockedDecrement)(volatile long*);
}

struct DxUserInput {
    char padding[4];
    Value value;
    Reference* reference;

    void setValue(int unused, const Value& source);
};

void DxUserInput::setValue(int unused, const Value& source)
{
    const Value* input = &source;
    Value* destination = &value;

    if (different(destination, input)) {
        assignString(&destination->text, &input->text);
        destination->extra = input->extra;

        if (reference) {
            if (InterlockedDecrement(&reference->count) == 0) {
                reference->release();
                delete reference;
            }
            reference = 0;
        }
    }
}
}
