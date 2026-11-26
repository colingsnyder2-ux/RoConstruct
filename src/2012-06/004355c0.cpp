// from server: 100% by Xemicl
// roc 2012-06 004355c0  unit: CWrapperView  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004355c0
//
// 004355c0  8b442408             mov eax, dword ptr [esp + 8]
// 004355c4  83ec10               sub esp, 0x10
// 004355c7  53                   push ebx
// 004355c8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004355cc  55                   push ebp
// 004355cd  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 004355d1  56                   push esi
// 004355d2  57                   push edi
// 004355d3  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004355d7  55                   push ebp
// 004355d8  57                   push edi
// 004355d9  50                   push eax
// 004355da  53                   push ebx
// 004355db  8bf1                 mov esi, ecx
// 004355dd  e8b2cc5400           call 0x982294
// 004355e2  33d2                 xor edx, edx
// 004355e4  3bc2                 cmp eax, edx
// 004355e6  7409                 je 0x4355f1
// 004355e8  395500               cmp dword ptr [ebp], edx
// 004355eb  0f858f000000         jne 0x435680
// 004355f1  8bcb                 mov ecx, ebx
// 004355f3  83e901               sub ecx, 1
// 004355f6  7433                 je 0x43562b
// 004355f8  83e904               sub ecx, 4
// 004355fb  0f8584000000         jne 0x435685
// 00435601  395678               cmp dword ptr [esi + 0x78], edx
// 00435604  747a                 je 0x435680
// 00435606  6a01                 push 1
// 00435608  8bcf                 mov ecx, edi
// 0043560a  c1e910               shr ecx, 0x10
// 0043560d  51                   push ecx
// 0043560e  0fb7c7               movzx eax, di
// 00435611  50                   push eax
// 00435612  52                   push edx
// 00435613  52                   push edx
// 00435614  8d4e58               lea ecx, [esi + 0x58]
// 00435617  e8bece5400           call 0x9824da
// 0043561c  5f                   pop edi
// 0043561d  5e                   pop esi
// 0043561e  5d                   pop ebp
// 0043561f  b801000000           mov eax, 1
// 00435624  5b                   pop ebx
// 00435625  83c410               add esp, 0x10
// 00435628  c21000               ret 0x10
// 0043562b  52                   push edx
// 0043562c  56                   push esi
// 0043562d  8d4c2418             lea ecx, [esp + 0x18]
// 00435631  51                   push ecx
// 00435632  b864000000           mov eax, 0x64
// 00435637  8d7e58               lea edi, [esi + 0x58]
// 0043563a  6800000056           push 0x56000000
// 0043563f  8bcf                 mov ecx, edi
// 00435641  89542420             mov dword ptr [esp + 0x20], edx
// 00435645  89542424             mov dword ptr [esp + 0x24], edx
// 00435649  89442428             mov dword ptr [esp + 0x28], eax
// 0043564d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00435651  e87ed45400           call 0x982ad4
// 00435656  85c0                 test eax, eax
// 00435658  7516                 jne 0x435670
// 0043565a  5f                   pop edi
// 0043565b  5e                   pop esi
// 0043565c  c74500ffffffff       mov dword ptr [ebp], 0xffffffff
// 00435663  5d                   pop ebp
// 00435664  b801000000           mov eax, 1
// 00435669  5b                   pop ebx
// 0043566a  83c410               add esp, 0x10
// 0043566d  c21000               ret 0x10
// 00435670  6a20                 push 0x20
// 00435672  6800020000           push 0x200
// 00435677  6a00                 push 0
// 00435679  8bcf                 mov ecx, edi
// 0043567b  e834d05400           call 0x9826b4
// 00435680  b801000000           mov eax, 1
// 00435685  5f                   pop edi
// 00435686  5e                   pop esi
// 00435687  5d                   pop ebp
// 00435688  5b                   pop ebx
// 00435689  83c410               add esp, 0x10
// 0043568c  c21000               ret 0x10
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