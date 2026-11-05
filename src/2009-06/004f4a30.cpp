// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class PacketLogger {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
protected:
    static char* BaseIDTOString(unsigned char Id);
    char* IDTOString(unsigned char Id);
    virtual char* UserIDTOString(unsigned char Id);
};
char* PacketLogger::BaseIDTOString(unsigned char Id)
{
	if (Id >= 0x5f)
		return 0;
	const char *IDTable[0x5f]=
	{
"ID_0",
"ID_1",
"ID_2",
"ID_3",
"ID_4",
"ID_5",
"ID_6",
"ID_7",
"ID_8",
"ID_9",
"ID_10",
"ID_11",
"ID_12",
"ID_13",
"ID_14",
"ID_15",
"ID_16",
"ID_17",
"ID_18",
"ID_19",
"ID_20",
"ID_21",
"ID_22",
"ID_23",
"ID_24",
"ID_25",
"ID_26",
"ID_27",
"ID_28",
"ID_29",
"ID_30",
"ID_31",
"ID_32",
"ID_33",
"ID_34",
"ID_35",
"ID_36",
"ID_37",
"ID_38",
"ID_39",
"ID_40",
"ID_41",
"ID_42",
"ID_43",
"ID_44",
"ID_45",
"ID_46",
"ID_47",
"ID_48",
"ID_49",
"ID_50",
"ID_51",
"ID_52",
"ID_53",
"ID_54",
"ID_55",
"ID_56",
"ID_57",
"ID_58",
"ID_59",
"ID_60",
"ID_61",
"ID_62",
"ID_63",
"ID_64",
"ID_65",
"ID_66",
"ID_67",
"ID_68",
"ID_69",
"ID_70",
"ID_71",
"ID_72",
"ID_73",
"ID_74",
"ID_75",
"ID_76",
"ID_77",
"ID_78",
"ID_79",
"ID_80",
"ID_81",
"ID_82",
"ID_83",
"ID_84",
"ID_85",
"ID_86",
"ID_87",
"ID_88",
"ID_89",
"ID_90",
"ID_91",
"ID_92",
"ID_93",
"ID_94"
	};
	return (char*)IDTable[Id];
}
char* PacketLogger::IDTOString(unsigned char Id)
{
	char *out;
	out=BaseIDTOString(Id);
	if (out)
		return (char*)out;
	return UserIDTOString(Id);
}
