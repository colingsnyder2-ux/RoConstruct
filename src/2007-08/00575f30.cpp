// from server: 40% by colin
struct PropBase {
    void* m_value;
    void* m_getter;
    void* m_setter;
    void* m_attributes;
    void* m_seenAttributes;
};

struct GetSet {
    virtual void dummy();
};

struct TypedPropertyDescriptor : PropBase {
    void* getset;
    void setWritable(bool value);
    void checkFlags();
    void construct(GetSet* gs, bool value);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void TypedPropertyDescriptor::setWritable(bool value)
{
    void** begin = (void**)m_value;
    void** end = (void**)m_getter;
    unsigned count = 0;
    if (begin != 0)
        count = (unsigned)(((char*)end - (char*)begin) >> 2);

    void* saved = m_seenAttributes;
    void** localBegin = begin;
    unsigned localCount = count;
    void* localSaved = saved;
    m_seenAttributes = (void*)&localBegin;

    if (count > 0) {
        unsigned i = 0;
        do {
            void** cur = (void**)m_value;
            if (cur == 0 || i >= (unsigned)(((char*)m_getter - (char*)cur) >> 2))
                _invalid_parameter_noinfo();
            void* item = ((void**)m_value)[i];
            this->setWritable(value);
            i++;
        } while (i < localCount);
        m_seenAttributes = localSaved;
    } else {
        m_seenAttributes = saved;
    }
}
