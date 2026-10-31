// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640150  unit: RBX::CloneTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640150
//
// 00640150  56                   push esi
// 00640151  8bf1                 mov esi, ecx
// 00640153  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00640157  80b9f001000000       cmp byte ptr [ecx + 0x1f0], 0
// 0064015e  7522                 jne 0x640182
// 00640160  e8cb93f5ff           call 0x599530
// 00640165  84c0                 test al, al
// 00640167  7519                 jne 0x640182
// 00640169  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0064016d  50                   push eax
// 0064016e  8bce                 mov ecx, esi
// 00640170  e80b57fdff           call 0x615880
// 00640175  84c0                 test al, al
// 00640177  7409                 je 0x640182
// 00640179  b801000000           mov eax, 1
// 0064017e  5e                   pop esi
// 0064017f  c20800               ret 8
// 00640182  33c0                 xor eax, eax
// 00640184  5e                   pop esi
// 00640185  c20800               ret 8

struct Object {
    char padding[0x1f0];
    unsigned char flag;
    bool isRestricted();
};

struct Tool {
    bool accepts(void* value);
    int check(Object* object, void* value);
};

int Tool::check(Object* object, void* value)
{
    if (!object->flag && !object->isRestricted() && accepts(value))
        return 1;
    return 0;
}
