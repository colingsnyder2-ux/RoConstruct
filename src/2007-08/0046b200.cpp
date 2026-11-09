// from server: 100% by colin
// roc 2007-08 0046b200  unit: RBX::LDraw2Lua::LuaObjectWriter  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046b200
//
// 0046b200  56                   push esi
// 0046b201  8bf1                 mov esi, ecx
// 0046b203  8b06                 mov eax, dword ptr [esi]
// 0046b205  8b08                 mov ecx, dword ptr [eax]
// 0046b207  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046b20a  03c8                 add ecx, eax
// 0046b20c  ff1508e67700         call dword ptr [0x77e608]
// 0046b212  85c0                 test eax, eax
// 0046b214  7418                 je 0x46b22e
// 0046b216  8b06                 mov eax, dword ptr [esi]
// 0046b218  8b10                 mov edx, dword ptr [eax]
// 0046b21a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0046b21d  03c8                 add ecx, eax
// 0046b21f  ff1508e67700         call dword ptr [0x77e608]
// 0046b225  8bc8                 mov ecx, eax
// 0046b227  5e                   pop esi
// 0046b228  ff25d8e57700         jmp dword ptr [0x77e5d8]
// 0046b22e  5e                   pop esi
// 0046b22f  c3                   ret 
// copied from an identical function in another client (function ?Unlock@CIDEDocManager@@QAEXXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Stream {
    int* offsets;
};

struct Buffer;

extern Buffer* (__thiscall* rdbuf)(const void*);
extern void (__thiscall* unlock)(Buffer*);

struct CIDEDocManager {
    Stream* stream;
    void Unlock();
};

void CIDEDocManager::Unlock()
{
    if (rdbuf(reinterpret_cast<const char*>(stream) + stream->offsets[1]))
        unlock(rdbuf(reinterpret_cast<const char*>(stream) + stream->offsets[1]));
}