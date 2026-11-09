// from server: 100% by king_originala
struct Ogre_Vector3 {
    float x;
    float y;
    float z;
};

struct Ogre_ShadowCaster;

extern float (__thiscall *getExtrusionDistance)(
    const Ogre_ShadowCaster*, const Ogre_Vector3&, const void*);

struct Ogre_RbxSubEntity {
    char pad0[0x10];
    float m_a;
    char pad1[0xc];
    float m_b;
    char pad2[0xc];
    float m_c;
    float f(const void* light);
};

float Ogre_RbxSubEntity::f(const void* light)
{
    Ogre_Vector3 v;
    v.x = m_a;
    v.y = m_b;
    v.z = m_c;
    return getExtrusionDistance((const Ogre_ShadowCaster*)this, v, light);
}
