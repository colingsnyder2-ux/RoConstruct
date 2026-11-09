// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_dxinputcentervector98f9a346a508877e.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector2.h>
#include <G3D/Rect2D.h>
typedef G3D::Vector2 Vec2;typedef G3D::Rect2D Rect;
inline Vec2 center(const Rect& r){return Vec2(r.x1()+r.x0(),r.y1()+r.y0())*0.5f;}
struct Device;

struct DeviceTable
{
    void *reserved0[7];
    int (__stdcall *acquire)(Device *);
    int (__stdcall *unacquire)(Device *);
    void *reserved1[4];
    int (__stdcall *setCooperativeLevel)(Device *, void *, unsigned long);
};

struct Device
{
    DeviceTable *table;
};

extern Vec2 __cdecl adjust(const Vec2 &, int);

struct DxUserInput
{
    char reserved0[0x59];
    unsigned char flag;
    char reserved1[6];
    Vec2 delta;
    char reserved2[0x108];
    void *window;
    char reserved3[4];
    Device *device;
    char reserved4[0x16];
    unsigned char active;

    Rect bounds();
    void update(const Vec2 &);
};

void DxUserInput::update(const Vec2 &point)
{
    device->table->unacquire(device);

    if (device->table->setCooperativeLevel(device, window, 5) != 0)
        return;

    if (device->table->acquire(device) != 0)
        return;

    delta = adjust(point-center(bounds()), -10);
    active = 1;
    flag = 0;
}
