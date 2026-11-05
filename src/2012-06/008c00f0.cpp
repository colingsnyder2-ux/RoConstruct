// from server: 36% by atomic.potato
struct G3D_Sphere {
    char data[36];
    G3D_Sphere();
    G3D_Sphere(const G3D_Sphere&);
};

struct RBX_Clump {
    void* sub_8bfae0(void*, void*);
    void* sub_8c00f0(void*, void*);
};

void* RBX_Clump::sub_8c00f0(void* a, void* b)
{
    G3D_Sphere sphere;
    G3D_Sphere tmp;
    sphere = *(G3D_Sphere*)0;
    tmp = sphere;
    return sub_8bfae0(a, b);
}
