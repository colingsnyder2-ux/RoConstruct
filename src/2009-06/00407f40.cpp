// from server: 100% by Yeetserama
// roc 2009-06 00407f40  unit: VCApp::?$CComObject  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00407f40
//
// 00407f40  55                   push ebp
// 00407f41  8bec                 mov ebp, esp
// 00407f43  6aff                 push -1
// 00407f45  6870cd8400           push 0x84cd70
// 00407f4a  64a100000000         mov eax, dword ptr fs:[0]
// 00407f50  50                   push eax
// 00407f51  64892500000000       mov dword ptr fs:[0], esp
// 00407f58  83ec08               sub esp, 8
// 00407f5b  53                   push ebx
// 00407f5c  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00407f5f  56                   push esi
// 00407f60  33f6                 xor esi, esi
// 00407f62  57                   push edi
// 00407f63  8965f0               mov dword ptr [ebp - 0x10], esp
// 00407f66  3bde                 cmp ebx, esi
// 00407f68  7518                 jne 0x407f82
// 00407f6a  b803400080           mov eax, 0x80004003
// 00407f6f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00407f72  64890d00000000       mov dword ptr fs:[0], ecx
// 00407f79  5f                   pop edi
// 00407f7a  5e                   pop esi
// 00407f7b  5b                   pop ebx
// 00407f7c  8be5                 mov esp, ebp
// 00407f7e  5d                   pop ebp
// 00407f7f  c20c00               ret 0xc
// 00407f82  bf0e000780           mov edi, 0x8007000e
// 00407f87  6a1c                 push 0x1c
// 00407f89  8933                 mov dword ptr [ebx], esi
// 00407f8b  897d10               mov dword ptr [ebp + 0x10], edi
// 00407f8e  8975fc               mov dword ptr [ebp - 4], esi
// 00407f91  e8a20a3100           call 0x718a38
// 00407f96  83c404               add esp, 4
// 00407f99  3bc6                 cmp eax, esi
// 00407f9b  740d                 je 0x407faa
// 00407f9d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00407fa0  51                   push ecx
// 00407fa1  8bc8                 mov ecx, eax
// 00407fa3  e818e8ffff           call 0x4067c0
// 00407fa8  8bf0                 mov esi, eax
// 00407faa  83c8ff               or eax, 0xffffffff
// 00407fad  8945fc               mov dword ptr [ebp - 4], eax
// 00407fb0  85f6                 test esi, esi
// 00407fb2  7438                 je 0x407fec
// 00407fb4  ff4618               inc dword ptr [esi + 0x18]
// 00407fb7  014618               add dword ptr [esi + 0x18], eax
// 00407fba  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00407fbd  8b16                 mov edx, dword ptr [esi]
// 00407fbf  8b0a                 mov ecx, dword ptr [edx]
// 00407fc1  53                   push ebx
// 00407fc2  50                   push eax
// 00407fc3  56                   push esi
// 00407fc4  ffd1                 call ecx
// 00407fc6  8bf8                 mov edi, eax
// 00407fc8  85ff                 test edi, edi
// 00407fca  7420                 je 0x407fec
// 00407fcc  8b560c               mov edx, dword ptr [esi + 0xc]
// 00407fcf  8b4214               mov eax, dword ptr [edx + 0x14]
// 00407fd2  8d4e0c               lea ecx, [esi + 0xc]
// 00407fd5  6a01                 push 1
// 00407fd7  ffd0                 call eax
// 00407fd9  eb11                 jmp 0x407fec
// 00407fdb  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00407fde  e8310d3100           call 0x718d14
// 00407fe3  b8e97f4000           mov eax, 0x407fe9
// 00407fe8  c3                   ret 
// 00407fe9  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00407fec  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00407fef  8bc7                 mov eax, edi
// 00407ff1  5f                   pop edi
// 00407ff2  5e                   pop esi
// 00407ff3  64890d00000000       mov dword ptr fs:[0], ecx
// 00407ffa  5b                   pop ebx
// 00407ffb  8be5                 mov esp, ebp
// 00407ffd  5d                   pop ebp
// 00407ffe  c20c00               ret 0xc
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