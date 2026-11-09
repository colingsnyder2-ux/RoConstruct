// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_xmlreadtagfirstnamed5db5d26e4828904a.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <streambuf>
#include <stdexcept>
struct Parser {void* table;std::streambuf* buffer;void skipWhitespace();std::string readTag();};
std::string Parser::readTag(){skipWhitespace();{int count=0;char c;do{if(count++>4){std::string message="tag expected after Byte-Order-Mark";throw std::runtime_error(message);}c=static_cast<char>(buffer->sgetc());if(buffer->sbumpc()==-1)throw std::runtime_error("Expected '<' but got EOF in Xml stream");}while(c!='<');}std::string tag;tag+='<';char c;do{c=static_cast<char>(buffer->sgetc());if(buffer->sbumpc()==-1)throw std::runtime_error("Expected '>' but got EOF in Xml stream");tag+=c;}while(c!='>');return tag;}
