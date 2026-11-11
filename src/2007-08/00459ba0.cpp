// from server: 86% by EspClaude
// from server: 83% by colin
// roc 2007-08 00459ba0  unit: CRobloxWnd  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459ba0
//
// 00459ba0  8b442404             mov eax, dword ptr [esp + 4]
// 00459ba4  83e800               sub eax, 0
// 00459ba7  56                   push esi
// 00459ba8  8bf1                 mov esi, ecx
// 00459baa  7422                 je 0x459bce
// 00459bac  83e801               sub eax, 1
// 00459baf  7529                 jne 0x459bda
// 00459bb1  837e6800             cmp dword ptr [esi + 0x68], 0
// 00459bb5  7423                 je 0x459bda
// 00459bb7  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00459bba  85c9                 test ecx, ecx
// 00459bbc  741c                 je 0x459bda
// 00459bbe  e86db10000           call 0x464d30
// 00459bc3  8bce                 mov ecx, esi
// 00459bc5  e874661d00           call 0x63023e
// 00459bca  5e                   pop esi
// 00459bcb  c20400               ret 4
// 00459bce  e82df0ffff           call 0x458c00
// 00459bd3  8bce                 mov ecx, esi
// 00459bd5  e8c6fcffff           call 0x4598a0
// 00459bda  8bce                 mov ecx, esi
// 00459bdc  e85d661d00           call 0x63023e
// 00459be1  5e                   pop esi
// 00459be2  c20400               ret 4

struct CRobloxWnd {
    char pad[0x68];
    int field_68;
    char pad2[0x74 - 0x6c];
    struct Sub74 { void method_464d30(); }* field_74;
    void method_4598a0();
    void method_458c00();
    void method_63023e();
    void method_464d30();
    void func_00459ba0(int);
};

void CRobloxWnd::func_00459ba0(int arg)
{
    switch (arg) {
    case 0:
        method_458c00();
        method_4598a0();
        break;
    case 1:
        if (field_68 != 0) {
            if (field_74 != 0) {
                field_74->method_464d30();
                method_63023e();
                return;
            }
        }
        break;
    }
    method_63023e();
}
