// from server: 100% by king_originala
extern unsigned char property;

struct MotorData
{
    void set(int index, int value);
};

struct S
{
    unsigned char padding[0x150];
    MotorData* motor;

    void notify(const void* descriptor);
    void setValue(int value);
};

void S::setValue(int value)
{
    motor->set(0, value);
    notify(&property);
}
