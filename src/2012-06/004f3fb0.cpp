// from server: 38% by Intel
struct Ogre_RbxMeshPartAdapter {
    char pad0[76];
    float m_values[2];

    void __thiscall func_004f3fb0(float arg1, float arg2);
};

struct Interface {
    virtual void __stdcall method(float a, float b) = 0;
};

struct Object {
    Interface* vftable;
};

void __thiscall Ogre_RbxMeshPartAdapter::func_004f3fb0(float arg1, float arg2)
{
    float val1 = -arg1;
    float val2 = arg2;
    Object* obj = reinterpret_cast<Object*>(this);
    obj->vftable->method(val1, val2);
    obj->vftable->method(arg1, val2);
    m_values[0] = val1;
    m_values[1] = arg1;
}
