// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: ATL CRegParser::SkipAssignment (thiscall member, ecx = this, ret 4).
// INFERRED: fn_00402060 is CRegParser::NextToken; it is called with ecx = this
// after the first call, so it is declared __fastcall with the object first.
// INFERRED: fn_00402000 is CRegParser::SkipWhiteSpace.
extern "C" int __fastcall fn_00402060(void* self, int unusedEdx, char* token);
extern "C" int __fastcall fn_00402000(void* self, int unusedEdx);

#define FAILED(hr) (((long)(hr)) < 0)

extern "C" long __fastcall fn_00402220(void* self, int unusedEdx, char* szToken)
{
    char szValue[4096];
    long hr;

    if (*szToken == '=')
    {
        if (FAILED(hr = fn_00402060(self, 0, szToken)))
            return hr;
        fn_00402000(self, 0);
        if (FAILED(hr = fn_00402060(self, 0, szValue)))
            return hr;
        if (FAILED(hr = fn_00402060(self, 0, szToken)))
            return hr;
    }
    return 0;
}
