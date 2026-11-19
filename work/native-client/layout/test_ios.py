import unittest

import layout_ios


class IosNameTest(unittest.TestCase):
    def test_msvc_and_itanium_names_meet(self):
        self.assertEqual(layout_ios.msvc('?setParent@Instance@RBX@@QAEXPAV12@@Z'), ('RBX', 'Instance', 'setParent'))
        self.assertEqual(layout_ios.itanium('__ZN3RBX8Instance9setParentEPS0_'), ('RBX', 'Instance', 'setParent'))
        self.assertEqual(layout_ios.msvc('??0Instance@RBX@@QAE@XZ'), ('RBX', 'Instance', '<init>'))
        self.assertEqual(layout_ios.itanium('__ZN3RBX8InstanceC1Ev'), ('RBX', 'Instance', '<init>'))
        self.assertIsNone(layout_ios.msvc('??$create@VTeams@RBX@@@Foo@@YAXXZ'))      # template
        self.assertIsNone(layout_ios.msvc('??8Foo@@QAE_NABV0@@Z'))                    # operator

    def test_client_path_keeps_case_and_resolves_dotdot(self):
        self.assertEqual(layout_ios.client_path('/Volumes/x/work/id/Client/iOS/../ClientShared/A.cpp'), 'client/ClientShared/A.cpp')
        self.assertIsNone(layout_ios.client_path('/Volumes/x/Contrib2/AppRater/Appirater.m'))

    def test_winner_needs_votes_and_share(self):
        ios = {('A', 'f'): {'client/App/a.cpp': 1}, ('A', 'g'): {'client/App/a.cpp': 1}, ('B', 'h'): {'client/App/b.cpp': 1}}

        def job(*names):
            return {'source': 's', 'checks': [{'symbol': '?%s@%s@@QAEXXZ' % (n[1], n[0])} for n in names]}
        self.assertEqual(layout_ios.targets([job(('A', 'f'), ('A', 'g'))], ios)['s']['target'], 'client/App/a.cpp')
        self.assertEqual(layout_ios.targets([job(('A', 'f'))], ios), {})                         # one vote is thin
        self.assertEqual(layout_ios.targets([job(('A', 'f'), ('A', 'g'), ('B', 'h'), ('B', 'h'))], ios), {})   # 50% share


if __name__ == '__main__':
    unittest.main()
