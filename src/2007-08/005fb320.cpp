// from server: 100% by atomic.potato
struct VPartInstance {
    char pad[0x1d8];
    void* field_1d8;
    void sub_573D60();
    void sub_573D80();
};

struct OscillateMotorTool {
    VPartInstance* field_0;
    void setInt(int value);
    void setInt2(int value);
    void setFloat(float value);
    void setFloat2(float value);
    void construct(OscillateMotorTool* p);
};

extern float g_7bcf14;
extern float g_797eb0;

void OscillateMotorTool::construct(OscillateMotorTool* p) {
    p->field_0->sub_573D60();
    p->setInt(7);
    p->setInt2(0xd);
    p->setFloat(g_7bcf14);
    p->setFloat2(g_797eb0);
    p->field_0->sub_573D80();
}
