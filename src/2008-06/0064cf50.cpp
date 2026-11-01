// from server: 100% by king_originala
struct Stage {
    virtual ~Stage();
};

struct StageOwner {
    unsigned int reserved0;
    Stage* owned;
    unsigned int reserved1;
    ~StageOwner();
};

inline StageOwner::~StageOwner()
{
    if (owned)
        delete owned;
}

struct Collection {
    ~Collection();
};

struct ClumpStage : StageOwner {
    Collection collection;
    virtual ~ClumpStage();
};

ClumpStage::~ClumpStage()
{
}
