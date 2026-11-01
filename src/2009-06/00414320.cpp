// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00413d10  unit: CopyVerb  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413d10
//
// 00413d10  53                   push ebx
// 00413d11  56                   push esi
// 00413d12  8bb154010000         mov esi, dword ptr [ecx + 0x154]
// 00413d18  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00413d1b  57                   push edi
// 00413d1c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00413d20  c70700000000         mov dword ptr [edi], 0
// 00413d26  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00413d29  7606                 jbe 0x413d31
// 00413d2b  ff1590288000         call dword ptr [0x802890]
// 00413d31  8b06                 mov eax, dword ptr [esi]
// 00413d33  8907                 mov dword ptr [edi], eax
// 00413d35  895f04               mov dword ptr [edi + 4], ebx
// 00413d38  8bc7                 mov eax, edi
// 00413d3a  5f                   pop edi
// 00413d3b  5e                   pop esi
// 00413d3c  5b                   pop ebx
// 00413d3d  c20400               ret 4

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Data {
    unsigned int value;
    unsigned int unused[2];
    unsigned int limit;
    unsigned int position;
};

struct Result {
    unsigned int value;
    unsigned int position;
};

struct CopyVerb {
    char padding[0x8c];
    Data* data;
    Result* get(Result* result);
};

Result* CopyVerb::get(Result* result)
{
    Data* source = data;
    unsigned int position = source->position;
    result->value = 0;
    if (source->limit > position)
        invalid_parameter_noinfo();
    result->value = source->value;
    result->position = position;
    return result;
}
