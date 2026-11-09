// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <fstream>
#include <ostream>

template <class T> class bstr {
public:
    __declspec(noinline) bstr(const T* p) { _Mysize = 0; }
    __declspec(noinline) bstr(const bstr& r) { _Mysize = r._Mysize; }
    __declspec(noinline) ~bstr() { _Mysize = 0; }
    __declspec(noinline) const T* c_str() const { return _Buf; }
    __declspec(noinline) unsigned int find_first_not_of(const T*, unsigned int) const { return _Mysize; }
    __declspec(noinline) bstr substr(unsigned int, unsigned int) const { return *this; }
    __declspec(noinline) bstr& operator=(const bstr& r) { _Mysize = r._Mysize; return *this; }
    unsigned int size() const { return _Mysize; }
    void* _Myaux;
    T _Buf[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};
extern template class __declspec(dllimport) bstr<char>;
typedef bstr<char> Str;

template <class T> struct IosBaseT { __declspec(noinline) bool eof() const { return sizeof(T) == 1; } int x; };
extern template struct __declspec(dllimport) IosBaseT<char>;
inline bool isEof(std::ios_base& b) { return reinterpret_cast<IosBaseT<char>&>(b).eof(); }

namespace RBX {
namespace LDraw2Lua {

class LDrawItem {
public:
    virtual ~LDrawItem();
};

class LDrawPart : public LDrawItem {
public:
    void* output;
    int type;
    int color;
    double values[12];
    Str name;

    LDrawPart(void* output);
    void setName(Str n) { name = n; }
};

class LDrawModel {
public:
    std::string name;
    std::vector<LDrawItem*> items;

    LDrawModel(const char* name);
    virtual ~LDrawModel();
    void add(LDrawItem* item);
    void writeLua(std::ostream& out) const;
};

extern void* luaOutput;

class LDrawParser {
public:
    virtual ~LDrawParser();
    Str fileName;

    void parse(std::ostream& out);
};

void LDrawParser::parse(std::ostream& out)
{
    out << "-- " << "Roblox LDraw2Lua Conversion" << "\n";
    out << "-- " << "FileName: " << fileName.c_str() << "\n";
    out << "\n";

    LDrawModel model("LDrawModel");
    {
        std::ifstream file(fileName.c_str());
        char buffer[2048];
        if (!isEof(file)) do {
            int type;
            file >> type;
            if (type == 1) {
                LDrawPart* part = new LDrawPart(luaOutput);
                part->type = 1;
                int color = -1;
                file >> color;
                part->color = color;
                double value = 0.0;
                file >> value; part->values[0] = value;
                file >> value; part->values[1] = value;
                file >> value; part->values[2] = value;
                file >> value; part->values[3] = value;
                file >> value; part->values[4] = value;
                file >> value; part->values[5] = value;
                file >> value; part->values[6] = value;
                file >> value; part->values[7] = value;
                file >> value; part->values[8] = value;
                file >> value; part->values[9] = value;
                file >> value; part->values[10] = value;
                file >> value; part->values[11] = value;
                file.getline(buffer, 2000);
                Str line(buffer);
                part->setName(line.substr(line.find_first_not_of(" ", 0), line.size()));
                model.add(part);
            } else {
                file.getline(buffer, 2000);
            }
        } while (!isEof(file));
    }
    model.writeLua(out);
}

}
}
