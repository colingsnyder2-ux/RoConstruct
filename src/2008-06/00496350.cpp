// from server: 100% by atomic.potato
struct Name;
struct Guid {
    static const Name& getLocalScope();
};

struct Players {
    bool isLocalPlayer() const;
};

bool Players::isLocalPlayer() const {
    return &Guid::getLocalScope() == (const Name*)this;
}
