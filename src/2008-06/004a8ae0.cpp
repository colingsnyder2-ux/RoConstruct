// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 004a8ae0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a8ae0
//
// 004a8ae0  83ec08               sub esp, 8
// 004a8ae3  56                   push esi
// 004a8ae4  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a8ae8  57                   push edi
// 004a8ae9  8bf9                 mov edi, ecx
// 004a8aeb  85f6                 test esi, esi
// 004a8aed  7441                 je 0x4a8b30
// 004a8aef  8bce                 mov ecx, esi
// 004a8af1  e8aa30ffff           call 0x49bba0
// 004a8af6  8b4608               mov eax, dword ptr [esi + 8]
// 004a8af9  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a8afc  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a8b00  89442408             mov dword ptr [esp + 8], eax
// 004a8b04  83c004               add eax, 4
// 004a8b07  50                   push eax
// 004a8b08  894c2410             mov dword ptr [esp + 0x10], ecx
// 004a8b0c  56                   push esi
// 004a8b0d  8d8f30010000         lea ecx, [edi + 0x130]
// 004a8b13  e808f3ffff           call 0x4a7e20
// 004a8b18  6a01                 push 1
// 004a8b1a  6a18                 push 0x18
// 004a8b1c  8d542414             lea edx, [esp + 0x14]
// 004a8b20  52                   push edx
// 004a8b21  8bce                 mov ecx, esi
// 004a8b23  e8d8caffff           call 0x4a5600
// 004a8b28  5f                   pop edi
// 004a8b29  5e                   pop esi
// 004a8b2a  83c408               add esp, 8
// 004a8b2d  c20800               ret 8
// 004a8b30  e83bb70a00           call 0x554270
// 004a8b35  83c004               add eax, 4
// 004a8b38  50                   push eax
// 004a8b39  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a8b3d  50                   push eax
// 004a8b3e  8d8f30010000         lea ecx, [edi + 0x130]
// 004a8b44  e8d7f2ffff           call 0x4a7e20
// 004a8b49  5f                   pop edi
// 004a8b4a  5e                   pop esi
// 004a8b4b  83c408               add esp, 8
// 004a8b4e  c20800               ret 8

struct Mutex {
    void lock();
    void unlock();
};

struct Key {
    unsigned int first;
    unsigned int second;
};

struct Stream {
    void writeBits(const void*, int, bool);
};

struct Target {
    unsigned char pad[0x130];
    void methodA(Stream*, const void*);
};

struct Creator {
    void invoke(Stream*, Key*);
};

extern "C" unsigned int* __cdecl sub_554270();

void Creator::invoke(Stream* stream, Key* key)
{
    if (key) {
        ((Mutex*)key)->lock();
        Key local;
        local.first = *(unsigned int*)((char*)key + 8);
        local.second = *(unsigned int*)((char*)key + 0xc);
        // Add dummy to adjust stack layout
        int dummy = 0;
        ((Target*)((char*)this + 0x130))->methodA(stream, (char*)local.first + 4);
        stream->writeBits(&local.second, 0x18, true);
    } else {
        unsigned int* p = sub_554270();
        ((Target*)((char*)this + 0x130))->methodA(stream, (char*)p + 4);
    }
}