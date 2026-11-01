// from server: 100% by colin
// roc 2007-08 007257b0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007257b0
//
// 007257b0  80790400             cmp byte ptr [ecx + 4], 0
// 007257b4  740c                 je 0x7257c2
// 007257b6  8b01                 mov eax, dword ptr [ecx]
// 007257b8  89442404             mov dword ptr [esp + 4], eax
// 007257bc  ff25f8d27700         jmp dword ptr [0x77d2f8]
// 007257c2  8b09                 mov ecx, dword ptr [ecx]
// 007257c4  894c2404             mov dword ptr [esp + 4], ecx
// 007257c8  ff25c8d17700         jmp dword ptr [0x77d1c8]
// copied from an identical function in another client (function ?unlock@S@@QAEXAAPAX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" {
    extern void (__stdcall *LeaveCriticalSection)(void *);
    extern int (__stdcall *ReleaseMutex)(void *);
}

struct S {
    void *handle;
    unsigned char criticalSection;
    void unlock(void *&);
};

void S::unlock(void *&)
{
    if (criticalSection)
        LeaveCriticalSection(handle);
    else
        ReleaseMutex(handle);
}