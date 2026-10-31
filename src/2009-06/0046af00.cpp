// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00468a60  unit: DxUserInput  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00468a60
//
// 00468a60  6aff                 push -1
// 00468a62  68f8367c00           push 0x7c36f8
// 00468a67  64a100000000         mov eax, dword ptr fs:[0]
// 00468a6d  50                   push eax
// 00468a6e  64892500000000       mov dword ptr fs:[0], esp
// 00468a75  83ec14               sub esp, 0x14
// 00468a78  53                   push ebx
// 00468a79  55                   push ebp
// 00468a7a  56                   push esi
// 00468a7b  57                   push edi
// 00468a7c  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00468a80  d94704               fld dword ptr [edi + 4]
// 00468a83  8bf1                 mov esi, ecx
// 00468a85  e8668d2300           call 0x6a17f0
// 00468a8a  d907                 fld dword ptr [edi]
// 00468a8c  8bd8                 mov ebx, eax
// 00468a8e  e85d8d2300           call 0x6a17f0
// 00468a93  8be8                 mov ebp, eax
// 00468a95  8b866c010000         mov eax, dword ptr [esi + 0x16c]
// 00468a9b  50                   push eax
// 00468a9c  8d4c2414             lea ecx, [esp + 0x14]
// 00468aa0  e849892300           call 0x6a13ee
// 00468aa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00468aa9  8b425c               mov eax, dword ptr [edx + 0x5c]
// 00468aac  53                   push ebx
// 00468aad  55                   push ebp
// 00468aae  8d4c2418             lea ecx, [esp + 0x18]
// 00468ab2  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00468aba  ffd0                 call eax
// 00468abc  8b8e6c010000         mov ecx, dword ptr [esi + 0x16c]
// 00468ac2  85c0                 test eax, eax
// 00468ac4  0f95c3               setne bl
// 00468ac7  e8d6892300           call 0x6a14a2
// 00468acc  85c0                 test eax, eax
// 00468ace  0f95c0               setne al
// 00468ad1  84db                 test bl, bl
// 00468ad3  740b                 je 0x468ae0
// 00468ad5  84c0                 test al, al
// 00468ad7  7407                 je 0x468ae0
// 00468ad9  b801000000           mov eax, 1
// 00468ade  eb02                 jmp 0x468ae2
// 00468ae0  33c0                 xor eax, eax
// 00468ae2  57                   push edi
// 00468ae3  8bce                 mov ecx, esi
// 00468ae5  888690010000         mov byte ptr [esi + 0x190], al
// 00468aeb  e830faffff           call 0x468520
// 00468af0  8d4c2410             lea ecx, [esp + 0x10]
// 00468af4  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00468afc  e8e7882300           call 0x6a13e8
// 00468b01  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00468b05  5f                   pop edi
// 00468b06  5e                   pop esi
// 00468b07  5d                   pop ebp
// 00468b08  5b                   pop ebx
// 00468b09  64890d00000000       mov dword ptr fs:[0], ecx
// 00468b10  83c420               add esp, 0x20
// 00468b13  c20400               ret 4

struct Point {
    float x;
    float y;
};

struct Device {
    int available();
};

struct ScopedDevice;

struct DeviceTable {
    char pad0[92];
    int (__thiscall *setPosition)(ScopedDevice *, int, int);
};

struct ScopedDevice {
    DeviceTable *table;
    char pad0[16];

    ScopedDevice(Device *);
    ~ScopedDevice();
};

struct S_func_00468a60 {
    char pad0[364];
    Device *device;
    char pad1[32];
    bool active;

    void update(const Point *);
    void f(const Point *);
};

void S_func_00468a60::f(const Point *point)
{
    int y = (int)point->y;
    int x = (int)point->x;
    ScopedDevice scoped(device);
    bool positioned = scoped.table->setPosition(&scoped, x, y) != 0;
    bool available = device->available() != 0;
    active = positioned && available;
    update(point);
}
