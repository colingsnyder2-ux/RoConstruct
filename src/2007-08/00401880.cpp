// from server: 100% by colin
// roc 2007-08 00401880  unit: CAboutRobloxDialog  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401880
//
// 00401880  8b442410             mov eax, dword ptr [esp + 0x10]
// 00401884  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401888  8b542408             mov edx, dword ptr [esp + 8]
// 0040188c  50                   push eax
// 0040188d  8b442408             mov eax, dword ptr [esp + 8]
// 00401891  51                   push ecx
// 00401892  52                   push edx
// 00401893  50                   push eax
// 00401894  ff15d4e67700         call dword ptr [0x77e6d4]
// 0040189a  50                   push eax
// 0040189b  e840feffff           call 0x4016e0
// 004018a0  83c414               add esp, 0x14
// 004018a3  c3                   ret 

extern "C" void* (__cdecl *memcpy_s_import)(void*, unsigned int, const void*, unsigned int);
extern "C" void* __cdecl sub_4016E0(void*);

void* __cdecl sub_401880(void* dst, unsigned int size, const void* src, unsigned int count)
{
    void* p = memcpy_s_import(dst, size, src, count);
    return sub_4016E0(p);
}
