// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 00496190  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00496190
//
// 00496190  6aff                 push -1
// 00496192  68b9837400           push 0x7483b9
// 00496197  64a100000000         mov eax, dword ptr fs:[0]
// 0049619d  50                   push eax
// 0049619e  56                   push esi
// 0049619f  a188518b00           mov eax, dword ptr [0x8b5188]
// 004961a4  33c4                 xor eax, esp
// 004961a6  50                   push eax
// 004961a7  8d442408             lea eax, [esp + 8]
// 004961ab  64a300000000         mov dword ptr fs:[0], eax
// 004961b1  8bf1                 mov esi, ecx
// 004961b3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004961b7  e854920d00           call 0x56f410
// 004961bc  83ec1c               sub esp, 0x1c
// 004961bf  8bcc                 mov ecx, esp
// 004961c1  89642440             mov dword ptr [esp + 0x40], esp
// 004961c5  50                   push eax
// 004961c6  ff159ce67700         call dword ptr [0x77e69c]
// 004961cc  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004961d0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004961d8  e883980d00           call 0x56fa60
// 004961dd  8b10                 mov edx, dword ptr [eax]
// 004961df  83ec08               sub esp, 8
// 004961e2  8bcc                 mov ecx, esp
// 004961e4  8911                 mov dword ptr [ecx], edx
// 004961e6  8b4004               mov eax, dword ptr [eax + 4]
// 004961e9  85c0                 test eax, eax
// 004961eb  89642448             mov dword ptr [esp + 0x48], esp
// 004961ef  894104               mov dword ptr [ecx + 4], eax
// 004961f2  740c                 je 0x496200
// 004961f4  83c004               add eax, 4
// 004961f7  b901000000           mov ecx, 1
// 004961fc  f00fc108             lock xadd dword ptr [eax], ecx
// 00496200  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00496203  034c243c             add ecx, dword ptr [esp + 0x3c]
// 00496207  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0049620f  8b5628               mov edx, dword ptr [esi + 0x28]
// 00496212  ffd2                 call edx
// 00496214  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00496218  64890d00000000       mov dword ptr fs:[0], ecx
// 0049621f  59                   pop ecx

#include <string>
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct sp_counted_base {
    virtual void dispose();
    virtual void destroy();
    long use_count;   // +4
    long weak_count;
    void add_ref_copy() { _InterlockedIncrement(&use_count); }
};

struct Arg;
struct ArgPtr {
    Arg* px;
    sp_counted_base* pn;
    ArgPtr(const ArgPtr& r) : px(r.px), pn(r.pn) { if (pn != 0) pn->add_ref_copy(); }
    ~ArgPtr();
};

struct Reflected { const ArgPtr& value() const; };          // 0x56fa60
struct Named { const std::string& name() const; };          // 0x56f410

class __multiple_inheritance Target;

struct BoundFuncDesc {
    char pad[0x28];
    void (Target::*func)(ArgPtr, std::string);   // +0x28 fn, +0x2c this-adjust
    void call(Target* object, int unused, const Reflected* a, const Named* b) const;
};

void BoundFuncDesc::call(Target* object, int unused, const Reflected* a, const Named* b) const
{
    (object->*func)(a->value(), b->name());
}
