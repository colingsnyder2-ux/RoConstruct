// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
class ProfiledRakPeerRatio {
private:
    char fieldsBeforeTotal[0xa00];
    unsigned int total;
    char fieldBetweenCounters[4];
    unsigned int selected;

public:
    float ratio() const;
};

float ProfiledRakPeerRatio::ratio() const
{
    if (total > 0)
        return static_cast<float>(selected) / static_cast<float>(total);

    return 0.0f;
}
