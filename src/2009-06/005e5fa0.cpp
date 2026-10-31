// from server: 87% by EspClaude
// from server: 100% by tester
// roc 2008-06 0056d020  unit: G3D::VColor3::?$holder  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056d020
//
// 0056d020  64a100000000         mov eax, dword ptr fs:[0]
// 0056d026  6aff                 push -1
// 0056d028  687efe7c00           push 0x7cfe7e
// 0056d02d  50                   push eax
// 0056d02e  b801000000           mov eax, 1
// 0056d033  64892500000000       mov dword ptr fs:[0], esp
// 0056d03a  84056c4c9700         test byte ptr [0x974c6c], al
// 0056d040  752f                 jne 0x56d071
// 0056d042  09056c4c9700         or dword ptr [0x974c6c], eax
// 0056d048  6840639400           push 0x946340
// 0056d04d  68e8f68200           push 0x82f6e8
// 0056d052  b95c4c9700           mov ecx, 0x974c5c
// 0056d057  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0056d05f  e82cedffff           call 0x56bd90
// 0056d064  68e0d27f00           push 0x7fd2e0
// 0056d069  e841471300           call 0x6a17af
// 0056d06e  83c404               add esp, 4
// 0056d071  8b0c24               mov ecx, dword ptr [esp]
// 0056d074  b85c4c9700           mov eax, 0x974c5c
// 0056d079  64890d00000000       mov dword ptr fs:[0], ecx
// 0056d080  83c40c               add esp, 0xc
// 0056d083  c3                   ret 

struct Type
{
    unsigned char data[16];
    Type(const char*, const void*);
    ~Type();
};

const Type& singleton()
{
    static Type instance(
        reinterpret_cast<const char*>(0x0082F6C8),
        reinterpret_cast<const void*>(0x00931034));
    return instance;
}
