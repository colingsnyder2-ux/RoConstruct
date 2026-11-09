// from server: 85% by atomic.potato
struct CSHA1 {
    unsigned int value[2];

    int __cdecl f(unsigned int a, unsigned int b);
};

int CSHA1::f(unsigned int a, unsigned int b)
{
    unsigned int oldValue = value[0];
    value[0] = oldValue + b;

    if (value[0] < oldValue)
        return 0;

    if (a > 1) {
        unsigned int i = 1;
        do {
            if (++value[i] == 0)
                ++i;
            else
                break;
        } while (i < a);
    }

    return 1;
}
