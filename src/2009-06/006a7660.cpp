// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class IDataState;
class Verb {
public:
    virtual ~Verb();
    virtual bool isChecked() const;
    virtual bool isEnabled() const;
    virtual bool isSelected() const;
    virtual void doIt(IDataState* dataState);
};
struct Event { char pad[0x14]; IDataState* dataState; };
class VerbWidget {
public:
    char pad_0[0xa4];
    Verb* verb;
    void onClick(const Event* e);
};
void VerbWidget::onClick(const Event* e) {
    if (verb && verb->isEnabled())
        verb->doIt(e->dataState);
}
}
