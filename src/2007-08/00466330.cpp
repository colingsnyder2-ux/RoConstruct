// from server: 100% by colin
struct DxUserInput {
    unsigned short w0;
    unsigned short w2;
    int d4;
    int d8;
    int dC;
    int d10;
    DxUserInput* init();
};

DxUserInput* DxUserInput::init()
{
    d4 = 0;
    d10 = 0;
    w0 = 0;
    w2 = 0x4e4;
    d8 = 0;
    dC = 0;
    return this;
}
