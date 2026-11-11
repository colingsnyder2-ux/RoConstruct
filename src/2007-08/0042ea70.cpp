// from server: 100% by EspClaude
// from server: 92% by colin
// roc 2007-08 0042ea70  unit: MyXTPCommandBars  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ea70
//
// 0042ea70  56                   push esi
// 0042ea71  6a00                 push 0
// 0042ea73  8bf1                 mov esi, ecx
// 0042ea75  68b4a77800           push 0x78a7b4
// 0042ea7a  56                   push esi
// 0042ea7b  8d8ef4000000         lea ecx, [esi + 0xf4]
// 0042ea81  e8faf32300           call 0x66de80
// 0042ea86  8b442408             mov eax, dword ptr [esp + 8]
// 0042ea8a  85c0                 test eax, eax
// 0042ea8c  7406                 je 0x42ea94
// 0042ea8e  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0042ea94  50                   push eax
// 0042ea95  8bce                 mov ecx, esi
// 0042ea97  e8ae142000           call 0x62ff4a
// 0042ea9c  f7d8                 neg eax
// 0042ea9e  1bc0                 sbb eax, eax
// 0042eaa0  f7d8                 neg eax
// 0042eaa2  5e                   pop esi
// 0042eaa3  c20400               ret 4

// target: thiscall on [esi+0xf4] with (this, &data_78a7b4, 0); thiscall on this with one arg
extern const char g_data_78a7b4[];

struct SubF4 {
    int Call(void* owner, const char* p, int z);
};

struct MyXTPCommandBars {
    char pad[0xf4];
    SubF4 field_f4;
    char pad2[0xfc - 0xf5];
    int field_fc;
    int Helper(int);
    int func(int);
};

int MyXTPCommandBars::func(int arg) {
    field_f4.Call(this, g_data_78a7b4, 0);
    int v = arg;
    if (v != 0) {
        v = field_fc;
    }
    return Helper(v) != 0;
}
