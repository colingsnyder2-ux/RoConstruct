// from server: 21% by atomic.potato
struct PasteVerb
{
    PasteVerb& f(PasteVerb&);
};

PasteVerb& PasteVerb::f(PasteVerb& value)
{
    return value;
}
