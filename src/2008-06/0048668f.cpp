// from server: 58% by coldek
extern "C" int __cdecl convertFloat();

extern "C" void __cdecl invokeFunction();

struct Shader
{
    void setValues();
};

void Shader::setValues()
{
    convertFloat();
    convertFloat();
    convertFloat();
    convertFloat();
    invokeFunction();
}
