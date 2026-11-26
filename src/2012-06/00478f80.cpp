// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 004780b0  unit: CRobloxControlColorSelector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004780b0
//
// 004780b0  8b442408             mov eax, dword ptr [esp + 8]
// 004780b4  56                   push esi
// 004780b5  8bf1                 mov esi, ecx
// 004780b7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004780bb  50                   push eax
// 004780bc  51                   push ecx
// 004780bd  8bce                 mov ecx, esi
// 004780bf  e83cfdffff           call 0x477e00
// 004780c4  83f8ff               cmp eax, -1
// 004780c7  740f                 je 0x4780d8
// 004780c9  6a01                 push 1
// 004780cb  8bce                 mov ecx, esi
// 004780cd  898674010000         mov dword ptr [esi + 0x174], eax
// 004780d3  e858cf5000           call 0x985030
// 004780d8  5e                   pop esi
// 004780d9  c20800               ret 8

struct CRobloxControlColorSelector
{
    char pad[0x17c];
    int field_168;
    int sub_44BBD0(int, int);
    void sub_63A690(int);
    void sub_44BF20(int, int);
};

void CRobloxControlColorSelector::sub_44BF20(int a, int b)
{
    int r = sub_44BBD0(a, b);
    if (r != -1)
    {
        field_168 = r;
        sub_63A690(1);
    }
}
