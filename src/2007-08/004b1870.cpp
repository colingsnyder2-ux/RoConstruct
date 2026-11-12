// from server: 100% by EspClaude
// roc 2007-08 004b1870  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 309 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b1870
//
// 004b1870  6aff                 push -1
// 004b1872  6854a97400           push 0x74a954
// 004b1877  64a100000000         mov eax, dword ptr fs:[0]
// 004b187d  50                   push eax
// 004b187e  83ec08               sub esp, 8
// 004b1881  56                   push esi
// 004b1882  57                   push edi
// 004b1883  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b1888  33c4                 xor eax, esp
// 004b188a  50                   push eax
// 004b188b  8d442414             lea eax, [esp + 0x14]
// 004b188f  64a300000000         mov dword ptr fs:[0], eax
// 004b1895  8bf1                 mov esi, ecx
// 004b1897  8974240c             mov dword ptr [esp + 0xc], esi
// 004b189b  e840f8ffff           call 0x4b10e0
// 004b18a0  8dbee8000000         lea edi, [esi + 0xe8]
// 004b18a6  8bcf                 mov ecx, edi
// 004b18a8  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004b18b0  e82b7afeff           call 0x4992e0
// 004b18b5  c786ec000000605b7900 mov dword ptr [esi + 0xec], 0x795b60
// 004b18bf  c70604d77900         mov dword ptr [esi], 0x79d704
// 004b18c5  c74604f8d67900       mov dword ptr [esi + 4], 0x79d6f8
// 004b18cc  c74610f0d67900       mov dword ptr [esi + 0x10], 0x79d6f0
// 004b18d3  c74614e0d67900       mov dword ptr [esi + 0x14], 0x79d6e0
// 004b18da  c7462cd0d67900       mov dword ptr [esi + 0x2c], 0x79d6d0
// 004b18e1  c74644c0d67900       mov dword ptr [esi + 0x44], 0x79d6c0
// 004b18e8  c7465cb0d67900       mov dword ptr [esi + 0x5c], 0x79d6b0
// 004b18ef  c74674a0d67900       mov dword ptr [esi + 0x74], 0x79d6a0
// 004b18f6  c7868c00000090d67900 mov dword ptr [esi + 0x8c], 0x79d690
// 004b1900  c70760d67900         mov dword ptr [edi], 0x79d660
// 004b1906  c786ec00000054d67900 mov dword ptr [esi + 0xec], 0x79d654
// 004b1910  c786f000000000000000 mov dword ptr [esi + 0xf0], 0
// 004b191a  6840000200           push 0x20040
// 004b191f  c644242003           mov byte ptr [esp + 0x20], 3
// 004b1924  e8cde51700           call 0x62fef6
// 004b1929  83c404               add esp, 4
// 004b192c  89442410             mov dword ptr [esp + 0x10], eax
// 004b1930  85c0                 test eax, eax
// 004b1932  c644241c04           mov byte ptr [esp + 0x1c], 4
// 004b1937  740e                 je 0x4b1947
// 004b1939  68b4db7900           push 0x79dbb4
// 004b193e  8bc8                 mov ecx, eax
// 004b1940  e83b030e00           call 0x591c80
// 004b1945  eb02                 jmp 0x4b1949
// 004b1947  33c0                 xor eax, eax
// 004b1949  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 004b194f  6800090000           push 0x900
// 004b1954  c644242005           mov byte ptr [esp + 0x20], 5
// 004b1959  e898e51700           call 0x62fef6
// 004b195e  83c404               add esp, 4
// 004b1961  89442410             mov dword ptr [esp + 0x10], eax
// 004b1965  85c0                 test eax, eax
// 004b1967  c644241c06           mov byte ptr [esp + 0x1c], 6
// 004b196c  7409                 je 0x4b1977
// 004b196e  8bc8                 mov ecx, eax
// 004b1970  e85bce0000           call 0x4be7d0
// 004b1975  eb02                 jmp 0x4b1979
// 004b1977  33c0                 xor eax, eax
// 004b1979  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 004b197f  8bc8                 mov ecx, eax
// 004b1981  8b01                 mov eax, dword ptr [ecx]
// 004b1983  8b90e8000000         mov edx, dword ptr [eax + 0xe8]
// 004b1989  57                   push edi
// 004b198a  c644242007           mov byte ptr [esp + 0x20], 7
// 004b198f  ffd2                 call edx
// 004b1991  8bc6                 mov eax, esi
// 004b1993  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004b1997  64890d00000000       mov dword ptr fs:[0], ecx
// 004b199e  59                   pop ecx
// 004b199f  5f                   pop edi
// 004b19a0  5e                   pop esi
// 004b19a1  83c414               add esp, 0x14
// 004b19a4  c3                   ret 
// Rewritten as a constructor: base A at +0 (ctor 0x4b10e0, polymorphic subobjects at
// 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c from the vptr stores), base B at +0xe8 (ctor 0x4992e0),
// base C at +0xec (inline vptr store 0x795b60), members at 0xf0 (=0), 0xf4 (new 0x20040,
// ctor(const char*) 0x591c80, "Packets Thread" at 0x79dbb4), 0xf8 (new 0x900, RakPeer ctor 0x4be7d0);
// then peer->vtable[0xe8/4](B*) . EH states 3,5,7 show the three members have destructors.
struct V0 { virtual void f0(); };
struct V1 { virtual void f1(); int p[2]; };   // 4 -> 0x10
struct V2 { virtual void f2(); };             // 0x10 -> 0x14
struct V3 { virtual void f3(); int p[5]; };   // 0x14 -> 0x2c
struct V4 { virtual void f4(); int p[5]; };   // 0x2c -> 0x44
struct V5 { virtual void f5(); int p[5]; };   // 0x44 -> 0x5c
struct V6 { virtual void f6(); int p[5]; };   // 0x5c -> 0x74
struct V7 { virtual void f7(); int p[5]; };   // 0x74 -> 0x8c
struct V8 { virtual void f8(); int p[22]; };  // 0x8c -> 0xe8
struct A : V0, V1, V2, V3, V4, V5, V6, V7, V8 { A(); ~A(); };
struct PluginInterface { PluginInterface(); virtual ~PluginInterface(); };
struct C { virtual ~C(); };

template<class T> struct scoped_ptr {
    T* p;
    explicit scoped_ptr(T* q = 0) : p(q) {}
    ~scoped_ptr();
    T* operator->() const { return p; }
};
struct Worker { explicit Worker(const char* name); ~Worker(); int data[0x20040/4]; };
struct RakPeer {
    RakPeer();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void AttachPlugin(PluginInterface* plugin);
    int data[(0x900 - 4)/4];
};

struct Replicator : A, PluginInterface, C {
    scoped_ptr<int> m0;
    scoped_ptr<Worker> worker;
    scoped_ptr<RakPeer> peer;
    Replicator();
};

Replicator::Replicator()
    : worker(new Worker("Packets Thread")), peer(new RakPeer())
{
    peer->AttachPlugin(this);
}
