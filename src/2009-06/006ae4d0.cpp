// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
int getCount();
class X {
public:
    char pad[0x7c];
    float rate;
    bool stopped;
    void setValue(float value);
};
void X::setValue(float value)
{
    rate = value / getCount();
    if (value == 0.0f)
        stopped = true;
}
