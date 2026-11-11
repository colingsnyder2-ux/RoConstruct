// from server: 100% by EspClaude
// from server: 93% by colin
// roc 2007-08 00461d00  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461d00
//
// 00461d00  56                   push esi
// 00461d01  57                   push edi
// 00461d02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00461d06  57                   push edi
// 00461d07  8bf1                 mov esi, ecx
// 00461d09  e852a0fbff           call 0x41bd60
// 00461d0e  83c404               add esp, 4
// 00461d11  85c0                 test eax, eax
// 00461d13  740f                 je 0x461d24
// 00461d15  8b442420             mov eax, dword ptr [esp + 0x20]
// 00461d19  5f                   pop edi
// 00461d1a  c70001000000         mov dword ptr [eax], 1
// 00461d20  5e                   pop esi
// 00461d21  c21800               ret 0x18
// 00461d24  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00461d28  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00461d2c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00461d30  51                   push ecx
// 00461d31  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00461d35  52                   push edx
// 00461d36  8b542418             mov edx, dword ptr [esp + 0x18]
// 00461d3a  50                   push eax
// 00461d3b  51                   push ecx
// 00461d3c  52                   push edx
// 00461d3d  57                   push edi
// 00461d3e  8bce                 mov ecx, esi
// 00461d40  e825e91c00           call 0x63066a
// 00461d45  5f                   pop edi
// 00461d46  5e                   pop esi
// 00461d47  c21800               ret 0x18

int __cdecl sub_41BD60(int);

struct VCSecureHtmlView_CXTPCommandBarsSiteBase {
    void sub_63066A(int, int, int, int, int, int);
    void f(int, int, int, int, int, int);
};

void VCSecureHtmlView_CXTPCommandBarsSiteBase::f(int a1, int a2, int a3, int a4, int a5, int a6) {
    if (sub_41BD60(a1)) {
        *(int*)a6 = 1;
        return;
    }
    sub_63066A(a1, a2, a3, a4, a5, a6);
}
