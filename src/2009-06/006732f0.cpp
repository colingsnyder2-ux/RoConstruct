// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 006334f0  unit: RBX::Network::VPlayer::?$BoundPropGetSet  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006334f0
//
// 006334f0  8b442408             mov eax, dword ptr [esp + 8]
// 006334f4  85c0                 test eax, eax
// 006334f6  7413                 je 0x63350b
// 006334f8  8b4908               mov ecx, dword ptr [ecx + 8]
// 006334fb  8b5408ec             mov edx, dword ptr [eax + ecx - 0x14]
// 006334ff  83c0ec               add eax, -0x14
// 00633502  8b442404             mov eax, dword ptr [esp + 4]
// 00633506  8910                 mov dword ptr [eax], edx
// 00633508  c20800               ret 8
// 0063350b  8b4908               mov ecx, dword ptr [ecx + 8]
// 0063350e  33c0                 xor eax, eax
// 00633510  8b1408               mov edx, dword ptr [eax + ecx]
// 00633513  8b442404             mov eax, dword ptr [esp + 4]
// 00633517  8910                 mov dword ptr [eax], edx
// 00633519  c20800               ret 8

struct Result
{
    int value;
};

struct S
{
    int unused[2];
    int offset;
    Result f(void* object);
};

Result S::f(void* object)
{
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    Result result;
    result.value = *reinterpret_cast<int*>(base + offset);
    return result;
}
