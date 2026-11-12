// from server: 98% by EspClaude
// from server: 57% by colin
// roc 2007-08 004b1ad0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 386 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b1ad0
//
// 004b1ad0  6aff                 push -1
// 004b1ad2  68e6a97400           push 0x74a9e6
// 004b1ad7  64a100000000         mov eax, dword ptr fs:[0]
// 004b1add  50                   push eax
// 004b1ade  81ec68010000         sub esp, 0x168
// 004b1ae4  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b1ae9  33c4                 xor eax, esp
// 004b1aeb  89842464010000       mov dword ptr [esp + 0x164], eax
// 004b1af2  53                   push ebx
// 004b1af3  55                   push ebp
// 004b1af4  56                   push esi
// 004b1af5  57                   push edi
// 004b1af6  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b1afb  33c4                 xor eax, esp
// 004b1afd  50                   push eax
// 004b1afe  8d84247c010000       lea eax, [esp + 0x17c]
// 004b1b05  64a300000000         mov dword ptr fs:[0], eax
// 004b1b0b  8bf1                 mov esi, ecx
// 004b1b0d  80beb41d000000       cmp byte ptr [esi + 0x1db4], 0
// 004b1b14  7507                 jne 0x4b1b1d
// 004b1b16  32c0                 xor al, al
// 004b1b18  e90d010000           jmp 0x4b1c2a
// 004b1b1d  8b961c1e0000         mov edx, dword ptr [esi + 0x1e1c]
// 004b1b23  8b8e141e0000         mov ecx, dword ptr [esi + 0x1e14]
// 004b1b29  8b01                 mov eax, dword ptr [ecx]
// 004b1b2b  8b8008010000         mov eax, dword ptr [eax + 0x108]
// 004b1b31  52                   push edx
// 004b1b32  8b96181e0000         mov edx, dword ptr [esi + 0x1e18]
// 004b1b38  52                   push edx
// 004b1b39  ffd0                 call eax
// 004b1b3b  85c0                 test eax, eax
// 004b1b3d  74d7                 je 0x4b1b16
// 004b1b3f  8b860c1e0000         mov eax, dword ptr [esi + 0x1e0c]
// 004b1b45  6a00                 push 0
// 004b1b47  50                   push eax
// 004b1b48  8d4c2424             lea ecx, [esp + 0x24]
// 004b1b4c  e8df63faff           call 0x457f30
// 004b1b51  8b8e141e0000         mov ecx, dword ptr [esi + 0x1e14]
// 004b1b57  51                   push ecx
// 004b1b58  56                   push esi
// 004b1b59  8d4c2450             lea ecx, [esp + 0x50]
// 004b1b5d  c784248c01000000000000 mov dword ptr [esp + 0x18c], 0
// 004b1b68  e8e333ffff           call 0x4a4f50
// 004b1b6d  56                   push esi
// 004b1b6e  c684248801000001     mov byte ptr [esp + 0x188], 1
// 004b1b76  e855c5fdff           call 0x48e0d0
// 004b1b7b  83c404               add esp, 4
// 004b1b7e  85c0                 test eax, eax
// 004b1b80  747a                 je 0x4b1bfc
// 004b1b82  8b887c020000         mov ecx, dword ptr [eax + 0x27c]
// 004b1b88  e8a3750f00           call 0x5a9130
// 004b1b8d  8bce                 mov ecx, esi
// 004b1b8f  8be8                 mov ebp, eax
// 004b1b91  e87a4cffff           call 0x4a6810
// 004b1b96  8bf8                 mov edi, eax
// 004b1b98  85ff                 test edi, edi
// 004b1b9a  744c                 je 0x4b1be8
// 004b1b9c  e88fe30400           call 0x4fff30
// 004b1ba1  dd542414             fst qword ptr [esp + 0x14]
// 004b1ba5  dd8610010000         fld qword ptr [esi + 0x110]
// 004b1bab  dc05c8db7900         fadd qword ptr [0x79dbc8]
// 004b1bb1  ded9                 fcompp 
// 004b1bb3  dfe0                 fnstsw ax
// 004b1bb5  f6c405               test ah, 5
// 004b1bb8  7a2c                 jp 0x4b1be6
// 004b1bba  6a01                 push 1
// 004b1bbc  8d4c244c             lea ecx, [esp + 0x4c]
// 004b1bc0  e83b34ffff           call 0x4a5000
// 004b1bc5  57                   push edi
// 004b1bc6  8d4c244c             lea ecx, [esp + 0x4c]
// 004b1bca  e87179ffff           call 0x4a9540
// 004b1bcf  6a02                 push 2
// 004b1bd1  8d4c244c             lea ecx, [esp + 0x4c]
// 004b1bd5  e82634ffff           call 0x4a5000
// 004b1bda  dd442414             fld qword ptr [esp + 0x14]
// 004b1bde  dd9e10010000         fstp qword ptr [esi + 0x110]
// 004b1be4  eb02                 jmp 0x4b1be8
// 004b1be6  33ff                 xor edi, edi
// 004b1be8  57                   push edi
// 004b1be9  81c608010000         add esi, 0x108
// 004b1bef  56                   push esi
// 004b1bf0  8d542450             lea edx, [esp + 0x50]
// 004b1bf4  52                   push edx
// 004b1bf5  8bcd                 mov ecx, ebp
// 004b1bf7  e8e484ffff           call 0x4aa0e0
// 004b1bfc  8a9c2474010000       mov bl, byte ptr [esp + 0x174]
// 004b1c03  8d4c2448             lea ecx, [esp + 0x48]
// 004b1c07  c684248401000000     mov byte ptr [esp + 0x184], 0
// 004b1c0f  e88c33ffff           call 0x4a4fa0
// 004b1c14  8d4c241c             lea ecx, [esp + 0x1c]
// 004b1c18  c7842484010000ffffffff mov dword ptr [esp + 0x184], 0xffffffff
// 004b1c23  e86863faff           call 0x457f90
// 004b1c28  8ac3                 mov al, bl
// 004b1c2a  8b8c247c010000       mov ecx, dword ptr [esp + 0x17c]
// 004b1c31  64890d00000000       mov dword ptr fs:[0], ecx
// 004b1c38  59                   pop ecx
// 004b1c39  5f                   pop edi
// 004b1c3a  5e                   pop esi
// 004b1c3b  5d                   pop ebp
// 004b1c3c  5b                   pop ebx
// 004b1c3d  8b8c2464010000       mov ecx, dword ptr [esp + 0x164]
// 004b1c44  33cc                 xor ecx, esp
// 004b1c46  e8d3ed1700           call 0x630a1e
// 004b1c4b  81c474010000         add esp, 0x174
// 004b1c51  c3                   ret 

struct Peer {
    virtual void v0();
};

struct PeerSlots {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
    virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
    virtual void s20(); virtual void s24(); virtual void s28(); virtual void s2c();
    virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual void s40(); virtual void s44(); virtual void s48(); virtual void s4c();
    virtual void s50(); virtual void s54(); virtual void s58(); virtual void s5c();
    virtual void s60(); virtual void s64(); virtual void s68(); virtual void s6c();
    virtual void s70(); virtual void s74(); virtual void s78(); virtual void s7c();
    virtual void s80(); virtual void s84(); virtual void s88(); virtual void s8c();
    virtual void s90(); virtual void s94(); virtual void s98(); virtual void s9c();
    virtual void sa0(); virtual void sa4(); virtual void sa8(); virtual void sac();
    virtual void sb0(); virtual void sb4(); virtual void sb8(); virtual void sbc();
    virtual void sc0(); virtual void sc4(); virtual void sc8(); virtual void scc();
    virtual void sd0(); virtual void sd4(); virtual void sd8(); virtual void sdc();
    virtual void se0(); virtual void se4(); virtual void se8(); virtual void sec();
    virtual void sf0(); virtual void sf4(); virtual void sf8(); virtual void sfc();
    virtual void s100(); virtual void s104();
    virtual int isConnected(int a, int b);
};

struct Lock {
    int data[11];
    Lock(int mutex, int flag);
    ~Lock();
};

struct VReplicator;

struct Packet {
    char data[0x12c];
    bool sent;
    Packet(VReplicator* replicator, Peer* peer);
    ~Packet();
    void writeTag(int tag);
    void writeItem(void* item);
};

struct Stamp {
    int a;
    int b;
};

struct Sender {
    void send(Packet* packet, Stamp* stamp, void* item);
};

struct SenderOwner {
    char pad[0x27c];
    struct SenderHost* host;
};

struct SenderHost {
    Sender* getSender();
};

struct Time {
    static double now();
};

extern const double sendInterval;

SenderOwner* findOwner(VReplicator* replicator);

struct VReplicator {
    char pad0[0x108];
    Stamp stamp;
    double lastSendTime;
    char pad118[0x1db4 - 0x118];
    bool enabled;
    char pad1db5[0x1e0c - 0x1db5];
    int mutex;
    char pad1e10[0x1e14 - 0x1e10];
    Peer* peer;
    int address;
    int port;
    void* nextItem();
    bool sendPending();
};

bool VReplicator::sendPending()
{
    if (!enabled)
        return false;
    if (!((PeerSlots*)peer)->isConnected(address, port))
        return false;
    Lock lock(mutex, 0);
    Packet packet(this, peer);
    SenderOwner* owner = findOwner(this);
    if (owner) {
        Sender* sender = owner->host->getSender();
        void* item = nextItem();
        if (item) {
            double t = Time::now();
            if (t > lastSendTime + sendInterval) {
                packet.writeTag(1);
                packet.writeItem(item);
                packet.writeTag(2);
                lastSendTime = t;
            } else {
                item = 0;
            }
        }
        sender->send(&packet, &stamp, item);
    }
    return packet.sent;
}
