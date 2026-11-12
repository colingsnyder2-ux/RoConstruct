// from server: 73% by EspClaude
// from server: 62% by Intel
// roc 2007-08 00437090  unit: RBX::VStandardOut::?$Listener  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437090
//
// 00437090  83ec1c               sub esp, 0x1c
// 00437093  a188518b00           mov eax, dword ptr [0x8b5188]
// 00437098  33c4                 xor eax, esp
// 0043709a  89442418             mov dword ptr [esp + 0x18], eax
// 0043709e  8b442420             mov eax, dword ptr [esp + 0x20]
// 004370a2  56                   push esi
// 004370a3  8b742428             mov esi, dword ptr [esp + 0x28]
// 004370a7  57                   push edi
// 004370a8  50                   push eax
// 004370a9  68b0cd7800           push 0x78cdb0
// 004370ae  8d4c2410             lea ecx, [esp + 0x10]
// 004370b2  6a0b                 push 0xb
// 004370b4  51                   push ecx
// 004370b5  ff156ce97700         call dword ptr [0x77e96c]
// 004370bb  6a14                 push 0x14
// 004370bd  8d54241c             lea edx, [esp + 0x1c]
// 004370c1  52                   push edx
// 004370c2  6a16                 push 0x16
// 004370c4  56                   push esi
// 004370c5  8bf8                 mov edi, eax
// 004370c7  ff15d4e67700         call dword ptr [0x77e6d4]
// 004370cd  50                   push eax
// 004370ce  e80da6fcff           call 0x4016e0
// 004370d3  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 004370d7  83c424               add esp, 0x24
// 004370da  8bc7                 mov eax, edi
// 004370dc  5f                   pop edi
// 004370dd  5e                   pop esi
// 004370de  33cc                 xor ecx, esp
// 004370e0  e839991f00           call 0x630a1e

typedef unsigned int size_t;

extern "C" __declspec(dllimport) int __cdecl swprintf_s(wchar_t* buffer, size_t sizeOfBuffer, const wchar_t* format, ...);
extern "C" __declspec(dllimport) int __cdecl sub_77e6d4(int, int, wchar_t*, int);
extern "C" void __cdecl sub_4016e0(int);

int __cdecl ListenerFormat(int a1, int a2) {
    wchar_t buffer[11];
    int result = swprintf_s(buffer, 11, L"&#x%06X;", a1);
    sub_4016e0(sub_77e6d4(a2, 0x16, buffer, 0x14));
    return result;
}
