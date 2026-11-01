// from server: 100% by Yeetserama
// roc 2010-06 00433a00  unit: RBX::VBrickColor::?$XItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00433a00
//
// 00433a00  56                   push esi
// 00433a01  57                   push edi
// 00433a02  8d44240c             lea eax, [esp + 0xc]
// 00433a06  8bf1                 mov esi, ecx
// 00433a08  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00433a0c  50                   push eax
// 00433a0d  e89eb51e00           call 0x61efb0
// 00433a12  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00433a16  0fb64c240e           movzx ecx, byte ptr [esp + 0xe]
// 00433a1b  8b16                 mov edx, dword ptr [esi]
// 00433a1d  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00433a23  c1e108               shl ecx, 8
// 00433a26  0fb6fc               movzx edi, ah
// 00433a29  0bcf                 or ecx, edi
// 00433a2b  0fb6c0               movzx eax, al
// 00433a2e  c1e108               shl ecx, 8
// 00433a31  0bc8                 or ecx, eax
// 00433a33  51                   push ecx
// 00433a34  8bce                 mov ecx, esi
// 00433a36  ffd2                 call edx
// 00433a38  5f                   pop edi
// 00433a39  5e                   pop esi
// 00433a3a  c20400               ret 4
// copied from an identical function in another client (function ?apply@Item@ns_ROCX000000@@QAEXPAUColor@2@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
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
