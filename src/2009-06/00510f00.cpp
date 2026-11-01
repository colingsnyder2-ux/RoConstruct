// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void fillRandom(unsigned int* data, int bytes);
bool isProbablePrime(unsigned int* data, int words, int rounds);

void generatePrime(unsigned int* data, int words)
{
    do
    {
        fillRandom(data, words * 4);
        data[words - 1] |= 0x80000000u;
        data[0] |= 1u;
    } while (!isProbablePrime(data, words, 20));
}
