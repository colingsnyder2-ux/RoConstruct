// from server: 42% by atomic.potato
struct Node {
    char pad0[4];
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    char pad1C[8];
    unsigned char field24;
    char pad25[0x14];
    unsigned short field3A;
};

struct Inner {
    char pad0[0x24];
    Node** begin;
    Node** end;
};

struct Outer {
    char pad0[0x24];
    Inner inner;
};

struct Self {
    char pad0[0x78];
    int count78;
    char pad7C[4];
    int field80;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" Node* __fastcall sub_483630(Self* self, int, int, int);

extern "C" Node* __fastcall sub_6DC240(Self* self, int, int, int*);

extern "C" Node* __fastcall sub_6DD070(Self* self, int, int, int*);

Node* __fastcall find_visible(Self* self, int, int* pos, int arg)
{
    int hash;
    int idx;
    int shift;
    int mask;
    int i;
    int found;
    Node* node;
    Outer* outer;
    Inner* inner;
    Node** slot;
    int x, y, z;
    unsigned char bit;
    int bitpos;
    int tmp;

    hash = pos[2] * 0x4f9ffb7;
    hash ^= pos[1] * 0x127409f;
    hash ^= pos[0] * 0x466f45d;

    shift = *(int*)((char*)self + 0x240);
    mask = 0xffff >> shift;
    hash &= mask;

    self->count78++;

    node = sub_483630(self, shift, hash, (int)pos);
    node->field14 = arg;
    node->field8 = pos[0];
    node->fieldC = pos[1];
    node->field10 = pos[2];

    outer = (Outer*)((char*)self + shift * 24);
    inner = &outer->inner;

    if ((unsigned)hash >= (unsigned)((inner->end - inner->begin) >> 3))
        _invalid_parameter_noinfo();

    node->field18 = (int)inner->begin[hash];

    if ((unsigned)hash >= (unsigned)((inner->end - inner->begin) >> 3))
        _invalid_parameter_noinfo();

    inner->begin[hash] = node;

    x = pos[0];
    y = pos[1];
    z = pos[2];

    found = -1;
    i = shift;
    bit = 1;
    tmp = -1 - shift;

    while (i < 4) {
        if (i > shift) {
            x >>= 1;
            y >>= 1;
            z >>= 1;
            hash = (z * 0x4f9ffb7) ^ (x * 0x466f45d) ^ (y * 0x127409f);
            mask = 0xffff >> i;
            hash &= mask;
            if ((unsigned)hash >= (unsigned)((inner->end - inner->begin) >> 3))
                _invalid_parameter_noinfo();
            if (bit) {
                node = sub_6DC240(self, i, hash, &x);
                if (!node)
                    node = sub_6DD070(self, i, hash, &x);
                bitpos = ((z >> (tmp + i)) & 1) + (((y >> (tmp + i)) & 1) << 1) + (((x >> (tmp + i)) & 1) << 2);
                if (node->field24 & (1 << bitpos)) {
                    i++;
                    bit = 0;
                    found = hash;
                    outer = (Outer*)((char*)outer + 0x18);
                    continue;
                }
                node->field24 |= (1 << bitpos);
                *(unsigned short*)((char*)node + bitpos * 2 + 0x14) = (unsigned short)found;
            }
        }
        i++;
        found = hash;
        outer = (Outer*)((char*)outer + 0x18);
    }

    if (self->field80 < 1)
        self->field80 = found;

    return node;
}
