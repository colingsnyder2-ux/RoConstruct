// from server: 32% by colin
struct COleException_Helper
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    int fieldCC;
    int fieldD0;
    int fieldD4;
    int fieldD8;
    int fieldDC;
    int fieldE0;
    int fieldE4;
    int fieldE8;
    int fieldEC;
    int fieldF0;
    int fieldF4;
    int fieldF8;
    int fieldFC;
    int field100;
    int field104;
    int field108;
    int field10C;
    int field110;
    int field114;
    int field118;
    int field11C;
    int field120;
    int field124;
    int field128;
    int field12C;
    int field130;
    int field134;
    int field138;
    int field13C;
};

struct COleException_Node
{
    COleException_Node* next;
    int pad;
    COleException_Helper data;
};

extern "C" int __fastcall sub_427BB0(COleException_Helper* self);

struct COleException
{
    COleException_Node* head;
    COleException_Node* tail;
    void find(COleException_Node** out, COleException_Node* value);
};

void COleException::find(COleException_Node** out, COleException_Node* value)
{
    COleException_Node* cur = this->head;
    while (cur != value)
    {
        COleException_Helper tmp;
        COleException_Helper* src = &cur->data;
        COleException_Helper* dst = &tmp;
        int count = 0x50;
        while (count--)
        {
            *dst = *src;
            dst++;
            src++;
        }
        if (sub_427BB0(&tmp) != 0)
            break;
        cur = cur->next;
    }
    out[1] = cur;
    out[0] = this->tail;
}
