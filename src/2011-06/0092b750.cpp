// from server: 43% by atomic.potato
extern "C" void __stdcall Ogre_Quaternion_FromRotationMatrix(void *, const void *);

struct S_func_0092b750 {
    float m_x;
    float m_y;
    float m_z;
    float m_w;
    S_func_0092b750 * __cdecl f(void *);
};

S_func_0092b750 *S_func_0092b750::f(void *a1)
{
    static const float value = 1.0f;
    m_x = value;
    m_y = 0.0f;
    m_z = 0.0f;
    m_w = 0.0f;
    Ogre_Quaternion_FromRotationMatrix(this, a1);
    return this;
}
