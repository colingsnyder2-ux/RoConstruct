// from server: 100% by nuck16
// from server: 80% by coldek
// roc 2008-06 00656430  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00656430
//

// from server: 78% by colin
// roc 2008-06 00656430  unit: RBX::ScoreHud  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00656430
//

struct ScoreHud {
    int getState();
    void setA(int, int);
    void setB(int);
    void dispatch(int);
};

void ScoreHud::dispatch(int arg)
{
    switch (getState())
    {
    case 1:
        setB(arg);
        break;
    case 2:
        setA(arg, 2);
        break;
    case 3:
        setA(arg, 3);
        break;
    case 0:
        setB(arg);
        break;
    }
}
