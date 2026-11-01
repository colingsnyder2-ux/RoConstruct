// from server: 100% by king_originala
struct Holder
{
    virtual ~Holder();
    virtual void type() const = 0;
    virtual Holder* clone() const = 0;
};

struct Element
{
    int first;
    Holder* second;
};

Element* __cdecl copy_backward(Element* first, Element* last, Element* result)
{
    while (first != last)
    {
        --last;
        --result;
        result->first = last->first;

        Holder* source = last->second;
        Holder* temporary = source ? source->clone() : 0;
        if (&temporary != &result->second)
        {
            Holder* old = temporary;
            temporary = result->second;
            result->second = old;
        }

        if (temporary)
            delete temporary;
    }

    return result;
}
