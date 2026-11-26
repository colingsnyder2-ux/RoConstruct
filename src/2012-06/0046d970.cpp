// from server: 100% by Xemicl
// roc 2012-06 0046d970  unit: CRobloxApp  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d970
//
// 0046d970  56                   push esi
// 0046d971  8b742408             mov esi, dword ptr [esp + 8]
// 0046d975  68000e0000           push 0xe00
// 0046d97a  6800080000           push 0x800
// 0046d97f  8bce                 mov ecx, esi
// 0046d981  ff15a825b200         call dword ptr [0xb225a8]
// 0046d987  8bc6                 mov eax, esi
// 0046d989  5e                   pop esi
// 0046d98a  c3                   ret 
// copied from an identical function in another client (function ?myhex@@YAAAVios_base@std@@AAV12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { class ios_base { public: __declspec(dllimport) int setf(int, int); }; }
std::ios_base& myhex(std::ios_base& s) { s.setf(0x800, 0xe00); return s; }