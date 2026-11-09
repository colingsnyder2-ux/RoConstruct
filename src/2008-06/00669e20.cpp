// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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

    if ((left == 2 || right == 2) && compatible(a,b,i,j)) {

    Frame x;
    Frame y;
    getFrames(a, b, i, j, &x, &y);
    return new Joint(a, b, x, y);
    }
    return 0;
}
