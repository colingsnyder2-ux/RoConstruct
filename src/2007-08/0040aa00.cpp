// from server: 100% by Yeetserama
// roc 2007-08 0040aa00  unit: CBrowserView  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040aa00
//
// 0040aa00  6aff                 push -1
// 0040aa02  687a997300           push 0x73997a
// 0040aa07  64a100000000         mov eax, dword ptr fs:[0]
// 0040aa0d  50                   push eax
// 0040aa0e  51                   push ecx
// 0040aa0f  53                   push ebx
// 0040aa10  56                   push esi
// 0040aa11  57                   push edi
// 0040aa12  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040aa17  33c4                 xor eax, esp
// 0040aa19  50                   push eax
// 0040aa1a  8d442414             lea eax, [esp + 0x14]
// 0040aa1e  64a300000000         mov dword ptr fs:[0], eax
// 0040aa24  8b742428             mov esi, dword ptr [esp + 0x28]
// 0040aa28  33db                 xor ebx, ebx
// 0040aa2a  8bce                 mov ecx, esi
// 0040aa2c  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040aa30  ff15bcdc7700         call dword ptr [0x77dcbc]
// 0040aa36  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0040aa3a  50                   push eax
// 0040aa3b  8bcf                 mov ecx, edi
// 0040aa3d  ff15c0dc7700         call dword ptr [0x77dcc0]
// 0040aa43  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0040aa47  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0040aa4b  53                   push ebx
// 0040aa4c  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0040aa54  ff15c4dc7700         call dword ptr [0x77dcc4]
// 0040aa5a  83c404               add esp, 4
// 0040aa5d  50                   push eax
// 0040aa5e  53                   push ebx
// 0040aa5f  8bce                 mov ecx, esi
// 0040aa61  ff15c8dc7700         call dword ptr [0x77dcc8]
// 0040aa67  50                   push eax
// 0040aa68  8bce                 mov ecx, esi
// 0040aa6a  ff1598dd7700         call dword ptr [0x77dd98]
// 0040aa70  50                   push eax
// 0040aa71  57                   push edi
// 0040aa72  ff15ccdc7700         call dword ptr [0x77dccc]
// 0040aa78  83c414               add esp, 0x14
// 0040aa7b  8bc7                 mov eax, edi
// 0040aa7d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040aa81  64890d00000000       mov dword ptr fs:[0], ecx
// 0040aa88  59                   pop ecx
// 0040aa89  5f                   pop edi
// 0040aa8a  5e                   pop esi
// 0040aa8b  5b                   pop ebx
// 0040aa8c  83c410               add esp, 0x10
// 0040aa8f  c3                   ret 
// copied from an identical function in another client (function ??Hns_ROCX000017@@YA?AUString@0@ABU10@PBD@Z)

namespace ns_ROCX000017 {
// from server: 100% by Espeon
// from server: 81% by king_originala
struct String;

extern void* (__thiscall *getManager)(const String*);
extern void (__thiscall *constructString)(String*, void*);
extern unsigned int (__cdecl *stringLength)(const char*);
extern int (__thiscall *getLength)(const String*);
extern const char* (__thiscall *getString)(const String*);
extern void (__cdecl *concatenate)(String*, const char*, int, const char*, unsigned int);

struct String {
    char* data;
    __declspec(dllimport) void* manager() const throw();
    __declspec(dllimport) String(void* manager) throw();
    String(const String&);
    ~String() throw();
};

String __cdecl operator+(const String& source, const char* suffix)
{
    String result(source.manager());
    unsigned int length = stringLength(suffix);
    concatenate(&result, getString(&source), getLength(&source), suffix, length);
    return result;
}
}
