// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043f140  unit: ScriptItem  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043f140
//
// 0043f140  6aff                 push -1
// 0043f142  6898ed7300           push 0x73ed98
// 0043f147  64a100000000         mov eax, dword ptr fs:[0]
// 0043f14d  50                   push eax
// 0043f14e  51                   push ecx
// 0043f14f  53                   push ebx
// 0043f150  55                   push ebp
// 0043f151  56                   push esi
// 0043f152  57                   push edi
// 0043f153  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043f158  33c4                 xor eax, esp
// 0043f15a  50                   push eax
// 0043f15b  8d442418             lea eax, [esp + 0x18]
// 0043f15f  64a300000000         mov dword ptr fs:[0], eax
// 0043f165  8bf1                 mov esi, ecx
// 0043f167  89742414             mov dword ptr [esp + 0x14], esi
// 0043f16b  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043f16f  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0043f173  50                   push eax
// 0043f174  53                   push ebx
// 0043f175  e846e1ffff           call 0x43d2c0
// 0043f17a  c7062ced7800         mov dword ptr [esi], 0x78ed2c
// 0043f180  c74620ccec7800       mov dword ptr [esi + 0x20], 0x78eccc
// 0043f187  c78608010000c0ec7800 mov dword ptr [esi + 0x108], 0x78ecc0
// 0043f191  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 0043f194  8b7714               mov esi, dword ptr [edi + 0x14]
// 0043f197  83c710               add edi, 0x10
// 0043f19a  3b7708               cmp esi, dword ptr [edi + 8]
// 0043f19d  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043f1a5  7606                 jbe 0x43f1ad
// 0043f1a7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f1ad  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 0043f1b0  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0043f1b3  83c510               add ebp, 0x10
// 0043f1b6  395d04               cmp dword ptr [ebp + 4], ebx
// 0043f1b9  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0043f1bd  7606                 jbe 0x43f1c5
// 0043f1bf  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f1c5  85ff                 test edi, edi
// 0043f1c7  7404                 je 0x43f1cd
// 0043f1c9  3bfd                 cmp edi, ebp
// 0043f1cb  7406                 je 0x43f1d3
// 0043f1cd  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f1d3  3bf3                 cmp esi, ebx
// 0043f1d5  745e                 je 0x43f235
// 0043f1d7  85ff                 test edi, edi
// 0043f1d9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043f1dd  8b99bc000000         mov ebx, dword ptr [ecx + 0xbc]
// 0043f1e3  7506                 jne 0x43f1eb
// 0043f1e5  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f1eb  3b7708               cmp esi, dword ptr [edi + 8]
// 0043f1ee  7211                 jb 0x43f201
// 0043f1f0  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f1f6  3b7708               cmp esi, dword ptr [edi + 8]
// 0043f1f9  7206                 jb 0x43f201
// 0043f1fb  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f201  8b16                 mov edx, dword ptr [esi]
// 0043f203  8b4204               mov eax, dword ptr [edx + 4]
// 0043f206  8d4804               lea ecx, [eax + 4]
// 0043f209  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043f20f  8b0e                 mov ecx, dword ptr [esi]
// 0043f211  8b4908               mov ecx, dword ptr [ecx + 8]
// 0043f214  8b13                 mov edx, dword ptr [ebx]
// 0043f216  8b5258               mov edx, dword ptr [edx + 0x58]
// 0043f219  6aff                 push -1
// 0043f21b  51                   push ecx
// 0043f21c  50                   push eax
// 0043f21d  8bcb                 mov ecx, ebx
// 0043f21f  ffd2                 call edx
// 0043f221  3b7708               cmp esi, dword ptr [edi + 8]
// 0043f224  7206                 jb 0x43f22c
// 0043f226  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043f22c  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0043f230  83c604               add esi, 4
// 0043f233  eb90                 jmp 0x43f1c5
// 0043f235  8b442414             mov eax, dword ptr [esp + 0x14]
// 0043f239  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043f23d  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f244  59                   pop ecx
// 0043f245  5f                   pop edi
// 0043f246  5e                   pop esi
// 0043f247  5d                   pop ebp
// 0043f248  5b                   pop ebx
// 0043f249  83c410               add esp, 0x10
// 0043f24c  c20800               ret 8

// from server: 100% by EspClaude
// roc 2008-06 0043e3a0  unit: ScriptItem  size: 281 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043e3a0
//
// 0043e3a0  6aff                 push -1
// 0043e3a2  6818087c00           push 0x7c0818
// 0043e3a7  64a100000000         mov eax, dword ptr fs:[0]
// 0043e3ad  50                   push eax
// 0043e3ae  64892500000000       mov dword ptr fs:[0], esp
// 0043e3b5  83ec0c               sub esp, 0xc
// 0043e3b8  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043e3bc  53                   push ebx
// 0043e3bd  55                   push ebp
// 0043e3be  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0043e3c2  56                   push esi
// 0043e3c3  57                   push edi
// 0043e3c4  50                   push eax
// 0043e3c5  8bf1                 mov esi, ecx
// 0043e3c7  55                   push ebp
// 0043e3c8  89742418             mov dword ptr [esp + 0x18], esi
// 0043e3cc  e86fe0ffff           call 0x43c440
// 0043e3d1  c706244f8100         mov dword ptr [esi], 0x814f24
// 0043e3d7  c74620c44e8100       mov dword ptr [esi + 0x20], 0x814ec4
// 0043e3de  c78614010000b84e8100 mov dword ptr [esi + 0x114], 0x814eb8
// 0043e3e8  8b7518               mov esi, dword ptr [ebp + 0x18]
// 0043e3eb  8b5e1c               mov ebx, dword ptr [esi + 0x1c]
// 0043e3ee  83c610               add esi, 0x10
// 0043e3f1  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043e3f9  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0043e3fc  7606                 jbe 0x43e404
// 0043e3fe  ff1590288000         call dword ptr [0x802890]
// 0043e404  8b3e                 mov edi, dword ptr [esi]
// 0043e406  8b7518               mov esi, dword ptr [ebp + 0x18]
// 0043e409  8b4620               mov eax, dword ptr [esi + 0x20]
// 0043e40c  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0043e412  83c610               add esi, 0x10
// 0043e415  89442430             mov dword ptr [esp + 0x30], eax
// 0043e419  39460c               cmp dword ptr [esi + 0xc], eax
// 0043e41c  7602                 jbe 0x43e420
// 0043e41e  ffd5                 call ebp
// 0043e420  8b0e                 mov ecx, dword ptr [esi]
// 0043e422  894c2414             mov dword ptr [esp + 0x14], ecx
// 0043e426  85ff                 test edi, edi
// 0043e428  7406                 je 0x43e430
// 0043e42a  3b7c2414             cmp edi, dword ptr [esp + 0x14]
// 0043e42e  7402                 je 0x43e432
// 0043e430  ffd5                 call ebp
// 0043e432  3b5c2430             cmp ebx, dword ptr [esp + 0x30]
// 0043e436  7468                 je 0x43e4a0
// 0043e438  8b542410             mov edx, dword ptr [esp + 0x10]
// 0043e43c  8bb2c4000000         mov esi, dword ptr [edx + 0xc4]
// 0043e442  85ff                 test edi, edi
// 0043e444  754e                 jne 0x43e494
// 0043e446  ffd5                 call ebp
// 0043e448  33c0                 xor eax, eax
// 0043e44a  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 0043e44d  7202                 jb 0x43e451
// 0043e44f  ffd5                 call ebp
// 0043e451  85ff                 test edi, edi
// 0043e453  7543                 jne 0x43e498
// 0043e455  ffd5                 call ebp
// 0043e457  33c0                 xor eax, eax
// 0043e459  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 0043e45c  7202                 jb 0x43e460
// 0043e45e  ffd5                 call ebp
// 0043e460  8b03                 mov eax, dword ptr [ebx]
// 0043e462  8b4004               mov eax, dword ptr [eax + 4]
// 0043e465  8d4804               lea ecx, [eax + 4]
// 0043e468  ff1564248000         call dword ptr [0x802464]
// 0043e46e  8b0b                 mov ecx, dword ptr [ebx]
// 0043e470  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0043e473  8b16                 mov edx, dword ptr [esi]
// 0043e475  8b5258               mov edx, dword ptr [edx + 0x58]
// 0043e478  6aff                 push -1
// 0043e47a  51                   push ecx
// 0043e47b  50                   push eax
// 0043e47c  8bce                 mov ecx, esi
// 0043e47e  ffd2                 call edx
// 0043e480  85ff                 test edi, edi
// 0043e482  7518                 jne 0x43e49c
// 0043e484  ffd5                 call ebp
// 0043e486  33c0                 xor eax, eax
// 0043e488  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 0043e48b  7202                 jb 0x43e48f
// 0043e48d  ffd5                 call ebp
// 0043e48f  83c304               add ebx, 4
// 0043e492  eb92                 jmp 0x43e426
// 0043e494  8b07                 mov eax, dword ptr [edi]
// 0043e496  ebb2                 jmp 0x43e44a
// 0043e498  8b07                 mov eax, dword ptr [edi]
// 0043e49a  ebbd                 jmp 0x43e459
// 0043e49c  8b07                 mov eax, dword ptr [edi]
// 0043e49e  ebe8                 jmp 0x43e488
// 0043e4a0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0043e4a4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043e4a8  5f                   pop edi
// 0043e4a9  5e                   pop esi
// 0043e4aa  5d                   pop ebp
// 0043e4ab  5b                   pop ebx
// 0043e4ac  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e4b3  83c418               add esp, 0x18
// 0043e4b6  c20800               ret 8

// from server: 72% by king_originala
// roc-cl: 50727
#include <vector>
#include <string>
template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
typedef std::string Text;
struct Name {int index;const std::string text; const char* c_str() const { return static_cast<const ImpStr<char>&>(text).c_str(); }};
struct Entry {void* vptr;const Name& name;const unsigned index;};
struct EnumDescriptor {char prefix[16];std::vector<const Entry*> items;typedef std::vector<const Entry*>::const_iterator const_iterator;const_iterator begin()const{return items.begin();}const_iterator end()const{return items.end();}};
struct Descriptor {char prefix[0x18];const EnumDescriptor& enumType;};
struct Constraints {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21(); virtual void* AddConstraint(const char*,unsigned,int);};
struct Primary {virtual ~Primary();char pad[0x1c];};
struct Secondary {public: virtual ~Secondary();char before[0xbc-0x24];Constraints* constraints;public: Constraints* GetConstraints() const {return constraints;} private:char after[0x108-0xc0];};
struct Third {virtual ~Third();virtual void slot4();};
struct Base:Primary,Secondary,Third {Base(const Descriptor*,int);virtual ~Base();};
struct EnumItem:Base {EnumItem(const Descriptor*,int);virtual ~EnumItem();};
EnumItem::EnumItem(const Descriptor* desc,int id):Base(desc,id){
 EnumDescriptor::const_iterator end, iter;
 iter=desc->enumType.begin();
 end=desc->enumType.end();
 for(;iter!=end;++iter){
  GetConstraints()->AddConstraint((*iter)->name.c_str(),(*iter)->index,-1);
 }
}
