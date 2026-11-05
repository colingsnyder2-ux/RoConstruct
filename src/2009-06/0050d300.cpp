// from server: 100% by EspClaude
// from server: 80% by EspClaude
// roc 2009-06 0050d300  unit: RBX::Network::InterpolatingPhysicsReceiver::Nugget::UHistory::?$sp_counted_impl_p  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0050d300
//
// 0050d300  55                   push ebp
// 0050d301  56                   push esi
// 0050d302  57                   push edi
// 0050d303  8bf9                 mov edi, ecx
// 0050d305  85ff                 test edi, edi
// 0050d307  7405                 je 0x50d30e
// 0050d309  8d47f4               lea eax, [edi - 0xc]
// 0050d30c  eb02                 jmp 0x50d310
// 0050d30e  33c0                 xor eax, eax
// 0050d310  8b4004               mov eax, dword ptr [eax + 4]
// 0050d313  8b4024               mov eax, dword ptr [eax + 0x24]
// 0050d316  85c0                 test eax, eax
// 0050d318  7405                 je 0x50d31f
// 0050d31a  83c0e0               add eax, -0x20
// 0050d31d  eb02                 jmp 0x50d321
// 0050d31f  33c0                 xor eax, eax
// 0050d321  8b742414             mov esi, dword ptr [esp + 0x14]
// 0050d325  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0050d329  3bf0                 cmp esi, eax
// 0050d32b  7441                 je 0x50d36e
// 0050d32d  85f6                 test esi, esi
// 0050d32f  7409                 je 0x50d33a
// 0050d331  8d4e20               lea ecx, [esi + 0x20]
// 0050d334  894c2414             mov dword ptr [esp + 0x14], ecx
// 0050d338  eb08                 jmp 0x50d342
// 0050d33a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0050d342  8d542414             lea edx, [esp + 0x14]
// 0050d346  52                   push edx
// 0050d347  e814b6ffff           call 0x508960
// 0050d34c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050d350  83c404               add esp, 4
// 0050d353  85c0                 test eax, eax
// 0050d355  7405                 je 0x50d35c
// 0050d357  83c0e0               add eax, -0x20
// 0050d35a  eb02                 jmp 0x50d35e
// 0050d35c  33c0                 xor eax, eax
// 0050d35e  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0050d361  3b4808               cmp ecx, dword ptr [eax + 8]
// 0050d364  7308                 jae 0x50d36e
// 0050d366  5f                   pop edi
// 0050d367  5e                   pop esi
// 0050d368  32c0                 xor al, al
// 0050d36a  5d                   pop ebp
// 0050d36b  c20c00               ret 0xc
// 0050d36e  85f6                 test esi, esi
// 0050d370  7409                 je 0x50d37b
// 0050d372  83c620               add esi, 0x20
// 0050d375  89742414             mov dword ptr [esp + 0x14], esi
// 0050d379  eb08                 jmp 0x50d383
// 0050d37b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0050d383  8d542414             lea edx, [esp + 0x14]
// 0050d387  52                   push edx
// 0050d388  e883b9ffff           call 0x508d10
// 0050d38d  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050d391  83c404               add esp, 4
// 0050d394  85c0                 test eax, eax
// 0050d396  7405                 je 0x50d39d
// 0050d398  8d48e0               lea ecx, [eax - 0x20]
// 0050d39b  eb02                 jmp 0x50d39f
// 0050d39d  33c9                 xor ecx, ecx
// 0050d39f  85ff                 test edi, edi
// 0050d3a1  7405                 je 0x50d3a8
// 0050d3a3  8d47f4               lea eax, [edi - 0xc]
// 0050d3a6  eb02                 jmp 0x50d3aa
// 0050d3a8  33c0                 xor eax, eax
// 0050d3aa  3b4804               cmp ecx, dword ptr [eax + 4]
// 0050d3ad  7410                 je 0x50d3bf
// 0050d3af  8b4108               mov eax, dword ptr [ecx + 8]
// 0050d3b2  3b4508               cmp eax, dword ptr [ebp + 8]
// 0050d3b5  7308                 jae 0x50d3bf
// 0050d3b7  5f                   pop edi
// 0050d3b8  5e                   pop esi
// 0050d3b9  33c0                 xor eax, eax
// 0050d3bb  5d                   pop ebp
// 0050d3bc  c20c00               ret 0xc
// 0050d3bf  5f                   pop edi
// 0050d3c0  5e                   pop esi
// 0050d3c1  b801000000           mov eax, 1
// 0050d3c6  5d                   pop ebp
// 0050d3c7  c20c00               ret 0xc

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
    char padding[0x20 - 12];
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
