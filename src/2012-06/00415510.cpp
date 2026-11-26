// from server: 100% by Xemicl
// roc 2012-06 00415510  unit: CIDEBrowserView  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415510
//
// 00415510  53                   push ebx
// 00415511  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00415515  56                   push esi
// 00415516  57                   push edi
// 00415517  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0041551b  53                   push ebx
// 0041551c  57                   push edi
// 0041551d  8bf1                 mov esi, ecx
// 0041551f  e8aacf5600           call 0x9824ce
// 00415524  83ffff               cmp edi, -1
// 00415527  742c                 je 0x415555
// 00415529  83ff01               cmp edi, 1
// 0041552c  7416                 je 0x415544
// 0041552e  83ff02               cmp edi, 2
// 00415531  7533                 jne 0x415566
// 00415533  85db                 test ebx, ebx
// 00415535  0f95c0               setne al
// 00415538  5f                   pop edi
// 00415539  8886ac020000         mov byte ptr [esi + 0x2ac], al
// 0041553f  5e                   pop esi
// 00415540  5b                   pop ebx
// 00415541  c20800               ret 8
// 00415544  85db                 test ebx, ebx
// 00415546  0f95c1               setne cl
// 00415549  5f                   pop edi
// 0041554a  888ead020000         mov byte ptr [esi + 0x2ad], cl
// 00415550  5e                   pop esi
// 00415551  5b                   pop ebx
// 00415552  c20800               ret 8
// 00415555  8b9620010000         mov edx, dword ptr [esi + 0x120]
// 0041555b  6a01                 push 1
// 0041555d  6a00                 push 0
// 0041555f  52                   push edx
// 00415560  ff15ec3bb200         call dword ptr [0xb23bec]
// 00415566  5f                   pop edi
// 00415567  5e                   pop esi
// 00415568  5b                   pop ebx
// 00415569  c20800               ret 8
// copied from an identical function in another client (function ?notify@CBrowserView@ns_ROCX00000e@@QAEXHH@Z)

namespace ns_ROCX00000e {
// from server: 100% by king_originala
// roc 2008-06 0040dfe0  unit: CBrowserView  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040dfe0
//
// 0040dfe0  53                   push ebx
// 0040dfe1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0040dfe5  56                   push esi
// 0040dfe6  57                   push edi
// 0040dfe7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040dfeb  53                   push ebx
// 0040dfec  57                   push edi
// 0040dfed  8bf1                 mov esi, ecx
// 0040dfef  e84c2a2900           call 0x6a0a40
// 0040dff4  83ffff               cmp edi, -1
// 0040dff7  742c                 je 0x40e025
// 0040dff9  83ff01               cmp edi, 1
// 0040dffc  7416                 je 0x40e014
// 0040dffe  83ff02               cmp edi, 2
// 0040e001  7533                 jne 0x40e036
// 0040e003  85db                 test ebx, ebx
// 0040e005  0f95c0               setne al
// 0040e008  5f                   pop edi
// 0040e009  8886c8020000         mov byte ptr [esi + 0x2c8], al
// 0040e00f  5e                   pop esi
// 0040e010  5b                   pop ebx
// 0040e011  c20800               ret 8
// 0040e014  85db                 test ebx, ebx
// 0040e016  0f95c1               setne cl
// 0040e019  5f                   pop edi
// 0040e01a  888ec9020000         mov byte ptr [esi + 0x2c9], cl
// 0040e020  5e                   pop esi
// 0040e021  5b                   pop ebx
// 0040e022  c20800               ret 8
// 0040e025  8b963c010000         mov edx, dword ptr [esi + 0x13c]
// 0040e02b  6a01                 push 1
// 0040e02d  6a00                 push 0
// 0040e02f  52                   push edx
// 0040e030  ff15182e8000         call dword ptr [0x802e18]
// 0040e036  5f                   pop edi
// 0040e037  5e                   pop esi
// 0040e038  5b                   pop ebx
// 0040e039  c20800               ret 8

extern "C" int (__stdcall *InvalidateRect)(void *, const void *, int);

struct CBrowserView {
    char reserved0[0x120];
    void *window;
    char reserved1[0x188];
    bool flag2;
    bool flag1;

    void baseNotify(int code, int value);
    void notify(int code, int value);
};

void CBrowserView::notify(int code, int value)
{
    baseNotify(code, value);

    switch (code) {
    case -1:
        InvalidateRect(window, 0, 1);
        break;
    case 1:
        flag1 = value != 0;
        break;
    case 2:
        flag2 = value != 0;
        break;
    }
}
}
