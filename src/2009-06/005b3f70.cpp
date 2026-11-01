// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
class DoubleArray {
public:
    void resize(unsigned int n, double value);
    void resize(unsigned int n);
private:
    void resizeImpl(unsigned int n, double value, bool initialize);
    int capacity;
    unsigned int count;
    double* data;
};
void DoubleArray::resize(unsigned int n, double value)
{
    resizeImpl(n, value, true);
}
