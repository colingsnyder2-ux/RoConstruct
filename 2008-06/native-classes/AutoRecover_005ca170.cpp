// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The target is a compiler-generated
// adjustor thunk (this -= 16, then jump to the real vector deleting destructor).
// To make MSVC emit it, SoundServiceStatsItem needs a secondary polymorphic base
// at offset 16 whose virtual destructor it overrides. The layout below is a guess.

struct SoundStatsPrimaryBase {
    virtual ~SoundStatsPrimaryBase() {}
    int pad[3]; // INFERRED: fills the primary base to 16 bytes so the second base sits at +16
};

struct SoundStatsSecondaryBase {
    virtual ~SoundStatsSecondaryBase() {}
};

class SoundServiceStatsItem : public SoundStatsPrimaryBase, public SoundStatsSecondaryBase {
public:
    SoundServiceStatsItem();
    virtual ~SoundServiceStatsItem();
    int value; // INFERRED
};

// Out-of-line definitions force the vtable and the destructor thunks to be emitted.
SoundServiceStatsItem::SoundServiceStatsItem()
    : value(0)
{
}

SoundServiceStatsItem::~SoundServiceStatsItem()
{
}
