// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base
{
    unsigned int words[83];
    Base();
    ~Base();
};

struct Tree
{
    unsigned char storage[32];
    Tree();
    ~Tree();
};

struct Tail
{
    void** anchor;
    unsigned int unused[3];
    unsigned int count;
    unsigned int first;
    unsigned int second;
    unsigned int third;

    Tail();
};

__forceinline Tail::Tail()
    : anchor(new void*(this)),
      count(0),
      first(0),
      second(0),
      third(0)
{
}

struct ImageKeyButton : Base
{
    unsigned int field14c;
    unsigned int field150;
    Tree tree;
    Tail tail;
    float value;

    ImageKeyButton();
};

ImageKeyButton::ImageKeyButton()
    : Base(),
      field14c((
          words[0] = 0x84bb84,
          words[4] = 0x84bb78,
          words[5] = 0x84bb70,
          words[8] = 0x84bb68,
          words[9] = 0x84bb58,
          words[17] = 0x84bb48,
          words[25] = 0x84bb38,
          words[33] = 0x84bb28,
          words[41] = 0x84bb18,
          words[49] = 0x84bb08,
          words[76] = 0x84bb00,
          words[81] = 0x84baf4,
          words[82] = 0x84bae8,
          0)),
      field150(0),
      tree(),
      tail(),
      value(0.0f)
{
}
