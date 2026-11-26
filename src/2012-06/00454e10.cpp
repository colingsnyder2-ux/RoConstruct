// from server: 100% by Xemicl
// roc 2012-06 00454e10  unit: RBX::VBrickColor::?$XItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00454e10
//
// 00454e10  56                   push esi
// 00454e11  57                   push edi
// 00454e12  8d44240c             lea eax, [esp + 0xc]
// 00454e16  8bf1                 mov esi, ecx
// 00454e18  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00454e1c  50                   push eax
// 00454e1d  e88edf2e00           call 0x742db0
// 00454e22  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00454e26  0fb64c240e           movzx ecx, byte ptr [esp + 0xe]
// 00454e2b  8b16                 mov edx, dword ptr [esi]
// 00454e2d  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00454e33  c1e108               shl ecx, 8
// 00454e36  0fb6fc               movzx edi, ah
// 00454e39  0bcf                 or ecx, edi
// 00454e3b  0fb6c0               movzx eax, al
// 00454e3e  c1e108               shl ecx, 8
// 00454e41  0bc8                 or ecx, eax
// 00454e43  51                   push ecx
// 00454e44  8bce                 mov ecx, esi
// 00454e46  ffd2                 call edx
// 00454e48  5f                   pop edi
// 00454e49  5e                   pop esi
// 00454e4a  c20400               ret 4
// copied from an identical function in another client (function ?apply@Item@ns_ROCX000000@@QAEXPAUColor@2@@Z)

namespace ns_ROCX000000 {
struct Color {
    void convert(unsigned long* output);
};

struct Item {
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7();
    virtual void v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47();
    virtual void v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55();
    virtual void v56();
    virtual void setColor(unsigned long value);
    void apply(Color* color);
};

void Item::apply(Color* color)
{
    color->convert(reinterpret_cast<unsigned long*>(&color));
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&color);
    setColor((((unsigned long)bytes[2] << 8) | bytes[1]) << 8 | bytes[0]);
}
}