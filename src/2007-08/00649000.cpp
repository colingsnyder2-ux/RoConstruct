// from server: 87% by EspClaude
// from server: 41% by colin
// roc 2007-08 00649000  unit: CXTPCommandBar  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00649000
// 00649000  55                   push ebp
// 00649001  8bec                 mov ebp, esp
// 00649003  6afe                 push -2
// 00649005  68e0ac8600           push 0x86ace0
// 0064900a  68760a6300           push 0x630a76
// 0064900f  64a100000000         mov eax, dword ptr fs:[0]
// 00649015  50                   push eax
// 00649016  83ec18               sub esp, 0x18
// 00649019  53                   push ebx
// 0064901a  56                   push esi
// 0064901b  57                   push edi
// 0064901c  a188518b00           mov eax, dword ptr [0x8b5188]
// 00649021  3145f8               xor dword ptr [ebp - 8], eax
// 00649024  33c5                 xor eax, ebp
// 00649026  50                   push eax
// 00649027  8d45f0               lea eax, [ebp - 0x10]
// 0064902a  64a300000000         mov dword ptr fs:[0], eax
// 00649030  8bf1                 mov esi, ecx
// 00649032  33db                 xor ebx, ebx
// 00649034  895de0               mov dword ptr [ebp - 0x20], ebx
// 00649037  8d45e0               lea eax, [ebp - 0x20]
// 0064903a  50                   push eax
// 0064903b  e8c26efeff           call 0x62ff02
// 00649040  8b889c000000         mov ecx, dword ptr [eax + 0x9c]
// 00649046  51                   push ecx
// 00649047  e80274feff           call 0x63044e
// 0064904c  8bf8                 mov edi, eax
// 0064904e  897ddc               mov dword ptr [ebp - 0x24], edi
// 00649051  895de4               mov dword ptr [ebp - 0x1c], ebx
// 00649054  3bfb                 cmp edi, ebx
// 00649056  7516                 jne 0x64906e
// 00649058  33c0                 xor eax, eax
// 0064905a  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 0064905d  64890d00000000       mov dword ptr fs:[0], ecx
// 00649064  59                   pop ecx
// 00649065  5f                   pop edi
// 00649066  5e                   pop esi
// 00649067  5b                   pop ebx
// 00649068  8be5                 mov esp, ebp
// 0064906a  5d                   pop ebp
// 0064906b  c20c00               ret 0xc
// 0064906e  895dfc               mov dword ptr [ebp - 4], ebx
// 00649071  8d55d8               lea edx, [ebp - 0x28]
// 00649074  52                   push edx
// 00649075  8bce                 mov ecx, esi
// 00649077  e844ffffff           call 0x648fc0
// 0064907c  8bb69c000000         mov esi, dword ptr [esi + 0x9c]
// 00649082  33c0                 xor eax, eax
// 00649084  3bf3                 cmp esi, ebx
// 00649086  0f95c0               setne al
// 00649089  3bc3                 cmp eax, ebx
// 0064908b  7505                 jne 0x649092
// 0064908d  e88e6efeff           call 0x62ff20
// 00649092  8b4510               mov eax, dword ptr [ebp + 0x10]
// 00649095  50                   push eax
// 00649096  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00649099  51                   push ecx
// 0064909a  8b5508               mov edx, dword ptr [ebp + 8]
// 0064909d  52                   push edx
// 0064909e  ffd6                 call esi
// 006490a0  8bd8                 mov ebx, eax
// 006490a2  895de4               mov dword ptr [ebp - 0x1c], ebx
// 006490a5  c745fcfeffffff       mov dword ptr [ebp - 4], 0xfffffffe
// 006490ac  e81c000000           call 0x6490cd
// 006490b1  8bc3                 mov eax, ebx
// 006490b3  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 006490b6  64890d00000000       mov dword ptr fs:[0], ecx
// 006490bd  59                   pop ecx
// 006490be  5f                   pop edi
// 006490bf  5e                   pop esi
// 006490c0  5b                   pop ebx
// 006490c1  8be5                 mov esp, ebp
// 006490c3  5d                   pop ebp
// 006490c4  c20c00               ret 0xc

struct AFX_MODULE_STATE_ {
    char padding[0x9c];
    void* m_hActCtx;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long);
extern "C" AFX_MODULE_STATE_* __cdecl AfxGetModuleState();
extern "C" int __stdcall AfxActivateActCtxWrapper(void* hActCtx, unsigned long* cookie);
extern "C" int __stdcall AfxDeactivateActCtx(unsigned long flags, unsigned long cookie);
extern "C" void __cdecl AfxThrowInvalidArgException();

typedef int (__stdcall *PFN3)(int, int, int);

struct CXTPCommandBar {
    char padding[0x9c];
    void* m_pfn;
    void** GetProc(void** result);
    int Call(int a1, int a2, int a3);
};

int CXTPCommandBar::Call(int a1, int a2, int a3)
{
    unsigned long cookie = 0;
    int eResult = AfxActivateActCtxWrapper(AfxGetModuleState()->m_hActCtx, &cookie);
    int rc = 0;
    if (eResult == 0)
        return 0;
    __try {
        void* tmp;
        GetProc(&tmp);
        PFN3 pfn = (PFN3)m_pfn;
        int valid = pfn != 0;
        if (!valid)
            AfxThrowInvalidArgException();
        rc = pfn(a1, a2, a3);
    }
    __finally {
        if (eResult != 2) {
            const int fPreserve = (rc == 0);
            const unsigned long err = fPreserve ? GetLastError() : 0;
            AfxDeactivateActCtx(0, cookie);
            if (fPreserve)
                SetLastError(err);
        }
    }
    return rc;
}
