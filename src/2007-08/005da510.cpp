// from server: 100% by colin
struct VelocityMotor {
    char pad[0xfc];
    int field_fc;
    void sub_5da300(int, int);
    void func();
};

void VelocityMotor::func() {
    sub_5da300(1, field_fc);
}
