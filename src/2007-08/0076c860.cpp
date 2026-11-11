// from server: 100% by EspClaude
// from server: 79% by Intel
// roc 2007-08 0076c860  unit: seg_00760000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076c860
//
// 0076c860  51                   push ecx
// 0076c861  56                   push esi
// 0076c862  57                   push edi
// 0076c863  6a01                 push 1
// 0076c865  83ec1c               sub esp, 0x1c
// 0076c868  8bcc                 mov ecx, esp
// 0076c86a  89642428             mov dword ptr [esp + 0x28], esp
// 0076c86e  682c5d7800           push 0x785d2c
// 0076c873  bef08e4100           mov esi, 0x418ef0
// 0076c878  33ff                 xor edi, edi
// 0076c87a  ff1598e67700         call dword ptr [0x77e698]
// 0076c880  6880797800           push 0x787980
// 0076c885  6874797800           push 0x787974
// 0076c88a  57                   push edi
// 0076c88b  56                   push esi
// 0076c88c  b910b08b00           mov ecx, 0x8bb010
// 0076c891  e8ead6caff           call 0x419f80
// 0076c896  6820757700           push 0x777520
// 0076c89b  e88344ecff           call 0x630d23
// 0076c8a0  83c404               add esp, 4
// 0076c8a3  5f                   pop edi
// 0076c8a4  5e                   pop esi
// 0076c8a5  59                   pop ecx
// 0076c8a6  c3                   ret 

#include <string>

struct A { int a; };
struct B { int b; };
struct C : A, B { void method(); };

struct Desc {
    Desc(void (C::*fn)(), const char* s1, const char* s2, std::string name, unsigned flags);
    ~Desc();
};

extern const char str_787974[];
extern const char str_787980[];
extern const char str_785D2C[];

Desc g_desc(&C::method, str_787974, str_787980, str_785D2C, 1);
