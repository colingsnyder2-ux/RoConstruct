// from server: 100% by EspClaude
// roc 2007-08 0041d6a0  unit: CInstanceRecord::CNameItem
class StdString {
public:
    __declspec(dllimport) const char* c_str() const throw();
    char storage[0x1c];
};
class CString {
public:
    __declspec(dllimport) CString(const char* psz);
    __declspec(dllimport) CString(const CString& s);
    __declspec(dllimport) ~CString() throw();
    char* m_pszData;
};
struct InstanceData {
    char pad[0xc8];
    StdString name;
};
class CNameItem {
public:
    char pad[0x7c];
    InstanceData* m_instance;
    CString GetCaption(void* pColumn);
};
CString CNameItem::GetCaption(void*)
{
    return CString(m_instance->name.c_str());
}
