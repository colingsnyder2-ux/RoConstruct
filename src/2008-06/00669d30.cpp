// from server: 100% by king_originala
struct Part
{
    unsigned char padding[0xb8];
    int state[1];
};

struct Frame
{
    unsigned char data[0x30];
    Frame();
};

extern bool __cdecl compatible(Part*, Part*, int, int);
extern void __cdecl getFrames(Part*, Part*, int, int, Frame*, Frame*);

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct JointBase
{
    unsigned char data[0x84];
    JointBase(Part*, Part*, const Frame&, const Frame&);
    virtual void type();
};

struct Joint : JointBase
{
    Joint(Part*, Part*, const Frame&, const Frame&);
    virtual void type();
};

__forceinline Joint::Joint(Part* a, Part* b, const Frame& x, const Frame& y)
    : JointBase(a, b, x, y)
{
}

Joint* __cdecl func_00669d30(Part* a, Part* b, int i, int j)
{
    int left = a->state[i];
    int right = b->state[j];

    if (left == 3)
    {
        if (right != 4)
            return 0;
    }
    else
    {
        if (left != 4 || right != 3)
            return 0;
    }

    if (!compatible(a, b, i, j))
        return 0;

    Frame x;
    Frame y;
    getFrames(a, b, i, j, &x, &y);
    return new Joint(a, b, x, y);
}
