// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 0046b0d0  unit: RBX::LDraw2Lua::LuaObjectWriter  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046b0d0
//
// 0046b0d0  6aff                 push -1
// 0046b0d2  68143e7400           push 0x743e14
// 0046b0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0046b0dd  50                   push eax
// 0046b0de  83ec24               sub esp, 0x24
// 0046b0e1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046b0e6  33c4                 xor eax, esp
// 0046b0e8  89442420             mov dword ptr [esp + 0x20], eax
// 0046b0ec  56                   push esi
// 0046b0ed  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046b0f2  33c4                 xor eax, esp
// 0046b0f4  50                   push eax
// 0046b0f5  8d44242c             lea eax, [esp + 0x2c]
// 0046b0f9  64a300000000         mov dword ptr fs:[0], eax
// 0046b0ff  8bf1                 mov esi, ecx
// 0046b101  89742408             mov dword ptr [esp + 8], esi
// 0046b105  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0046b109  8d4e70               lea ecx, [esi + 0x70]
// 0046b10c  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0046b114  c706b4617900         mov dword ptr [esi], 0x7961b4
// 0046b11a  894604               mov dword ptr [esi + 4], eax
// 0046b11d  ff15a4e67700         call dword ptr [0x77e6a4]
// 0046b123  d9ee                 fldz 
// 0046b125  dd5610               fst qword ptr [esi + 0x10]
// 0046b128  6854597800           push 0x785954
// 0046b12d  dd5618               fst qword ptr [esi + 0x18]
// 0046b130  8d4c2410             lea ecx, [esp + 0x10]
// 0046b134  dd5620               fst qword ptr [esi + 0x20]
// 0046b137  c644243801           mov byte ptr [esp + 0x38], 1
// 0046b13c  dd5628               fst qword ptr [esi + 0x28]
// 0046b13f  c7460800000000       mov dword ptr [esi + 8], 0
// 0046b146  dd5630               fst qword ptr [esi + 0x30]
// 0046b149  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0046b150  dd5638               fst qword ptr [esi + 0x38]
// 0046b153  dd5640               fst qword ptr [esi + 0x40]
// 0046b156  dd5648               fst qword ptr [esi + 0x48]
// 0046b159  dd5650               fst qword ptr [esi + 0x50]
// 0046b15c  dd5658               fst qword ptr [esi + 0x58]
// 0046b15f  dd5660               fst qword ptr [esi + 0x60]
// 0046b162  dd5e68               fstp qword ptr [esi + 0x68]
// 0046b165  ff1598e67700         call dword ptr [0x77e698]
// 0046b16b  8d4c240c             lea ecx, [esp + 0xc]
// 0046b16f  ff15ace67700         call dword ptr [0x77e6ac]
// 0046b175  8bc6                 mov eax, esi
// 0046b177  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0046b17b  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b182  59                   pop ecx
// 0046b183  5e                   pop esi
// 0046b184  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0046b188  33cc                 xor ecx, esp
// 0046b18a  e88f581c00           call 0x630a1e
// 0046b18f  83c430               add esp, 0x30
// 0046b192  c20400               ret 4

#include <string>

namespace RBX { namespace LDraw2Lua {
class ObjectWriter {
public:
    virtual ~ObjectWriter();
};
class LuaObjectWriter : public ObjectWriter {
public:
    LuaObjectWriter(int stream);
    virtual ~LuaObjectWriter();
private:
    int stream;          // +4
    int field8;          // +8
    int fieldC;          // +c
    double d10, d18, d20, d28, d30, d38, d40, d48, d50, d58, d60, d68;
    std::string text;    // +70 (std::string default ctor import)
};

LuaObjectWriter::LuaObjectWriter(int s)
    : stream(s)
{
    d10 = 0.0; d18 = 0.0; d20 = 0.0; d28 = 0.0; d30 = 0.0; d38 = 0.0;
    d40 = 0.0; d48 = 0.0; d50 = 0.0; d58 = 0.0; d60 = 0.0; d68 = 0.0;
    field8 = 0;
    fieldC = 0;
    std::string empty("");
}
}}
