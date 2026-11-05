// from server: 100% by king_originala
struct S {
    unsigned long words[77];
    int* table;

    void f();
    void cleanup();
};

void S::f()
{
    int* p = table;
    words[0] = 0x830c2c;
    words[4] = 0x830c1c;
    words[5] = 0x830c14;
    words[8] = 0x830c0c;
    words[9] = 0x830bfc;
    words[17] = 0x830bec;
    words[25] = 0x830bdc;
    words[33] = 0x830bcc;
    words[41] = 0x830bbc;
    words[49] = 0x830bac;
    words[76] = 0x830ba0;
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + p[1] + 0x134) = 0x830b94;
    p = table;
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + p[2] + 0x134) = 0x830b8c;
    cleanup();
}
