// from server: 100% by Yeetserama
// roc 2007-08 0045d120  unit: Scintilla::CScintillaCtrl  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045d120
//
// 0045d120  51                   push ecx
// 0045d121  56                   push esi
// 0045d122  57                   push edi
// 0045d123  6a00                 push 0
// 0045d125  8bf1                 mov esi, ecx
// 0045d127  8b4658               mov eax, dword ptr [esi + 0x58]
// 0045d12a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0045d12d  6a00                 push 0
// 0045d12f  685f080000           push 0x85f
// 0045d134  50                   push eax
// 0045d135  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045d13d  ffd1                 call ecx
// 0045d13f  8b5658               mov edx, dword ptr [esi + 0x58]
// 0045d142  6a00                 push 0
// 0045d144  6a00                 push 0
// 0045d146  8bf8                 mov edi, eax
// 0045d148  8b4654               mov eax, dword ptr [esi + 0x54]
// 0045d14b  6861080000           push 0x861
// 0045d150  52                   push edx
// 0045d151  ffd0                 call eax
// 0045d153  2bc7                 sub eax, edi
// 0045d155  83c001               add eax, 1
// 0045d158  50                   push eax
// 0045d159  e8d42d1d00           call 0x62ff32
// 0045d15e  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0045d161  8b5654               mov edx, dword ptr [esi + 0x54]
// 0045d164  8bf8                 mov edi, eax
// 0045d166  57                   push edi
// 0045d167  6a00                 push 0
// 0045d169  6871080000           push 0x871
// 0045d16e  51                   push ecx
// 0045d16f  ffd2                 call edx
// 0045d171  8b742444             mov esi, dword ptr [esp + 0x44]
// 0045d175  83c434               add esp, 0x34
// 0045d178  57                   push edi
// 0045d179  8bce                 mov ecx, esi
// 0045d17b  ff15b8dd7700         call dword ptr [0x77ddb8]
// 0045d181  57                   push edi
// 0045d182  e89f2d1d00           call 0x62ff26
// 0045d187  83c404               add esp, 4
// 0045d18a  5f                   pop edi
// 0045d18b  8bc6                 mov eax, esi
// 0045d18d  5e                   pop esi
// 0045d18e  59                   pop ecx
// 0045d18f  c20400               ret 4
// copied from an identical function in another client (function ?getSelectedText@S@ns_ROCX000004@@QAEPAUText@2@PAU32@@Z)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
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
