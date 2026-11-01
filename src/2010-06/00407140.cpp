// from server: 100% by Yeetserama
// roc 2010-06 00407140  unit: VCApp::?$CComObject  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00407140
//
// 00407140  55                   push ebp
// 00407141  8bec                 mov ebp, esp
// 00407143  6aff                 push -1
// 00407145  68d0db9700           push 0x97dbd0
// 0040714a  64a100000000         mov eax, dword ptr fs:[0]
// 00407150  50                   push eax
// 00407151  64892500000000       mov dword ptr fs:[0], esp
// 00407158  83ec08               sub esp, 8
// 0040715b  53                   push ebx
// 0040715c  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 0040715f  56                   push esi
// 00407160  33f6                 xor esi, esi
// 00407162  57                   push edi
// 00407163  8965f0               mov dword ptr [ebp - 0x10], esp
// 00407166  3bde                 cmp ebx, esi
// 00407168  7518                 jne 0x407182
// 0040716a  b803400080           mov eax, 0x80004003
// 0040716f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00407172  64890d00000000       mov dword ptr fs:[0], ecx
// 00407179  5f                   pop edi
// 0040717a  5e                   pop esi
// 0040717b  5b                   pop ebx
// 0040717c  8be5                 mov esp, ebp
// 0040717e  5d                   pop ebp
// 0040717f  c20c00               ret 0xc
// 00407182  bf0e000780           mov edi, 0x8007000e
// 00407187  6a1c                 push 0x1c
// 00407189  8933                 mov dword ptr [ebx], esi
// 0040718b  897d10               mov dword ptr [ebp + 0x10], edi
// 0040718e  8975fc               mov dword ptr [ebp - 4], esi
// 00407191  e80a083a00           call 0x7a79a0
// 00407196  83c404               add esp, 4
// 00407199  3bc6                 cmp eax, esi
// 0040719b  740d                 je 0x4071aa
// 0040719d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004071a0  51                   push ecx
// 004071a1  8bc8                 mov ecx, eax
// 004071a3  e8e8f1ffff           call 0x406390
// 004071a8  8bf0                 mov esi, eax
// 004071aa  83c8ff               or eax, 0xffffffff
// 004071ad  8945fc               mov dword ptr [ebp - 4], eax
// 004071b0  85f6                 test esi, esi
// 004071b2  7438                 je 0x4071ec
// 004071b4  ff4618               inc dword ptr [esi + 0x18]
// 004071b7  014618               add dword ptr [esi + 0x18], eax
// 004071ba  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004071bd  8b16                 mov edx, dword ptr [esi]
// 004071bf  8b0a                 mov ecx, dword ptr [edx]
// 004071c1  53                   push ebx
// 004071c2  50                   push eax
// 004071c3  56                   push esi
// 004071c4  ffd1                 call ecx
// 004071c6  8bf8                 mov edi, eax
// 004071c8  85ff                 test edi, edi
// 004071ca  7420                 je 0x4071ec
// 004071cc  8b560c               mov edx, dword ptr [esi + 0xc]
// 004071cf  8b4214               mov eax, dword ptr [edx + 0x14]
// 004071d2  8d4e0c               lea ecx, [esi + 0xc]
// 004071d5  6a01                 push 1
// 004071d7  ffd0                 call eax
// 004071d9  eb11                 jmp 0x4071ec
// 004071db  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004071de  e8990a3a00           call 0x7a7c7c
// 004071e3  b8e9714000           mov eax, 0x4071e9
// 004071e8  c3                   ret 
// 004071e9  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004071ec  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004071ef  8bc7                 mov eax, edi
// 004071f1  5f                   pop edi
// 004071f2  5e                   pop esi
// 004071f3  64890d00000000       mov dword ptr fs:[0], ecx
// 004071fa  5b                   pop ebx
// 004071fb  8be5                 mov esp, ebp
// 004071fd  5d                   pop ebp
// 004071fe  c20c00               ret 0xc
// copied from an identical function in another client (function ?create@S@@SGJPAXPBXPAPAX@Z)

// from server: 100% by colin
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