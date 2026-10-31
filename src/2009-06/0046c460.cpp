// from server: 100% by EspClaude
// roc 2009-06 0046c460  unit: DxUserInput  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046c460
//
// 0046c460  6aff                 push -1
// 0046c462  68d3338500           push 0x8533d3
// 0046c467  64a100000000         mov eax, dword ptr fs:[0]
// 0046c46d  50                   push eax
// 0046c46e  64892500000000       mov dword ptr fs:[0], esp
// 0046c475  83ec10               sub esp, 0x10
// 0046c478  56                   push esi
// 0046c479  57                   push edi
// 0046c47a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0046c482  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0046c486  8bf1                 mov esi, ecx
// 0046c488  8bcf                 mov ecx, edi
// 0046c48a  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0046c490  8d4c2408             lea ecx, [esp + 8]
// 0046c494  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0046c49c  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0046c4a2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0046c4a6  8b08                 mov ecx, dword ptr [eax]
// 0046c4a8  0fb75602             movzx edx, word ptr [esi + 2]
// 0046c4ac  0fb706               movzx eax, word ptr [esi]
// 0046c4af  51                   push ecx
// 0046c4b0  52                   push edx
// 0046c4b1  50                   push eax
// 0046c4b2  8d4c2414             lea ecx, [esp + 0x14]
// 0046c4b6  686cd08b00           push 0x8bd06c
// 0046c4bb  51                   push ecx
// 0046c4bc  c744243401000000     mov dword ptr [esp + 0x34], 1
// 0046c4c4  ff15c4fc8900         call dword ptr [0x89fcc4]
// 0046c4ca  83c414               add esp, 0x14
// 0046c4cd  8d542414             lea edx, [esp + 0x14]
// 0046c4d1  52                   push edx
// 0046c4d2  8d442410             lea eax, [esp + 0x10]
// 0046c4d6  50                   push eax
// 0046c4d7  8d4c2410             lea ecx, [esp + 0x10]
// 0046c4db  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046c4e3  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046c4eb  ff1508028a00         call dword ptr [0x8a0208]
// 0046c4f1  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046c4f4  50                   push eax
// 0046c4f5  51                   push ecx
// 0046c4f6  e8c3ec3a00           call 0x81b1be
// 0046c4fb  85c0                 test eax, eax
// 0046c4fd  740d                 je 0x46c50c
// 0046c4ff  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046c503  52                   push edx
// 0046c504  8bcf                 mov ecx, edi
// 0046c506  ff15acfc8900         call dword ptr [0x89fcac]
// 0046c50c  8d4c2408             lea ecx, [esp + 8]
// 0046c510  ff1510fd8900         call dword ptr [0x89fd10]
// 0046c516  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046c51a  8bc7                 mov eax, edi
// 0046c51c  5f                   pop edi
// 0046c51d  5e                   pop esi
// 0046c51e  64890d00000000       mov dword ptr fs:[0], ecx
// 0046c525  83c41c               add esp, 0x1c
// 0046c528  c20800               ret 8
// copied from an identical function in another client (function ?query@DxUserInput@ns_ROCX00001e@@QAE?AUString@2@ABU32@@Z)

namespace ns_ROCX00001e {
// from server: 86% by colin
struct __declspec(dllimport) String
{
    char* data;

    String() throw();
    ~String() throw();
    void __cdecl Format(const char* format, ...);
    operator const char*() const throw();
    String& operator=(const char* text);
};

struct __declspec(dllimport) PathString
{
    char* data;

    PathString() throw();
    ~PathString() throw();
    void __cdecl Format(const char* format, ...);
    operator const char*() const throw();
    PathString& operator=(const char* text);
};

extern "C" int __stdcall VerQueryValueA(
    const void* block,
    const char* subBlock,
    void** value,
    unsigned int* length);

extern "C" int __cdecl sub_7A6368(void*, void*);

struct DxUserInput
{
    unsigned short language;
    unsigned short codePage;
    void* block;

    String query(const String& name);
};

String DxUserInput::query(const String& name)
{
    String result;
    PathString path;

    path.Format("\\StringFileInfo\\%04x%04x\\%s",
                language, codePage, name.data);

    void* value = 0;
    unsigned int length = 0;

    if (VerQueryValueA(block, path, &value, &length))
        result = static_cast<const char*>(value);

    return result;
}
}
