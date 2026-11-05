// from server: 59% by atomic.potato
struct CPropertyGridItemBrickColor
{
    char padding[0x10c];
    int value;
    void initialize(void *, void *);
    void update();
    void setValue(int);
};

void CPropertyGridItemBrickColor::setValue(int value)
{
    this->value = value;
    initialize(0, 0);
    update();
}
