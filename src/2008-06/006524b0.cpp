// from server: 100% by king_originala
struct Element {
    char data[24];
};

struct IteratorTag {};
struct CopyTag {
    char value;
};

extern Element* __cdecl copy_backward_impl(
    Element*, Element*, Element*, IteratorTag, IteratorTag, CopyTag);

Element* __cdecl copy_backward(Element* first, Element* last, Element* destination)
{
    IteratorTag inputTag;
    IteratorTag outputTag;
    CopyTag copyTag;
    copyTag.value = 0;

    copy_backward_impl(first, last, destination, inputTag, outputTag, copyTag);
    return destination - (last - first);
}
