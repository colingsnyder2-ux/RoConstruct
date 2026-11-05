// from server: 29% by atomic.potato
// roc 2010-06 00483080  unit: RBX::LDraw2Lua::LDrawParser  size: 922 bytes

struct LDrawParser {
    char pad0[4];
    void* stream;
    void parse(const char* filename);
};

struct LDrawModel {
    int refs;
    int type;
    double v[13];
    char name[0x10];
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

extern "C" void* __stdcall sub_44DF20(void*, const char*, const char*);
extern "C" void* __stdcall sub_4828B0(void*, void*);
extern "C" void __stdcall sub_4834B0(void*, const char*);
extern "C" void __stdcall sub_483530(void*, const char*);
extern "C" void __stdcall sub_4836A0(void*);
extern "C" void __stdcall sub_4837A0(void*, void*);
extern "C" void* __stdcall sub_7A79A0(unsigned int);

extern "C" void* __stdcall ifstream_ctor(void*, const char*, int, int);
extern "C" void __stdcall ifstream_dtor(void*);
extern "C" void* __stdcall string_ctor(void*, const char*);
extern "C" void __stdcall string_dtor(void*);
extern "C" void* __stdcall string_assign(void*, const void*);
extern "C" void* __stdcall istream_int(void*, int*);
extern "C" void* __stdcall istream_double(void*, double*);
extern "C" const char* __stdcall string_c_str(void*);
extern "C" bool __stdcall ios_eof(void*);
extern "C" unsigned int __stdcall string_find_first_not_of(void*, const char*, unsigned int);
extern "C" void* __stdcall istream_getline(void*, char*, int);
extern "C" void* __stdcall string_substr(void*, void*, unsigned int, unsigned int);

void LDrawParser::parse(const char* filename)
{
    void* s = sub_44DF20(0, "Roblox LDraw2Lua Conversion", "LDrawModel");
    s = sub_44DF20(s, "FileName: ", filename);
    s = sub_44DF20(s, "m.Parent = w", 0);
    s = sub_44DF20(s, "SUVW", 0);

    char buf[0x900];
    sub_4834B0(buf, "LDrawModel");

    void* fs[0x30];
    ifstream_ctor(fs, filename, 1, 0x40);

    char line[0x400];
    while (!ios_eof(fs)) {
        istream_getline(fs, line, 0x400);
        if (string_find_first_not_of(line, " \t\r\n", 0) == -1)
            continue;

        int tok;
        istream_int(fs, &tok);
        if (tok != 1) {
            istream_getline(fs, line, 0x400);
            continue;
        }

        LDrawModel* m = (LDrawModel*)operator_new(0x90);
        if (m) {
            m = (LDrawModel*)sub_4828B0(m, (void*)0xc0308c);
        } else {
            m = 0;
        }
        m->refs = 1;
        m->type = tok;

        double d;
        istream_double(fs, &d);
        m->v[0] = d;
        istream_double(fs, &d);
        m->v[1] = d;
        istream_double(fs, &d);
        m->v[2] = d;
        istream_double(fs, &d);
        m->v[3] = d;
        istream_double(fs, &d);
        m->v[4] = d;
        istream_double(fs, &d);
        m->v[5] = d;
        istream_double(fs, &d);
        m->v[6] = d;
        istream_double(fs, &d);
        m->v[7] = d;
        istream_double(fs, &d);
        m->v[8] = d;
        istream_double(fs, &d);
        m->v[9] = d;
        istream_double(fs, &d);
        m->v[10] = d;
        istream_double(fs, &d);
        m->v[11] = d;
        istream_double(fs, &d);
        m->v[12] = d;

        istream_getline(fs, line, 0x7d0);
        string_ctor(m->name, line);
        sub_4837A0(buf, m);
    }

    ifstream_dtor(fs);
    sub_483530(buf, filename);
    sub_4836A0(buf);
}
