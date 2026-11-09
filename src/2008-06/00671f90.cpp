// from server: 100% by king_originala
struct DeviceA;
struct DeviceB;

struct TableA {
    void* unused[93];
    void (__thiscall *invoke)(DeviceA*);
};

struct TableB {
    void* unused[60];
    void (__thiscall *invoke)(DeviceB*);
};

struct DeviceA {
    TableA* table;
};

struct DeviceB {
    TableB* table;
};

struct Holder {
    char unused[4];
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
