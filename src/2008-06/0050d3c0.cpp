// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
unsigned char* blend(unsigned char* out, unsigned int a, unsigned int b, float t)
{
    double inverse = 1.0 - t;

    out[0] = (unsigned char)((int)((unsigned char)a * t)
                          + (unsigned char)b * inverse);
    out[1] = (unsigned char)((int)((unsigned char)(a >> 8) * t)
                          + (unsigned char)(b >> 8) * inverse);
    out[2] = (unsigned char)((int)((unsigned char)(a >> 16) * t)
                          + (unsigned char)(b >> 16) * inverse);
    out[3] = (unsigned char)((int)((unsigned char)(a >> 24) * t)
                          + (unsigned char)(b >> 24) * inverse);

    return out;
}
