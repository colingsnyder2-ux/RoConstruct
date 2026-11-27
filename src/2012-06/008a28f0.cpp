// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct DescribedBase { int x; };
struct A { char pad[0x1c]; };
struct B { int y; };
struct Player : A, DescribedBase, B {
    void set(bool);
};
struct GetSetImpl {
    char pad[8];
    void (Player::*setter)(bool);
    virtual void setValue(DescribedBase* object, const bool& value) const;
};
void GetSetImpl::setValue(DescribedBase* object, const bool& value) const
{
    (static_cast<Player*>(object)->*setter)(value);
}
