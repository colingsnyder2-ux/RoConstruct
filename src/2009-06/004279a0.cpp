// from server: 100% by EspClaude
// roc 2009-06 004279a0  unit: CWrapperView  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004279a0
//
// 004279a0  8b442408             mov eax, dword ptr [esp + 8]
// 004279a4  83ec10               sub esp, 0x10
// 004279a7  53                   push ebx
// 004279a8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004279ac  55                   push ebp
// 004279ad  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 004279b1  56                   push esi
// 004279b2  57                   push edi
// 004279b3  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004279b7  55                   push ebp
// 004279b8  57                   push edi
// 004279b9  50                   push eax
// 004279ba  53                   push ebx
// 004279bb  8bf1                 mov esi, ecx
// 004279bd  e8f0112f00           call 0x718bb2
// 004279c2  33d2                 xor edx, edx
// 004279c4  3bc2                 cmp eax, edx
// 004279c6  7409                 je 0x4279d1
// 004279c8  395500               cmp dword ptr [ebp], edx
// 004279cb  0f858f000000         jne 0x427a60
// 004279d1  8bcb                 mov ecx, ebx
// 004279d3  83e901               sub ecx, 1
// 004279d6  7433                 je 0x427a0b
// 004279d8  83e904               sub ecx, 4
// 004279db  0f8584000000         jne 0x427a65
// 004279e1  395678               cmp dword ptr [esi + 0x78], edx
// 004279e4  747a                 je 0x427a60
// 004279e6  6a01                 push 1
// 004279e8  8bcf                 mov ecx, edi
// 004279ea  c1e910               shr ecx, 0x10
// 004279ed  51                   push ecx
// 004279ee  0fb7c7               movzx eax, di
// 004279f1  50                   push eax
// 004279f2  52                   push edx
// 004279f3  52                   push edx
// 004279f4  8d4e58               lea ecx, [esi + 0x58]
// 004279f7  e80e142f00           call 0x718e0a
// 004279fc  5f                   pop edi
// 004279fd  5e                   pop esi
// 004279fe  5d                   pop ebp
// 004279ff  b801000000           mov eax, 1
// 00427a04  5b                   pop ebx
// 00427a05  83c410               add esp, 0x10
// 00427a08  c21000               ret 0x10
// 00427a0b  52                   push edx
// 00427a0c  56                   push esi
// 00427a0d  8d4c2418             lea ecx, [esp + 0x18]
// 00427a11  51                   push ecx
// 00427a12  b864000000           mov eax, 0x64
// 00427a17  8d7e58               lea edi, [esi + 0x58]
// 00427a1a  6800000056           push 0x56000000
// 00427a1f  8bcf                 mov ecx, edi
// 00427a21  89542420             mov dword ptr [esp + 0x20], edx
// 00427a25  89542424             mov dword ptr [esp + 0x24], edx
// 00427a29  89442428             mov dword ptr [esp + 0x28], eax
// 00427a2d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00427a31  e8ec192f00           call 0x719422
// 00427a36  85c0                 test eax, eax
// 00427a38  7516                 jne 0x427a50
// 00427a3a  5f                   pop edi
// 00427a3b  5e                   pop esi
// 00427a3c  c74500ffffffff       mov dword ptr [ebp], 0xffffffff
// 00427a43  5d                   pop ebp
// 00427a44  b801000000           mov eax, 1
// 00427a49  5b                   pop ebx
// 00427a4a  83c410               add esp, 0x10
// 00427a4d  c21000               ret 0x10
// 00427a50  6a20                 push 0x20
// 00427a52  6800020000           push 0x200
// 00427a57  6a00                 push 0
// 00427a59  8bcf                 mov ecx, edi
// 00427a5b  e878152f00           call 0x718fd8
// 00427a60  b801000000           mov eax, 1
// 00427a65  5f                   pop edi
// 00427a66  5e                   pop esi
// 00427a67  5d                   pop ebp
// 00427a68  5b                   pop ebx
// 00427a69  83c410               add esp, 0x10
// 00427a6c  c21000               ret 0x10
// copied from an identical function in another client (function ?func_42ec10@CWrapperView@ns_ROCX0000e8@@QAEHIIIPAH@Z)

namespace ns_ROCX0000e8 {
struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct Child {
    char pad[0x20];
    int handle;

    void sub_6a0a4c(int, int, int, int, int);
    int sub_6a0fb0(unsigned int, const Rect *, void *, unsigned int);
    void sub_6a0c38(unsigned int, unsigned int, unsigned int);
};

struct CWrapperView {
    char pad[0x58];
    Child child;

    int sub_6a0800(unsigned int, unsigned int, unsigned int, int *);
    int func_42ec10(unsigned int, unsigned int, unsigned int, int *);
};

int CWrapperView::func_42ec10(unsigned int message, unsigned int wparam,
                            unsigned int lparam, int *result)
{
    int handled = sub_6a0800(message, wparam, lparam, result);
    if (handled && *result)
        return 1;

    switch (message) {
    case 1:
        {
            Rect rect = { 0, 0, 100, 100 };
            if (!child.sub_6a0fb0(0x56000000, &rect, this, 0)) {
                *result = -1;
                return 1;
            }
            child.sub_6a0c38(0, 0x200, 0x20);
        }
        return 1;

    case 5:
        if (child.handle)
            child.sub_6a0a4c(0, 0, (unsigned short)lparam, lparam >> 16, 1);
        return 1;
    }
    return handled;
}
}
