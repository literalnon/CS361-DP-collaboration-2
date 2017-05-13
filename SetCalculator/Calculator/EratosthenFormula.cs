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
        Formula f;
        int cnt;

        public EratosthenFormula(Formula formula, int n)
        {
            cnt = n;
            f = formula;
        }

        public SortedSet<int> Evaluate()
        {
            var eratostheneFormula = new EratosthenesSieveSet.EratosthenesSieveSet(cnt);

            List<int> list = new List<int>();
            SortedSet<int> set = f.Evaluate();

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
            return "(" + f + ")" + "#" + cnt.ToString();

        }
    }
}
