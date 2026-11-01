// from server: 100% by EspClaude
// from server: 89% by colin
// roc 2008-06 0044f010  unit: CRobloxDHtmlDialog  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f010
//
// 0044f010  64a100000000         mov eax, dword ptr fs:[0]
// 0044f016  6aff                 push -1
// 0044f018  6809167c00           push 0x7c1609
// 0044f01d  50                   push eax
// 0044f01e  64892500000000       mov dword ptr fs:[0], esp
// 0044f025  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044f029  56                   push esi
// 0044f02a  8bf1                 mov esi, ecx
// 0044f02c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044f02f  57                   push edi
// 0044f030  51                   push ecx
// 0044f031  8d4c2420             lea ecx, [esp + 0x20]
// 0044f035  ff15d83e8000         call dword ptr [0x803ed8]
// 0044f03b  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f03f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044f047  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f04d  50                   push eax
// 0044f04e  e85decfcff           call 0x41dcb0
// 0044f053  83c404               add esp, 4
// 0044f056  85c0                 test eax, eax
// 0044f058  740c                 je 0x44f066
// 0044f05a  8b542430             mov edx, dword ptr [esp + 0x30]
// 0044f05e  c70201000000         mov dword ptr [edx], 1
// 0044f064  eb1c                 jmp 0x44f082
// 0044f066  8b3e                 mov edi, dword ptr [esi]
// 0044f068  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f06c  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f072  8b9770010000         mov edx, dword ptr [edi + 0x170]
// 0044f078  50                   push eax
// 0044f079  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f07d  50                   push eax
// 0044f07e  8bce                 mov ecx, esi
// 0044f080  ffd2                 call edx
// 0044f082  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f086  ff15143f8000         call dword ptr [0x803f14]
// 0044f08c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044f090  5f                   pop edi
// 0044f091  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f098  5e                   pop esi
// 0044f099  83c40c               add esp, 0xc
// 0044f09c  c21c00               ret 0x1c

// from server: 84% by king_originala
// roc 2008-06 0044f010  unit: CRobloxDHtmlDialog  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f010
//
// 0044f010  64a100000000         mov eax, dword ptr fs:[0]
// 0044f016  6aff                 push -1
// 0044f018  6809167c00           push 0x7c1609
// 0044f01d  50                   push eax
// 0044f01e  64892500000000       mov dword ptr fs:[0], esp
// 0044f025  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044f029  56                   push esi
// 0044f02a  8bf1                 mov esi, ecx
// 0044f02c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044f02f  57                   push edi
// 0044f030  51                   push ecx
// 0044f031  8d4c2420             lea ecx, [esp + 0x20]
// 0044f035  ff15d83e8000         call dword ptr [0x803ed8]
// 0044f03b  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f03f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044f047  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f04d  50                   push eax
// 0044f04e  e85decfcff           call 0x41dcb0
// 0044f053  83c404               add esp, 4
// 0044f056  85c0                 test eax, eax
// 0044f058  740c                 je 0x44f066
// 0044f05a  8b542430             mov edx, dword ptr [esp + 0x30]
// 0044f05e  c70201000000         mov dword ptr [edx], 1
// 0044f064  eb1c                 jmp 0x44f082
// 0044f066  8b3e                 mov edi, dword ptr [esi]
// 0044f068  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f06c  ff15e03e8000         call dword ptr [0x803ee0]
// 0044f072  8b9770010000         mov edx, dword ptr [edi + 0x170]
// 0044f078  50                   push eax
// 0044f079  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f07d  50                   push eax
// 0044f07e  8bce                 mov ecx, esi
// 0044f080  ffd2                 call edx
// 0044f082  8d4c241c             lea ecx, [esp + 0x1c]
// 0044f086  ff15143f8000         call dword ptr [0x803f14]
// 0044f08c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044f090  5f                   pop edi
// 0044f091  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f098  5e                   pop esi
// 0044f099  83c40c               add esp, 0xc
// 0044f09c  c21c00               ret 0x1c

typedef void* (__thiscall *StringAccess)(void*);
typedef void (__thiscall *StringDestroy)(void*);

extern StringAccess stringAccess;
extern StringDestroy stringDestroy;
extern long __cdecl function(void*);

struct String
{
    void* data;
    __declspec(dllimport) String(void*);
    __declspec(dllimport) ~String() throw();
    void* value();
};

__forceinline void* String::value()
{
    return stringAccess(this);
}



struct Argument
{
    unsigned char padding[8];
    void* value;
};

struct Dialog;
typedef void (__thiscall *Dispatch)(Dialog*, void*, void*);

struct DialogTable
{
    void* padding[92];
    Dispatch dispatch;
};

struct Dialog
{
    DialogTable* table;
    void invoke(void*, Argument*, unsigned long, unsigned long,
                void*, void*, int*);
};

void Dialog::invoke(void* context, Argument* argument,
                    unsigned long, unsigned long,
                    void*, void*, int* handled)
{
    String text(argument->value);
    if (function(text.value()))
        *handled = 1;
    else
    {
        DialogTable* savedTable = table;
        savedTable->dispatch(this, context, text.value());
    }
}
