// from server: 100% by king_originala
struct Resource {
    virtual ~Resource();
};

struct Owner {
    Resource* pointer;
    ~Owner();
};

__forceinline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

struct StageData {
    unsigned char data[32];
    ~StageData();
};

struct TreeStage {
    virtual ~TreeStage();

    unsigned int reserved;
    Owner owner;
    unsigned char padding[12];
    StageData first;
    StageData second;
    StageData third;
};

TreeStage::~TreeStage()
{
}
