// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0046cf40  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046cf40
//
// 0046cf40  53                   push ebx
// 0046cf41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0046cf45  56                   push esi
// 0046cf46  8bf1                 mov esi, ecx
// 0046cf48  8b06                 mov eax, dword ptr [esi]
// 0046cf4a  83f8fc               cmp eax, -4
// 0046cf4d  7439                 je 0x46cf88
// 0046cf4f  55                   push ebp
// 0046cf50  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0046cf56  57                   push edi
// 0046cf57  85c0                 test eax, eax
// 0046cf59  7502                 jne 0x46cf5d
// 0046cf5b  ffd5                 call ebp
// 0046cf5d  8b3e                 mov edi, dword ptr [esi]
// 0046cf5f  8bcf                 mov ecx, edi
// 0046cf61  ff1558238000         call dword ptr [0x802358]
// 0046cf67  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046cf6a  034714               add eax, dword ptr [edi + 0x14]
// 0046cf6d  03cb                 add ecx, ebx
// 0046cf6f  3bc8                 cmp ecx, eax
// 0046cf71  7711                 ja 0x46cf84
// 0046cf73  8bcf                 mov ecx, edi
// 0046cf75  ff1558238000         call dword ptr [0x802358]
// 0046cf7b  8b5604               mov edx, dword ptr [esi + 4]
// 0046cf7e  03d3                 add edx, ebx
// 0046cf80  3bd0                 cmp edx, eax
// 0046cf82  7302                 jae 0x46cf86
// 0046cf84  ffd5                 call ebp
// 0046cf86  5f                   pop edi
// 0046cf87  5d                   pop ebp
// 0046cf88  015e04               add dword ptr [esi + 4], ebx
// 0046cf8b  8bc6                 mov eax, esi
// 0046cf8d  5e                   pop esi
// 0046cf8e  5b                   pop ebx
// 0046cf8f  c20400               ret 4
#include <intrin.h>

extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" char *(__thiscall *string_pointer)(void *);

struct String {
    char padding[20];
    unsigned int size;
};

struct S {
    String *owner;
    char *position;
    S &operator+=(int offset);
};

S &S::operator+=(int offset)
{
    if (owner != reinterpret_cast<String *>(-4)) {
        void (__cdecl *invalid)() = _invalid_parameter_noinfo;
        if (!owner)
            invalid();

        String *s = owner;
        if (position + offset > string_pointer(s) + s->size ||
            position + offset < string_pointer(s))
            invalid();
            _ReadWriteBarrier();
    }

    position += offset;
    return *this;
}
