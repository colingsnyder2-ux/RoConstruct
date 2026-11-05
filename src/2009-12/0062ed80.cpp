// from server: 100% by nuck16
// roc 2009-12 0062ed80  unit: RBX::DataModelArbiter::W4ConcurrencyModel::?$EnumDesc  size: 103 bytes
//
// 0062ed80  64a100000000         mov eax, dword ptr fs:[0]
// 0062ed86  6aff                 push -1
// 0062ed88  68cefc9300           push 0x93fcce
// 0062ed8d  50                   push eax
// 0062ed8e  b801000000           mov eax, 1
// 0062ed93  64892500000000       mov dword ptr fs:[0], esp
// 0062ed9a  84051842b800         test byte ptr [0xb84218], al
// 0062eda0  7532                 jne 0x62edd4
// 0062eda2  09051842b800         or dword ptr [0xb84218], eax
// 0062eda8  6a00                 push 0
// 0062edaa  68c8ac9c00           push 0x9cacc8
// 0062edaf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062edb7  e8f4b5ddff           call 0x40a3b0
// 0062edbc  50                   push eax
// 0062edbd  b92041b800           mov ecx, 0xb84120
// 0062edc2  e839520300           call 0x664000
// 0062edc7  6850169800           push 0x981650
// 0062edcc  e8585b1c00           call 0x7f4929
// 0062edd1  83c404               add esp, 4
// 0062edd4  8b0c24               mov ecx, dword ptr [esp]
// 0062edd7  b82041b800           mov eax, 0xb84120
// 0062eddc  64890d00000000       mov dword ptr fs:[0], ecx
// 0062ede3  83c40c               add esp, 0xc
// 0062ede6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "TaskScheduler", 0);
    return object;
}
