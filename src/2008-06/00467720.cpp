// from server: 100% by king_originala
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
