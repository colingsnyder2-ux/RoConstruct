"""Check corrected geometry instructions and exact actual archive member identity."""
import hashlib
import json
from pathlib import Path
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent
scope = ROOT / 'work/2008-06/shared-layouts/sol-drag-abi-20261105'
sha = lambda data: hashlib.sha256(data).hexdigest()
hashes = {'helper-providers.json': 'b51a9dbad6b2d76ce7051cc0563b83e6387f4763afa1cf36ae374b5a7cf65f53',
          'contracts.json': 'fd1d26f383401d56fd3a49aab84bdccfe7b6a24cfa8901f40d3164ee97207316'}
for name, expected in hashes.items():
    assert sha((scope / name).read_bytes()) == expected
providers = json.loads((scope / 'helper-providers.json').read_text())
row = next(row for row in providers['providers'] if row['helper'] == 'anyPartAlive')
raw = Path(row['input']).read_bytes()
assert sha(raw) == row['input_sha256']
offset = row['member_offset']
assert offset == 22672778 and raw[offset+58:offset+60] == b'`\n'
size = int(raw[offset+48:offset+58])
assert sha(raw[offset+60:offset+60+size]) == row['member_sha256']
contracts = json.loads((scope / 'contracts.json').read_text())
campaign = json.loads((HERE / 'campaign.json').read_text())
current_archive = Path(campaign['cumulative_archive'])
current = current_archive.read_bytes()
assert sha(current) == campaign['cumulative_archive_sha256']
position, positions = 8, []
while position < len(current):
    header = current[position:position+60]
    assert header[58:] == b'`\n'
    length = int(header[48:58])
    if sha(current[position+60:position+60+length]) == row['member_sha256']:
        positions.append(position)
    position += 60 + length + (length & 1)
assert len(positions) == 1
original = ROOT / 'clients/2008-06/Roblox.exe'
assert sha(original.read_bytes()) == contracts['original_sha256']
pe = pefile.PE(str(original))
body = contracts['original_bodies']['0060ff80']
raw = pe.get_data(0x0060ff80 - pe.OPTIONAL_HEADER.ImageBase, body['size'])
assert sha(raw) == body['sha256']
instructions = list(Cs(CS_ARCH_X86, CS_MODE_32).disasm(raw, 0x0060ff80))
window = [dict(address=hex(i.address), mnemonic=i.mnemonic, operands=i.op_str)
          for i in instructions if 0x0060ffea <= i.address <= 0x00610000]
assert window[0]['operands'] == 'eax, dword ptr [ecx + 0x9c]'
assert all(i['mnemonic'] != 'call' for i in window)
report = {'status': 'corrected static evidence verified', 'evidence_hashes': hashes,
          'previous_archive': row['input'], 'previous_archive_member_offset': offset,
          'current_archive': str(current_archive), 'current_archive_sha256': sha(current),
          'archive_member_offset': positions[0], 'archive_member_sha256': row['member_sha256'],
          'original_geometry_reads': window,
          'all_original_calls': [dict(address=hex(i.address), operands=i.op_str)
                                 for i in instructions if i.mnemonic == 'call'],
          'correction': 'No Geometry virtual call in this body. Indirect CRT and transitive helper/RTTI/EH obligations remain.',
          'selected_pe_proven': False, 'source_compiles': 0}
(HERE / 'drag-static-correction.json').write_text(json.dumps(report, indent=2) + '\n')
print(report['status'])
