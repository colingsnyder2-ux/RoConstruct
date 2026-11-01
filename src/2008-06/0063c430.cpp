// from server: 100% by king_originala
struct S {
    unsigned int words[77];
    int* offsets;
    unsigned int rest[38];

    void f();
    void finish();
};

void S::f()
{
    int* table = offsets;
    words[0] = 0x849c8c;
    words[4] = 0x849c7c;
    words[5] = 0x849c74;
    words[8] = 0x849c6c;
    words[9] = 0x849c5c;
    words[17] = 0x849c4c;
    words[25] = 0x849c3c;
    words[33] = 0x849c2c;
    words[41] = 0x849c1c;
    words[49] = 0x849c0c;
    words[76] = 0x849c00;
    rest[26] = 0x849bf0;
    rest[34] = 0x849be4;
    rest[37] = 0x849bcc;

    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x134 + table[1]) = 0x849bc0;
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x134 + offsets[2]) = 0x849bb8;
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x134 + offsets[3]) = 0x849b9c;

    int displacement = offsets[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x130 + displacement) =
        displacement - 0x2b8;

    displacement = offsets[2];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x130 + displacement) =
        displacement - 0x2c0;

    displacement = offsets[3];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x130 + displacement) =
        displacement - 0x2c8;

    finish();
}
