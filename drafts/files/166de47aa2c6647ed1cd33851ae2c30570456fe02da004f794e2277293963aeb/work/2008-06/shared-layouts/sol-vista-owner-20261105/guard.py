from pathlib import Path
import json,hashlib
F=Path(__file__).resolve().parent;R=F.parents[3]
inputs=json.loads((F/'guard-inputs.json').read_text());drift=[p for p,h in inputs.items() if not Path(p).exists() or hashlib.sha256(Path(p).read_bytes()).hexdigest()!=h]
comparison=json.loads((F/'body-comparison.json').read_text());assert not drift,drift
assert not comparison['changed'],'Rejected candidate: retained body/EH regression; archive replacement prohibited'
