// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_spawnlateroffsetsb236f45df1ce3558.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/signals/connection.hpp>
#include <string>
// from server: 95% by king_originala
// roc 2008-06 005d3490  unit: RBX::VSpawnLocation::?$FactoryProduct  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d3490
//
// 005d3490  6aff                 push -1
// 005d3492  687f597d00           push 0x7d597f
// 005d3497  64a100000000         mov eax, dword ptr fs:[0]
// 005d349d  50                   push eax
// 005d349e  64892500000000       mov dword ptr fs:[0], esp
// 005d34a5  83ec24               sub esp, 0x24
// 005d34a8  53                   push ebx
// 005d34a9  33db                 xor ebx, ebx
// 005d34ab  56                   push esi
// 005d34ac  8bf1                 mov esi, ecx
// 005d34ae  89742408             mov dword ptr [esp + 8], esi
// 005d34b2  895c240c             mov dword ptr [esp + 0xc], ebx
// 005d34b6  395c243c             cmp dword ptr [esp + 0x3c], ebx
// 005d34ba  7414                 je 0x5d34d0
// 005d34bc  c786340100003cc18300 mov dword ptr [esi + 0x134], 0x83c13c
// 005d34c6  c7862004000044618400 mov dword ptr [esi + 0x420], 0x846144
// 005d34d0  53                   push ebx
// 005d34d1  e8dafcffff           call 0x5d31b0
// 005d34d6  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005d34dc  c706d4c08300         mov dword ptr [esi], 0x83c0d4
// 005d34e2  c74610c8c08300       mov dword ptr [esi + 0x10], 0x83c0c8
// 005d34e9  c74614c0c08300       mov dword ptr [esi + 0x14], 0x83c0c0
// 005d34f0  c74620b8c08300       mov dword ptr [esi + 0x20], 0x83c0b8
// 005d34f7  c74624a8c08300       mov dword ptr [esi + 0x24], 0x83c0a8
// 005d34fe  c7464498c08300       mov dword ptr [esi + 0x44], 0x83c098
// 005d3505  c7466488c08300       mov dword ptr [esi + 0x64], 0x83c088
// 005d350c  c7868400000078c08300 mov dword ptr [esi + 0x84], 0x83c078
// 005d3516  c786a400000068c08300 mov dword ptr [esi + 0xa4], 0x83c068
// 005d3520  c786c400000058c08300 mov dword ptr [esi + 0xc4], 0x83c058
// 005d352a  c786300100004cc08300 mov dword ptr [esi + 0x130], 0x83c04c
// 005d3534  c786a00100003cc08300 mov dword ptr [esi + 0x1a0], 0x83c03c
// 005d353e  c786c001000030c08300 mov dword ptr [esi + 0x1c0], 0x83c030
// 005d3548  c786cc01000018c08300 mov dword ptr [esi + 0x1cc], 0x83c018
// 005d3552  8b4804               mov ecx, dword ptr [eax + 4]
// 005d3555  c78431340100000cc08300 mov dword ptr [ecx + esi + 0x134], 0x83c00c
// 005d3560  8b9634010000         mov edx, dword ptr [esi + 0x134]
// 005d3566  8b4208               mov eax, dword ptr [edx + 8]
// 005d3569  c784303401000004c08300 mov dword ptr [eax + esi + 0x134], 0x83c004
// 005d3574  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 005d357a  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005d357d  c7843234010000e8bf8300 mov dword ptr [edx + esi + 0x134], 0x83bfe8
// 005d3588  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005d358e  8b4004               mov eax, dword ptr [eax + 4]
// 005d3591  8d8828fdffff         lea ecx, [eax - 0x2d8]
// 005d3597  898c3030010000       mov dword ptr [eax + esi + 0x130], ecx
// 005d359e  8b9634010000         mov edx, dword ptr [esi + 0x134]
// 005d35a4  8b4208               mov eax, dword ptr [edx + 8]
// 005d35a7  8d8820fdffff         lea ecx, [eax - 0x2e0]
// 005d35ad  898c3030010000       mov dword ptr [eax + esi + 0x130], ecx
// 005d35b4  8b9634010000         mov edx, dword ptr [esi + 0x134]
// 005d35ba  8b420c               mov eax, dword ptr [edx + 0xc]
// 005d35bd  8d8818fdffff         lea ecx, [eax - 0x2e8]
// 005d35c3  898c3030010000       mov dword ptr [eax + esi + 0x130], ecx
// 005d35ca  c786e8030000c2000000 mov dword ptr [esi + 0x3e8], 0xc2
// 005d35d4  899ef0030000         mov dword ptr [esi + 0x3f0], ebx
// 005d35da  899ef4030000         mov dword ptr [esi + 0x3f4], ebx
// 005d35e0  895c2434             mov dword ptr [esp + 0x34], ebx
// 005d35e4  889ef8030000         mov byte ptr [esi + 0x3f8], bl
// 005d35ea  889efc030000         mov byte ptr [esi + 0x3fc], bl
// 005d35f0  68cc259500           push 0x9525cc
// 005d35f5  8d4c2414             lea ecx, [esp + 0x14]
// 005d35f9  c644243801           mov byte ptr [esp + 0x38], 1
// 005d35fe  c6860004000001       mov byte ptr [esi + 0x400], 1
// 005d3605  889e01040000         mov byte ptr [esi + 0x401], bl
// 005d360b  c786040400000a000000 mov dword ptr [esi + 0x404], 0xa
// 005d3615  ff1558248000         call dword ptr [0x802458]
// 005d361b  8d542410             lea edx, [esp + 0x10]
// 005d361f  52                   push edx
// 005d3620  8bce                 mov ecx, esi
// 005d3622  c644243802           mov byte ptr [esp + 0x38], 2
// 005d3627  e8f455fcff           call 0x598c20
// 005d362c  8d4c2410             lea ecx, [esp + 0x10]
// 005d3630  c644243401           mov byte ptr [esp + 0x34], 1
// 005d3635  ff1568248000         call dword ptr [0x802468]
// 005d363b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d363f  8bc6                 mov eax, esi
// 005d3641  5e                   pop esi
// 005d3642  5b                   pop ebx
// 005d3643  64890d00000000       mov dword ptr fs:[0], ecx
// 005d364a  83c430               add esp, 0x30
// 005d364d  c20400               ret 4

typedef std::string String;

struct Base {
    int data[250];
    Base(int);
    ~Base();
};

extern int table134[];
extern int table420[];
extern int table000[];
extern int table010[];
extern int table014[];
extern int table020[];
extern int table024[];
extern int table044[];
extern int table064[];
extern int table084[];
extern int table0a4[];
extern int table0c4[];
extern int table130[];
extern int table1a0[];
extern int table1c0[];
extern int table1cc[];
extern int virtualTable1[];
extern int virtualTable2[];
extern int virtualTable3[];
extern const char spawnName[];

struct S : Base {
    int duration;
    boost::signals::scoped_connection connection;
    char active;
    char locked;
    char padding3[2];
    int delay;
    char tail[28];

    S(int);
    int prepare(int);
    int initializeTables();
    void fixOffset(int index,int delta) {int offset=((int*)data[0x134/4])[index];*(int*)((char*)this+0x130+offset)=offset-delta;}
    void setName(const String&);
};

__forceinline int S::prepare(int initialize) {
    volatile int constructionState = 0;
    if (initialize) {
        data[0x134 / 4] = reinterpret_cast<int>(table134);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x420) =
            reinterpret_cast<int>(table420);
    }
    return 0;
}

__forceinline int S::initializeTables() {
    int* table = reinterpret_cast<int*>(data[0x134 / 4]);

    data[0x000 / 4] = reinterpret_cast<int>(table000);
    data[0x010 / 4] = reinterpret_cast<int>(table010);
    data[0x014 / 4] = reinterpret_cast<int>(table014);
    data[0x020 / 4] = reinterpret_cast<int>(table020);
    data[0x024 / 4] = reinterpret_cast<int>(table024);
    data[0x044 / 4] = reinterpret_cast<int>(table044);
    data[0x064 / 4] = reinterpret_cast<int>(table064);
    data[0x084 / 4] = reinterpret_cast<int>(table084);
    data[0x0a4 / 4] = reinterpret_cast<int>(table0a4);
    data[0x0c4 / 4] = reinterpret_cast<int>(table0c4);
    data[0x130 / 4] = reinterpret_cast<int>(table130);
    data[0x1a0 / 4] = reinterpret_cast<int>(table1a0);
    data[0x1c0 / 4] = reinterpret_cast<int>(table1c0);
    data[0x1cc / 4] = reinterpret_cast<int>(table1cc);

    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[1]) =
        reinterpret_cast<int>(virtualTable1);
    table = reinterpret_cast<int*>(data[0x134 / 4]);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[2]) =
        reinterpret_cast<int>(virtualTable2);
    table = reinterpret_cast<int*>(data[0x134 / 4]);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x134 + table[3]) =
        reinterpret_cast<int>(virtualTable3);

    table=reinterpret_cast<int*>(data[0x134/4]);
    int offset=table[1];
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x130+offset)=offset-0x2d8;
    fixOffset(2,0x2e0);
    fixOffset(3,0x2e8);

    return 194;
}

S::S(int initialize)
    : Base(prepare(initialize)),
      duration(initializeTables()),
      active(1),
      locked(0),
      delay(10)
{
    String name("SpawnLocation");
    setName(name);
}
