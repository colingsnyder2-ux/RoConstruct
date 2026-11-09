// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#include <utility>
struct Holder {
    int alloc;
    int* head;
    unsigned int size;
    void swap(Holder& right);
};
void Holder::swap(Holder& right)
{
    if (this != &right) {
        std::swap(head, right.head);
        std::swap(size, right.size);
    }
}
