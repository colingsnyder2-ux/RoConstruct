// from server: 100% by king_originala
struct CommandBars;

struct CommandsPage
{
    void Initialize(int resource, int category);
    void AddCategories(int resource, int position);
    void AddMenuCategory(int menu, int resource, int position);
    void AddAllCommandsCategory(int resource, int position);
};

struct OptionsPage;

struct CustomizeSheet
{
    unsigned char reserved0[176];
    CommandsPage* commandsPage;
    unsigned char reserved1[16];

    CustomizeSheet(CommandBars* bars, int flags);
    ~CustomizeSheet();
    void AddPage(OptionsPage* page);
    int DoModal();
};

struct OptionsPage
{
    int reserved[110];

    OptionsPage(CustomizeSheet* sheet);
    ~OptionsPage();
};

struct CMainFrame
{
    unsigned char reserved[236];
    CommandBars* commandBars;

    void Customize();
};

void CMainFrame::Customize()
{
    if (commandBars)
    {
        CustomizeSheet sheet(commandBars, 0);
        OptionsPage options(&sheet);
        sheet.AddPage(&options);

        CommandsPage* page = sheet.commandsPage;
        page->Initialize(0x81, 0);
        page->AddCategories(0x23d1, -1);
        page->AddMenuCategory(0x81, 0x23d6, -1);
        page->AddAllCommandsCategory(0x23ca, -1);

        sheet.DoModal();
    }
}
