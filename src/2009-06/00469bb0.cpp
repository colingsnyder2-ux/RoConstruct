// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00467720  unit: DxUserInput  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00467720
//
// 00467720  56                   push esi
// 00467721  8bf1                 mov esi, ecx
// 00467723  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 00467729  8b08                 mov ecx, dword ptr [eax]
// 0046772b  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0046772e  50                   push eax
// 0046772f  ffd2                 call edx
// 00467731  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 00467737  8b9670010000         mov edx, dword ptr [esi + 0x170]
// 0046773d  8b08                 mov ecx, dword ptr [eax]
// 0046773f  6a05                 push 5
// 00467741  52                   push edx
// 00467742  50                   push eax
// 00467743  8b4134               mov eax, dword ptr [ecx + 0x34]
// 00467746  ffd0                 call eax
// 00467748  85c0                 test eax, eax
// 0046774a  7519                 jne 0x467765
// 0046774c  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 00467752  8b08                 mov ecx, dword ptr [eax]
// 00467754  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00467757  50                   push eax
// 00467758  ffd2                 call edx
// 0046775a  85c0                 test eax, eax
// 0046775c  7c07                 jl 0x467765
// 0046775e  c6869301000001       mov byte ptr [esi + 0x193], 1
// 00467765  5e                   pop esi
// 00467766  c3                   ret 

struct Device;

struct DeviceTable {
    void* reserved0[7];
    long (__stdcall *acquire)(Device*);
    long (__stdcall *unacquire)(Device*);
    void* reserved1[4];
    long (__stdcall *setCooperativeLevel)(Device*, void*, unsigned long);
};

struct Device {
    DeviceTable* table;
};

struct DxUserInput {
    char reserved0[0x170];
    void* window;
    char reserved1[8];
    Device* device;
    char reserved2[0x13];
    bool acquired;

    void configure();
};

void DxUserInput::configure()
{
    device->table->unacquire(device);
    if (device->table->setCooperativeLevel(device, window, 5) == 0) {
        if (device->table->acquire(device) >= 0)
            acquired = true;
    }
}
