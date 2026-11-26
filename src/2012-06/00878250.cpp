// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 006a5db0  unit: RBX::Lua::WeakThreadRef  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a5db0
//
// 006a5db0  6aff                 push -1
// 006a5db2  68f840ac00           push 0xac40f8
// 006a5db7  64a100000000         mov eax, dword ptr fs:[0]
// 006a5dbd  50                   push eax
// 006a5dbe  64892500000000       mov dword ptr fs:[0], esp
// 006a5dc5  51                   push ecx
// 006a5dc6  56                   push esi
// 006a5dc7  8bf1                 mov esi, ecx
// 006a5dc9  89742404             mov dword ptr [esp + 4], esi
// 006a5dcd  c70600000000         mov dword ptr [esi], 0
// 006a5dd3  6820476a00           push 0x6a4720
// 006a5dd8  6820dbe200           push 0xe2db20
// 006a5ddd  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006a5de5  e8b6b7d5ff           call 0x4015a0
// 006a5dea  b801000000           mov eax, 1
// 006a5def  83c408               add esp, 8
// 006a5df2  84050cdbe200         test byte ptr [0xe2db0c], al
// 006a5df8  7527                 jne 0x6a5e21
// 006a5dfa  09050cdbe200         or dword ptr [0xe2db0c], eax
// 006a5e00  684062b100           push 0xb16240
// 006a5e05  c70504dbe20000000000 mov dword ptr [0xe2db04], 0
// 006a5e0f  c70508dbe20000000000 mov dword ptr [0xe2db08], 0
// 006a5e19  e8d7d32d00           call 0x9831f5
// 006a5e1e  83c404               add esp, 4
// 006a5e21  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006a5e25  8bc6                 mov eax, esi
// 006a5e27  5e                   pop esi
// 006a5e28  64890d00000000       mov dword ptr fs:[0], ecx
// 006a5e2f  83c410               add esp, 0x10
// 006a5e32  c3                   ret 

struct Ptr {
    int p;
    Ptr() : p(0) {}
    ~Ptr();
};

struct Holder {
    int a;
    int b;
    Holder() : a(0), b(0) {}
    ~Holder();
};

extern long g_once;
void g_once_init();
void call_once(long& flag, void (*f)());

struct ThreadRef {
    Ptr liveThreadRef;
    ThreadRef();
};

ThreadRef::ThreadRef() {
    call_once(g_once, g_once_init);
    static Holder holder;
}
