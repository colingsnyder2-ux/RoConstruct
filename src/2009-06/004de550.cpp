// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a7570  unit: RBX::VHint::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7570
//
// 004a7570  83ec0c               sub esp, 0xc
// 004a7573  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a7577  8d442408             lea eax, [esp + 8]
// 004a757b  50                   push eax
// 004a757c  e8dffeffff           call 0x4a7460
// 004a7581  8b08                 mov ecx, dword ptr [eax]
// 004a7583  890c24               mov dword ptr [esp], ecx
// 004a7586  8d0c24               lea ecx, [esp]
// 004a7589  e802e71000           call 0x5b5c90
// 004a758e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004a7592  6a01                 push 1
// 004a7594  6a05                 push 5
// 004a7596  8d54240c             lea edx, [esp + 0xc]
// 004a759a  52                   push edx
// 004a759b  89442410             mov dword ptr [esp + 0x10], eax
// 004a759f  e85ce0ffff           call 0x4a5600
// 004a75a4  83c40c               add esp, 0xc
// 004a75a7  c3                   ret 

struct Color
{
    unsigned int value;
    unsigned int getClosestPaletteIndex() const;
};

struct Source
{
    Color* getColor(Color* result) const;
};

struct Writer
{
    void write(const unsigned int* value, int bits, int count);
};

void func_004a7570(Source* source, Writer* writer)
{
    Color temporary;
    Color color = *source->getColor(&temporary);
    unsigned int index = color.getClosestPaletteIndex();
    writer->write(&index, 5, 1);
}
