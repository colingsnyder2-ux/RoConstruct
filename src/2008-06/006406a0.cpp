// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 006406a0  unit: RBX::AxisMoveTool  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006406a0
//
// 006406a0  56                   push esi
// 006406a1  8bf1                 mov esi, ecx
// 006406a3  807e4000             cmp byte ptr [esi + 0x40], 0
// 006406a7  7439                 je 0x6406e2
// 006406a9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006406ac  e8cfe0fcff           call 0x60e780
// 006406b1  c7462000000000       mov dword ptr [esi + 0x20], 0
// 006406b8  8b06                 mov eax, dword ptr [esi]
// 006406ba  8b10                 mov edx, dword ptr [eax]
// 006406bc  8bce                 mov ecx, esi
// 006406be  c6464000             mov byte ptr [esi + 0x40], 0
// 006406c2  ffd2                 call edx
// 006406c4  83c004               add eax, 4
// 006406c7  83781810             cmp dword ptr [eax + 0x18], 0x10
// 006406cb  7205                 jb 0x6406d2
// 006406cd  8b4004               mov eax, dword ptr [eax + 4]
// 006406d0  eb03                 jmp 0x6406d5
// 006406d2  83c004               add eax, 4
// 006406d5  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006406d8  51                   push ecx
// 006406d9  50                   push eax
// 006406da  e8e1bef4ff           call 0x58c5c0
// 006406df  83c408               add esp, 8
// 006406e2  8b16                 mov edx, dword ptr [esi]
// 006406e4  8b4228               mov eax, dword ptr [edx + 0x28]
// 006406e7  8bce                 mov ecx, esi
// 006406e9  ffd0                 call eax
// 006406eb  33c0                 xor eax, eax
// 006406ed  5e                   pop esi
// 006406ee  c20400               ret 4
#include <intrin.h>

namespace RBX {
    void handle(int a, int b);
}

struct Resource {
    void release();
};

struct Text {
    int allocator;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Description {
    int prefix;
    Text text;
};

struct S {
    virtual Description* description();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void update();

    char padding04[20];
    int context;
    int padding1c;
    Resource* resource;
    char padding24[28];
    bool active;

    int f(int);
};

int S::f(int)
{
    if (active) {
        resource->release();
        resource = 0;
        _ReadWriteBarrier();
        active = false;

        Text& text = description()->text;
        char* data = text.capacity >= 16
            ? text.storage.heap
            : text.storage.local;
        RBX::handle(reinterpret_cast<int>(data), context);
    }

    update();
    return 0;
}
