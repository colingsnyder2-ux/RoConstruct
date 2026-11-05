// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Target passes the address of the by-value byte argument with (8, true).
class BitStream { public: void WriteBits(const unsigned char* input, int numberOfBits, bool rightAligned); };
BitStream& __cdecl operator<<(BitStream& stream, unsigned char value)
{
    stream.WriteBits(&value, 8, true);
    return stream;
}
