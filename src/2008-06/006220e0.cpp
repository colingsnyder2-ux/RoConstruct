// from server: 54% by king_originala
struct S {
    unsigned char reserved[12];
    unsigned int value;
    unsigned int auxiliary;
    unsigned char released;

    S(S& source);
};

S::S(S& source)
{
    value = source.value;
    auxiliary = source.auxiliary;
    released = source.released;
    source.released = 1;
}
