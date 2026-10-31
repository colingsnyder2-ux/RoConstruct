// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e7850  unit: RBX::Ball  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7850
//
// 005e7850  8b442404             mov eax, dword ptr [esp + 4]
// 005e7854  8b542408             mov edx, dword ptr [esp + 8]
// 005e7858  399481b8000000       cmp dword ptr [ecx + eax*4 + 0xb8], edx
// 005e785f  7407                 je 0x5e7868
// 005e7861  899481b8000000       mov dword ptr [ecx + eax*4 + 0xb8], edx
// 005e7868  c20800               ret 8

struct Ball {
    char padding[0xB8];
    int values[1];
    void set(int index, int value);
};

void Ball::set(int index, int value) {
    if (values[index] != value)
        values[index] = value;
}
