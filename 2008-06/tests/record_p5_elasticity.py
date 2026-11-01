"""Record original 2008 elasticity constants and the measured falling-block bounce."""
import hashlib
import json
import pathlib
import struct
import subprocess

import pefile

root = pathlib.Path(__file__).resolve().parents[3]
original = root / 'work/2008-06/original-p4-reference/Roblox.exe'
fall = root / 'work/2008-06/p5-original-fall-1-0bc4b85c42/receipt.json'
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
assert sha(original) == '2fbbfdf8577b5b28ea198c14747613ba8fd83d094363b2b23fe2f9e587343764'
pe = pefile.PE(str(original))
addresses = [0x81c430, 0x84afec, 0x84afe8, 0x84afe4, 0x843768, 0x84afe0, 0x84afdc, 0x819b48]
values = [struct.unpack('<f', pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, 4))[0] for address in addresses]
expected = [.05, .28, .26, .42, .51, .57, .76, .8]
assert all(abs(a-b) < 1e-6 for a, b in zip(values, expected))
samples = json.loads(fall.read_text())['comparisons']
assert samples[5]['original_y'] > samples[4]['original_y'] + 5
assert samples[6]['original_y'] > samples[5]['original_y'] + 5
out = root / 'work/2008-06/p5-elasticity-source-322f7a5c31'
out.mkdir(exist_ok=False)
receipt = {'revision': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
           'original_sha256': sha(original), 'observer_sha256': sha(pathlib.Path(__file__)),
           'fall_receipt_sha256': sha(fall), 'target_function': '00649320',
           'constants': {hex(a): v for a, v in zip(addresses, values)},
           'original_fall_samples': samples[4:7],
           'scope': 'Original function constants and existing falling-block observation. Character landing is not explained by this alone.'}
(out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print('original elasticity constants and observed bounce PASS')
