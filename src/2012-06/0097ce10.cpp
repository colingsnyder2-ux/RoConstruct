// from server: 67% by atomic.potato
// roc 2012-06 0097ce10  unit: RBX::Tasks::SequenceBase  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097ce10

struct SequenceBase {
    char* begin;
    char* end;
    SequenceBase* __cdecl assign(char* first, char* last, char* pred);
};

SequenceBase* SequenceBase::assign(char* first, char* last, char* pred) {
    char* f = first;
    char* l = last;
    this->begin = f;
    this->end = l;
    while (this->end == last) {
        if (!((char (*)(char))pred)(*this->end)) {
            break;
        }
        this->end++;
    }
    return this;
}
