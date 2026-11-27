// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct PropDesc { int dummy; };
extern PropDesc prop_a, prop_b, prop_c;
struct TextBox {
    char pad[0x240];
    bool flag;
    void raisePropertyChanged(const PropDesc&);
    void set(bool);
};
void TextBox::set(bool value)
{
    if (flag != value) {
        flag = value;
        raisePropertyChanged(prop_a);
        raisePropertyChanged(prop_b);
        raisePropertyChanged(prop_c);
    }
}
