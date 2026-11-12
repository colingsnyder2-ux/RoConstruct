// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 00724fa3  unit: CXTIconHandle  size: 86 bytes
// roc-flags: /O1 /GS /EHsc /MD
// Make this compile to the exact bytes below, then: roc check 2007-08 00724fa3
//
// 00724fa3  55                   push ebp
// 00724fa4  8bec                 mov ebp, esp
// 00724fa6  51                   push ecx
// 00724fa7  51                   push ecx
// 00724fa8  56                   push esi
// 00724fa9  8bf1                 mov esi, ecx
// 00724fab  8d4618               lea eax, [esi + 0x18]
// 00724fae  50                   push eax
// 00724faf  8945f8               mov dword ptr [ebp - 8], eax
// 00724fb2  ff15fcd27700         call dword ptr [0x77d2fc]
// 00724fb8  8b4634               mov eax, dword ptr [esi + 0x34]
// 00724fbb  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00724fbe  3bc8                 cmp ecx, eax
// 00724fc0  c645fc01             mov byte ptr [ebp - 4], 1
// 00724fc4  7f24                 jg 0x724fea
// 00724fc6  85c9                 test ecx, ecx
// 00724fc8  7c20                 jl 0x724fea
// 00724fca  3bc8                 cmp ecx, eax
// 00724fcc  750f                 jne 0x724fdd
// 00724fce  8b7608               mov esi, dword ptr [esi + 8]
// 00724fd1  8d4df8               lea ecx, [ebp - 8]
// 00724fd4  e8a78bcfff           call 0x41db80
// 00724fd9  8bc6                 mov eax, esi
// 00724fdb  eb17                 jmp 0x724ff4
// 00724fdd  51                   push ecx
// 00724fde  8d4e30               lea ecx, [esi + 0x30]
// 00724fe1  e8ecfeffff           call 0x724ed2
// 00724fe6  8b30                 mov esi, dword ptr [eax]
// 00724fe8  ebe7                 jmp 0x724fd1
// 00724fea  8d4df8               lea ecx, [ebp - 8]
// 00724fed  e88e8bcfff           call 0x41db80
// 00724ff2  33c0                 xor eax, eax
// 00724ff4  5e                   pop esi
// 00724ff5  c9                   leave 
// 00724ff6  c20400               ret 4

struct CXTIconHandle {
    int sub_724fa3(int);
};

struct Inner {
    char pad[0x30];
    int sub_724ed2(int);
};

extern "C" {
    __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
}

struct Lock {
    void* cs;
    char flag;
    void sub_41db80();
};

int CXTIconHandle::sub_724fa3(int idx)
{
    Lock lock;
    lock.cs = (char*)this + 0x18;
    EnterCriticalSection((char*)this + 0x18);
    int count = *(int*)((char*)this + 0x34);
    lock.flag = 1;
    if (idx > count || idx < 0) {
        lock.sub_41db80();
        return 0;
    }
    if (idx == count) {
        int v = *(int*)((char*)this + 8);
        lock.sub_41db80();
        return v;
    }
    int r = *(int*)((Inner*)((char*)this + 0x30))->sub_724ed2(idx);
    lock.sub_41db80();
    return r;
}
