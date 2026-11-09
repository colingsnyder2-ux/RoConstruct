// from server: 100% by atomic.potato
struct RBX_FormFactorPart {
    void construct();
    char pad0[0x80];
    int field80;
    int field84;
    char pad88[0x8];
    int field90;
    char pad94[0x8];
    int field9c;
    char padA0[0x14];
    int fieldB4;
    char padB8[0x10];
    int fieldC8;
};

void RBX_FormFactorPart::construct() {
    int* p = *(int**)((char*)this + 0x84);
    *(int*)((char*)this + 0x00) = 0xbb8734;
    *(int*)((char*)this + 0x04) = 0xbb872c;
    *(int*)((char*)this + 0x18) = 0xbb8720;
    *(int*)((char*)this + 0x1c) = 0xbb8714;
    *(int*)((char*)this + 0x80) = 0xbb870c;
    *(int*)((char*)this + 0x90) = 0xbb86f4;
    *(int*)((char*)this + 0x9c) = 0xbb86c8;
    *(int*)((char*)this + 0xb4) = 0xbb869c;
    *(int*)((char*)this + 0xc8) = 0xbb8694;
    int v = p[1];
    *(int*)((char*)this + v + 0x84) = 0xbb868c;
    int* q = *(int**)((char*)this + 0x84);
    int w = q[1];
    *(int*)((char*)this + w + 0x80) = w - 0x248;
    extern void tail();
    tail();
}
