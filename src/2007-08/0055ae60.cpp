// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 0055ae60  size: 309 bytes
// Reconstructed from target assembly (objdump of clients/2007-08/Roblox.exe 0x55ae60-0x55af95):
//   std::stringstream (in|out, IAT 0x77e674 / vbase dtor 0x77e678) at frame+0x48,
//   std::auto_ptr<Object> from 0x569800 (dtor 0x40f800 + delete 0x62fc62) at frame+8,
//   this->fill(obj) 0x53e720, Writer(ostream&) 0x467cd0 at frame+0x28 (0x20 bytes), write(obj) 0x566670,
//   ostream::flush 0x77e5fc, ~Writer 0x4675d0, std::string local frame+0xc,
//   cdecl 0x553ea0(name, ss, 1, local), by-value std::string param + 4-byte param (ret 0x20).

#include <string>
#include <sstream>
#include <memory>

class Object {
public:
    ~Object();                                   // 0x40f800
};

Object* createObject();                          // 0x569800

class Writer {
public:
    explicit Writer(std::ostream& stream);       // 0x467cd0
    ~Writer();                                   // 0x4675d0
    void write(Object* object);                  // 0x566670
private:
    int data[8];                                 // frame+0x28 .. +0x48
};

void store(const std::string& name, std::stringstream& data, bool flag, std::string& result);   // 0x553ea0

class Tool {
public:
    void fill(Object* object);                   // 0x53e720
    void save(std::string name, int unused);
};

void Tool::save(std::string name, int unused)
{
    std::stringstream stream;
    {
        std::auto_ptr<Object> object(createObject());
        fill(object.get());
        Writer writer(stream);
        writer.write(object.get());
        stream.flush();
    }
    std::string result;
    store(name, stream, true, result);
}
