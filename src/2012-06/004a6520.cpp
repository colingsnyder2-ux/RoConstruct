// from server: 100% by Xemicl
// roc 2012-06 004a6520  unit: CSettingsDialog  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a6520
//
// 004a6520  56                   push esi
// 004a6521  8bf1                 mov esi, ecx
// 004a6523  8b4604               mov eax, dword ptr [esi + 4]
// 004a6526  85c0                 test eax, eax
// 004a6528  7504                 jne 0x4a652e
// 004a652a  3906                 cmp dword ptr [esi], eax
// 004a652c  741d                 je 0x4a654b
// 004a652e  57                   push edi
// 004a652f  8b3de821b200         mov edi, dword ptr [0xb221e8]
// 004a6535  50                   push eax
// 004a6536  ffd7                 call edi
// 004a6538  8b06                 mov eax, dword ptr [esi]
// 004a653a  50                   push eax
// 004a653b  ffd7                 call edi
// 004a653d  c7460400000000       mov dword ptr [esi + 4], 0
// 004a6544  c70600000000         mov dword ptr [esi], 0
// 004a654a  5f                   pop edi
// 004a654b  5e                   pop esi
// 004a654c  c3                   ret 
// copied from an identical function in another client (function ?close@HandlePair@@QAEXXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct HandlePair {
    void* a;
    void* b;
    void close();
};
void HandlePair::close()
{
    if (b != 0 || a != 0) {
        CloseHandle(b);
        CloseHandle(a);
        b = 0;
        a = 0;
    }
}