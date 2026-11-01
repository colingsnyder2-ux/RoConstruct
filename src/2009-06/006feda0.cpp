// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00671f90  unit: RBX::AdornRbxGfx  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671f90
//
// 00671f90  56                   push esi
// 00671f91  8bf1                 mov esi, ecx
// 00671f93  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00671f96  8b01                 mov eax, dword ptr [ecx]
// 00671f98  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 00671f9e  ffd2                 call edx
// 00671fa0  8b4604               mov eax, dword ptr [esi + 4]
// 00671fa3  8b4804               mov ecx, dword ptr [eax + 4]
// 00671fa6  8b11                 mov edx, dword ptr [ecx]
// 00671fa8  8b82f0000000         mov eax, dword ptr [edx + 0xf0]
// 00671fae  ffd0                 call eax
// 00671fb0  c70558da970000000000 mov dword ptr [0x97da58], 0
// 00671fba  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 00671fc0  e80bb40000           call 0x67d3d0
// 00671fc5  8bce                 mov ecx, esi
// 00671fc7  5e                   pop esi
// 00671fc8  e953feffff           jmp 0x671e20

struct DeviceA;
struct DeviceB;

struct TableA {
    void* unused[93];
    void (__thiscall *invoke)(DeviceA*);
};

struct TableB {
    void* unused[73];
    void (__thiscall *invoke)(DeviceB*);
};

struct DeviceA {
    TableA* table;
};

struct DeviceB {
    TableB* table;
};

struct Holder {
    char unused[16];
    DeviceB* device;
};

struct Resource {
    void release();
};

extern int globalState;

struct S {
    char unused0[4];
    Holder* holder;
    char unused1[40];
    DeviceA* device;
    char unused2[100];
    Resource* resource;

    void f();
    void finish();
};

void S::f()
{
    device->table->invoke(device);
    holder->device->table->invoke(holder->device);
    globalState = 0;
    resource->release();
    finish();
}
