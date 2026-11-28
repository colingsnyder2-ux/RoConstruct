import ast
import json
import re
import unittest
from pathlib import Path

root = Path(__file__).parent
tree = ast.parse((root / 'natinit.py').read_text())
function = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'literal_matches_symbol')
scope = {'re': re}
exec(compile(ast.Module(body=[function], type_ignores=[]), 'natinit.py', 'exec'), scope)
matches = scope['literal_matches_symbol']


class InitializerBindings(unittest.TestCase):
    def test_descriptor_name_must_match(self):
        self.assertTrue(matches(['State', 'ScriptsDisabled'], '?propScriptsDisabled@ScriptContext@RBX@@'))
        self.assertFalse(matches(['userId', 'CreateLocalPlayer'], '?event_IncommingConnection@Server@Network@RBX@@'))
        self.assertFalse(matches(['Data', 'CurrentAngle'], '?creator@?$FactoryProduct@VProperties@Metadata@@'))

    def test_current_plan_has_no_mismatched_literals(self):
        plan = json.loads((root / 'auto/natinit_plan.json').read_text())
        scan = json.loads((root / 'auto/initscan.json').read_text())
        for address, (symbol, offset) in plan.items():
            original = '%08x' % (int(address[4:], 16) - offset)
            literals = scan.get(original, {}).get('literals', [])
            self.assertTrue(matches(literals, symbol), (address, literals, symbol))


if __name__ == '__main__':
    unittest.main()
