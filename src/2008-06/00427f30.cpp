// from server: 100% by king_originala
// from server: 99% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
typedef std::string String;
struct ImportedString:std::string {
 ImportedString(const char* s):std::string(s){}
 __declspec(dllimport) const char* c_str()const;
};
struct BufferString {
 char* data;
 __declspec(dllimport) ~BufferString() throw();
 __declspec(dllimport) int length()const;
 __declspec(dllimport) char* buffer(int);
 __declspec(dllimport) void release(int);
 __declspec(dllimport) const char* text()const;
 __declspec(dllimport) static unsigned __cdecl stringLength(const char*);
};
extern "C" __declspec(dllimport) int __stdcall PathAppendA(char*,const char*);
struct MainLogManager {
 char padding[0x2c];
 String name;
 BufferString getPath();
 String fileName();
};
String MainLogManager::fileName(){
 BufferString path=getPath();
 ImportedString tail("log_");
 tail+=name;
 tail.erase(12,String::npos);
 tail.erase(4,3);
 tail+=".txt";
 const char* text=tail.c_str();
 char* p=path.buffer(BufferString::stringLength(text)+path.length()+1);
 PathAppendA(p,text);
 path.release(-1);
 return String(path.text());
}
