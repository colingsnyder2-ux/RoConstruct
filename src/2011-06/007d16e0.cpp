// from server: 28% by atomic.potato
extern "C" void __cdecl sub_7d1300(
    unsigned char,
    unsigned char,
    unsigned char,
    unsigned char,
    unsigned char,
    unsigned char);

void f(unsigned char value)
{
    unsigned char local = 0;
    sub_7d1300(local, local, local, local, value, value);
}
