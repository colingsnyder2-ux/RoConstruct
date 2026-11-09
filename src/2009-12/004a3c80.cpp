// from server: 7% by atomic.potato
// roc 2009-12 004a3c80  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen
// Make this compile to the exact bytes below, then: roc check 2009-12 004a3c80

extern "C" void __cdecl _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int, int);
extern "C" void __cdecl op_delete(void*);
extern "C" void __stdcall sub_49f180();
extern "C" void __stdcall sub_4a2ab0();

struct Vec {
    char pad[0x2c];
};

struct Container {
    char pad0[8];
    Vec* begin;
    Vec* end;
    Vec* cap;
    void insert(Vec* pos, unsigned int n, const Vec* val);
};

void Container::insert(Vec* pos, unsigned int n, const Vec* val) {
    unsigned int cur;
    unsigned int capn;
    unsigned int newcap;
    Vec* newbuf;
    unsigned int idx;
    if (n == 0) return;
    cur = (unsigned int)((char*)end - (char*)begin) / 0x2c;
    if (n > 0x5d1745d - cur) {
        _invalid_parameter_noinfo();
    }
    if (n > (unsigned int)((char*)cap - (char*)end) / 0x2c) {
        capn = (unsigned int)((char*)cap - (char*)begin) / 0x2c;
        newcap = capn + n;
        if (newcap < capn) {
            newcap = 0;
        } else {
            unsigned int half = capn >> 1;
            if (0x5d1745d - half < capn) {
                newcap = 0;
            } else {
                newcap = capn + half;
            }
        }
        if (newcap < capn + n) newcap = capn + n;
        newbuf = (Vec*)operator_new(newcap * 0x2c, 0);
        idx = (unsigned int)((char*)pos - (char*)begin) / 0x2c;
        sub_4a2ab0();
        sub_49f180();
        sub_49f180();
        if (begin) op_delete(begin);
        begin = newbuf;
        end = newbuf + (idx + n);
        cap = newbuf + newcap;
    } else {
        if (n > (unsigned int)((char*)end - (char*)pos) / 0x2c) {
            sub_49f180();
            sub_49f180();
            end = end + n;
        } else {
            sub_49f180();
            end = end + n;
        }
    }
}
