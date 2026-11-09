// from server: 100% by king_originala
struct S {
    unsigned char padding[8];
    unsigned int offset;
    double get(void* object);
};

double S::get(void* object)
{
    return *reinterpret_cast<double*>(
        (object ? static_cast<char*>(object) - 20 : 0) + offset);
}
