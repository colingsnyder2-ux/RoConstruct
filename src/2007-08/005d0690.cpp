// from server: 82% by EspClaude
// from server: 53% by colin
// roc 2007-08 005d0690  unit: RBX::LocalBackpackItem  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d0690
//
// 005d0690  56                   push esi
// 005d0691  8bf1                 mov esi, ecx
// 005d0693  e89815f7ff           call 0x541c30
// 005d0698  83be4801000000       cmp dword ptr [esi + 0x148], 0
// 005d069f  747e                 je 0x5d071f
// 005d06a1  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 005d06a7  85c0                 test eax, eax
// 005d06a9  8d8e20010000         lea ecx, [esi + 0x120]
// 005d06af  7409                 je 0x5d06ba
// 005d06b1  51                   push ecx
// 005d06b2  8d4814               lea ecx, [eax + 0x14]
// 005d06b5  e8761ee6ff           call 0x432530
// 005d06ba  8b8648010000         mov eax, dword ptr [esi + 0x148]
// 005d06c0  85c0                 test eax, eax
// 005d06c2  8d8e24010000         lea ecx, [esi + 0x124]
// 005d06c8  7409                 je 0x5d06d3
// 005d06ca  51                   push ecx
// 005d06cb  8d482c               lea ecx, [eax + 0x2c]
// 005d06ce  e85d1ee6ff           call 0x432530
// 005d06d3  c7864801000000000000 mov dword ptr [esi + 0x148], 0
// 005d06dd  57                   push edi
// 005d06de  8bbe4c010000         mov edi, dword ptr [esi + 0x14c]
// 005d06e4  85ff                 test edi, edi
// 005d06e6  c7864c01000000000000 mov dword ptr [esi + 0x14c], 0
// 005d06f0  742c                 je 0x5d071e
// 005d06f2  8d4704               lea eax, [edi + 4]
// 005d06f5  83c9ff               or ecx, 0xffffffff
// 005d06f8  f00fc108             lock xadd dword ptr [eax], ecx
// 005d06fc  7520                 jne 0x5d071e
// 005d06fe  8b17                 mov edx, dword ptr [edi]
// 005d0700  8b4204               mov eax, dword ptr [edx + 4]
// 005d0703  8bcf                 mov ecx, edi
// 005d0705  ffd0                 call eax
// 005d0707  8d4f08               lea ecx, [edi + 8]
// 005d070a  83caff               or edx, 0xffffffff
// 005d070d  f00fc111             lock xadd dword ptr [ecx], edx
// 005d0711  750b                 jne 0x5d071e
// 005d0713  8b07                 mov eax, dword ptr [edi]
// 005d0715  8b5008               mov edx, dword ptr [eax + 8]
// 005d0718  8bcf                 mov ecx, edi
// 005d071a  5f                   pop edi
// 005d071b  5e                   pop esi
// 005d071c  ffe2                 jmp edx
// 005d071e  5f                   pop edi
// 005d071f  5e                   pop esi
// 005d0720  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// boost-style sp_counted_base: vtable slot +4 dispose, +8 destroy; counts at +4/+8
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct Signal {
    void remove(void* c);   // 0x432530, thiscall
};

struct Item {
    char pad[0x14];
    Signal sig14;           // +0x14
    char pad2[0x2c - 0x15];
    Signal sig2c;           // +0x2c
};

struct Base {
    void sub_541c30();
};

struct LocalBackpackItem : Base {
    char pad[0x120];
    int field120;
    int field124;
    char pad128[0x148 - 0x128];
    Item* px;                  // +0x148
    sp_counted_base* pn;       // +0x14c
    void func_005d0690();
};

void LocalBackpackItem::func_005d0690()
{
    sub_541c30();
    if (px != 0) {
        if (px) px->sig14.remove(&field120);
        if (px) px->sig2c.remove(&field124);
        px = 0;
        sp_counted_base* r = pn;
        pn = 0;
        if (r != 0)
            r->release();
    }
}
