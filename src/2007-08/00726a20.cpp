// from server: 100% by Yeetserama
// roc 2007-08 00726a20  unit: boost::thread_resource_error  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726a20
//
// 00726a20  53                   push ebx
// 00726a21  8b1db4d27700         mov ebx, dword ptr [0x77d2b4]
// 00726a27  55                   push ebp
// 00726a28  56                   push esi
// 00726a29  57                   push edi
// 00726a2a  8bf1                 mov esi, ecx
// 00726a2c  8b4604               mov eax, dword ptr [esi + 4]
// 00726a2f  6aff                 push -1
// 00726a31  50                   push eax
// 00726a32  ffd3                 call ebx
// 00726a34  8b4e08               mov ecx, dword ptr [esi + 8]
// 00726a37  6aff                 push -1
// 00726a39  51                   push ecx
// 00726a3a  ffd3                 call ebx
// 00726a3c  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00726a3f  85ff                 test edi, edi
// 00726a41  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00726a44  7425                 je 0x726a6b
// 00726a46  8d47ff               lea eax, [edi - 1]
// 00726a49  85c0                 test eax, eax
// 00726a4b  894614               mov dword ptr [esi + 0x14], eax
// 00726a4e  7549                 jne 0x726a99
// 00726a50  394610               cmp dword ptr [esi + 0x10], eax
// 00726a53  7410                 je 0x726a65
// 00726a55  8b16                 mov edx, dword ptr [esi]
// 00726a57  50                   push eax
// 00726a58  6a01                 push 1
// 00726a5a  52                   push edx
// 00726a5b  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726a61  33ff                 xor edi, edi
// 00726a63  eb34                 jmp 0x726a99
// 00726a65  85ed                 test ebp, ebp
// 00726a67  7430                 je 0x726a99
// 00726a69  eb27                 jmp 0x726a92
// 00726a6b  8d4501               lea eax, [ebp + 1]
// 00726a6e  3dffffff7f           cmp eax, 0x7fffffff
// 00726a73  89460c               mov dword ptr [esi + 0xc], eax
// 00726a76  7521                 jne 0x726a99
// 00726a78  8b06                 mov eax, dword ptr [esi]
// 00726a7a  6aff                 push -1
// 00726a7c  50                   push eax
// 00726a7d  ffd3                 call ebx
// 00726a7f  8b16                 mov edx, dword ptr [esi]
// 00726a81  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00726a84  294e10               sub dword ptr [esi + 0x10], ecx
// 00726a87  6a00                 push 0
// 00726a89  6a01                 push 1
// 00726a8b  52                   push edx
// 00726a8c  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726a92  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00726a99  8b4608               mov eax, dword ptr [esi + 8]
// 00726a9c  50                   push eax
// 00726a9d  ff15c8d17700         call dword ptr [0x77d1c8]
// 00726aa3  83ff01               cmp edi, 1
// 00726aa6  7522                 jne 0x726aca
// 00726aa8  85ed                 test ebp, ebp
// 00726aaa  7411                 je 0x726abd
// 00726aac  8d642400             lea esp, [esp]
// 00726ab0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00726ab3  6aff                 push -1
// 00726ab5  51                   push ecx
// 00726ab6  ffd3                 call ebx
// 00726ab8  83ed01               sub ebp, 1
// 00726abb  75f3                 jne 0x726ab0
// 00726abd  8b16                 mov edx, dword ptr [esi]
// 00726abf  6a00                 push 0
// 00726ac1  6a01                 push 1
// 00726ac3  52                   push edx
// 00726ac4  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726aca  5f                   pop edi
// 00726acb  5e                   pop esi
// 00726acc  5d                   pop ebp
// 00726acd  5b                   pop ebx
// 00726ace  c3                   ret 
// copied from an identical function in another client (function ?method@S@ns_ROCX000003@@QAEXXZ)

namespace ns_ROCX000003 {
// from server: 100% by colin
extern "C" {
    __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
    __declspec(dllimport) int __stdcall ReleaseMutex(void*);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
}

struct S {
    void* field0;
    void* field4;
    void* field8;
    int fieldC;
    int field10;
    int field14;
    void method();
};

void S::method()
{
    unsigned long (__stdcall *wait)(void*, unsigned long) = WaitForSingleObject;
    int (__stdcall *relmutex)(void*) = ReleaseMutex;
    int (__stdcall *relsem)(void*, long, long*) = ReleaseSemaphore;

    wait(field4, 0xffffffffUL);
    wait(field8, 0xffffffffUL);

    int edi = field14;
    int ebp = fieldC;

    if (edi != 0) {
        int remaining = edi - 1;
        field14 = remaining;
        if (remaining == 0) {
            if (field10 != 0) {
                relsem(field0, 1, 0);
                edi = 0;
            } else if (ebp != 0) {
                fieldC = 0;
            }
        }
    } else {
        int count = ebp + 1;
        fieldC = count;
        if (count == 0x7fffffff) {
            wait(field0, 0xffffffffUL);
            field10 -= fieldC;
            relsem(field0, 1, 0);
            fieldC = 0;
        }
    }

    relmutex(field8);

    if (edi == 1) {
        while (ebp != 0) {
            wait(field4, 0xffffffffUL);
            --ebp;
        }
        relsem(field0, 1, 0);
    }
}
}
