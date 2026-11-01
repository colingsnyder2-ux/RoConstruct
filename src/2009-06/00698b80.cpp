// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00698b80  unit: RBX::Hole  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00698b80
//
// 00698b80  83ec30               sub esp, 0x30
// 00698b83  56                   push esi
// 00698b84  8bf1                 mov esi, ecx
// 00698b86  8d4c2404             lea ecx, [esp + 4]
// 00698b8a  e8216de0ff           call 0x49f8b0
// 00698b8f  8d442404             lea eax, [esp + 4]
// 00698b93  50                   push eax
// 00698b94  8d8e74ffffff         lea ecx, [esi - 0x8c]
// 00698b9a  e801ffffff           call 0x698aa0
// 00698b9f  5e                   pop esi
// 00698ba0  84c0                 test al, al
// 00698ba2  7432                 je 0x698bd6
// 00698ba4  6a01                 push 1
// 00698ba6  e865d9edff           call 0x576510
// 00698bab  d90540aa8b00         fld dword ptr [0x8baa40]
// 00698bb1  8b542438             mov edx, dword ptr [esp + 0x38]
// 00698bb5  50                   push eax
// 00698bb6  83ec08               sub esp, 8
// 00698bb9  d95c2404             fstp dword ptr [esp + 4]
// 00698bbd  8d4c2410             lea ecx, [esp + 0x10]
// 00698bc1  d905ace98b00         fld dword ptr [0x8be9ac]
// 00698bc7  d91c24               fstp dword ptr [esp]
// 00698bca  6a02                 push 2
// 00698bcc  51                   push ecx
// 00698bcd  52                   push edx
// 00698bce  e87dab0600           call 0x703750
// 00698bd3  83c41c               add esp, 0x1c
// 00698bd6  83c430               add esp, 0x30
// 00698bd9  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0060a580  unit: RBX::Hole  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060a580
//
// 0060a580  83ec30               sub esp, 0x30
// 0060a583  56                   push esi
// 0060a584  8bf1                 mov esi, ecx
// 0060a586  8d4c2404             lea ecx, [esp + 4]
// 0060a58a  e841dde6ff           call 0x4782d0
// 0060a58f  8d442404             lea eax, [esp + 4]
// 0060a593  50                   push eax
// 0060a594  8d8ed0feffff         lea ecx, [esi - 0x8c]
// 0060a59a  e8f1feffff           call 0x60a490
// 0060a59f  5e                   pop esi
// 0060a5a0  84c0                 test al, al
// 0060a5a2  7430                 je 0x60a5d4
// 0060a5a4  e847a4f0ff           call 0x5149f0
// 0060a5a9  d9051c718200         fld dword ptr [0x82711c]
// 0060a5af  8b542434             mov edx, dword ptr [esp + 0x34]
// 0060a5b3  50                   push eax
// 0060a5b4  83ec08               sub esp, 8
// 0060a5b7  d95c2404             fstp dword ptr [esp + 4]
// 0060a5bb  8d4c240c             lea ecx, [esp + 0xc]
// 0060a5bf  d905f8498200         fld dword ptr [0x8249f8]
// 0060a5c5  d91c24               fstp dword ptr [esp]
// 0060a5c8  6a02                 push 2
// 0060a5ca  51                   push ecx
// 0060a5cb  52                   push edx
// 0060a5cc  e81fce0600           call 0x6773f0
// 0060a5d1  83c418               add esp, 0x18
// 0060a5d4  83c430               add esp, 0x30
// 0060a5d7  c20400               ret 4

struct Frame {
    char data[48];
    Frame();
};

extern float value8249f8;
extern float value82711c;

extern const float* __cdecl camera5149f0();
extern void __cdecl draw6773f0(
    void*, const Frame*, int, float, float, const float*, int);

struct Hole {
    bool check60a490(Frame*);
    void render(void*);
};

void Hole::render(void* context)
{
    Frame frame;
    Hole* base = reinterpret_cast<Hole*>(
        reinterpret_cast<char*>(this) - 0x8c);

    if (base->check60a490(&frame))
        draw6773f0(context, &frame, 2,
                   value8249f8, value82711c, camera5149f0(), 1);
}
