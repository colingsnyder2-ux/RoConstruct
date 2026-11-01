// from server: 100% by Yeetserama
// roc 2007-08 007268b0  unit: boost::thread_resource_error  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007268b0
//
// 007268b0  53                   push ebx
// 007268b1  8b1db4d27700         mov ebx, dword ptr [0x77d2b4]
// 007268b7  55                   push ebp
// 007268b8  56                   push esi
// 007268b9  57                   push edi
// 007268ba  8bf1                 mov esi, ecx
// 007268bc  8b4608               mov eax, dword ptr [esi + 8]
// 007268bf  6aff                 push -1
// 007268c1  50                   push eax
// 007268c2  33ff                 xor edi, edi
// 007268c4  ffd3                 call ebx
// 007268c6  8b4614               mov eax, dword ptr [esi + 0x14]
// 007268c9  85c0                 test eax, eax
// 007268cb  8b2dd4d17700         mov ebp, dword ptr [0x77d1d4]
// 007268d1  7429                 je 0x7268fc
// 007268d3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007268d6  85c9                 test ecx, ecx
// 007268d8  750f                 jne 0x7268e9
// 007268da  8b4e08               mov ecx, dword ptr [esi + 8]
// 007268dd  51                   push ecx
// 007268de  ff15c8d17700         call dword ptr [0x77d1c8]
// 007268e4  5f                   pop edi
// 007268e5  5e                   pop esi
// 007268e6  5d                   pop ebp
// 007268e7  5b                   pop ebx
// 007268e8  c3                   ret 
// 007268e9  83c001               add eax, 1
// 007268ec  83c1ff               add ecx, -1
// 007268ef  894614               mov dword ptr [esi + 0x14], eax
// 007268f2  894e10               mov dword ptr [esi + 0x10], ecx
// 007268f5  bf01000000           mov edi, 1
// 007268fa  eb34                 jmp 0x726930
// 007268fc  8b16                 mov edx, dword ptr [esi]
// 007268fe  6aff                 push -1
// 00726900  52                   push edx
// 00726901  ffd3                 call ebx
// 00726903  8b4610               mov eax, dword ptr [esi + 0x10]
// 00726906  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00726909  3bc1                 cmp eax, ecx
// 0072690b  761a                 jbe 0x726927
// 0072690d  85c9                 test ecx, ecx
// 0072690f  7408                 je 0x726919
// 00726911  2bc1                 sub eax, ecx
// 00726913  894610               mov dword ptr [esi + 0x10], eax
// 00726916  897e0c               mov dword ptr [esi + 0xc], edi
// 00726919  834610ff             add dword ptr [esi + 0x10], -1
// 0072691d  bf01000000           mov edi, 1
// 00726922  897e14               mov dword ptr [esi + 0x14], edi
// 00726925  eb09                 jmp 0x726930
// 00726927  8b06                 mov eax, dword ptr [esi]
// 00726929  6a00                 push 0
// 0072692b  6a01                 push 1
// 0072692d  50                   push eax
// 0072692e  ffd5                 call ebp
// 00726930  8b4e08               mov ecx, dword ptr [esi + 8]
// 00726933  51                   push ecx
// 00726934  ff15c8d17700         call dword ptr [0x77d1c8]
// 0072693a  85ff                 test edi, edi
// 0072693c  7409                 je 0x726947
// 0072693e  8b5604               mov edx, dword ptr [esi + 4]
// 00726941  6a00                 push 0
// 00726943  57                   push edi
// 00726944  52                   push edx
// 00726945  ffd5                 call ebp
// 00726947  5f                   pop edi
// 00726948  5e                   pop esi
// 00726949  5d                   pop ebp
// 0072694a  5b                   pop ebx
// 0072694b  c3                   ret 
// copied from an identical function in another client (function ?func@FaceInstance@ns_ROCX000001@@QAEXXZ)

namespace ns_ROCX000001 {
// from server: 100% by tester
extern "C" {
    __declspec(dllimport) void* __stdcall WaitForSingleObject(void*, unsigned long);
    __declspec(dllimport) int __stdcall ReleaseMutex(void*);
    __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
}

struct FaceInstance {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void func();
};

void FaceInstance::func()
{
    void* (__stdcall *wait)(void*, unsigned long) = WaitForSingleObject;
    int (__stdcall *release)(void*, long, long*) = ReleaseSemaphore;
    int (__stdcall *relmutex)(void*) = ReleaseMutex;

    int did = 0;
    wait(field8, (unsigned long)-1);

    if (field14 != 0) {
        if (field10 == 0) {
            relmutex(field8);
            return;
        }
        field14 = (char*)field14 + 1;
        field10 = (char*)field10 - 1;
        did = 1;
    } else {
        wait(field0, (unsigned long)-1);
        unsigned int a = (unsigned int)field10;
        unsigned int b = (unsigned int)fieldC;
        if (a > b) {
            if (b != 0) {
                field10 = (void*)(a - b);
                fieldC = (void*)did;
            }
            field10 = (char*)field10 - 1;
            did = 1;
            field14 = (void*)did;
        } else {
            release(field0, 1, 0);
        }
    }

    relmutex(field8);

    if (did != 0) {
        release(field4, did, 0);
    }
}
}
