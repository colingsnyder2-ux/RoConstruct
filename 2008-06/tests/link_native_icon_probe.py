from pathlib import Path
p=Path('rebuild/2008-06/p6/build_client.py').resolve()
s=p.read_text(encoding='utf8')
s=s.replace('out = rebuild.workspace(client) / "out" / "p6"','out = rebuild.workspace(client) / "out" / "native-icon-link-probe"')
s=s.replace('"/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO"] + [u[0] for u in units]', '"/NODEFAULTLIB:mfcs90.lib", "/MANIFEST:NO", "/INCLUDE:?InitializeAllIcons@@YAXPAVCXTPImageManager@@@Z", str(ROOT / "rebuild/2008-06/out/native-layouts/NativeFrameIconsFresh.obj"), str(ROOT / "rebuild/2008-06/out/native-layouts/NativeFrameIconWidth.obj")] + [u[0] for u in units]')
s=s.replace('system = ["kernel32"', 'system = ["gdiplus", "kernel32"')
exec(compile(s,str(p),'exec'),{'__file__':str(p),'__name__':'__main__'})
