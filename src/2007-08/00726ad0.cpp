// from server: 100% by Yeetserama
// roc 2007-08 00726ad0  unit: boost::thread_resource_error  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726ad0
//
// 00726ad0  83ec14               sub esp, 0x14
// 00726ad3  53                   push ebx
// 00726ad4  8b1db4d27700         mov ebx, dword ptr [0x77d2b4]
// 00726ada  55                   push ebp
// 00726adb  56                   push esi
// 00726adc  57                   push edi
// 00726add  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00726ae1  8bf1                 mov esi, ecx
// 00726ae3  8b0f                 mov ecx, dword ptr [edi]
// 00726ae5  8b5704               mov edx, dword ptr [edi + 4]
// 00726ae8  8d442410             lea eax, [esp + 0x10]
// 00726aec  50                   push eax
// 00726aed  83ec10               sub esp, 0x10
// 00726af0  8bc4                 mov eax, esp
// 00726af2  8908                 mov dword ptr [eax], ecx
// 00726af4  8b4f08               mov ecx, dword ptr [edi + 8]
// 00726af7  895004               mov dword ptr [eax + 4], edx
// 00726afa  8b570c               mov edx, dword ptr [edi + 0xc]
// 00726afd  894808               mov dword ptr [eax + 8], ecx
// 00726b00  89500c               mov dword ptr [eax + 0xc], edx
// 00726b03  e8d8f7ffff           call 0x7262e0
// 00726b08  8b442424             mov eax, dword ptr [esp + 0x24]
// 00726b0c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00726b0f  83c414               add esp, 0x14
// 00726b12  50                   push eax
// 00726b13  51                   push ecx
// 00726b14  ffd3                 call ebx
// 00726b16  85c0                 test eax, eax
// 00726b18  0f94442428           sete byte ptr [esp + 0x28]
// 00726b1d  3d02010000           cmp eax, 0x102
// 00726b22  752f                 jne 0x726b53
// 00726b24  8d542414             lea edx, [esp + 0x14]
// 00726b28  6a01                 push 1
// 00726b2a  52                   push edx
// 00726b2b  e850fcffff           call 0x726780
// 00726b30  8b07                 mov eax, dword ptr [edi]
// 00726b32  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00726b36  8b4f04               mov ecx, dword ptr [edi + 4]
// 00726b39  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00726b3d  83c408               add esp, 8
// 00726b40  3bc2                 cmp eax, edx
// 00726b42  7537                 jne 0x726b7b
// 00726b44  3bcd                 cmp ecx, ebp
// 00726b46  7535                 jne 0x726b7d
// 00726b48  8b4708               mov eax, dword ptr [edi + 8]
// 00726b4b  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 00726b4f  85c0                 test eax, eax
// 00726b51  7f90                 jg 0x726ae3
// 00726b53  8b4608               mov eax, dword ptr [esi + 8]
// 00726b56  6aff                 push -1
// 00726b58  50                   push eax
// 00726b59  ffd3                 call ebx
// 00726b5b  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00726b5e  85ff                 test edi, edi
// 00726b60  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00726b63  7456                 je 0x726bbb
// 00726b65  807c242800           cmp byte ptr [esp + 0x28], 0
// 00726b6a  7528                 jne 0x726b94
// 00726b6c  8b4610               mov eax, dword ptr [esi + 0x10]
// 00726b6f  85c0                 test eax, eax
// 00726b71  741b                 je 0x726b8e
// 00726b73  83c0ff               add eax, -1
// 00726b76  894610               mov dword ptr [esi + 0x10], eax
// 00726b79  eb19                 jmp 0x726b94
// 00726b7b  3bcd                 cmp ecx, ebp
// 00726b7d  7cd4                 jl 0x726b53
// 00726b7f  0f8f5effffff         jg 0x726ae3
// 00726b85  3bc2                 cmp eax, edx
// 00726b87  76ca                 jbe 0x726b53
// 00726b89  e955ffffff           jmp 0x726ae3
// 00726b8e  8d4d01               lea ecx, [ebp + 1]
// 00726b91  894e0c               mov dword ptr [esi + 0xc], ecx
// 00726b94  8d47ff               lea eax, [edi - 1]
// 00726b97  85c0                 test eax, eax
// 00726b99  894614               mov dword ptr [esi + 0x14], eax
// 00726b9c  754b                 jne 0x726be9
// 00726b9e  394610               cmp dword ptr [esi + 0x10], eax
// 00726ba1  7410                 je 0x726bb3
// 00726ba3  8b16                 mov edx, dword ptr [esi]
// 00726ba5  50                   push eax
// 00726ba6  6a01                 push 1
// 00726ba8  52                   push edx
// 00726ba9  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726baf  33ff                 xor edi, edi
// 00726bb1  eb36                 jmp 0x726be9
// 00726bb3  837e0c00             cmp dword ptr [esi + 0xc], 0
// 00726bb7  7430                 je 0x726be9
// 00726bb9  eb27                 jmp 0x726be2
// 00726bbb  8d4501               lea eax, [ebp + 1]
// 00726bbe  3dffffff7f           cmp eax, 0x7fffffff
// 00726bc3  89460c               mov dword ptr [esi + 0xc], eax
// 00726bc6  7521                 jne 0x726be9
// 00726bc8  8b06                 mov eax, dword ptr [esi]
// 00726bca  6aff                 push -1
// 00726bcc  50                   push eax
// 00726bcd  ffd3                 call ebx
// 00726bcf  8b16                 mov edx, dword ptr [esi]
// 00726bd1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00726bd4  294e10               sub dword ptr [esi + 0x10], ecx
// 00726bd7  6a00                 push 0
// 00726bd9  6a01                 push 1
// 00726bdb  52                   push edx
// 00726bdc  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726be2  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00726be9  8b4608               mov eax, dword ptr [esi + 8]
// 00726bec  50                   push eax
// 00726bed  ff15c8d17700         call dword ptr [0x77d1c8]
// 00726bf3  83ff01               cmp edi, 1
// 00726bf6  7522                 jne 0x726c1a
// 00726bf8  85ed                 test ebp, ebp
// 00726bfa  7411                 je 0x726c0d
// 00726bfc  8d642400             lea esp, [esp]
// 00726c00  8b4e04               mov ecx, dword ptr [esi + 4]
// 00726c03  6aff                 push -1
// 00726c05  51                   push ecx
// 00726c06  ffd3                 call ebx
// 00726c08  83ed01               sub ebp, 1
// 00726c0b  75f3                 jne 0x726c00
// 00726c0d  8b16                 mov edx, dword ptr [esi]
// 00726c0f  6a00                 push 0
// 00726c11  6a01                 push 1
// 00726c13  52                   push edx
// 00726c14  ff15d4d17700         call dword ptr [0x77d1d4]
// 00726c1a  8a442428             mov al, byte ptr [esp + 0x28]
// 00726c1e  5f                   pop edi
// 00726c1f  5e                   pop esi
// 00726c20  5d                   pop ebp
// 00726c21  5b                   pop ebx
// 00726c22  83c414               add esp, 0x14
// 00726c25  c20400               ret 4
// copied from an identical function in another client (function ?wait@S@ns_ROCX000004@@QAE_NPBUTimeValue@2@@Z)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
struct TimeValue {
    __int64 seconds;
    int nanoseconds;
};

extern int __cdecl readTime(TimeValue*, int);
extern void __cdecl remainingTime(TimeValue, unsigned long*);

extern unsigned long (__stdcall * const WaitForSingleObject)(void*, unsigned long);
extern int (__stdcall * const ReleaseSemaphore)(void*, long, long*);
extern int (__stdcall * const ReleaseMutex)(void*);

struct S {
    void* semaphore;
    void* event;
    void* mutex;
    int pending;
    int consumed;
    int waiters;

    bool wait(const TimeValue*);
};

bool S::wait(const TimeValue* target)
{
    unsigned long (__stdcall *waitFunction)(void*, unsigned long) =
        WaitForSingleObject;
    unsigned long timeout;
    TimeValue now;
    bool success;

    do {
        remainingTime(*target, &timeout);
        unsigned long result = waitFunction(event, timeout);
        success = result == 0;
        if (result != 0x102)
            break;
        readTime(&now, 1);
    } while ((target->seconds == now.seconds
              ? target->nanoseconds - now.nanoseconds
              : (target->seconds > now.seconds ? 1 : -1)) > 0);

    waitFunction(mutex, 0xffffffffUL);

    int oldWaiters = waiters;
    int oldPending = pending;

    if (oldWaiters != 0) {
        if (!success) {
            if (consumed != 0)
                --consumed;
            else
                pending = oldPending + 1;
        }

        if (--waiters == 0) {
            if (consumed != 0) {
                ReleaseSemaphore(semaphore, 1, 0);
                oldWaiters = 0;
            } else if (pending != 0) {
                pending = 0;
            }
        }
    } else {
        if ((pending = oldPending + 1) == 0x7fffffff) {
            waitFunction(semaphore, 0xffffffffUL);
            consumed -= pending;
            ReleaseSemaphore(semaphore, 1, 0);
            pending = 0;
        }
    }

    ReleaseMutex(mutex);

    if (oldWaiters == 1) {
        if (oldPending != 0) {
            do {
                waitFunction(event, 0xffffffffUL);
            } while (--oldPending != 0);
        }
        ReleaseSemaphore(semaphore, 1, 0);
    }

    return success;
}
}
