// from server: 28% by 41k
struct G3D {
    struct VColor3 {
        struct V {
            struct Value {
                struct FactoryProduct {
                    void* vtbl0;
                    void* vtbl4;
                    char pad[0x10];
                    void* vtbl18;
                    void* vtbl1c;

                    FactoryProduct* construct(unsigned int flags);
                };
            };
        };
    };
};

extern "C" void __stdcall sub_77dba0();
extern "C" void __cdecl sub_75a4e0(void*);

G3D::VColor3::V::Value::FactoryProduct* G3D::VColor3::V::Value::FactoryProduct::construct(unsigned int flags)
{
    vtbl0 = (void*)0x00abae2b;
    vtbl4 = (void*)0x00abae2b;
    vtbl18 = (void*)0x00abae2b;
    vtbl1c = (void*)0x00abae2b;
    sub_77dba0();
    if (flags & 1) {
        sub_75a4e0(this);
    }
    return this;
}
