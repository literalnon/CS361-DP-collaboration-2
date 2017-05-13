using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Calculator
{
    class EratosthenFormula : Formula
    {
        SortedSet<int> set;
        int cnt;

        public EratosthenFormula(SortedSet<int> formula_set, int n)
        {
            cnt = n;
            set = formula_set;
        }

        public SortedSet<int> Evaluate()
        {
            var eratostheneFormula = new EratosthenesSieveSet.EratosthenesSieveSet(cnt);

            List<int> list = new List<int>();

            foreach (int s in set)
                list.Add(s);

            eratostheneFormula.RemoveNotPrimes(list);
            set = new SortedSet<int>();

            foreach (int x in list)
                set.Add(x);
            return set;
        }

        public override string ToString()
        {
            return "(" + string.Join(", ", set) + ")" + "#" + cnt.ToString();
        }
    }
}
