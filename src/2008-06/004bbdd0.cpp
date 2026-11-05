// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-raknet roc_profiled_rakpeer_ratio_6e565fa5f20deb46.cpp

// Candidate translation unit (score above; library headers required).
class ProfiledRakPeerRatio {
private:
    char fieldsBeforeTotal[0x6d8];
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
