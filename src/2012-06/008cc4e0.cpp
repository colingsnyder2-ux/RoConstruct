// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct BodyForce
{
    char pad[0x140];
    float force[3];
    void getForce(int, int, int, float* out, int) const;
};
void BodyForce::getForce(int, int, int, float* out, int) const
{
    out[0] = force[0];
    out[1] = force[1];
    out[2] = force[2];
}
