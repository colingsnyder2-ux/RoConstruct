// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class headers were provided. The target is a compiler-generated
// vector-deleting-destructor adjustor thunk (this -= 20; jmp real dtor).
// It has no source-level name, so I reproduce the class layout that makes MSVC
// emit it: a primary base of 20 bytes, and a second base at offset 20 that
// declares the virtual destructor, overridden by SoundServiceStatsItem.

struct StatsItemPrimaryBase {
    virtual void primaryVirtual();
    int pad[4];                      // vptr (4) + 16 = 20 bytes
};

struct StatsItemSecondBase {         // lives at offset 20
    virtual ~StatsItemSecondBase();
    int value;
};

struct SoundServiceStatsItem : public StatsItemPrimaryBase, public StatsItemSecondBase {
    SoundServiceStatsItem();
    virtual ~SoundServiceStatsItem();
    virtual void primaryVirtual();
    int extra;
};

void StatsItemPrimaryBase::primaryVirtual() {}
StatsItemSecondBase::~StatsItemSecondBase() {}
SoundServiceStatsItem::SoundServiceStatsItem() : extra(0) {}
SoundServiceStatsItem::~SoundServiceStatsItem() {}
void SoundServiceStatsItem::primaryVirtual() {}

// Forces the vftable for the second base, and with it the
// `vector deleting destructor'`adjustor{20}' thunk, to be emitted.
SoundServiceStatsItem* createSoundServiceStatsItem()
{
    return new SoundServiceStatsItem();
}
