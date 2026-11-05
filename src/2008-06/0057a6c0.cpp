// from server: 100% by coldek
// roc 2008-06 0057a6c0  unit: RBX::VDataModel::?$BoundFuncDesc  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057a6c0
//
// 0057a6c0  64a100000000         mov eax, dword ptr fs:[0]
// 0057a6c6  6aff                 push -1
// 0057a6c8  68c80a7d00           push 0x7d0ac8
// 0057a6cd  50                   push eax
// 0057a6ce  64892500000000       mov dword ptr fs:[0], esp
// 0057a6d5  83ec10               sub esp, 0x10
// 0057a6d8  53                   push ebx
// 0057a6d9  56                   push esi
// 0057a6da  8bf1                 mov esi, ecx
// 0057a6dc  33db                 xor ebx, ebx
// 0057a6de  389e59020000         cmp byte ptr [esi + 0x259], bl
// 0057a6e4  0f84b2000000         je 0x57a79c
// 0057a6ea  ff8650020000         inc dword ptr [esi + 0x250]
// 0057a6f0  57                   push edi
// 0057a6f1  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0057a6f5  3bfb                 cmp edi, ebx
// 0057a6f7  0f849e000000         je 0x57a79b
// 0057a6fd  8b8604020000         mov eax, dword ptr [esi + 0x204]
// 0057a703  8d88a0010000         lea ecx, [eax + 0x1a0]
// 0057a709  8b01                 mov eax, dword ptr [ecx]
// 0057a70b  8b500c               mov edx, dword ptr [eax + 0xc]
// 0057a70e  57                   push edi
// 0057a70f  ffd2                 call edx
// 0057a711  8bce                 mov ecx, esi
// 0057a713  e8a88df3ff           call 0x4b34c0
// 0057a718  3bc3                 cmp eax, ebx
// 0057a71a  740c                 je 0x57a728
// 0057a71c  57                   push edi
// 0057a71d  8d8838010000         lea ecx, [eax + 0x138]
// 0057a723  e8382c0600           call 0x5dd360
// 0057a728  389e30020000         cmp byte ptr [esi + 0x230], bl
// 0057a72e  7517                 jne 0x57a747
// 0057a730  8b8604020000         mov eax, dword ptr [esi + 0x204]
// 0057a736  8b80b0030000         mov eax, dword ptr [eax + 0x3b0]
// 0057a73c  8d4804               lea ecx, [eax + 4]
// 0057a73f  8b01                 mov eax, dword ptr [ecx]
// 0057a741  8b500c               mov edx, dword ptr [eax + 0xc]
// 0057a744  57                   push edi
// 0057a745  ffd2                 call edx
// 0057a747  381d614e9700         cmp byte ptr [0x974e61], bl
// 0057a74d  744c                 je 0x57a79b
// 0057a74f  381d624e9700         cmp byte ptr [0x974e62], bl
// 0057a755  7444                 je 0x57a79b
// 0057a757  895c2410             mov dword ptr [esp + 0x10], ebx
// 0057a75b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0057a75f  895c240c             mov dword ptr [esp + 0xc], ebx
// 0057a763  885c2418             mov byte ptr [esp + 0x18], bl
// 0057a767  c644241901           mov byte ptr [esp + 0x19], 1
// 0057a76c  8d44240c             lea eax, [esp + 0xc]
// 0057a770  50                   push eax
// 0057a771  8bce                 mov ecx, esi
// 0057a773  895c2428             mov dword ptr [esp + 0x28], ebx
// 0057a777  e8a4e4ffff           call 0x578c20
// 0057a77c  57                   push edi
// 0057a77d  8d4c2410             lea ecx, [esp + 0x10]
// 0057a781  e80ae10800           call 0x608890
// 0057a786  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0057a78a  51                   push ecx
// 0057a78b  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0057a793  e888d5f8ff           call 0x507d20
// 0057a798  83c404               add esp, 4
// 0057a79b  5f                   pop edi
// 0057a79c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057a7a0  5e                   pop esi
// 0057a7a1  5b                   pop ebx
// 0057a7a2  64890d00000000       mov dword ptr fs:[0], ecx
// 0057a7a9  83c41c               add esp, 0x1c
// 0057a7ac  c20400               ret 4

void __cdecl alignedFree(void*);

extern bool flag1;
extern bool flag2;

struct Dispatch
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void notify(void*);
};

struct Secondary
{
    int padding;
    Dispatch dispatch;
};

struct Owner
{
    char padding0[0x1a0];
    Dispatch dispatch;
    char padding1[0x20c];
    Secondary* secondary;
};

struct Message
{
    void notify(void*);
};

struct Buffer
{
    void* data;
    int size;
    int capacity;
    bool flag;
    bool enabled;

    Buffer()
    {
        size = 0;
        capacity = 0;
        data = 0;
        flag = false;
        enabled = true;
    }

    ~Buffer() { alignedFree(data); }

    void notify(void*);
};

struct S
{
    char padding0[0x204];
    Owner* owner;
    char padding1[0x28];
    bool disabled;
    char padding2[0x1f];
    int count;
    char padding3[5];
    bool active;

    void* getObject();
    Owner* getOwner() const { return owner; }
    void collect(Buffer&);
    void notify(void*);
};

void S::notify(void* argument)
{
    if (active)
    {
        ++count;
        if (argument)
        {
            owner->dispatch.notify(argument);

            void* object = getObject();
            if (object)
                reinterpret_cast<Message*>(
                    static_cast<char*>(object) + 0x138)->notify(argument);

            if (!disabled)
                {
                    getOwner()->secondary->dispatch.notify(argument);
                }

            if (flag1 && flag2)
            {
                Buffer buffer;
                collect(buffer);
                buffer.notify(argument);
            }
        }
    }
}
