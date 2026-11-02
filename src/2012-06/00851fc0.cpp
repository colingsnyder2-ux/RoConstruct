// from server: 100% by tajop
struct Element { char data[24]; };
struct S {
    int pad0;
    int pad4;
    Element* first;
    Element* last;
    int size() const;
};
int S::size() const
{
    return (int)(last - first);
}
