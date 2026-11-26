// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00412e70  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00412e70
//
// 00412e70  6aff                 push -1
// 00412e72  682eaaa900           push 0xa9aa2e
// 00412e77  64a100000000         mov eax, dword ptr fs:[0]
// 00412e7d  50                   push eax
// 00412e7e  64892500000000       mov dword ptr fs:[0], esp
// 00412e85  51                   push ecx
// 00412e86  b801000000           mov eax, 1
// 00412e8b  84055c6fe100         test byte ptr [0xe16f5c], al
// 00412e91  7548                 jne 0x412edb
// 00412e93  09055c6fe100         or dword ptr [0xe16f5c], eax
// 00412e99  33c9                 xor ecx, ecx
// 00412e9b  51                   push ecx
// 00412e9c  83ec0c               sub esp, 0xc
// 00412e9f  8bc4                 mov eax, esp
// 00412ea1  8808                 mov byte ptr [eax], cl
// 00412ea3  884801               mov byte ptr [eax + 1], cl
// 00412ea6  894804               mov dword ptr [eax + 4], ecx
// 00412ea9  c740081b000000       mov dword ptr [eax + 8], 0x1b
// 00412eb0  a16c76b500           mov eax, dword ptr [0xb5766c]
// 00412eb5  89642410             mov dword ptr [esp + 0x10], esp
// 00412eb9  50                   push eax
// 00412eba  894c2420             mov dword ptr [esp + 0x20], ecx
// 00412ebe  e80df7ffff           call 0x4125d0
// 00412ec3  50                   push eax
// 00412ec4  b9786de100           mov ecx, 0xe16d78
// 00412ec9  e8927c2b00           call 0x6cab60
// 00412ece  68d016b100           push 0xb116d0
// 00412ed3  e81d035700           call 0x9831f5
// 00412ed8  83c404               add esp, 4
// 00412edb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00412edf  b8786de100           mov eax, 0xe16d78
// 00412ee4  64890d00000000       mov dword ptr fs:[0], ecx
// 00412eeb  83c410               add esp, 0x10
// 00412eee  c3                   ret 

// from server: 100% by tajop
// roc 2012-06 00781330  unit: RBX::W4WaterCellDirection::?$EnumDesc  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00781330
//
// 00781330  6aff                 push -1
// 00781332  689e49ac00           push 0xac499e
// 00781337  64a100000000         mov eax, dword ptr fs:[0]
// 0078133d  50                   push eax
// 0078133e  64892500000000       mov dword ptr fs:[0], esp
// 00781345  51                   push ecx
// 00781346  b801000000           mov eax, 1
// 0078134b  8405dc18e400         test byte ptr [0xe418dc], al
// 00781351  7548                 jne 0x78139b
// 00781353  0905dc18e400         or dword ptr [0xe418dc], eax
// 00781359  33c9                 xor ecx, ecx
// 0078135b  51                   push ecx
// 0078135c  83ec0c               sub esp, 0xc
// 0078135f  8bc4                 mov eax, esp
// 00781361  8808                 mov byte ptr [eax], cl
// 00781363  884801               mov byte ptr [eax + 1], cl
// 00781366  894804               mov dword ptr [eax + 4], ecx
// 00781369  c740081b000000       mov dword ptr [eax + 8], 0x1b
// 00781370  a100febe00           mov eax, dword ptr [0xbefe00]
// 00781375  89642410             mov dword ptr [esp + 0x10], esp
// 00781379  50                   push eax
// 0078137a  894c2420             mov dword ptr [esp + 0x20], ecx
// 0078137e  e8fd43f8ff           call 0x705780
// 00781383  50                   push eax
// 00781384  b9f816e400           mov ecx, 0xe416f8
// 00781389  e8d297f4ff           call 0x6cab60
// 0078138e  6860afb100           push 0xb1af60
// 00781393  e85d1e2000           call 0x9831f5
// 00781398  83c404               add esp, 4
// 0078139b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078139f  b8f816e400           mov eax, 0xe416f8
// 007813a4  64890d00000000       mov dword ptr fs:[0], ecx
// 007813ab  83c410               add esp, 0x10
// 007813ae  c3                   ret 

struct WaterDirArg
{
    char a;
    char b;
    int c;
    int d;
    WaterDirArg() : a(0), b(0), c(0), d(11) {}
    WaterDirArg(const WaterDirArg& o);
    ~WaterDirArg();
};

extern int g_waterDirName;
int __stdcall makeWaterDirDesc(int name, WaterDirArg arg, int extra);

struct W4WaterCellDirectionEnumDesc
{
    W4WaterCellDirectionEnumDesc(int x);
    ~W4WaterCellDirectionEnumDesc();
};

const W4WaterCellDirectionEnumDesc& func_00781330()
{
    static W4WaterCellDirectionEnumDesc s(makeWaterDirDesc(g_waterDirName, WaterDirArg(), 0));
    return s;
}
