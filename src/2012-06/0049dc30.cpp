// from server: 100% by Xemicl
// roc 2012-06 0049dc30  unit: Scintilla::CScintillaCtrl  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049dc30
//
// 0049dc30  51                   push ecx
// 0049dc31  56                   push esi
// 0049dc32  57                   push edi
// 0049dc33  6a00                 push 0
// 0049dc35  8bf1                 mov esi, ecx
// 0049dc37  8b4658               mov eax, dword ptr [esi + 0x58]
// 0049dc3a  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0049dc3d  6a00                 push 0
// 0049dc3f  685f080000           push 0x85f
// 0049dc44  50                   push eax
// 0049dc45  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0049dc4d  ffd1                 call ecx
// 0049dc4f  8b5658               mov edx, dword ptr [esi + 0x58]
// 0049dc52  6a00                 push 0
// 0049dc54  6a00                 push 0
// 0049dc56  8bf8                 mov edi, eax
// 0049dc58  8b4654               mov eax, dword ptr [esi + 0x54]
// 0049dc5b  6861080000           push 0x861
// 0049dc60  52                   push edx
// 0049dc61  ffd0                 call eax
// 0049dc63  2bc7                 sub eax, edi
// 0049dc65  40                   inc eax
// 0049dc66  50                   push eax
// 0049dc67  e884474e00           call 0x9823f0
// 0049dc6c  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0049dc6f  8b5654               mov edx, dword ptr [esi + 0x54]
// 0049dc72  8bf8                 mov edi, eax
// 0049dc74  57                   push edi
// 0049dc75  6a00                 push 0
// 0049dc77  6871080000           push 0x871
// 0049dc7c  51                   push ecx
// 0049dc7d  ffd2                 call edx
// 0049dc7f  8b742444             mov esi, dword ptr [esp + 0x44]
// 0049dc83  83c434               add esp, 0x34
// 0049dc86  57                   push edi
// 0049dc87  8bce                 mov ecx, esi
// 0049dc89  ff15c847b200         call dword ptr [0xb247c8]
// 0049dc8f  57                   push edi
// 0049dc90  e825474e00           call 0x9823ba
// 0049dc95  83c404               add esp, 4
// 0049dc98  5f                   pop edi
// 0049dc99  8bc6                 mov eax, esi
// 0049dc9b  5e                   pop esi
// 0049dc9c  59                   pop ecx
// 0049dc9d  c20400               ret 4
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