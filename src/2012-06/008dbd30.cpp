// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 007b4650  unit: RBX::FormFactorPart  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b4650
//
// 007b4650  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 007b4656  c7013487bb00         mov dword ptr [ecx], 0xbb8734
// 007b465c  c741042c87bb00       mov dword ptr [ecx + 4], 0xbb872c
// 007b4663  c741182087bb00       mov dword ptr [ecx + 0x18], 0xbb8720
// 007b466a  c7411c1487bb00       mov dword ptr [ecx + 0x1c], 0xbb8714
// 007b4671  c781800000000c87bb00 mov dword ptr [ecx + 0x80], 0xbb870c
// 007b467b  c78190000000f486bb00 mov dword ptr [ecx + 0x90], 0xbb86f4
// 007b4685  c7819c000000c886bb00 mov dword ptr [ecx + 0x9c], 0xbb86c8
// 007b468f  c781b40000009c86bb00 mov dword ptr [ecx + 0xb4], 0xbb869c
// 007b4699  c781c80000009486bb00 mov dword ptr [ecx + 0xc8], 0xbb8694
// 007b46a3  8b5004               mov edx, dword ptr [eax + 4]
// 007b46a6  c7840a840000008c86bb00 mov dword ptr [edx + ecx + 0x84], 0xbb868c
// 007b46b1  8b8184000000         mov eax, dword ptr [ecx + 0x84]
// 007b46b7  8b4004               mov eax, dword ptr [eax + 4]
// 007b46ba  8d90b8fdffff         lea edx, [eax - 0x248]
// 007b46c0  89940880000000       mov dword ptr [eax + ecx + 0x80], edx
// 007b46c7  e9d4feffff           jmp 0x7b45a0

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
    *(int*)((char*)this + w + 0x80) = w - 0x260;
    extern void tail();
    tail();
}
