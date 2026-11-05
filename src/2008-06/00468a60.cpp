// from server: 100% by king_originala
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
