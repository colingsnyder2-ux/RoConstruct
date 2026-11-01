// from server: 100% by Espeon
// from server: 89% by colin
// roc 2008-06 005d18e0  unit: RBX::Backpack  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d18e0
//
// 005d18e0  51                   push ecx
// 005d18e1  55                   push ebp
// 005d18e2  56                   push esi
// 005d18e3  57                   push edi
// 005d18e4  8bf9                 mov edi, ecx
// 005d18e6  8db798feffff         lea esi, [edi - 0x168]
// 005d18ec  56                   push esi
// 005d18ed  e85e05ecff           call 0x491e50
// 005d18f2  8be8                 mov ebp, eax
// 005d18f4  83c404               add esp, 4
// 005d18f7  85ed                 test ebp, ebp
// 005d18f9  7473                 je 0x5d196e
// 005d18fb  8b7f9c               mov edi, dword ptr [edi - 0x64]
// 005d18fe  53                   push ebx
// 005d18ff  56                   push esi
// 005d1900  e87b93ecff           call 0x49ac80
// 005d1905  3bf8                 cmp edi, eax
// 005d1907  6a01                 push 1
// 005d1909  56                   push esi
// 005d190a  0f9444241e           sete byte ptr [esp + 0x1e]
// 005d190f  e89c45ecff           call 0x495eb0
// 005d1914  8b742424             mov esi, dword ptr [esp + 0x24]
// 005d1918  6a00                 push 0
// 005d191a  68d48d9400           push 0x948dd4
// 005d191f  68c8e19200           push 0x92e1c8
// 005d1924  6a00                 push 0
// 005d1926  56                   push esi
// 005d1927  88442433             mov byte ptr [esp + 0x33], al
// 005d192b  e896fe0c00           call 0x6a17c6
// 005d1930  8bb604010000         mov esi, dword ptr [esi + 0x104]
// 005d1936  6a00                 push 0
// 005d1938  68a0969400           push 0x9496a0
// 005d193d  687c909200           push 0x92907c
// 005d1942  85c0                 test eax, eax
// 005d1944  6a00                 push 0
// 005d1946  56                   push esi
// 005d1947  0f95c3               setne bl
// 005d194a  e877fe0c00           call 0x6a17c6
// 005d194f  83c434               add esp, 0x34
// 005d1952  85c0                 test eax, eax
// 005d1954  0f95c0               setne al
// 005d1957  84db                 test bl, bl
// 005d1959  5b                   pop ebx
// 005d195a  751b                 jne 0x5d1977
// 005d195c  84c0                 test al, al
// 005d195e  7407                 je 0x5d1967
// 005d1960  807c240e00           cmp byte ptr [esp + 0xe], 0
// 005d1965  7517                 jne 0x5d197e
// 005d1967  807c240f00           cmp byte ptr [esp + 0xf], 0
// 005d196c  7510                 jne 0x5d197e
// 005d196e  5f                   pop edi
// 005d196f  5e                   pop esi
// 005d1970  33c0                 xor eax, eax
// 005d1972  5d                   pop ebp
// 005d1973  59                   pop ecx
// 005d1974  c20400               ret 4
// 005d1977  807c240e00           cmp byte ptr [esp + 0xe], 0
// 005d197c  74f0                 je 0x5d196e
// 005d197e  5f                   pop edi
// 005d197f  5e                   pop esi
// 005d1980  8d8540030000         lea eax, [ebp + 0x340]
// 005d1986  5d                   pop ebp
// 005d1987  59                   pop ecx
// 005d1988  c20400               ret 4

namespace RBX {
    struct Instance {
        virtual ~Instance();
        char pad[0x100];
        Instance* next;
    };
    struct ServiceProvider;
}

RBX::ServiceProvider* __cdecl func_00491e50(RBX::Instance*);
void* __cdecl func_0049ac80(void*);
int __cdecl sub_495e80(int, int);

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char type_Instance[];
extern char type_HopperBin[];
extern char type_Script[];
extern char type_LocalScript[];

struct S {
    void* f(RBX::Instance*);
};

void* S::f(RBX::Instance* object)
{
    RBX::Instance* owner =
        reinterpret_cast<RBX::Instance*>(reinterpret_cast<char*>(this) - 0x168);
    RBX::ServiceProvider* provider = func_00491e50(owner);

    if (provider) {
        void* value = *reinterpret_cast<void**>(
            reinterpret_cast<char*>(this) - 0x64);
        bool equal = value == func_0049ac80(owner);
        unsigned char enabled =
            static_cast<unsigned char>(sub_495e80(reinterpret_cast<int>(owner), 1));

        bool hopper = __RTDynamicCast(
            object, 0, type_Instance, type_HopperBin, 0) != 0;

        object = object->next;
        bool local = __RTDynamicCast(
            object, 0, type_Script, type_LocalScript, 0) != 0;

        if (!hopper) {
            if (!(local && equal) && !enabled) return 0;
        } else if (!equal) return 0;
        return reinterpret_cast<char*>(provider)+0x340;

    }
    return 0;
}
