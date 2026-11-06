// from server: 100% by tajop
struct PropertyDescriptor;

struct Notifier
{
	void raisePropertyChanged(const PropertyDescriptor* desc);
};

extern const PropertyDescriptor desc_ShadowMode;

struct CRenderSettings
{
	char pad0[0xfc];
	unsigned char shadowMode;
	char pad1[0x144 - 0xfd];
	Notifier notifier;

	void setShadowMode(unsigned char value);
};

void CRenderSettings::setShadowMode(unsigned char value)
{
	if (value != shadowMode)
	{
		shadowMode = value;
		notifier.raisePropertyChanged(&desc_ShadowMode);
	}
}
