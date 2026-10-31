// from server: 89% by EspClaude
// from server: 100% by colin
// roc 2008-06 004081e0  unit: VCApp::?$CComObject  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004081e0
//
// 004081e0  55                   push ebp
// 004081e1  8bec                 mov ebp, esp
// 004081e3  6aff                 push -1
// 004081e5  68e0ce7b00           push 0x7bcee0
// 004081ea  64a100000000         mov eax, dword ptr fs:[0]
// 004081f0  50                   push eax
// 004081f1  64892500000000       mov dword ptr fs:[0], esp
// 004081f8  83ec08               sub esp, 8
// 004081fb  53                   push ebx
// 004081fc  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004081ff  56                   push esi
// 00408200  33f6                 xor esi, esi
// 00408202  57                   push edi
// 00408203  8965f0               mov dword ptr [ebp - 0x10], esp
// 00408206  3bde                 cmp ebx, esi
// 00408208  7518                 jne 0x408222
// 0040820a  b803400080           mov eax, 0x80004003
// 0040820f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00408212  64890d00000000       mov dword ptr fs:[0], ecx
// 00408219  5f                   pop edi
// 0040821a  5e                   pop esi
// 0040821b  5b                   pop ebx
// 0040821c  8be5                 mov esp, ebp
// 0040821e  5d                   pop ebp
// 0040821f  c20c00               ret 0xc
// 00408222  bf0e000780           mov edi, 0x8007000e
// 00408227  6a1c                 push 0x1c
// 00408229  8933                 mov dword ptr [ebx], esi
// 0040822b  897d10               mov dword ptr [ebp + 0x10], edi
// 0040822e  8975fc               mov dword ptr [ebp - 4], esi
// 00408231  e8ea862900           call 0x6a0920
// 00408236  83c404               add esp, 4
// 00408239  3bc6                 cmp eax, esi
// 0040823b  740d                 je 0x40824a
// 0040823d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00408240  51                   push ecx
// 00408241  8bc8                 mov ecx, eax
// 00408243  e8a8faffff           call 0x407cf0
// 00408248  8bf0                 mov esi, eax
// 0040824a  83c8ff               or eax, 0xffffffff
// 0040824d  8945fc               mov dword ptr [ebp - 4], eax
// 00408250  85f6                 test esi, esi
// 00408252  7438                 je 0x40828c
// 00408254  ff4618               inc dword ptr [esi + 0x18]
// 00408257  014618               add dword ptr [esi + 0x18], eax
// 0040825a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0040825d  8b16                 mov edx, dword ptr [esi]
// 0040825f  8b0a                 mov ecx, dword ptr [edx]
// 00408261  53                   push ebx
// 00408262  50                   push eax
// 00408263  56                   push esi
// 00408264  ffd1                 call ecx
// 00408266  8bf8                 mov edi, eax
// 00408268  85ff                 test edi, edi
// 0040826a  7420                 je 0x40828c
// 0040826c  8b560c               mov edx, dword ptr [esi + 0xc]
// 0040826f  8b4214               mov eax, dword ptr [edx + 0x14]
// 00408272  8d4e0c               lea ecx, [esi + 0xc]
// 00408275  6a01                 push 1
// 00408277  ffd0                 call eax
// 00408279  eb11                 jmp 0x40828c

// b.cpp: king's fn-pointer QI shape + MFC-style catch (isolates funclet fix).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct CException {
    void* vfptr;
    void Delete();   // mfc90.dll!#2084 - non-virtual, direct __thiscall import call
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Subobject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void destroy(unsigned int);
};

struct S;
struct Table {
    long (__stdcall* query)(S*, const void*, void**);
};

struct S {
    Table* table;
    unsigned long reserved[2];
    Subobject subobject;
    unsigned long reserved2[2];
    volatile long references;

    S(void*) throw();
    static long __stdcall create(void*, const void*, void**);
};

long __stdcall S::create(void* context, const void* iid, void** result)
{
    if (!result)
        return (long)0x80004003;

    S* object = 0;
    *result = 0;
    long status = (long)0x8007000e;

    try {
        object = new S(context);
    }
    catch (CException* e) {
        e->Delete();
    }

    if (object) {
        ++object->references;
        --object->references;
        status = object->table->query(object, iid, result);
        if (status != 0)
            object->subobject.destroy(1);
    }

    return status;
}
