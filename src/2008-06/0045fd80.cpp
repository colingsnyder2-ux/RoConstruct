// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 0045fd80  unit: RBX::Stats::Item  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045fd80
//
// 0045fd80  56                   push esi
// 0045fd81  8bf1                 mov esi, ecx
// 0045fd83  e828c1ffff           call 0x45beb0
// 0045fd88  6a00                 push 0
// 0045fd8a  8bce                 mov ecx, esi
// 0045fd8c  e81ffaffff           call 0x45f7b0
// 0045fd91  837e5c02             cmp dword ptr [esi + 0x5c], 2
// 0045fd95  750f                 jne 0x45fda6
// 0045fd97  8bce                 mov ecx, esi
// 0045fd99  e842c0ffff           call 0x45bde0
// 0045fd9e  8bce                 mov ecx, esi
// 0045fda0  5e                   pop esi
// 0045fda1  e9d6122400           jmp 0x6a107c
// 0045fda6  83beb800000000       cmp dword ptr [esi + 0xb8], 0
// 0045fdad  742e                 je 0x45fddd
// 0045fdaf  8b8eb4000000         mov ecx, dword ptr [esi + 0xb4]
// 0045fdb5  85c9                 test ecx, ecx
// 0045fdb7  7408                 je 0x45fdc1
// 0045fdb9  8b01                 mov eax, dword ptr [ecx]
// 0045fdbb  8b10                 mov edx, dword ptr [eax]
// 0045fdbd  6a01                 push 1
// 0045fdbf  ffd2                 call edx
// 0045fdc1  c786b400000000000000 mov dword ptr [esi + 0xb4], 0
// 0045fdcb  8b8eb8000000         mov ecx, dword ptr [esi + 0xb8]
// 0045fdd1  85c9                 test ecx, ecx
// 0045fdd3  7408                 je 0x45fddd
// 0045fdd5  8b01                 mov eax, dword ptr [ecx]
// 0045fdd7  8b10                 mov edx, dword ptr [eax]
// 0045fdd9  6a01                 push 1
// 0045fddb  ffd2                 call edx
// 0045fddd  8bce                 mov ecx, esi
// 0045fddf  5e                   pop esi
// 0045fde0  e997122400           jmp 0x6a107c

extern "C" void _ReadWriteBarrier();

struct Stopwatch
{
    void start();
    void stop();
};

struct Interface
{
    virtual ~Interface();
};

struct S : Stopwatch
{
    char padding[0x5c];
    int state;
    char padding2[0x54];
    Interface* first;
    Interface* second;

    void reset(int);
    void special();
    void finish();
    void f();
};

void S::f()
{
    start();
    reset(0);

    if (state == 2)
    {
        special();
        finish();
        return;
    }

    if (second)
    {
        if (first)
            delete first;
        first = 0;
        _ReadWriteBarrier();
        if (second)
            delete second;
    }

    finish();
}
