// from server: 100% by EspClaude
// roc 2009-06 00431460  unit: RBX::VBrickColor::?$XItem  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00431460
//
// 00431460  51                   push ecx
// 00431461  8b01                 mov eax, dword ptr [ecx]
// 00431463  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 00431469  56                   push esi
// 0043146a  ffd2                 call edx
// 0043146c  0fb6d0               movzx edx, al
// 0043146f  89542404             mov dword ptr [esp + 4], edx
// 00431473  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00431477  8bd0                 mov edx, eax
// 00431479  db442404             fild dword ptr [esp + 4]
// 0043147d  c1ea08               shr edx, 8
// 00431480  d9056c3b8b00         fld dword ptr [0x8b3b6c]
// 00431486  0fb6d2               movzx edx, dl
// 00431489  dcc9                 fmul st(1), st(0)
// 0043148b  83ec0c               sub esp, 0xc
// 0043148e  d9c9                 fxch st(1)
// 00431490  8bcc                 mov ecx, esp
// 00431492  89542410             mov dword ptr [esp + 0x10], edx
// 00431496  c1e810               shr eax, 0x10
// 00431499  d919                 fstp dword ptr [ecx]
// 0043149b  0fb6c0               movzx eax, al
// 0043149e  db442410             fild dword ptr [esp + 0x10]
// 004314a2  89442410             mov dword ptr [esp + 0x10], eax
// 004314a6  d8c9                 fmul st(1)
// 004314a8  56                   push esi
// 004314a9  d95904               fstp dword ptr [ecx + 4]
// 004314ac  da4c2414             fimul dword ptr [esp + 0x14]
// 004314b0  d95908               fstp dword ptr [ecx + 8]
// 004314b3  e8e8172100           call 0x642ca0
// 004314b8  83c410               add esp, 0x10
// 004314bb  8bc6                 mov eax, esi
// 004314bd  5e                   pop esi
// 004314be  59                   pop ecx
// 004314bf  c20400               ret 4
// copied from an identical function in another client (function ?convert@S@@QAE?AUResult@@XZ)

// from server: 62% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct S;

struct Color3uint8 {
    unsigned char r, g, b, a;
};

struct VTable {
    void* slots[58];
    Color3uint8 (__thiscall *getColor)(S*);
};


struct Color3 {
    float r, g, b;
    Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {}
    Color3(const Color3uint8& c) : r(c.r / 255.0f), g(c.g / 255.0f), b(c.b / 255.0f) {}
};

struct Result {
    float data[4];
    Result(const Result&);
};

extern Result __cdecl makeResult(Color3);

struct S {
    VTable* vtable;
    Result convert();
};

Result S::convert()
{
    return makeResult(Color3(vtable->getColor(this)));
}