// from server: 100% by king_originala
extern "C" void __cdecl func_004c6d40();

struct Allocator {
    unsigned int storage;
    unsigned short *allocate(unsigned int count);
};

struct Mesh {
    unsigned int reserved[2];
    Allocator allocator;
    unsigned short *begin;
    unsigned short *end;
    unsigned short *limit;

    unsigned int func_004dc400();
    bool f(unsigned int count);
};

#pragma optimize("", off)
bool Mesh::f(unsigned int count)
{
    begin = 0;
    end = 0;
    limit = 0;

    if (count == 0) {
        return false;
    } else if (func_004dc400() < count) {
        func_004c6d40();
    } else {
        begin = allocator.allocate(count);
        end = begin;
        limit = begin + count;
    }

    return true;
}
#pragma optimize("", on)
