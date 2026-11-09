// from server: 25% by Intel
struct VCustomEventReceiver {
    struct EventDesc {
        void setValue(float value);
    };
};

float g_clampValue = 0.0f;

void VCustomEventReceiver::EventDesc::setValue(float value) {
    float zero = 0.0f;
    if (zero >= value) {
        float clamp = g_clampValue;
        if (value < clamp) {
            value = clamp;
        }
    } else {
        value = zero;
    }
    *(float*)((char*)this + 0x8C) = value;
}
