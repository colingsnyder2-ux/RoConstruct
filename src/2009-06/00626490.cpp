// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d0910  unit: RBX::LegacyHopperService  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d0910
//
// 005d0910  57                   push edi
// 005d0911  8bf9                 mov edi, ecx
// 005d0913  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005d0917  85c9                 test ecx, ecx
// 005d0919  745c                 je 0x5d0977
// 005d091b  53                   push ebx
// 005d091c  e84f04ecff           call 0x490d70
// 005d0921  8bcf                 mov ecx, edi
// 005d0923  8bd8                 mov ebx, eax
// 005d0925  e8f6a4ebff           call 0x48ae20
// 005d092a  85c0                 test eax, eax
// 005d092c  763f                 jbe 0x5d096d
// 005d092e  55                   push ebp
// 005d092f  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005d0935  56                   push esi
// 005d0936  eb08                 jmp 0x5d0940
// 005d0938  8da42400000000       lea esp, [esp]
// 005d093f  90                   nop 
// 005d0940  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 005d0946  8b4610               mov eax, dword ptr [esi + 0x10]
// 005d0949  2b460c               sub eax, dword ptr [esi + 0xc]
// 005d094c  c1f803               sar eax, 3
// 005d094f  85c0                 test eax, eax
// 005d0951  7702                 ja 0x5d0955
// 005d0953  ffd5                 call ebp
// 005d0955  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005d0958  8b09                 mov ecx, dword ptr [ecx]
// 005d095a  53                   push ebx
// 005d095b  e8909ff8ff           call 0x55a8f0
// 005d0960  8bcf                 mov ecx, edi
// 005d0962  e8b9a4ebff           call 0x48ae20
// 005d0967  85c0                 test eax, eax
// 005d0969  77d5                 ja 0x5d0940
// 005d096b  5e                   pop esi
// 005d096c  5d                   pop ebp
// 005d096d  6a00                 push 0
// 005d096f  8bcf                 mov ecx, edi
// 005d0971  e87a9ff8ff           call 0x55a8f0
// 005d0976  5b                   pop ebx
// 005d0977  5f                   pop edi
// 005d0978  c20800               ret 8

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Input {
    void* get();
};

struct S;

struct Entry {
    S* object;
    void* auxiliary;
};

struct Entries {
    char reserved[12];
    Entry* first;
    Entry* last;
};

struct S {
    char reserved[0x108];
    Entries* entries;

    unsigned int count();
    void apply(void*);
    void f(int, Input*);
};

void S::f(int, Input* input)
{
    if (input) {
        void* value = input->get();
        if (count() > 0) {
            void (__cdecl *handler)() = invalid_parameter_noinfo;
            do {
                Entries* list = entries;
                if ((unsigned int)(list->last - list->first) <= 0)
                    handler();
                list->first->object->apply(value);
            } while (count() > 0);
        }
        apply(0);
    }
}
