// from server: 100% by EspClaude
// from server: 72% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <string>
template<class E> struct ImpStr : std::basic_string<E> { __declspec(noinline) const E* c_str() const { return std::basic_string<E>::c_str(); } };
extern template struct __declspec(dllimport) ImpStr<char>;
typedef std::string Text;
struct Name {int index;const std::string text; const char* c_str() const { return static_cast<const ImpStr<char>&>(text).c_str(); }};
struct Entry {void* vptr;const Name& name;const int value;const unsigned index;};
struct EnumDescriptor {char prefix[16];std::vector<const Entry*> items;typedef std::vector<const Entry*>::const_iterator const_iterator;const_iterator begin()const{return items.begin();}const_iterator end()const{return items.end();}};
struct Descriptor {char prefix[0x18];const EnumDescriptor& enumType;};
struct Constraints {virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21(); virtual void* AddConstraint(const char*,unsigned,int);};
struct Primary {virtual ~Primary();char pad[0x1c];};
struct Secondary {public: virtual ~Secondary();char before[0xc4-0x24];Constraints* constraints;public: Constraints* GetConstraints() const {return constraints;} private:char after[0x114-0xc8];};
struct Third {virtual ~Third();};
struct Base:Primary,Secondary,Third {Base(const Descriptor*,int);virtual ~Base();};
struct EnumItem:Base {EnumItem(const Descriptor*,int);virtual ~EnumItem();};
EnumItem::EnumItem(const Descriptor* desc,int id):Base(desc,id){
 EnumDescriptor::const_iterator end, iter;
 iter=desc->enumType.begin();
 end=desc->enumType.end();
 for(;iter!=end;++iter){
  GetConstraints()->AddConstraint((*iter)->name.c_str(),(*iter)->index,-1);
 }
}
