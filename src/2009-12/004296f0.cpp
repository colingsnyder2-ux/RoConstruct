// from server: 56% by atomic.potato
struct CPatchedControlComboBox
{
    int value;
    void *fieldF0;

    void f(int);
};

extern "C" void G1_func_007e52a0(void *);
extern "C" void G1_func_007f3e30(CPatchedControlComboBox *);

void CPatchedControlComboBox::f(int value)
{
    if (value == 0)
        G1_func_007e52a0(fieldF0);
    G1_func_007f3e30(this);
}
