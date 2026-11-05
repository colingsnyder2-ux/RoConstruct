// from server: 100% by EspClaude
// roc 2009-06 00461f50  unit: Scintilla::CScintillaCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00461f50
//
// 00461f50  51                   push ecx
// 00461f51  56                   push esi
// 00461f52  57                   push edi
// 00461f53  6a00                 push 0
// 00461f55  8bf1                 mov esi, ecx
// 00461f57  8b4658               mov eax, dword ptr [esi + 0x58]
// 00461f5a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 00461f5d  6a00                 push 0
// 00461f5f  685f080000           push 0x85f
// 00461f64  50                   push eax
// 00461f65  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00461f6d  ffd1                 call ecx
// 00461f6f  8b5658               mov edx, dword ptr [esi + 0x58]
// 00461f72  6a00                 push 0
// 00461f74  6a00                 push 0
// 00461f76  8bf8                 mov edi, eax
// 00461f78  8b4654               mov eax, dword ptr [esi + 0x54]
// 00461f7b  6861080000           push 0x861
// 00461f80  52                   push edx
// 00461f81  ffd0                 call eax
// 00461f83  2bc7                 sub eax, edi
// 00461f85  40                   inc eax
// 00461f86  50                   push eax
// 00461f87  e88e6d2b00           call 0x718d1a
// 00461f8c  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00461f8f  8b5654               mov edx, dword ptr [esi + 0x54]
// 00461f92  8bf8                 mov edi, eax
// 00461f94  57                   push edi
// 00461f95  6a00                 push 0
// 00461f97  6871080000           push 0x871
// 00461f9c  51                   push ecx
// 00461f9d  ffd2                 call edx
// 00461f9f  8b742444             mov esi, dword ptr [esp + 0x44]
// 00461fa3  83c434               add esp, 0x34
// 00461fa6  57                   push edi
// 00461fa7  8bce                 mov ecx, esi
// 00461fa9  ff1508fd8900         call dword ptr [0x89fd08]
// 00461faf  57                   push edi
// 00461fb0  e8296d2b00           call 0x718cde
// 00461fb5  83c404               add esp, 4
// 00461fb8  5f                   pop edi
// 00461fb9  8bc6                 mov eax, esi
// 00461fbb  5e                   pop esi
// 00461fbc  59                   pop ecx
// 00461fbd  c20400               ret 4
// copied from an identical function in another client (function ?getSelectedText@S@ns_ROCX00005f@@QAEPAUText@2@PAU32@@Z)

namespace ns_ROCX00005f {
struct Text;

extern "C" void* __cdecl allocate(unsigned int);
extern "C" void __cdecl release(void*);
extern void (__thiscall *constructText)(Text*, const char*);

struct S {
    char padding[0x54];
    int (__cdecl *direct)(int, unsigned int, unsigned int, int);
    int context;

    Text* getSelectedText(Text* result);
};

Text* S::getSelectedText(Text* result)
{
    volatile int state = 0;
    int start = direct(context, 0x85F, 0, 0);
    int end = direct(context, 0x861, 0, 0);
    char* buffer = static_cast<char*>(allocate(end - start + 1));
    direct(context, 0x871, 0, reinterpret_cast<int>(buffer));
    constructText(result, buffer);
    release(buffer);
    return result;
}
}
