// from server: 100% by king_originala
struct Base
{
    char padding[84];

    Base();
    virtual ~Base();
};

struct Member
{
    Member();
    ~Member();
};

struct CPatchedControlComboBox : Base
{
    Member member;

    CPatchedControlComboBox();
    virtual ~CPatchedControlComboBox();
};

CPatchedControlComboBox::CPatchedControlComboBox()
    : Base(), member()
{
}
