// from server: 100% by sophus
// roc 2009-12 00574da0  unit: RBX::RbxParticleEmitter
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Color3
{
    float x, y, z;
};

struct S
{
    Color3 get();
};

Color3 S::get()
{
    Color3 c;
    c.x = *(float *)((char *)this + 0x1e4);
    c.y = *(float *)((char *)this + 0x1e8);
    c.z = *(float *)((char *)this + 0x1ec);
    return c;
}
