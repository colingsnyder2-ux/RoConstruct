// from server: 100% by Yeetserama
// roc 2007-08 007267f0  unit: boost::thread_resource_error  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007267f0
//
// 007267f0  83ec10               sub esp, 0x10
// 007267f3  56                   push esi
// 007267f4  57                   push edi
// 007267f5  8b3dd0d17700         mov edi, dword ptr [0x77d1d0]
// 007267fb  6a00                 push 0
// 007267fd  6a01                 push 1
// 007267ff  8bf1                 mov esi, ecx
// 00726801  6a01                 push 1
// 00726803  6a00                 push 0
// 00726805  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0072680c  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00726813  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0072681a  ffd7                 call edi
// 0072681c  6a00                 push 0
// 0072681e  68ffffff7f           push 0x7fffffff
// 00726823  6a00                 push 0
// 00726825  6a00                 push 0
// 00726827  8906                 mov dword ptr [esi], eax
// 00726829  ffd7                 call edi
// 0072682b  6a00                 push 0
// 0072682d  6a00                 push 0
// 0072682f  6a00                 push 0
// 00726831  894604               mov dword ptr [esi + 4], eax
// 00726834  ff15ccd17700         call dword ptr [0x77d1cc]
// 0072683a  8b0e                 mov ecx, dword ptr [esi]
// 0072683c  85c9                 test ecx, ecx
// 0072683e  8b3d3cd27700         mov edi, dword ptr [0x77d23c]
// 00726844  894608               mov dword ptr [esi + 8], eax
// 00726847  7415                 je 0x72685e
// 00726849  837e0400             cmp dword ptr [esi + 4], 0
// 0072684d  740c                 je 0x72685b
// 0072684f  85c0                 test eax, eax
// 00726851  7408                 je 0x72685b
// 00726853  5f                   pop edi
// 00726854  8bc6                 mov eax, esi
// 00726856  5e                   pop esi
// 00726857  83c410               add esp, 0x10
// 0072685a  c3                   ret 
// 0072685b  51                   push ecx
// 0072685c  ffd7                 call edi
// 0072685e  8b4604               mov eax, dword ptr [esi + 4]
// 00726861  85c0                 test eax, eax
// 00726863  7403                 je 0x726868
// 00726865  50                   push eax
// 00726866  ffd7                 call edi
// 00726868  8b7608               mov esi, dword ptr [esi + 8]
// 0072686b  85f6                 test esi, esi
// 0072686d  7403                 je 0x726872
// 0072686f  56                   push esi
// 00726870  ffd7                 call edi
// 00726872  8d4c2408             lea ecx, [esp + 8]
// 00726876  e895efffff           call 0x725810
// 0072687b  68783a8400           push 0x843a78
// 00726880  8d44240c             lea eax, [esp + 0xc]
// 00726884  50                   push eax
// 00726885  e814a3f0ff           call 0x630b9e
// copied from an identical function in another client (function ?init@S@ns_ROCX000000@@QAEPAU12@XZ)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
extern "C" void* (__stdcall *CreateSemaphoreA)(void*, long, long, const char*);
extern "C" void* (__stdcall *CreateMutexA)(void*, int, const char*);
extern "C" int (__stdcall *CloseHandle)(void*);

struct Error {
    void* vfptr;
    int pad[2];
    int field_c;
    Error* init();
};

extern unsigned char exception_type[];
extern "C" __declspec(noreturn) void __stdcall raise_exception(void*, void*);

struct S {
    void* semaphore;
    void* limit;
    void* mutex;
    int field_c;
    int field_10;
    int field_14;
    S* init();
};

S* S::init()
{
    void* (__stdcall *create)(void*, long, long, const char*) = CreateSemaphoreA;

    field_c = 0;
    field_10 = 0;
    field_14 = 0;

    semaphore = create(0, 1, 1, 0);
    limit = create(0, 0, 0x7fffffff, 0);

    void* handle = CreateMutexA(0, 0, 0);
    int (__stdcall *close)(void*) = CloseHandle;
    mutex = handle;

    if (semaphore && limit && mutex)
        return this;

    if (semaphore)
        close(semaphore);
    if (limit)
        close(limit);
    if (mutex)
        close(mutex);

    Error error;
    error.init();
    raise_exception(&error, exception_type);
}
}
