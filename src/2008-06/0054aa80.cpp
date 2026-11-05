// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Destructor analog for 0054aa80: members at +0x30 (ref, 00502a70), +0x24 and
// +0xc (00643  3e0), +0x18 and the base (005516d0) are destroyed in reverse order.
class Chunk { public: ~Chunk(); char data[0x0c]; };
class Index { public: ~Index(); char data[0x0c]; };
class Ref { public: ~Ref(); void* pointer; };

class Level : public Chunk {
public:
    ~Level();
    Index first;
    Chunk second;
    Index third;
    Ref owner;
};

Level::~Level()
{
}
