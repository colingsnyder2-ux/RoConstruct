// from server: 100% by colin
// roc 2007-03 004c4ad0  unit: seg_004c0000  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c4ad0
//
// 004c4ad0  8b542404             mov edx, dword ptr [esp + 4]
// 004c4ad4  56                   push esi
// 004c4ad5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c4ad9  8d4210               lea eax, [edx + 0x10]
// 004c4adc  8d4e10               lea ecx, [esi + 0x10]
// 004c4adf  3bc1                 cmp eax, ecx
// 004c4ae1  7306                 jae 0x4c4ae9
// 004c4ae3  b001                 mov al, 1
// 004c4ae5  5e                   pop esi
// 004c4ae6  c20800               ret 8
// 004c4ae9  7606                 jbe 0x4c4af1
// 004c4aeb  32c0                 xor al, al
// 004c4aed  5e                   pop esi
// 004c4aee  c20800               ret 8
// 004c4af1  8b420c               mov eax, dword ptr [edx + 0xc]
// 004c4af4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c4af7  3bc1                 cmp eax, ecx
// 004c4af9  7ce8                 jl 0x4c4ae3
// 004c4afb  7fee                 jg 0x4c4aeb
// 004c4afd  3bd6                 cmp edx, esi
// 004c4aff  0f92c0               setb al
// 004c4b02  5e                   pop esi
// 004c4b03  c20800               ret 8
// copied from an identical function in another client (function ?compare@S@@QBEEPBUItem@@0@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item {
    char padding[12];
    int value;
    char key;
};

struct S {
    unsigned char compare(const Item* a, const Item* b) const;
};

unsigned char S::compare(const Item* a, const Item* b) const {
    if (&a->key < &b->key)
        return 1;
    if (&a->key > &b->key)
        return 0;
    if (a->value < b->value)
        return 1;
    if (a->value > b->value)
        return 0;
    return static_cast<unsigned char>(a < b);
}