// from server: 46% by atomic.potato
extern "C" void Ogre_Quaternion_FromRotationMatrix(void *, const void *);

struct S_func_00484e00
{
    float m_w;
    float m_x;
    float m_y;
    float m_z;
    void *m_matrix;
    S_func_00484e00 * __cdecl f(void *);
};

S_func_00484e00 *S_func_00484e00::f(void *arg)
{
    m_w = *(const float *)0x9aea18;
    m_x = 0.0f;
    m_y = 0.0f;
    m_z = 0.0f;
    Ogre_Quaternion_FromRotationMatrix(this, arg);
    return this;
}
