// from server: 100% by Yeetserama
// roc 2010-06 0047ae80  unit: DxUserInput  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047ae80
//
// 0047ae80  6aff                 push -1
// 0047ae82  68b34e9800           push 0x984eb3
// 0047ae87  64a100000000         mov eax, dword ptr fs:[0]
// 0047ae8d  50                   push eax
// 0047ae8e  64892500000000       mov dword ptr fs:[0], esp
// 0047ae95  83ec10               sub esp, 0x10
// 0047ae98  56                   push esi
// 0047ae99  57                   push edi
// 0047ae9a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0047aea2  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0047aea6  8bf1                 mov esi, ecx
// 0047aea8  8bcf                 mov ecx, edi
// 0047aeaa  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0047aeb0  8d4c2408             lea ecx, [esp + 8]
// 0047aeb4  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0047aebc  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0047aec2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0047aec6  8b08                 mov ecx, dword ptr [eax]
// 0047aec8  0fb75602             movzx edx, word ptr [esi + 2]
// 0047aecc  0fb706               movzx eax, word ptr [esi]
// 0047aecf  51                   push ecx
// 0047aed0  52                   push edx
// 0047aed1  50                   push eax
// 0047aed2  8d4c2414             lea ecx, [esp + 0x14]
// 0047aed6  68fc27a100           push 0xa127fc
// 0047aedb  51                   push ecx
// 0047aedc  c744243401000000     mov dword ptr [esp + 0x34], 1
// 0047aee4  ff15acce9e00         call dword ptr [0x9eceac]
// 0047aeea  83c414               add esp, 0x14
// 0047aeed  8d542414             lea edx, [esp + 0x14]
// 0047aef1  52                   push edx
// 0047aef2  8d442410             lea eax, [esp + 0x10]
// 0047aef6  50                   push eax
// 0047aef7  8d4c2410             lea ecx, [esp + 0x10]
// 0047aefb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0047af03  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0047af0b  ff1548c39e00         call dword ptr [0x9ec348]
// 0047af11  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047af14  50                   push eax
// 0047af15  51                   push ecx
// 0047af16  e8e3f04200           call 0x8a9ffe
// 0047af1b  85c0                 test eax, eax
// 0047af1d  740d                 je 0x47af2c
// 0047af1f  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0047af23  52                   push edx
// 0047af24  8bcf                 mov ecx, edi
// 0047af26  ff158cce9e00         call dword ptr [0x9ece8c]
// 0047af2c  8d4c2408             lea ecx, [esp + 8]
// 0047af30  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047af36  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047af3a  8bc7                 mov eax, edi
// 0047af3c  5f                   pop edi
// 0047af3d  5e                   pop esi
// 0047af3e  64890d00000000       mov dword ptr fs:[0], ecx
// 0047af45  83c41c               add esp, 0x1c
// 0047af48  c20800               ret 8
// copied from an identical function in another client (function ?query@DxUserInput@ns_ROCX000014@@QAE?AUString@2@ABU32@@Z)

namespace ns_ROCX000014 {
// from server: 100% by Espeon
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
