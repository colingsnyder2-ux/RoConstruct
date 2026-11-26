// from server: 100% by Xemicl
// roc 2012-06 006b8ab0  unit: RBX::MD5HasherImpl  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006b8ab0
//
// 006b8ab0  81ec00040000         sub esp, 0x400
// 006b8ab6  56                   push esi
// 006b8ab7  8bb42408040000       mov esi, dword ptr [esp + 0x408]
// 006b8abe  8b06                 mov eax, dword ptr [esi]
// 006b8ac0  57                   push edi
// 006b8ac1  8bf9                 mov edi, ecx
// 006b8ac3  8b4804               mov ecx, dword ptr [eax + 4]
// 006b8ac6  6a00                 push 0
// 006b8ac8  6a00                 push 0
// 006b8aca  03ce                 add ecx, esi
// 006b8acc  ff154825b200         call dword ptr [0xb22548]
// 006b8ad2  6a00                 push 0
// 006b8ad4  6a00                 push 0
// 006b8ad6  8bce                 mov ecx, esi
// 006b8ad8  ff15cc26b200         call dword ptr [0xb226cc]
// 006b8ade  8bff                 mov edi, edi
// 006b8ae0  6800040000           push 0x400
// 006b8ae5  8d4c240c             lea ecx, [esp + 0xc]
// 006b8ae9  51                   push ecx
// 006b8aea  8bce                 mov ecx, esi
// 006b8aec  ff157425b200         call dword ptr [0xb22574]
// 006b8af2  8b4604               mov eax, dword ptr [esi + 4]
// 006b8af5  8b17                 mov edx, dword ptr [edi]
// 006b8af7  8b5204               mov edx, dword ptr [edx + 4]
// 006b8afa  50                   push eax
// 006b8afb  8d4c240c             lea ecx, [esp + 0xc]
// 006b8aff  51                   push ecx
// 006b8b00  8bcf                 mov ecx, edi
// 006b8b02  ffd2                 call edx
// 006b8b04  837e0400             cmp dword ptr [esi + 4], 0
// 006b8b08  7fd6                 jg 0x6b8ae0
// 006b8b0a  5f                   pop edi
// 006b8b0b  5e                   pop esi
// 006b8b0c  81c400040000         add esp, 0x400
// 006b8b12  c20400               ret 4
// copied from an identical function in another client (function ?addData@MD5Hasher@RBX@@QAEXAAV?$basic_istream@DU?$char_traits@D@std@@@std@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <istream>
namespace RBX {
class MD5Hasher {
public:
	virtual ~MD5Hasher() {}
	virtual void addData(const char* data, int len) = 0;
	void addData(std::istream& stream);
};
void MD5Hasher::addData(std::istream& stream)
{
	char buffer[1024];
	stream.clear();
	stream.seekg(0, std::ios::beg);
	do
	{
		stream.read(buffer, 1024);
		addData(buffer, stream.gcount());
	} while (stream.gcount() > 0);
}
}