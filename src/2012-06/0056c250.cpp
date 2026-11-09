// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Target: thiscall member on the first argument with the second argument, returns the first (cdecl).
class Stream { public: void write(const void* value); };
Stream& __cdecl operator<<(Stream& stream, const void* value)
{
    stream.write(value);
    return stream;
}
