// from server: 100% by colin
// roc 2009-12 0044ae50  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044ae50
//
// 0044ae50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044ae54  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044ae58  8b542404             mov edx, dword ptr [esp + 4]
// 0044ae5c  50                   push eax
// 0044ae5d  51                   push ecx
// 0044ae5e  52                   push edx
// 0044ae5f  ff15c8b79800         call dword ptr [0x98b7c8]
// 0044ae65  50                   push eax
// 0044ae66  e8857bfbff           call 0x4029f0
// 0044ae6b  83c410               add esp, 0x10
// 0044ae6e  c3                   ret 
// copied from an identical function in another client (function ?sub_00447C00@ns_ROCX00000f@@YAHHHH@Z)

namespace ns_ROCX00000f {
extern "C" int (__cdecl *strcat_s_ptr)(char*, unsigned int, const char*);
extern "C" int __cdecl sub_4016E0(int);

int sub_00447C00(int a, int b, int c)
{
    return sub_4016E0(strcat_s_ptr((char*)a, (unsigned int)b, (const char*)c));
}
}
