// from server: 100% by nuck16
// roc 2009-12 006d8350  unit: RBX::Stats::Item  size: 103 bytes
//
// 006d8350  64a100000000         mov eax, dword ptr fs:[0]
// 006d8356  6aff                 push -1
// 006d8358  68bea99400           push 0x94a9be
// 006d835d  50                   push eax
// 006d835e  b801000000           mov eax, 1
// 006d8363  64892500000000       mov dword ptr fs:[0], esp
// 006d836a  8405882fb900         test byte ptr [0xb92f88], al
// 006d8370  7532                 jne 0x6d83a4
// 006d8372  0905882fb900         or dword ptr [0xb92f88], eax
// 006d8378  6a00                 push 0
// 006d837a  6850919d00           push 0x9d9150
// 006d837f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d8387  e8a4c6d8ff           call 0x464a30
// 006d838c  50                   push eax
// 006d838d  b9902eb900           mov ecx, 0xb92e90
// 006d8392  e869bcf8ff           call 0x664000
// 006d8397  6810629800           push 0x986210
// 006d839c  e888c51100           call 0x7f4929
// 006d83a1  83c404               add esp, 4
// 006d83a4  8b0c24               mov ecx, dword ptr [esp]
// 006d83a7  b8902eb900           mov eax, 0xb92e90
// 006d83ac  64890d00000000       mov dword ptr fs:[0], ecx
// 006d83b3  83c40c               add esp, 0xc
// 006d83b6  c3                   ret 

struct Base;
Base &get_464a30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_464a30(), "RunningAverageItemDouble", 0);
    return object;
}
