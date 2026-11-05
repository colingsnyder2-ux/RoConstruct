// from server: 100% by atomic.potato
struct CPatchedControlComboBox {
    char pad[0x10];
    int m_state;
    bool compare(int a, int b);
    int Check();
};

int CPatchedControlComboBox::Check()
{
    if (m_state == 2 && compare(5, 1))
        return 1;
    return 0;
}
