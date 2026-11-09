// from server: 11% by Intel
// roc 2007-08 005e9ae0  unit: RBX::VFlagStand::?$FactoryProduct  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e9ae0
//
// 005e9ae0  6aff                 push -1
// 005e9ae2  68af597500           push 0x7559af
// 005e9ae7  64a100000000         mov eax, dword ptr fs:[0]
// 005e9aed  50                   push eax
// 005e9aee  64892500000000       mov dword ptr fs:[0], esp
// 005e9af5  83ec08               sub esp, 8
// 005e9af8  33c0                 xor eax, eax
// 005e9afa  39442418             cmp dword ptr [esp + 0x18], eax
// 005e9afe  56                   push esi
// 005e9aff  8bf1                 mov esi, ecx
// 005e9b01  89742408             mov dword ptr [esp + 8], esi
// 005e9b05  89442404             mov dword ptr [esp + 4], eax
// 005e9b09  7452                 je 0x5e9b5d
// 005e9b0b  c786ec000000d0ba7a00 mov dword ptr [esi + 0xec], 0x7abad0
// 005e9b15  c78698020000e8af7a00 mov dword ptr [esi + 0x298], 0x7aafe8
// 005e9b1f  c78684020000d44c7a00 mov dword ptr [esi + 0x284], 0x7a4cd4

extern "C" {
    __declspec(dllimport) void* __stdcall _except_handler4_common();
}

struct FactoryProduct {
    void __cdecl Constructor();
};

void __cdecl FactoryProduct::Constructor()
{
    int v = -1;
    int* p = (int*)0x7559af;
    int* fs0 = (int*)0x40000000;
    int fsval = *fs0;
    int* esp = (int*)((char*)&v - 0x14);
    int local_8 = 0;
    int local_4 = 0;
    int arg_24 = local_8;
    int esi = (int)this;
    int* esp_8 = (int*)((char*)&v - 0x10);
    int* esp_4 = (int*)((char*)&v - 0x0c);
    *esp_8 = esi;
    *esp_4 = local_8;
    if (arg_24 != 0) {
        goto label_5e9b5d;
    }
    *(int*)((char)this + 0xec) = 0x7abad0;
    *(int*)((char)this + 0x298) = 0x7aafe8;
    *(int*)((char)this + 0x284) = 0x7a4cd4;
label_5e9b5d:
    return;
}
