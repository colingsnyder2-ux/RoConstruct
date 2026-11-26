// from server: 100% by Xemicl
// roc 2012-06 00998670  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00998670
//
// 00998670  56                   push esi
// 00998671  8bf1                 mov esi, ecx
// 00998673  83be9c00000000       cmp dword ptr [esi + 0x9c], 0
// 0099867a  7517                 jne 0x998693
// 0099867c  6834e7c000           push 0xc0e734
// 00998681  e88a03a8ff           call 0x418a10
// 00998686  50                   push eax
// 00998687  ff15b021b200         call dword ptr [0xb221b0]
// 0099868d  89869c000000         mov dword ptr [esi + 0x9c], eax
// 00998693  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 00998699  8b442408             mov eax, dword ptr [esp + 8]
// 0099869d  8908                 mov dword ptr [eax], ecx
// 0099869f  5e                   pop esi
// 009986a0  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX000009@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX000009 {
// from server: 100% by tester
// roc 2008-06 006ba510  unit: CXTPPropertyGridItemConstraint  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba510
//
// 006ba510  56                   push esi
// 006ba511  8bf1                 mov esi, ecx
// 006ba513  83be9c00000000       cmp dword ptr [esi + 0x9c], 0
// 006ba51a  7517                 jne 0x6ba533
// 006ba51c  68a4208500           push 0x8520a4
// 006ba521  e81a8ad5ff           call 0x412f40
// 006ba526  50                   push eax
// 006ba527  ff15c0218000         call dword ptr [0x8021c0]
// 006ba52d  89869c000000         mov dword ptr [esi + 0x9c], eax
// 006ba533  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 006ba539  8b442408             mov eax, dword ptr [esp + 8]
// 006ba53d  8908                 mov dword ptr [eax], ecx
// 006ba53f  5e                   pop esi
// 006ba540  c20400               ret 4

extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x9c];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_GetImageInfo");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
