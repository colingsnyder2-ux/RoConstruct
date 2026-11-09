// from server: 100% by king_originala
struct Base {
    unsigned words[7];
    Base(int);
    ~Base();
};

struct Parent : Base {
    void* descriptor;
    unsigned slots[42];
    Parent(int);
};

struct Member {
    unsigned storage[7];
    Member();
};

struct S : Parent {
    unsigned padding[27];
    unsigned count;
    Member member;
    unsigned a154;
    unsigned a158;
    unsigned a15c;
    unsigned a160;
    unsigned char a164;
    unsigned char a165;
    unsigned char pad166[6];
    unsigned a16c;
    unsigned a170;
    unsigned char a174;
    unsigned char pad175[3];
    unsigned char a178;
    unsigned char pad179[7];
    unsigned a180;
    unsigned a184;
    unsigned char a188;
    unsigned char pad189[3];
    unsigned char a18c;
    unsigned char pad18d[7];
    unsigned a194;
    unsigned a198;
    unsigned char a19c;
    unsigned char pad19d[3];
    unsigned char a1a0;

    unsigned initialize();
    S();
};

__forceinline unsigned S::initialize() {
    unsigned* p = reinterpret_cast<unsigned*>(this);
    p[0] = 0x8318bc;
    p[4] = 0x8318b0;
    p[5] = 0x8318a8;
    p[8] = 0x8318a0;
    p[9] = 0x831890;
    p[17] = 0x831880;
    p[25] = 0x831870;
    p[33] = 0x831860;
    p[41] = 0x831850;
    p[49] = 0x831840;
    return 0;
}

S::S() : Parent(0x948df8), count(initialize()) {
    a154 = 0;
    a158 = 0;
    a15c = 0;
    a160 = 0;
    a164 = 0;
    a165 = 0;
    a16c = 0;
    a170 = 0;
    a174 = 0;
    a178 = 0;
    a180 = 0;
    a184 = 0;
    a188 = 0;
    a18c = 0;
    a194 = 0;
    a198 = 0;
    a19c = 0;
    a1a0 = 0;
}
