// from server: 93% by Intel
struct BodyForce
{
    void getForce(float* out, int, int, int) const;
};

void BodyForce::getForce(float* out, int, int, int) const
{
    out[0] = *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x140);
    out[1] = *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x144);
    out[2] = *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x148);
}
