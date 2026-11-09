// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Native ON_UPDATE_COMMAND_UI handler. Unused owner APIs/storage omitted;
// no owner or borrowed control object is constructed or allocated here.
#include <stddef.h>
typedef unsigned int UINT;typedef int BOOL;typedef unsigned long COLORREF;
class CMenu;class CWnd;class CCmdTarget;
// Consumed MFC90 CCmdUI declaration, including all four real virtual APIs.
class CCmdUI {public:
 UINT m_nID,m_nIndex;CMenu*m_pMenu;CMenu*m_pSubMenu;CWnd*m_pOther;
 virtual void Enable(BOOL=1);virtual void SetCheck(int=1);
 virtual void SetRadio(BOOL=1);virtual void SetText(const char*);
 CCmdUI();BOOL m_bEnableChanged,m_bContinueRouting;UINT m_nIndexMax;CMenu*m_pParentMenu;
};
namespace G3D {
class Color3 {public:float r,g,b;Color3(const Color3&v):r(v.r),g(v.g),b(v.b){}};
class Color3uint8 {public:unsigned char r,g,b;Color3uint8(const Color3&);};
}
namespace RBX {class BrickColor {public:
enum Number
		{
			lego_1 = 1,
			lego_2 = 2,
			lego_3 = 3,
			lego_5 = 5,
			lego_6 = 6,
			lego_9 = 9,
			lego_11 = 11,
			lego_12 = 12,
			lego_18 = 18,
			lego_21 = 21,
			lego_22 = 22,
			lego_23 = 23,
			lego_24 = 24,
			lego_25 = 25,
			lego_26 = 26,
			lego_27 = 27,
			lego_28 = 28,
			lego_29 = 29,
			lego_36 = 36,
			lego_37 = 37,
			lego_38 = 38,
			lego_39 = 39,
			lego_40 = 40,
			lego_41 = 41,
			lego_42 = 42,
			lego_43 = 43,
			lego_44 = 44,
			lego_45 = 45,
			lego_47 = 47,
			lego_48 = 48,
			lego_49 = 49,
			lego_50 = 50,
			lego_100 = 100,
			lego_101 = 101,
			lego_102 = 102,
			lego_103 = 103,
			lego_104 = 104,
			lego_105 = 105,
			lego_106 = 106,
			lego_107 = 107,
			lego_108 = 108,
			lego_110 = 110,
			lego_111 = 111,
			lego_112 = 112,
			lego_113 = 113,
			lego_115 = 115,
			lego_116 = 116,
			lego_118 = 118,
			lego_119 = 119,
			lego_120 = 120,
			lego_121 = 121,
			lego_123 = 123,
			lego_124 = 124,
			lego_125 = 125,
			lego_126 = 126,
			lego_127 = 127,
			lego_128 = 128,
			lego_131 = 131,
			lego_133 = 133,
			lego_134 = 134,
			lego_135 = 135,
			lego_136 = 136,
			lego_137 = 137,
			lego_138 = 138,
			lego_140 = 140,
			lego_141 = 141,
			lego_143 = 143,
			lego_145 = 145,
			lego_146 = 146,
			lego_147 = 147,
			lego_148 = 148,
			lego_149 = 149,
			lego_150 = 150,
			lego_151 = 151,
			lego_153 = 153,
			lego_154 = 154,
			lego_157 = 157,
			lego_158 = 158,
			lego_168 = 168,
			lego_176 = 176,
			lego_178 = 178,
			lego_179 = 179,
			lego_180 = 180,
			lego_190 = 190,
			lego_191 = 191,
			lego_192 = 192,
			lego_193 = 193,
			lego_194 = 194,
			lego_195 = 195,
			lego_196 = 196,
			lego_198 = 198,
			lego_199 = 199,
			lego_200 = 200,
			lego_208 = 208,
			lego_209 = 209,
			lego_210 = 210,
			lego_211 = 211,
			lego_212 = 212,
			lego_213 = 213,
			lego_216 = 216,
			lego_217 = 217,
			lego_218 = 218,
			lego_219 = 219,
			lego_220 = 220,
			lego_221 = 221,
			lego_222 = 222,
			lego_223 = 223,
			lego_224 = 224,
			lego_225 = 225,
			lego_226 = 226,
			lego_232 = 232,
			lego_268 = 268
		};
 Number number;
 BrickColor(int);BrickColor():number(lego_194){}BrickColor(Number n):number(n){}
 G3D::Color3 color3()const;
};}
// MFC90 DLL CObject/CArray interfaces. All five real CObject virtual APIs
// are retained; no CObject/CArray/controls instances or vtables are constructed.
typedef __w64 int INT_PTR;
struct CRuntimeClass;class CArchive;class CDumpContext;
class __declspec(novtable) CObject {public:
 virtual CRuntimeClass*GetRuntimeClass()const;virtual~CObject()=0;
 virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;
protected:CObject();private:CObject(const CObject&);void operator=(const CObject&);
};
void __declspec(noreturn) __stdcall AfxThrowInvalidArgException();
template<class TYPE,class ARG_TYPE>class CArray:public CObject {
public:CArray();~CArray();void Serialize(CArchive&);
 INT_PTR GetSize()const{return m_nSize;}
 const TYPE&GetAt(INT_PTR n)const{if(n>=0&&n<m_nSize)return m_pData[n];AfxThrowInvalidArgException();}
protected:TYPE*m_pData;INT_PTR m_nSize,m_nMaxSize,m_nGrowBy;
};
class CXTPControl;
// Borrowed existing-pointer prefixes, checked against actual XTP SDK getters.
// Unconsumed base/storage is opaque. No complete XTP object size is asserted.
class CXTPControls {char observed00[0x24];CArray<CXTPControl*,CXTPControl*>m_arrControls;
public:CXTPControl*GetAt(int n)const{return n>=0&&n<m_arrControls.GetSize()?m_arrControls.GetAt(n):0;}};
class CXTPCommandBar {char observed00[0xfc];CXTPControls*controls;
public:CXTPControls*GetControls()const{return controls;}};
// Existing custom control API at0044de10; no control layout is needed.
class CRobloxControlColorSelector {public:void SetColor(COLORREF);};
extern RBX::BrickColor selectedColor;
// Only this method interface is consumed; the original CView bases and fields
// are unused and omitted. No instance, constructor or owner vtable is emitted.
class CWrapperView {public:void OnUpdateColor(CCmdUI*);};
void CWrapperView::OnUpdateColor(CCmdUI* ui){
 if(ui->m_pOther){
  CXTPControls*controls=reinterpret_cast<CXTPCommandBar*>(ui->m_pOther)->GetControls();
  CRobloxControlColorSelector*item=reinterpret_cast<CRobloxControlColorSelector*>(controls->GetAt(ui->m_nIndex));
  RBX::BrickColor color=selectedColor;
  G3D::Color3uint8 rgb(color.color3());
  item->SetColor(((COLORREF(rgb.b)<<8|rgb.g)<<8)|rgb.r);
 }
 ui->Enable(1);
}
typedef char NativeColorCmdUI[sizeof(CCmdUI)==40?1:-1];
typedef char NativeColorIndex[offsetof(CCmdUI,m_nIndex)==8?1:-1];
typedef char NativeColorOther[offsetof(CCmdUI,m_pOther)==0x14?1:-1];
typedef char NativeColorBrick[sizeof(RBX::BrickColor)==4?1:-1];
typedef char NativeColorValue[sizeof(G3D::Color3)==12?1:-1];
typedef char NativeColorRGB[sizeof(G3D::Color3uint8)==3?1:-1];

typedef char NativeColorObject[sizeof(CObject)==4?1:-1];
typedef char NativeColorArray[sizeof(CArray<CXTPControl*,CXTPControl*>)==20?1:-1];
