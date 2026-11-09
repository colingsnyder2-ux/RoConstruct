// from server: 100% by king_originala
struct Device;
struct Property {
    unsigned long size;
    unsigned long headerSize;
    unsigned long object;
    unsigned long how;
    unsigned long value;
};

struct Input;
struct InputTable {
    void* reserved[3];
    long (__stdcall *createDevice)(Input*, const void*, Device**, void*);
};
struct Input {
    InputTable* table;
};

struct DeviceTable {
    void* reserved0[6];
    long (__stdcall *setProperty)(Device*, unsigned long, const Property*);
    void* reserved1[4];
    long (__stdcall *setDataFormat)(Device*, const void*);
};
struct Device {
    DeviceTable* table;
};

extern "C" __declspec(noreturn) void __stdcall checkError(long);

struct S {
    unsigned char reserved[0x174];
    Input* input;
    Device* device;
    void f();
};

void S::f()
{
    long result = input->table->createDevice(
        input, (const void*)0x85012c, &device, 0);
    if (result < 0)
        checkError(result);

    result = device->table->setDataFormat(device, (const void*)0x84ff0c);
    if (result < 0)
        checkError(result);

    Device* d = device;
    Property property;
    property.size = 20;
    property.headerSize = 16;
    property.object = 0;
    property.how = 0;
    property.value = 0x800;

    result = d->table->setProperty(d, 1, &property);
    if (result < 0)
        checkError(result);
}
