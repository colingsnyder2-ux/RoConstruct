// from server: 21% by atomic.potato
struct RBX_VehicleSeat {
    char pad[0x18];
    int field_18;
};

extern "C" void __stdcall sub_41bfa0();
extern "C" void __stdcall sub_6a3580(void* self, int a, int b, int c, int d, int e, int f);

RBX_VehicleSeat* __stdcall sub_6a3fa0(RBX_VehicleSeat* self, int a, int b, int c, int d, int e, int f, int g) {
    int local = 0;
    sub_41bfa0();
    sub_6a3580(self, a, b, c, d, e, f);
    return self;
}
