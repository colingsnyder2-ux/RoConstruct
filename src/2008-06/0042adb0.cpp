// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct GUID_ {unsigned long d1;unsigned short d2,d3;unsigned char d4[8];};
extern const GUID_ iid1,iid2;
extern int __cdecl compare(const GUID_&,const GUID_&);
struct EventHandler {
 virtual long __stdcall QueryInterface(const GUID_&,void**);
 virtual unsigned long __stdcall AddRef();
 virtual unsigned long __stdcall Release();
};
long __stdcall EventHandler::QueryInterface(const GUID_&riid,void**ppv){
 long hr=0;
 *ppv=0;
 if(compare(riid,iid1))*ppv=this;
 else if(compare(riid,iid2))*ppv=this;
 else hr=(long)0x80004002;
 if(hr>=0)AddRef();
 return hr;
}
