// from server: 100% by colin
// roc 2008-06 004ab8c0  unit: RBX::Network::Replicator::MarkerItem  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ab8c0
//
// 004ab8c0  6aff                 push -1
// 004ab8c2  68 13837c00          push 0x7c8313
// 004ab8c7  64a100000000         mov eax, dword ptr fs:[0]
// 004ab8cd  50                   push eax
// 004ab8ce  64892500000000       mov dword ptr fs:[0], esp
// 004ab8d5  51                   push ecx
// 004ab8d6  56                   push esi
// 004ab8d7  8bf1                 mov esi, ecx
// 004ab8d9  89742404             mov dword ptr [esp + 4], esi
// 004ab8dd  8d4e18               lea ecx, [esi + 0x18]
// 004ab8e0  c744241001000000     mov dword ptr [esp + 0x10], 1
// 004ab8e8  e8839a0e00           call 0x595370
// 004ab8ed  8d4e08               lea ecx, [esi + 8]
// 004ab8f0  c644241000           mov byte ptr [esp + 0x10], 0
// 004ab8f5  e8769a0e00           call 0x595370
// 004ab8fa  8b7604               mov esi, dword ptr [esi + 4]
// 004ab8fd  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004ab905  85f6                 test esi, esi
// 004ab907  742a                 je 0x4ab933
// 004ab909  8d4604               lea eax, [esi + 4]
// 004ab90c  83c9ff               or ecx, 0xffffffff
// 004ab90f  f00fc108             lock xadd dword ptr [eax], ecx
// 004ab913  751e                 jne 0x4ab933
// 004ab915  8b16                 mov edx, dword ptr [esi]
// 004ab917  8b4204               mov eax, dword ptr [edx + 4]
// 004ab91a  8bce                 mov ecx, esi
// 004ab91c  ffd0                 call eax
// 004ab91e  8d4e08               lea ecx, [esi + 8]
// 004ab921  83caff               or edx, 0xffffffff
// 004ab924  f00fc111             lock xadd dword ptr [ecx], edx
// 004ab928  7509                 jne 0x4ab933
// 004ab92a  8b06                 mov eax, dword ptr [esi]
// 004ab92c  8b5008               mov edx, dword ptr [eax + 8]
// 004ab92f  8bce                 mov ecx, esi
// 004ab931  ffd2                 call edx
// 004ab933  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004ab937  5e                   pop esi
// 004ab938  64890d00000000       mov dword ptr fs:[0], ecx
// 004ab93f  83c410               add esp, 0x10
// 004ab942  c3                   ret
//
// Target-proven layout (44-byte value, node value at node+0x10, node _Color at node+0x3c
// per src/2008-06/004aed00.cpp; dtor reads pn at +4 and destroys members at +8/+0x18):
//   +0x00 Slot base: shared_ptr<Connection> cnction (px +0, pn +4) released last (state -1)
//   +0x08 Connection (16 bytes, out-of-line dtor -> call 0x595370)
//   +0x18 Connection
//   +0x28 int marker (plain, no destruction)
// Member destruction order is reverse declaration: +0x18 then +8, then the base dtor's
// shared_ptr release, matching states 1, 0, -1. Sibling 004ab850 is the same class with
// this adjusted by the +4 base offset (members at +0xc/+0x1c there).

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void Connection_disconnect();

// shared control block: virtual dispose/destroy at +4/+8 (slot 0 unused),
// strong count at +4, weak at +8
struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

// Connection handle: 16 bytes, out-of-line dtor (target calls the boost connection dtor)
struct Connection
{
    void* con;
    Control* pn;
    bool controlling;
    int pad;

    __declspec(noinline) ~Connection();
};

Connection::~Connection()
{
    if (controlling) {
        Connection_disconnect();
    }
}

// Slot base: shared_ptr<Connection> handle, released inline in its dtor
struct Slot
{
    Connection* px;
    Control* pn;

    ~Slot()
    {
        if (pn) {
            Control* p = pn;
            if (_InterlockedDecrement(&p->strong) == 0) {
                p->dispose();
                if (_InterlockedDecrement(&p->weak) == 0)
                    p->destroy();
            }
        }
    }
};

struct MarkerItem : Slot
{
    Connection first;
    Connection second;
    int marker;

    ~MarkerItem();
};

MarkerItem::~MarkerItem()
{
}
