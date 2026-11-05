// from server: 100% by colin
// roc 2007-08 0040a730  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a730
//
// 0040a730  51                   push ecx
// 0040a731  56                   push esi
// 0040a732  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0040a736  6890be8b00           push 0x8bbe90
// 0040a73b  8bce                 mov ecx, esi
// 0040a73d  c744240800000000     mov dword ptr [esp + 8], 0
// 0040a745  ff1574dd7700         call dword ptr [0x77dd74]
// 0040a74b  8bc6                 mov eax, esi
// 0040a74d  5e                   pop esi
// 0040a74e  59                   pop ecx
// 0040a74f  c3                   ret 
// copied from an identical function in another client (function ?make_exception@@YAPAXPAX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void (__thiscall *Constructor)(void *, const char *);
extern Constructor construct;
extern const char message[];

void * __cdecl make_exception(void *object)
{
    volatile int state = 0;
    construct(object, message);
    return object;
}