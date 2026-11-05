// from server: 16% by atomic.potato
struct CircleRadialNormal {
    char pad0[0xc];
    char* end;
    char pad10[4];
    char* begin;
    void insert(char* pos, unsigned int count, const float* value);
    char* allocate(unsigned int count);
    void fill(char* first, char* last, const float* value);
    void copy(char* first, char* last, char* dest);
    void construct(char* first, char* last, const float* value);
};

extern "C" void __stdcall sub_7a89b2(int, int);

void CircleRadialNormal::insert(char* pos, unsigned int count, const float* value) {
    if (count == 0) return;
    unsigned int avail = (unsigned int)((this->end - pos) >> 3);
    if (count > avail) {
        char* oldend = this->end;
        unsigned int oldsize = (unsigned int)((oldend - this->begin) >> 3);
        float tmp[2];
        tmp[0] = value[0];
        tmp[1] = value[1];
        if (count > oldsize) {
            unsigned int newcap = oldsize + count;
            char* newbuf = this->allocate(newcap);
            this->construct(newbuf, newbuf + (count << 3), tmp);
            this->copy(this->begin, pos, newbuf);
            this->copy(pos, oldend, newbuf + (count << 3) + (pos - this->begin));
            this->begin = newbuf;
            this->end = newbuf + (newcap << 3);
        } else {
            unsigned int tail = (unsigned int)((oldend - pos) >> 3);
            char* newend = oldend + (count << 3);
            this->construct(oldend, newend, tmp);
            this->copy(pos, oldend, pos + (count << 3));
            this->fill(pos, pos + (count << 3), tmp);
            this->end = newend;
        }
    } else {
        char* newend = this->end + (count << 3);
        this->construct(this->end, newend, value);
        this->copy(pos, this->end, pos + (count << 3));
        this->fill(pos, pos + (count << 3), value);
        this->end = newend;
    }
}
