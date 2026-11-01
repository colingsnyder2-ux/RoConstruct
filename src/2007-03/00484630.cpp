// from server: 100% by tester
extern "C" void (__stdcall *glEnable)(unsigned int);

struct G3D_VertexAndPixelShader {
    char pad0[0x18];
    unsigned int enable;
    char pad1[0x1c];
    unsigned int arg;
    void apply();
    void setup(unsigned int, unsigned int);
};

void G3D_VertexAndPixelShader::apply()
{
    glEnable(this->enable);
    this->setup(this->enable, this->arg);
}
