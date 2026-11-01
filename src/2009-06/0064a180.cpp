// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005bda10  unit: RBX::Soundscape::SoundChannel  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bda10
//
// 005bda10  56                   push esi
// 005bda11  57                   push edi
// 005bda12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bda16  8bf1                 mov esi, ecx
// 005bda18  83ffff               cmp edi, -1
// 005bda1b  750a                 jne 0x5bda27
// 005bda1d  e86efbffff           call 0x5bd590
// 005bda22  5f                   pop edi
// 005bda23  5e                   pop esi
// 005bda24  c20400               ret 4
// 005bda27  85ff                 test edi, edi
// 005bda29  750a                 jne 0x5bda35
// 005bda2b  e810fbffff           call 0x5bd540
// 005bda30  5f                   pop edi
// 005bda31  5e                   pop esi
// 005bda32  c20400               ret 4
// 005bda35  3bbe68010000         cmp edi, dword ptr [esi + 0x168]
// 005bda3b  7e18                 jle 0x5bda55
// 005bda3d  56                   push esi
// 005bda3e  e86df4ffff           call 0x5bceb0
// 005bda43  6810709700           push 0x977010
// 005bda48  8bce                 mov ecx, esi
// 005bda4a  89be68010000         mov dword ptr [esi + 0x168], edi
// 005bda50  e8ab00e5ff           call 0x40db00
// 005bda55  5f                   pop edi
// 005bda56  5e                   pop esi
// 005bda57  c20400               ret 4

struct S;
extern "C" void __stdcall prepare(S *);
extern unsigned char descriptor;

struct S {
    unsigned char padding[0x168];
    int value;

    void setValue(int);
    void setAutomatic();
    void clear();
    void notify(const void *);
};

void S::setValue(int n)
{
    if (n == -1) {
        setAutomatic();
        return;
    }
    if (n == 0) {
        clear();
        return;
    }
    if (n > value) {
        prepare(this);
        value = n;
        notify(&descriptor);
    }
}
