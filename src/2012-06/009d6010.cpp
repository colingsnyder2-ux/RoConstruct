// roc 2012-06 009d6010  unit: CXTPDrawHelpers  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d6010
//
// 009d6010  8b442404             mov eax, dword ptr [esp + 4]
// 009d6014  85c0                 test eax, eax
// 009d6016  740c                 je 0x9d6024
// 009d6018  8b4004               mov eax, dword ptr [eax + 4]
// 009d601b  89442404             mov dword ptr [esp + 4], eax
// 009d601f  e9ece8ffff           jmp 0x9d4910
// 009d6024  c3                   ret 
// copied from an identical function in another client (function ?Draw3dRect@CXTPDrawHelpers@ns_ROCX000066@@SAXPAX@Z)

namespace ns_ROCX000066 {
struct CXTPDrawHelpers
{
    static void Draw3dRect(void* p);
};

extern "C" void __cdecl helper_0067f830(void* p);

void CXTPDrawHelpers::Draw3dRect(void* p)
{
    if (p != 0)
    {
        helper_0067f830(*(void**)((char*)p + 4));
    }
}
}
