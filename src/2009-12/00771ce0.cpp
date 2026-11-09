// from server: 100% by nuck16
// roc 2009-12 00771ce0  unit: RBX::VGuiObject::?$NonFactoryProduct  size: 99 bytes
//
// 00771ce0  64a100000000         mov eax, dword ptr fs:[0]
// 00771ce6  6aff                 push -1
// 00771ce8  684e2c9500           push 0x952c4e
// 00771ced  50                   push eax
// 00771cee  b801000000           mov eax, 1
// 00771cf3  64892500000000       mov dword ptr fs:[0], esp
// 00771cfa  84055482b900         test byte ptr [0xb98254], al
// 00771d00  752e                 jne 0x771d30
// 00771d02  09055482b900         or dword ptr [0xb98254], eax
// 00771d08  68c8fdb500           push 0xb5fdc8
// 00771d0d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00771d15  e8c605ecff           call 0x6322e0
// 00771d1a  83c404               add esp, 4
// 00771d1d  a35082b900           mov dword ptr [0xb98250], eax
// 00771d22  8b0c24               mov ecx, dword ptr [esp]
// 00771d25  64890d00000000       mov dword ptr fs:[0], ecx
// 00771d2c  83c40c               add esp, 0xc
// 00771d2f  c3                   ret 
// 00771d30  8b0c24               mov ecx, dword ptr [esp]
// 00771d33  a15082b900           mov eax, dword ptr [0xb98250]
// 00771d38  64890d00000000       mov dword ptr fs:[0], ecx
// 00771d3f  83c40c               add esp, 0xc
// 00771d42  c3                   ret 

extern char string_00b5fdc8[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b5fdc8);
    return *name;
}
