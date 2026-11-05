// from server: 53% by atomic.potato
extern "C" void __cdecl func_007b6f30(
    unsigned char*,
    unsigned int,
    unsigned int,
    unsigned int,
    unsigned int,
    unsigned int);

void func_007b7030(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    unsigned char x = 0;
    func_007b6f30(&x, d, e, a, b, c);
}
