from roc import rebuild
client = '2008-06'
ws = rebuild.workspace(client)
OUT = rebuild.ROOT / 'work/native-client/link'
rsp = OUT / 'link.rsp'
system = ['kernel32.lib', 'user32.lib', 'gdi32.lib', 'advapi32.lib', 'shell32.lib', 'ole32.lib', 'oleaut32.lib', 'uuid.lib',
          'comdlg32.lib', 'comctl32.lib', 'ws2_32.lib', 'winmm.lib', 'opengl32.lib', 'glu32.lib', 'imagehlp.lib',
          'version.lib', 'wininet.lib', 'dbghelp.lib', 'psapi.lib', 'shlwapi.lib', 'urlmon.lib', 'oledlg.lib', 'msimg32.lib']
cmd = ['link', '/nologo', '/SUBSYSTEM:WINDOWS', '/MACHINE:X86', '/FORCE', '/MAP:Roblox2008_force.map',
       '/OUT:Roblox2008_force.exe', '@' + str(rsp)] + system
cmd += ['/NODEFAULTLIB:' + l for l in rebuild.VENDOR_AUTOLINK]
cmd += ['/NODEFAULTLIB:' + str(rebuild.ROOT / 'tools/rbxgs/Client/fmod/api/lib/fmodexL_vc.lib')]
# Write to a batch file
batch_lines = ['cd /d "' + str(OUT) + '"']
batch_lines.append(' '.join('"' + c + '"' if ' ' in c else c for c in cmd))
batch = OUT / 'link_force.bat'
batch.write_text('\n'.join(batch_lines))
print(f'Written to {batch}')
print(f'Command: {" ".join(cmd[:3])} ...')
