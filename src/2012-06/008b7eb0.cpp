// from server: 100% by Xemicl
// roc 2012-06 008b7eb0  unit: seg_008b0000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b7eb0
//
// 008b7eb0  6aff                 push -1
// 008b7eb2  686948ad00           push 0xad4869
// 008b7eb7  64a100000000         mov eax, dword ptr fs:[0]
// 008b7ebd  50                   push eax
// 008b7ebe  64892500000000       mov dword ptr fs:[0], esp
// 008b7ec5  83ec0c               sub esp, 0xc
// 008b7ec8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008b7ecc  56                   push esi
// 008b7ecd  8bf1                 mov esi, ecx
// 008b7ecf  50                   push eax
// 008b7ed0  89742408             mov dword ptr [esp + 8], esi
// 008b7ed4  ff154826b200         call dword ptr [0xb22648]
// 008b7eda  8d4c2408             lea ecx, [esp + 8]
// 008b7ede  51                   push ecx
// 008b7edf  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 008b7ee7  e804d80b00           call 0x9756f0
// 008b7eec  dd00                 fld qword ptr [eax]
// 008b7eee  dc053042be00         fadd qword ptr [0xbe4230]
// 008b7ef4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b7ef8  83c404               add esp, 4
// 008b7efb  8bc6                 mov eax, esi
// 008b7efd  dd5e20               fstp qword ptr [esi + 0x20]
// 008b7f00  5e                   pop esi
// 008b7f01  64890d00000000       mov dword ptr fs:[0], ecx
// 008b7f08  83c418               add esp, 0x18
// 008b7f0b  c20400               ret 4
// copied from an identical function in another client (function ??0Item2009@RBX@@QAE@PBD@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class Time {
public:
    double sec;
    Time() : sec(0) {}
    explicit Time(double s) : sec(s) {}
    static Time now();
    Time operator+(double d) const { return Time(sec + d); }
};
class Item2009 {
public:
	std::string name;
	Time expire;
	Item2009(const char* n);
};
Item2009::Item2009(const char* n) : name(n), expire(Time::now() + 300.0) {}
}