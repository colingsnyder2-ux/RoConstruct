// from server: 100% by Xemicl
// roc 2012-06 0050abc0  unit: Ogre::RbxArchiveFactory  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050abc0
//
// 0050abc0  6aff                 push -1
// 0050abc2  686ea1aa00           push 0xaaa16e
// 0050abc7  64a100000000         mov eax, dword ptr fs:[0]
// 0050abcd  50                   push eax
// 0050abce  64892500000000       mov dword ptr fs:[0], esp
// 0050abd5  83ec20               sub esp, 0x20
// 0050abd8  56                   push esi
// 0050abd9  8bf1                 mov esi, ecx
// 0050abdb  57                   push edi
// 0050abdc  89742408             mov dword ptr [esp + 8], esi
// 0050abe0  8b442438             mov eax, dword ptr [esp + 0x38]
// 0050abe4  8d7e08               lea edi, [esi + 8]
// 0050abe7  8bcf                 mov ecx, edi
// 0050abe9  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0050abf1  c70668bbb600         mov dword ptr [esi], 0xb6bb68
// 0050abf7  894604               mov dword ptr [esi + 4], eax
// 0050abfa  ff155426b200         call dword ptr [0xb22654]
// 0050ac00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0050ac03  51                   push ecx
// 0050ac04  8d542410             lea edx, [esp + 0x10]
// 0050ac08  52                   push edx
// 0050ac09  c644243801           mov byte ptr [esp + 0x38], 1
// 0050ac0e  e83dfcffff           call 0x50a850
// 0050ac13  83c408               add esp, 8
// 0050ac16  50                   push eax
// 0050ac17  8bcf                 mov ecx, edi
// 0050ac19  c644243402           mov byte ptr [esp + 0x34], 2
// 0050ac1e  ff155826b200         call dword ptr [0xb22658]
// 0050ac24  8d4c240c             lea ecx, [esp + 0xc]
// 0050ac28  c644243001           mov byte ptr [esp + 0x30], 1
// 0050ac2d  ff153c26b200         call dword ptr [0xb2263c]
// 0050ac33  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0050ac37  5f                   pop edi
// 0050ac38  8bc6                 mov eax, esi
// 0050ac3a  5e                   pop esi
// 0050ac3b  64890d00000000       mov dword ptr fs:[0], ecx
// 0050ac42  83c42c               add esp, 0x2c
// 0050ac45  c20400               ret 4
// copied from an identical function in another client (function ??0RbxArchiveFactory@Ogre@@QAE@PAVContentProvider@1@@Z)

// from server: 100% by EspClaude
// roc 2009-06 00498ab0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace Ogre {
class Archive;
template<class T> class FactoryObj {
public:
    virtual ~FactoryObj() {}
    virtual const std::string& getType() const = 0;
};
class ArchiveFactory : public FactoryObj<Archive> {
public:
    virtual ~ArchiveFactory() {}
};
class ContentProvider;
std::string makeArchiveType(ContentProvider* provider);
class RbxArchiveFactory : public ArchiveFactory {
public:
    RbxArchiveFactory(ContentProvider* provider);
    const std::string& getType() const;
private:
    ContentProvider* provider;
    std::string mType;
};
RbxArchiveFactory::RbxArchiveFactory(ContentProvider* provider) : provider(provider)
{
    mType = makeArchiveType(this->provider);
}
}