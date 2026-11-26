// from server: 100% by Xemicl
// roc 2012-06 00745830  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00745830
//
// 00745830  8b442404             mov eax, dword ptr [esp + 4]
// 00745834  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00745838  7205                 jb 0x74583f
// 0074583a  8b4004               mov eax, dword ptr [eax + 4]
// 0074583d  eb03                 jmp 0x745842
// 0074583f  83c004               add eax, 4
// 00745842  50                   push eax
// 00745843  8d442408             lea eax, [esp + 8]
// 00745847  50                   push eax
// 00745848  e853d2ffff           call 0x742aa0
// 0074584d  8b08                 mov ecx, dword ptr [eax]
// 0074584f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00745853  83c408               add esp, 8
// 00745856  890a                 mov dword ptr [edx], ecx
// 00745858  b001                 mov al, 1
// 0074585a  c3                   ret 
// copied from an identical function in another client (function ?parse@ns_ROCX000007@@YA_NPBUString@1@PAH@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
// roc 2008-06 005bf0a0  unit: RBX::Soundscape::SoundService  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bf0a0
//
// 005bf0a0  8b442404             mov eax, dword ptr [esp + 4]
// 005bf0a4  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005bf0a8  7205                 jb 0x5bf0af
// 005bf0aa  8b4004               mov eax, dword ptr [eax + 4]
// 005bf0ad  eb03                 jmp 0x5bf0b2
// 005bf0af  83c004               add eax, 4
// 005bf0b2  50                   push eax
// 005bf0b3  8d442408             lea eax, [esp + 8]
// 005bf0b7  50                   push eax
// 005bf0b8  e8f36bffff           call 0x5b5cb0
// 005bf0bd  8b08                 mov ecx, dword ptr [eax]
// 005bf0bf  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bf0c3  83c408               add esp, 8
// 005bf0c6  890a                 mov dword ptr [edx], ecx
// 005bf0c8  b001                 mov al, 1
// 005bf0ca  c3                   ret 

struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;
};

extern int* __cdecl convert(void* result, const char* text);

bool __cdecl parse(const String* text, int* result)
{
    const char* chars = text->capacity >= 16
        ? text->data.pointer
        : text->data.buffer;
    *result = *convert(&text, chars);
    return true;
}
}
