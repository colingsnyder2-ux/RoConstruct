// from server: 68% by atomic.potato
struct S
{
    int value(int *p);
    int *items;
    int count;
    int *unused;
    int *unused2;
    int *unused3;
    int *unused4;
    int *unused5;
    int *unused6;
    int *unused7;
    int *unused8;
    int *unused9;
    int *unused10;
    int *unused11;
    int *unused12;
    int *unused13;
    int *unused14;
    int *unused15;
    int *unused16;
    int *unused17;
    int *unused18;
    int *unused19;
    int *unused20;
    int *unused21;
    int *unused22;
    int *unused23;
    int *unused24;
    int *unused25;
    int *unused26;
    int *unused27;
    int *unused28;
    int *unused29;
    int *unused30;
    int *unused31;
    int *unused32;
    int *unused33;
    int *unused34;
    int *unused35;
    int *unused36;
    int *unused37;
};

int S::value(int *p)
{
    int index;

    if (this == (S *)p[4])
        index = p[6];
    else
        index = p[7];

    ++index;
    if (index >= (int)(this->count))
        return 0;

    return this->items[index];
}
