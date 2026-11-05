// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00540f70  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540f70
//
// 00540f70  55                   push ebp
// 00540f71  8bec                 mov ebp, esp
// 00540f73  83ec08               sub esp, 8
// 00540f76  894df8               mov dword ptr [ebp - 8], ecx
// 00540f79  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00540f80  8b45f8               mov eax, dword ptr [ebp - 8]
// 00540f83  8b4804               mov ecx, dword ptr [eax + 4]
// 00540f86  51                   push ecx
// 00540f87  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00540f8a  e8a150faff           call 0x4e6030
// 00540f8f  8b55fc               mov edx, dword ptr [ebp - 4]
// 00540f92  83ca01               or edx, 1
// 00540f95  8955fc               mov dword ptr [ebp - 4], edx
// 00540f98  8b4508               mov eax, dword ptr [ebp + 8]
// 00540f9b  8be5                 mov esp, ebp
// 00540f9d  5d                   pop ebp
// 00540f9e  c20400               ret 4

struct PartChunk {
    void* value;
    PartChunk(void* source);
    ~PartChunk();
};

struct Bucket {
    unsigned char padding[4];
    void* value;
    PartChunk f();
};

#pragma optimize("", off)
PartChunk Bucket::f()
{
    return PartChunk(value);
}
#pragma optimize("", on)
