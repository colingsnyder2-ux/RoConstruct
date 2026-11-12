// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 00421c50  unit: CSelectionTreeCtrl  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00421c50
//
// 00421c50  6aff                 push -1
// 00421c52  68f8bc7300           push 0x73bcf8
// 00421c57  64a100000000         mov eax, dword ptr fs:[0]
// 00421c5d  50                   push eax
// 00421c5e  83ec14               sub esp, 0x14
// 00421c61  56                   push esi
// 00421c62  57                   push edi
// 00421c63  a188518b00           mov eax, dword ptr [0x8b5188]
// 00421c68  33c4                 xor eax, esp
// 00421c6a  50                   push eax
// 00421c6b  8d442420             lea eax, [esp + 0x20]
// 00421c6f  64a300000000         mov dword ptr fs:[0], eax
// 00421c75  8bf1                 mov esi, ecx
// 00421c77  8dbeb0000000         lea edi, [esi + 0xb0]
// 00421c7d  8bcf                 mov ecx, edi
// 00421c7f  897c240c             mov dword ptr [esp + 0xc], edi
// 00421c83  e8c83a3000           call 0x725750
// 00421c88  c644241001           mov byte ptr [esp + 0x10], 1
// 00421c8d  8d442430             lea eax, [esp + 0x30]
// 00421c91  50                   push eax
// 00421c92  8d4c2418             lea ecx, [esp + 0x18]
// 00421c96  51                   push ecx
// 00421c97  8d8ed8000000         lea ecx, [esi + 0xd8]
// 00421c9d  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00421ca5  e8b6790800           call 0x4a9660
// 00421caa  8bcf                 mov ecx, edi
// 00421cac  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00421cb4  e8b73a3000           call 0x725770
// 00421cb9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00421cbd  64890d00000000       mov dword ptr fs:[0], ecx
// 00421cc4  59                   pop ecx
// 00421cc5  5f                   pop edi
// 00421cc6  5e                   pop esi
// 00421cc7  83c420               add esp, 0x20
// 00421cca  c20400               ret 4


struct Mutex {
    void do_lock();
    void do_unlock();
};

struct ScopedLock {
    Mutex* m;
    bool locked;
    explicit ScopedLock(Mutex& mx) : m(&mx), locked(false) { m->do_lock(); locked = true; }
    ~ScopedLock() { if (locked) m->do_unlock(); }
};

struct InsertResult { int it0; int it1; bool second; };

struct ItemSet {
    InsertResult insert(const int& v);
};

struct CSelectionTreeCtrl {
    char pad[0xb0];
    Mutex mutex;              // +0xb0
    char pad2[0xd8 - 0xb1];
    ItemSet items;            // +0xd8

    void sub_421C50(int item);
};

void CSelectionTreeCtrl::sub_421C50(int item) {
    ScopedLock lock(mutex);
    items.insert(item);
}
