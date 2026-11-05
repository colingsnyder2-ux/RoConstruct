// from server: 100% by colin
// roc 2007-08 0044a6a0  unit: CRobloxModule  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a6a0
//
// 0044a6a0  83ec10               sub esp, 0x10
// 0044a6a3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044a6a7  8b1544ae8b00         mov edx, dword ptr [0x8bae44]
// 0044a6ad  33c0                 xor eax, eax
// 0044a6af  89442408             mov dword ptr [esp + 8], eax
// 0044a6b3  8944240c             mov dword ptr [esp + 0xc], eax
// 0044a6b7  8d0424               lea eax, [esp]
// 0044a6ba  50                   push eax
// 0044a6bb  51                   push ecx
// 0044a6bc  6a67                 push 0x67
// 0044a6be  52                   push edx
// 0044a6bf  c74424104c067900     mov dword ptr [esp + 0x10], 0x79064c
// 0044a6c7  c744241438037900     mov dword ptr [esp + 0x14], 0x790338
// 0044a6cf  e8bcc8fbff           call 0x406f90
// 0044a6d4  83c410               add esp, 0x10
// 0044a6d7  c20400               ret 4

struct CRobloxModule {
    void sub_44A6A0(int);
};

extern "C" int __stdcall sub_406F90(int, int, int, int);

int g_8BAE44;

void CRobloxModule::sub_44A6A0(int a1)
{
    int local[4];
    local[0] = 0x79064C;
    local[1] = 0x790338;
    local[2] = 0;
    local[3] = 0;
    sub_406F90(g_8BAE44, 0x67, a1, (int)local);
}
