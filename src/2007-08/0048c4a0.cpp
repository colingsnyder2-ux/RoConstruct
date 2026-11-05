// from server: 20% by colin
extern "C" void* __cdecl malloc(unsigned int size);

struct RBXName {
    static const RBXName& declare(const char* name);
};

struct ICreator {
    virtual ~ICreator();
    virtual void* create() const;
};

struct Creator : public ICreator {
    void* create() const;
    const RBXName& getClassName() const;
    Creator();
    ~Creator();
};

struct FactoryProduct {
    Creator* creator;
    void construct(Creator* c);
};

void* Creator::create() const {
    return 0;
}

const RBXName& Creator::getClassName() const {
    static RBXName n;
    return n;
}

Creator::Creator() {
    void* mem = malloc(0xf0);
    if (mem) {
        // construct something at mem
    }
    this->create();
}

Creator::~Creator() {
}

void FactoryProduct::construct(Creator* c) {
    creator = c;
}
