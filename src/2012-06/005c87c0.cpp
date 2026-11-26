// from server: 100% by Xemicl
// roc 2012-06 005c87c0  unit: RBX::AdornRbxGfx  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c87c0
//
// 005c87c0  6aff                 push -1
// 005c87c2  6889c9ac00           push 0xacc989
// 005c87c7  64a100000000         mov eax, dword ptr fs:[0]
// 005c87cd  50                   push eax
// 005c87ce  64892500000000       mov dword ptr fs:[0], esp
// 005c87d5  83ec48               sub esp, 0x48
// 005c87d8  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 005c87dc  6a01                 push 1
// 005c87de  6a02                 push 2
// 005c87e0  8d442408             lea eax, [esp + 8]
// 005c87e4  50                   push eax
// 005c87e5  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005c87ed  e88eeff9ff           call 0x567780
// 005c87f2  84c0                 test al, al
// 005c87f4  7534                 jne 0x5c882a
// 005c87f6  68c008b800           push 0xb808c0
// 005c87fb  8d4c2408             lea ecx, [esp + 8]
// 005c87ff  ff154826b200         call dword ptr [0xb22648]
// 005c8805  8d4c2404             lea ecx, [esp + 4]
// 005c8809  51                   push ecx
// 005c880a  8d4c2424             lea ecx, [esp + 0x24]
// 005c880e  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005c8816  e88538e4ff           call 0x40c0a0
// 005c881b  686c80cd00           push 0xcd806c
// 005c8820  8d542424             lea edx, [esp + 0x24]
// 005c8824  52                   push edx
// 005c8825  e81aa93b00           call 0x983144
// 005c882a  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 005c882e  0fb70424             movzx eax, word ptr [esp]
// 005c8832  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8839  83c454               add esp, 0x54
// 005c883c  c3                   ret 
// copied from an identical function in another client (function ?readCompressionType@Compressor@RBX@@SAHAAVBitStream@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <string>
class BitStream { public: bool ReadBits(unsigned char* output, unsigned int numberOfBitsToRead, bool alignBitsToRight = true); };
namespace RBX {
class Compressor {
public:
	static int readCompressionType(BitStream& stream);
};
int Compressor::readCompressionType(BitStream& stream)
{
	unsigned int compressionType = 0;
	if (!stream.ReadBits((unsigned char*)&compressionType, 2, true))
		throw std::runtime_error("Compressor::readTranslation failed reading compressionType");
	return (unsigned short)compressionType;
}
}