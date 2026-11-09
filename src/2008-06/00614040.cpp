// from server: 100% by EspClaude
// from server: 94% by king_originala
// roc 2008-06 00614040  unit: RBX::RevoluteLink  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00614040
//
// 00614040  83791400             cmp dword ptr [ecx + 0x14], 0
// 00614044  7566                 jne 0x6140ac
// 00614046  8b442404             mov eax, dword ptr [esp + 4]
// 0061404a  d900                 fld dword ptr [eax]
// 0061404c  d999c4000000         fstp dword ptr [ecx + 0xc4]
// 00614052  d94004               fld dword ptr [eax + 4]
// 00614055  d999c8000000         fstp dword ptr [ecx + 0xc8]
// 0061405b  d94008               fld dword ptr [eax + 8]
// 0061405e  d999cc000000         fstp dword ptr [ecx + 0xcc]
// 00614064  d9400c               fld dword ptr [eax + 0xc]
// 00614067  d999d0000000         fstp dword ptr [ecx + 0xd0]
// 0061406d  d94010               fld dword ptr [eax + 0x10]
// 00614070  d999d4000000         fstp dword ptr [ecx + 0xd4]
// 00614076  d94014               fld dword ptr [eax + 0x14]
// 00614079  a198a89500           mov eax, dword ptr [0x95a898]
// 0061407e  40                   inc eax
// 0061407f  d999d8000000         fstp dword ptr [ecx + 0xd8]
// 00614085  a398a89500           mov dword ptr [0x95a898], eax
// 0061408a  3dffffff7f           cmp eax, 0x7fffffff
// 0061408f  750a                 jne 0x61409b
// 00614091  b801000000           mov eax, 1
// 00614096  a398a89500           mov dword ptr [0x95a898], eax
// 0061409b  898190000000         mov dword ptr [ecx + 0x90], eax
// 006140a1  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 006140a4  85c9                 test ecx, ecx
// 006140a6  7404                 je 0x6140ac
// 006140a8  c6410801             mov byte ptr [ecx + 8], 1
// 006140ac  c20400               ret 4

static int counter;

struct DirtyState {
    char padding[8];
    unsigned char dirty;
};

struct RevoluteLink {
    char padding0[0x14];
    int state;
    char padding1[0x14];
    DirtyState* owner;
    char padding2[0x60];
    int serial;
    char padding3[0x30];
    float values[6];

    void set(const float* source);
};

void RevoluteLink::set(const float* source)
{
    if (state == 0) {
        values[0] = source[0];
        values[1] = source[1];
        values[2] = source[2];
        values[3] = source[3];
        values[4] = source[4];
        values[5] = source[5];

        ++counter;
        if (counter == 0x7fffffff)
            counter = 1;
        serial = counter;

        if (owner)
            owner->dirty = 1;
    }
}
