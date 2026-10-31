// from server: 80% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004c71d0  unit: RBX::VInstance::?$Association::Item  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c71d0
//
// 004c71d0  55                   push ebp
// 004c71d1  56                   push esi
// 004c71d2  57                   push edi
// 004c71d3  8bf9                 mov edi, ecx
// 004c71d5  85ff                 test edi, edi
// 004c71d7  7405                 je 0x4c71de
// 004c71d9  8d47f4               lea eax, [edi - 0xc]
// 004c71dc  eb02                 jmp 0x4c71e0
// 004c71de  33c0                 xor eax, eax
// 004c71e0  8b4004               mov eax, dword ptr [eax + 4]
// 004c71e3  8b8084020000         mov eax, dword ptr [eax + 0x284]
// 004c71e9  85c0                 test eax, eax
// 004c71eb  7407                 je 0x4c71f4
// 004c71ed  0580fdffff           add eax, 0xfffffd80
// 004c71f2  eb02                 jmp 0x4c71f6
// 004c71f4  33c0                 xor eax, eax
// 004c71f6  8b742414             mov esi, dword ptr [esp + 0x14]
// 004c71fa  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004c71fe  3bf0                 cmp esi, eax
// 004c7200  7446                 je 0x4c7248
// 004c7202  85f6                 test esi, esi
// 004c7204  740c                 je 0x4c7212
// 004c7206  8d8e80020000         lea ecx, [esi + 0x280]
// 004c720c  894c2414             mov dword ptr [esp + 0x14], ecx
// 004c7210  eb08                 jmp 0x4c721a
// 004c7212  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004c721a  8d542414             lea edx, [esp + 0x14]
// 004c721e  52                   push edx
// 004c721f  e8ecf4ffff           call 0x4c6710
// 004c7224  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c7228  83c404               add esp, 4
// 004c722b  85c0                 test eax, eax
// 004c722d  7407                 je 0x4c7236
// 004c722f  0580fdffff           add eax, 0xfffffd80
// 004c7234  eb02                 jmp 0x4c7238
// 004c7236  33c0                 xor eax, eax
// 004c7238  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004c723b  3b4808               cmp ecx, dword ptr [eax + 8]
// 004c723e  7308                 jae 0x4c7248
// 004c7240  5f                   pop edi
// 004c7241  5e                   pop esi
// 004c7242  32c0                 xor al, al
// 004c7244  5d                   pop ebp
// 004c7245  c20c00               ret 0xc
// 004c7248  85f6                 test esi, esi
// 004c724a  740c                 je 0x4c7258
// 004c724c  81c680020000         add esi, 0x280
// 004c7252  89742414             mov dword ptr [esp + 0x14], esi
// 004c7256  eb08                 jmp 0x4c7260
// 004c7258  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004c7260  8d542414             lea edx, [esp + 0x14]
// 004c7264  52                   push edx
// 004c7265  e856f4ffff           call 0x4c66c0
// 004c726a  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c726e  83c404               add esp, 4
// 004c7271  85c0                 test eax, eax
// 004c7273  7408                 je 0x4c727d
// 004c7275  8d8880fdffff         lea ecx, [eax - 0x280]
// 004c727b  eb02                 jmp 0x4c727f
// 004c727d  33c9                 xor ecx, ecx
// 004c727f  85ff                 test edi, edi
// 004c7281  7405                 je 0x4c7288
// 004c7283  8d47f4               lea eax, [edi - 0xc]
// 004c7286  eb02                 jmp 0x4c728a
// 004c7288  33c0                 xor eax, eax
// 004c728a  3b4804               cmp ecx, dword ptr [eax + 4]
// 004c728d  7410                 je 0x4c729f
// 004c728f  8b4108               mov eax, dword ptr [ecx + 8]
// 004c7292  3b4508               cmp eax, dword ptr [ebp + 8]
// 004c7295  7308                 jae 0x4c729f
// 004c7297  5f                   pop edi
// 004c7298  5e                   pop esi
// 004c7299  33c0                 xor eax, eax
// 004c729b  5d                   pop ebp
// 004c729c  c20c00               ret 0xc
// 004c729f  5f                   pop edi
// 004c72a0  5e                   pop esi
// 004c72a1  b801000000           mov eax, 1
// 004c72a6  5d                   pop ebp
// 004c72a7  c20c00               ret 0xc

struct Object;

struct Link {
    unsigned long reserved;
    Link* parent;
};

struct Header {
    unsigned long reserved0;
    unsigned long reserved1;
    unsigned long order;
    char padding[0x280 - 12];
};

struct Object : Header, Link {
};

struct Prefix {
    unsigned long reserved0;
    Object* object;
    unsigned long reserved1;
};

struct Item {
    bool f(Object* first, Object* second, unsigned long unused);
};

struct Owner : Prefix, Item {
};

extern void __cdecl previous(Link**);
extern void __cdecl next(Link**);

bool Item::f(Object* first, Object* second, unsigned long unused)
{
    Object* parent =
        static_cast<Object*>(static_cast<Owner*>(this)->object->parent);
    Link* link;

    if (second != parent) {
        link = static_cast<Link*>(second);
        previous(&link);
        if (first->order < static_cast<Object*>(link)->order)
            return false;
    }

    link = static_cast<Link*>(second);
    next(&link);
    Object* object = static_cast<Object*>(link);

    return object == static_cast<Owner*>(this)->object ||
        object->order >= first->order;
}
