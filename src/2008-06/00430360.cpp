// from server: 100% by tester
// roc 2008-06 00430360  unit: CWrapperView  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430360
//
// 00430360  56                   push esi
// 00430361  8bf1                 mov esi, ecx
// 00430363  e800092700           call 0x6a0c68
// 00430368  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 0043036f  7420                 je 0x430391
// 00430371  80befa00000000       cmp byte ptr [esi + 0xfa], 0
// 00430378  7517                 jne 0x430391
// 0043037a  837c240800           cmp dword ptr [esp + 8], 0
// 0043037f  7510                 jne 0x430391
// 00430381  8bce                 mov ecx, esi
// 00430383  e8d8fdffff           call 0x430160
// 00430388  6a07                 push 7
// 0043038a  8bce                 mov ecx, esi
// 0043038c  e8dd052700           call 0x6a096e
// 00430391  5e                   pop esi
// 00430392  c20800               ret 8

struct CWrapperView {
    char pad[0xf8];
    char field_f8;
    char pad2;
    char field_fa;
    void sub_6a0c68();
    void sub_430160();
    void sub_6a096e(int);
    void func_430360(int, int);
};

void CWrapperView::func_430360(int a, int b)
{
    sub_6a0c68();
    if (field_f8 != 0 && field_fa == 0 && a == 0) {
        sub_430160();
        sub_6a096e(7);
    }
}
