// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Desc;
extern Desc prop_Text;
struct Data { char pad[0x54]; std::string text; };
class Inst {
public:
    void raisePropertyChanged(const Desc& d);
};
class Label : public Inst {
public:
    char pad[0x118];
    Data* data;
    void setText(const std::string& s);
};
void Label::setText(const std::string& s)
{
    if (s != data->text) {
        data->text = s;
        raisePropertyChanged(prop_Text);
    }
}
