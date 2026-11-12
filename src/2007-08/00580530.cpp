// from server: 100% by EspClaude
// from server: 56% by colin
// roc 2007-08 00580530  unit: RBX::Log  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00580530
//
// 00580530  83ec24               sub esp, 0x24
// 00580533  8b1564e57700         mov edx, dword ptr [0x77e564]
// 00580539  dd02                 fld qword ptr [edx]
// 0058053b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0058053f  dc19                 fcomp qword ptr [ecx]
// 00580541  56                   push esi
// 00580542  c744240400000000     mov dword ptr [esp + 4], 0
// 0058054a  dfe0                 fnstsw ax
// 0058054c  f6c444               test ah, 0x44
// 0058054f  7a18                 jp 0x580569
// 00580551  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00580555  6814c07a00           push 0x7ac014
// 0058055a  8bce                 mov ecx, esi
// 0058055c  ff1598e67700         call dword ptr [0x77e698]
// 00580562  8bc6                 mov eax, esi
// 00580564  5e                   pop esi
// 00580565  83c424               add esp, 0x24
// 00580568  c3                   ret 
// 00580569  dd02                 fld qword ptr [edx]
// 0058056b  d9e0                 fchs 
// 0058056d  dc19                 fcomp qword ptr [ecx]
// 0058056f  dfe0                 fnstsw ax
// 00580571  f6c444               test ah, 0x44
// 00580574  7a18                 jp 0x58058e
// 00580576  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0058057a  680cc07a00           push 0x7ac00c
// 0058057f  8bce                 mov ecx, esi
// 00580581  ff1598e67700         call dword ptr [0x77e698]
// 00580587  8bc6                 mov eax, esi
// 00580589  5e                   pop esi
// 0058058a  83c424               add esp, 0x24
// 0058058d  c3                   ret 
// 0058058e  a144e57700           mov eax, dword ptr [0x77e544]
// 00580593  dd00                 fld qword ptr [eax]
// 00580595  dc19                 fcomp qword ptr [ecx]
// 00580597  dfe0                 fnstsw ax
// 00580599  f6c444               test ah, 0x44
// 0058059c  7a18                 jp 0x5805b6
// 0058059e  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 005805a2  6808c07a00           push 0x7ac008
// 005805a7  8bce                 mov ecx, esi
// 005805a9  ff1598e67700         call dword ptr [0x77e698]
// 005805af  8bc6                 mov eax, esi
// 005805b1  5e                   pop esi
// 005805b2  83c424               add esp, 0x24
// 005805b5  c3                   ret 
// 005805b6  8b15a8e47700         mov edx, dword ptr [0x77e4a8]
// 005805bc  dd02                 fld qword ptr [edx]
// 005805be  dc19                 fcomp qword ptr [ecx]
// 005805c0  dfe0                 fnstsw ax
// 005805c2  f6c444               test ah, 0x44
// 005805c5  7bd7                 jnp 0x58059e
// 005805c7  dd01                 fld qword ptr [ecx]
// 005805c9  83ec08               sub esp, 8
// 005805cc  dd1c24               fstp qword ptr [esp]
// 005805cf  6800c07a00           push 0x7ac000
// 005805d4  8d442414             lea eax, [esp + 0x14]
// 005805d8  6a20                 push 0x20
// 005805da  50                   push eax
// 005805db  ff155ce87700         call dword ptr [0x77e85c]
// 005805e1  8b742440             mov esi, dword ptr [esp + 0x40]
// 005805e5  83c414               add esp, 0x14
// 005805e8  8d4c2408             lea ecx, [esp + 8]
// 005805ec  51                   push ecx
// 005805ed  8bce                 mov ecx, esi
// 005805ef  ff1598e67700         call dword ptr [0x77e698]
// 005805f5  8bc6                 mov eax, esi
// 005805f7  5e                   pop esi
// roc-flags: /O2 /GS- /EHsc /MD

#include <string>
#include <ymath.h>
#include <stdio.h>

namespace RBX {
struct Log {
    static std::string formatTime(const double& time);
};

std::string Log::formatTime(const double& time)
{
    if (time == _Inf._Double)
        return std::string("INF");
    if (time == -_Inf._Double)
        return std::string("-INF");
    if (time == _Nan._Double)
        return std::string("NAN");
    if (time == _Snan._Double)
        return std::string("NAN");
    char buf[32];
    _snprintf(buf, 32, "%.9g", time);
    return std::string(buf);
}
}
