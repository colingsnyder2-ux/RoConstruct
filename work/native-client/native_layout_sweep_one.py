"""Layout dump + layout gate for one source, keeping only the gate result."""
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
source, out = Path(sys.argv[1]), Path(sys.argv[2])
with tempfile.TemporaryDirectory() as tmp:
    layout = Path(tmp) / 'layout.json'
    if subprocess.run([sys.executable, str(HERE / 'native_class_layout.py'), str(source), '--output', str(layout)]).returncode == 0:
        subprocess.run([sys.executable, str(HERE / 'native_layout_gate.py'), str(layout),
                        '--fields', str(HERE / 'claude-field-evidence.json'),
                        '--output', str(out / (source.stem + '.gate.json'))])
