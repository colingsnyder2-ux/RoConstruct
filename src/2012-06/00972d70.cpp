// from server: 100% by Xemicl
// roc 2012-06 00972d70  unit: RBX::Log  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00972d70
//
// 00972d70  6aff                 push -1
// 00972d72  6892e1ac00           push 0xace192
// 00972d77  64a100000000         mov eax, dword ptr fs:[0]
// 00972d7d  50                   push eax
// 00972d7e  64892500000000       mov dword ptr fs:[0], esp
// 00972d85  83ec20               sub esp, 0x20
// 00972d88  56                   push esi
// 00972d89  8d44243c             lea eax, [esp + 0x3c]
// 00972d8d  c744240400000000     mov dword ptr [esp + 4], 0
// 00972d95  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00972d99  50                   push eax
// 00972d9a  51                   push ecx
// 00972d9b  8d542410             lea edx, [esp + 0x10]
// 00972d9f  52                   push edx
// 00972da0  e86bfeffff           call 0x972c10
// 00972da5  83c40c               add esp, 0xc
// 00972da8  8b742434             mov esi, dword ptr [esp + 0x34]
// 00972dac  8d442408             lea eax, [esp + 8]
// 00972db0  50                   push eax
// 00972db1  8bce                 mov ecx, esi
// 00972db3  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00972dbb  e8e092a9ff           call 0x40c0a0
// 00972dc0  8d4c2408             lea ecx, [esp + 8]
// 00972dc4  c744240401000000     mov dword ptr [esp + 4], 1
// 00972dcc  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00972dd1  ff153c26b200         call dword ptr [0xb2263c]
// 00972dd7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00972ddb  8bc6                 mov eax, esi
// 00972ddd  5e                   pop esi
// 00972dde  64890d00000000       mov dword ptr fs:[0], ecx
// 00972de5  83c42c               add esp, 0x2c
// 00972de8  c3                   ret 
// copied from an identical function in another client (function ?format@runtime_error@RBX@@SA?AV12@PBDZZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>
#include <stdarg.h>
namespace G3D { std::string vformat(const char* fmt, va_list argPtr); }
namespace RBX {
class runtime_error : public std::exception {
    std::string msg;
public:
    runtime_error(const std::string& m);
    virtual ~runtime_error() throw();
    static runtime_error format(const char* fmt, ...);
};
runtime_error runtime_error::format(const char* fmt, ...)
{
    va_list argList;
    va_start(argList, fmt);
    std::string s = G3D::vformat(fmt, argList);
    return runtime_error(s);
}
}