// from server: 100% by nuck16
// roc 2009-12 0051a420  unit: RBX::Network::Players::W4ChatOption::?$EnumDesc  size: 103 bytes
//
// 0051a420  64a100000000         mov eax, dword ptr fs:[0]
// 0051a426  6aff                 push -1
// 0051a428  68ee7e9300           push 0x937eee
// 0051a42d  50                   push eax
// 0051a42e  b801000000           mov eax, 1
// 0051a433  64892500000000       mov dword ptr fs:[0], esp
// 0051a43a  840560eab700         test byte ptr [0xb7ea60], al
// 0051a440  7532                 jne 0x51a474
// 0051a442  090560eab700         or dword ptr [0xb7ea60], eax
// 0051a448  6a00                 push 0
// 0051a44a  68b87fb100           push 0xb17fb8
// 0051a44f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051a457  e854ffeeff           call 0x40a3b0
// 0051a45c  50                   push eax
// 0051a45d  b968e9b700           mov ecx, 0xb7e968
// 0051a462  e8999b1400           call 0x664000
// 0051a467  6880fb9700           push 0x97fb80
// 0051a46c  e8b8a42d00           call 0x7f4929
// 0051a471  83c404               add esp, 4
// 0051a474  8b0c24               mov ecx, dword ptr [esp]
// 0051a477  b868e9b700           mov eax, 0xb7e968
// 0051a47c  64890d00000000       mov dword ptr fs:[0], ecx
// 0051a483  83c40c               add esp, 0xc
// 0051a486  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b17fb8[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b17fb8, 0);
    return object;
}
