import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SCRIPT = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_provider_queue.py'
spec = importlib.util.spec_from_file_location('native_provider_queue', SCRIPT)
queue = importlib.util.module_from_spec(spec)
spec.loader.exec_module(queue)
SYMBOL = '?start@Service@RBX@@QAEXXZ'


def error(obj='Caller.obj', code='2019'):
    return f'{obj} : error LNK{code}: unresolved external symbol "public: void __thiscall RBX::Service::start(void)" ({SYMBOL}) referenced in function "caller"'


class ProviderQueueTests(unittest.TestCase):
    def test_deduplicate_requesters(self):
        rows = queue.parse_errors('\n'.join([error(), error(), error('Other.obj', '2001')]))
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]['requesters'], ['Caller.obj', 'Other.obj'])
        self.assertEqual(rows[0]['symbol'], SYMBOL)

    def test_leads_are_not_providers_and_object_failures_visible(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            log = base / 'link.log'
            log.write_text(error())
            (base / 'Service.cpp').write_text('void Service::start() {}\n')
            result = queue.inventory(log, [base], [base])
            self.assertEqual(result['queue'][0]['status'], 'source_lead_only')
            self.assertEqual(result['queue'][0]['source_leads'][0]['line'], 1)
            (base / 'Service.obj').write_bytes(b'broken' + SYMBOL.encode('ascii'))
            result = queue.inventory(log, [base], [base])
            self.assertEqual(len(result['scan_errors']), 1)
            with patch.object(queue.match, '_coff_data_index', return_value=([], {}, {SYMBOL: (0, 0)}, {})):
                result = queue.inventory(log, [base], [base])
            self.assertEqual(result['queue'][0]['status'], 'object_definition_found')
            self.assertEqual(len(result['queue'][0]['object_definitions'][0]['sha256']), 64)

    def test_default_search_includes_organized_sources(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            moved = base / 'App/src/v8datamodel'
            moved.mkdir(parents=True)
            (moved / 'Service.cpp').write_text('void Service::start() {}\n')
            (base / 'native-classes').mkdir()
            log = base / 'link.log'
            log.write_text(error())
            result = queue.inventory(log, [], queue.default_source_dirs(base))
            self.assertEqual(result['queue'][0]['status'], 'source_lead_only')
            self.assertEqual(result['queue'][0]['source_leads'][0]['path'], str(moved / 'Service.cpp'))

    def test_2001_without_reference_and_constructor(self):
        line = 'a.obj : error LNK2001: unresolved external symbol "public: __thiscall RBX::Thing::Thing(void)" (??0Thing@RBX@@QAE@XZ)'
        self.assertEqual(len(queue.parse_errors(line)), 1)
        self.assertEqual(queue.source_terms(queue.parse_errors(line)[0]['display']), {('Thing', 'Thing')})

    def test_template_member(self):
        self.assertIn(('TToolVerb', 'newMouseCommand'), queue.source_terms('RBX::TToolVerb<class RBX::ArrowTool,class RBX::RunStateVerb>::newMouseCommand(void)'))


if __name__ == '__main__':
    unittest.main()
