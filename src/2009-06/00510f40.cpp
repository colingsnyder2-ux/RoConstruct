// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void CopyWords(unsigned int* dst, unsigned int n, const unsigned int* src);
class BigInt {
    char pad[0x20];
    unsigned int* data;
    int pad2;
    unsigned int size;
public:
    void store(unsigned int* out) const;
};
void BigInt::store(unsigned int* out) const
{
    CopyWords(out, size, data);
}
