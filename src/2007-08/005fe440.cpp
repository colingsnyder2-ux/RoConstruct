// from server: 48% by colin
// roc 2007-08 005fe440  unit: RBX::AxisMoveTool  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005fe440
//
// 005fe440  8901                 mov dword ptr [ecx], eax
// 005fe442  8b4604               mov eax, dword ptr [esi + 4]
// 005fe445  85c0                 test eax, eax
// 005fe447  89642424             mov dword ptr [esp + 0x24], esp
// 005fe44b  894104               mov dword ptr [ecx + 4], eax
// 005fe44e  740c                 je 0x5fe45c
// 005fe450  83c004               add eax, 4
// 005fe453  b901000000           mov ecx, 1
// 005fe458  f00fc108             lock xadd dword ptr [eax], ecx
// 005fe45c  ffd5                 call ebp
// 005fe45e  83c608               add esi, 8
// 005fe461  83c40c               add esp, 0xc
// 005fe464  3bf3                 cmp esi, ebx
// 005fe466  75d0                 jne 0x5fe438
// 005fe468  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fe46c  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005fe470  8928                 mov dword ptr [eax], ebp
// 005fe472  895004               mov dword ptr [eax + 4], edx
// 005fe475  897808               mov dword ptr [eax + 8], edi
// 005fe478  5f                   pop edi
// 005fe479  5e                   pop esi
// 005fe47a  5d                   pop ebp
// 005fe47b  5b                   pop ebx
// 005fe47c  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct AxisMoveTool {
    void copyRange(void* dst, void* src, void* end, void (*fn)(void*));
};

void AxisMoveTool::copyRange(void* dst, void* src, void* end, void (*fn)(void*))
{
    char* d = (char*)dst;
    char* s = (char*)src;
    char* e = (char*)end;
    while (s != e) {
        *(void**)d = *(void**)s;
        void* p = *(void**)(s + 4);
        *(void**)(d + 4) = p;
        if (p != 0) {
            _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
        }
        fn(0);
        s += 8;
        d += 8;
    }
    *(void**)dst = fn;
    *(void**)((char*)dst + 4) = e;
    *(void**)((char*)dst + 8) = 0;
}
