// from server: 100% by why2
struct RBX_VelocityMotor {
    char pad[0xac];
    void* ptr;
    float get() const;
};

float RBX_VelocityMotor::get() const
{
    return *(float*)((char*)ptr + 0xa4);
}
