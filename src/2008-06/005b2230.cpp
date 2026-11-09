// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_accoutrementderivedtables01a1440885f0d2ec.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
extern char table_4782d0[];
extern char table_55af90[];
extern char table_5b2140[];
extern char table_5b2271[];
extern char table_628fc0[];
extern char table_7d3807[];
extern char table_802458[];
extern char table_802468[];
extern char table_834b34[];
extern char table_834b50[];
extern char table_834b58[];
extern char table_834b70[];
extern char table_834b78[];
extern char table_834b88[];
extern char table_834b98[];
extern char table_834ba8[];
extern char table_834bb8[];
extern char table_834bc8[];
extern char table_834bd8[];
extern char table_834be0[];
extern char table_834be8[];
extern char table_834bf4[];
extern char table_834eb4[];
extern char table_846144[];
extern char table_ffffff[];
// from server: 92% by king_originala
// roc 2008-06 005b2230  unit: RBX::VAccoutrement::?$FactoryProduct  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b2230
//
// 005b2230  6aff                 push -1
// 005b2232  6807387d00           push reinterpret_cast<unsigned long>(table_7d3807)
// 005b2237  64a100000000         mov eax, dword ptr fs:[0]
// 005b223d  50                   push eax
// 005b223e  64892500000000       mov dword ptr fs:[0], esp
// 005b2245  83ec24               sub esp, 0x24
// 005b2248  53                   push ebx
// 005b2249  56                   push esi
// 005b224a  33db                 xor ebx, ebx
// 005b224c  8bf1                 mov esi, ecx
// 005b224e  57                   push edi
// 005b224f  8974240c             mov dword ptr [esp + 0xc], esi
// 005b2253  895c2410             mov dword ptr [esp + 0x10], ebx
// 005b2257  395c2440             cmp dword ptr [esp + 0x40], ebx
// 005b225b  7414                 je reinterpret_cast<unsigned long>(table_5b2271)
// 005b225d  c78650010000b44e8300 mov dword ptr [esi + 0x150], reinterpret_cast<unsigned long>(table_834eb4)
// 005b2267  c786d401000044618400 mov dword ptr [esi + 0x1d4], reinterpret_cast<unsigned long>(table_846144)
// 005b2271  e8cafeffff           call reinterpret_cast<unsigned long>(table_5b2140)
// 005b2276  8dbe30010000         lea edi, [esi + 0x130]
// 005b227c  8bcf                 mov ecx, edi
// 005b227e  895c2438             mov dword ptr [esp + 0x38], ebx
// 005b2282  e8396d0700           call reinterpret_cast<unsigned long>(table_628fc0)
// 005b2287  83c8ff               or eax, reinterpret_cast<unsigned long>(table_ffffff)ff
// 005b228a  898644010000         mov dword ptr [esi + 0x144], eax
// 005b2290  898648010000         mov dword ptr [esi + 0x148], eax
// 005b2296  899e4c010000         mov dword ptr [esi + 0x14c], ebx
// 005b229c  8b8650010000         mov eax, dword ptr [esi + 0x150]
// 005b22a2  c706f44b8300         mov dword ptr [esi], reinterpret_cast<unsigned long>(table_834bf4)
// 005b22a8  c74610e84b8300       mov dword ptr [esi + 0x10], reinterpret_cast<unsigned long>(table_834be8)
// 005b22af  c74614e04b8300       mov dword ptr [esi + 0x14], reinterpret_cast<unsigned long>(table_834be0)
// 005b22b6  c74620d84b8300       mov dword ptr [esi + 0x20], reinterpret_cast<unsigned long>(table_834bd8)
// 005b22bd  c74624c84b8300       mov dword ptr [esi + 0x24], reinterpret_cast<unsigned long>(table_834bc8)
// 005b22c4  c74644b84b8300       mov dword ptr [esi + 0x44], reinterpret_cast<unsigned long>(table_834bb8)
// 005b22cb  c74664a84b8300       mov dword ptr [esi + 0x64], reinterpret_cast<unsigned long>(table_834ba8)
// 005b22d2  c78684000000984b8300 mov dword ptr [esi + 0x84], reinterpret_cast<unsigned long>(table_834b98)
// 005b22dc  c786a4000000884b8300 mov dword ptr [esi + 0xa4], reinterpret_cast<unsigned long>(table_834b88)
// 005b22e6  c786c4000000784b8300 mov dword ptr [esi + 0xc4], reinterpret_cast<unsigned long>(table_834b78)
// 005b22f0  c707704b8300         mov dword ptr [edi], reinterpret_cast<unsigned long>(table_834b70)
// 005b22f6  c78640010000584b8300 mov dword ptr [esi + 0x140], reinterpret_cast<unsigned long>(table_834b58)
// 005b2300  8b4804               mov ecx, dword ptr [eax + 4]
// 005b2303  c7843150010000504b8300 mov dword ptr [ecx + esi + 0x150], reinterpret_cast<unsigned long>(table_834b50)
// 005b230e  8b9650010000         mov edx, dword ptr [esi + 0x150]
// 005b2314  8b4208               mov eax, dword ptr [edx + 8]
// 005b2317  c7843050010000344b8300 mov dword ptr [eax + esi + 0x150], reinterpret_cast<unsigned long>(table_834b34)
// 005b2322  8b8e50010000         mov ecx, dword ptr [esi + 0x150]
// 005b2328  8b4104               mov eax, dword ptr [ecx + 4]
// 005b232b  8d5088               lea edx, [eax - 0x78]
// 005b232e  8994304c010000       mov dword ptr [eax + esi + 0x14c], edx
// 005b2335  8b8650010000         mov eax, dword ptr [esi + 0x150]
// 005b233b  8b4008               mov eax, dword ptr [eax + 8]
// 005b233e  8d4880               lea ecx, [eax - 0x80]
// 005b2341  898c304c010000       mov dword ptr [eax + esi + 0x14c], ecx
// 005b2348  8d8e58010000         lea ecx, [esi + 0x158]
// 005b234e  c644243802           mov byte ptr [esp + 0x38], 2
// 005b2353  899e54010000         mov dword ptr [esi + 0x154], ebx
// 005b2359  e8725fecff           call reinterpret_cast<unsigned long>(table_4782d0)
// 005b235e  899e8c010000         mov dword ptr [esi + 0x18c], ebx
// 005b2364  899e90010000         mov dword ptr [esi + 0x190], ebx
// 005b236a  889e94010000         mov byte ptr [esi + 0x194], bl
// 005b2370  889e98010000         mov byte ptr [esi + 0x198], bl
// 005b2376  899ea0010000         mov dword ptr [esi + 0x1a0], ebx
// 005b237c  899ea4010000         mov dword ptr [esi + 0x1a4], ebx
// 005b2382  889ea8010000         mov byte ptr [esi + 0x1a8], bl
// 005b2388  889eac010000         mov byte ptr [esi + 0x1ac], bl
// 005b238e  899eb4010000         mov dword ptr [esi + 0x1b4], ebx
// 005b2394  899eb8010000         mov dword ptr [esi + 0x1b8], ebx
// 005b239a  889ebc010000         mov byte ptr [esi + 0x1bc], bl
// 005b23a0  889ec0010000         mov byte ptr [esi + 0x1c0], bl
// 005b23a6  b305                 mov bl, 5
// 005b23a8  68f8498300           push 0x8349f8
// 005b23ad  8d4c2418             lea ecx, [esp + 0x18]
// 005b23b1  885c243c             mov byte ptr [esp + 0x3c], bl
// 005b23b5  ff1558248000         call dword ptr [reinterpret_cast<unsigned long>(table_802458)]
// 005b23bb  8d542414             lea edx, [esp + 0x14]
// 005b23bf  52                   push edx
// 005b23c0  8bce                 mov ecx, esi
// 005b23c2  c644243c06           mov byte ptr [esp + 0x3c], 6
// 005b23c7  e8c48bfaff           call reinterpret_cast<unsigned long>(table_55af90)
// 005b23cc  8d4c2414             lea ecx, [esp + 0x14]
// 005b23d0  885c2438             mov byte ptr [esp + 0x38], bl
// 005b23d4  ff1568248000         call dword ptr [reinterpret_cast<unsigned long>(table_802468)]
// 005b23da  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005b23de  5f                   pop edi
// 005b23df  8bc6                 mov eax, esi
// 005b23e1  5e                   pop esi
// 005b23e2  5b                   pop ebx
// 005b23e3  64890d00000000       mov dword ptr fs:[0], ecx
// 005b23ea  83c430               add esp, 0x30
// 005b23ed  c20400               ret 4

typedef std::string String;
struct Base {
    unsigned char data[0x130];
    Base(int);
    ~Base();
    void base();
};

__forceinline Base::Base(int initialize)
{
    volatile int state = 0;
    unsigned char* p = reinterpret_cast<unsigned char*>(this);
    if (initialize) {
        *reinterpret_cast<unsigned long*>(p + 0x150) = reinterpret_cast<unsigned long>(table_834eb4);
        *reinterpret_cast<unsigned long*>(p + 0x1d4) = reinterpret_cast<unsigned long>(table_846144);
    }
    base();
}

struct Vector {
    char storage[16];
    Vector();
    ~Vector();
};

struct Handle {
    unsigned long table;
    int first;
    int second;
    int third;
    Handle();
    ~Handle();
};

__forceinline Handle::Handle()
{
    first = -1;
    second = -1;
    third = 0;
}

struct Setup {
    unsigned long table;
    int value;
    Setup(int v):value(v) {}
};

struct NameItem {
    char storage[0x34];
    NameItem();

};

struct Record {
    int first;
    int second;
    unsigned char flag;
    unsigned char padding1[3];
    unsigned char otherFlag;
    unsigned char padding2[3];
    int last;
    Record();
    ~Record();
};

__forceinline Record::Record()
{
    first = 0;
    second = 0;
    flag = 0;
    otherFlag = 0;
}

struct S : Base {
    Vector vector;
    Handle handle;
    Setup setup;
    NameItem name;
    Record record1;
    Record record2;
    Record record3;
    unsigned char tail[8];

    int initializeTables();
    S(int);
    void setValue(const String&);
};

__forceinline int S::initializeTables()
{
    unsigned char* p = reinterpret_cast<unsigned char*>(this);
    int* t = *reinterpret_cast<int**>(p + 0x150);

    *reinterpret_cast<unsigned long*>(p) = reinterpret_cast<unsigned long>(table_834bf4);
    *reinterpret_cast<unsigned long*>(p + 0x10) = reinterpret_cast<unsigned long>(table_834be8);
    *reinterpret_cast<unsigned long*>(p + 0x14) = reinterpret_cast<unsigned long>(table_834be0);
    *reinterpret_cast<unsigned long*>(p + 0x20) = reinterpret_cast<unsigned long>(table_834bd8);
    *reinterpret_cast<unsigned long*>(p + 0x24) = reinterpret_cast<unsigned long>(table_834bc8);
    *reinterpret_cast<unsigned long*>(p + 0x44) = reinterpret_cast<unsigned long>(table_834bb8);
    *reinterpret_cast<unsigned long*>(p + 0x64) = reinterpret_cast<unsigned long>(table_834ba8);
    *reinterpret_cast<unsigned long*>(p + 0x84) = reinterpret_cast<unsigned long>(table_834b98);
    *reinterpret_cast<unsigned long*>(p + 0xa4) = reinterpret_cast<unsigned long>(table_834b88);
    *reinterpret_cast<unsigned long*>(p + 0xc4) = reinterpret_cast<unsigned long>(table_834b78);
    *reinterpret_cast<unsigned long*>(&vector) = reinterpret_cast<unsigned long>(table_834b70);
    *reinterpret_cast<unsigned long*>(p + 0x140) = reinterpret_cast<unsigned long>(table_834b58);

    *reinterpret_cast<unsigned long*>(p + 0x150 + t[1]) = reinterpret_cast<unsigned long>(table_834b50);
    t = *reinterpret_cast<int**>(p + 0x150);
    *reinterpret_cast<unsigned long*>(p + 0x150 + t[2]) = reinterpret_cast<unsigned long>(table_834b34);

    t = *reinterpret_cast<int**>(p + 0x150);
    int offset = t[1];
    *reinterpret_cast<int*>(p + 0x14c + offset) = offset - 0x78;

    t = *reinterpret_cast<int**>(p + 0x150);
    offset = t[2];
    *reinterpret_cast<int*>(p + 0x14c + offset) = offset - 0x80;
    return 0;
}


S::S(int initialize) : Base(initialize), setup(initializeTables())
{
    String value("Accoutrement");
    setValue(value);
}


