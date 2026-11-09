// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
class Handle {
public:
    int getId() const;
    bool operator==(const Handle& other) const;
private:
    int kind;
    int id;
};
bool Handle::operator==(const Handle& other) const
{
    return getId() == other.getId();
}
