// from server: 34% by atomic.potato
struct DxUserInput
{
    float m_x;
    float m_y;
    void Divide(DxUserInput* result, const DxUserInput* divisor);
};

void DxUserInput::Divide(DxUserInput* result, const DxUserInput* divisor)
{
    result->m_x = m_x / divisor->m_x;
    result->m_y = m_y / divisor->m_y;
}
