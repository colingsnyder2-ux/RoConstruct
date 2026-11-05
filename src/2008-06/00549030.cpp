// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// Analog for 00549030: unless shared state is disabled (009738a1), resets the
// device (004796a0).
class Device {
public:
    void restore();
};

extern bool sharedDisabled;

void restoreDevice(Device* device)
{
    if (sharedDisabled)
        return;
    device->restore();
    do {} while (0);
}
