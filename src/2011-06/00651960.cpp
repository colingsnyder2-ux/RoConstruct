// from server: 46% by atomic.potato
struct S_func_00651960 {
    float m_value;
    unsigned short m_unit;
    void f(S_func_00651960 *pDst, const S_func_00651960 *pSrc);
};

void S_func_00651960::f(S_func_00651960 *pDst, const S_func_00651960 *pSrc)
{
    pDst->m_value = m_value - pSrc->m_value;
    pDst->m_unit = (unsigned short)(m_unit - pSrc->m_unit);
}
