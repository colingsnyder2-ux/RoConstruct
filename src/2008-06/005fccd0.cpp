// from server: 100% by king_originala
struct Base {
    unsigned long layout[0x148 / 4];
    Base();
    ~Base();
};

struct Word {
    unsigned long value;
    Word(unsigned long v);
    ~Word();
};

inline Word::Word(unsigned long v) : value(v) {
}

struct Tail {
    Tail();
    ~Tail();
};

struct S : Base {
    unsigned long first;
    Word second;
    Tail tail;
    S();
};

S::S()
    : first((
        layout[0x000 / 4] = 0x0084164c,
        layout[0x010 / 4] = 0x0084163c,
        layout[0x014 / 4] = 0x00841634,
        layout[0x020 / 4] = 0x0084162c,
        layout[0x024 / 4] = 0x0084161c,
        layout[0x044 / 4] = 0x0084160c,
        layout[0x064 / 4] = 0x008415fc,
        layout[0x084 / 4] = 0x008415ec,
        layout[0x0a4 / 4] = 0x008415dc,
        layout[0x0c4 / 4] = 0x008415cc,
        layout[0x130 / 4] = 0x008415c4,
        0)),
      second(0),
      tail() {
}
