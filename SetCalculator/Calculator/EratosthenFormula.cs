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
<<<<<<< HEAD
=======
        //SortedSet<int> set;
>>>>>>> ac6700f79d670677c3831b550d19540979a6c2c3
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
<<<<<<< HEAD
            return "(" + f + ")" + "#" + cnt.ToString();
=======
            return f + "#" + cnt.ToString();
>>>>>>> ac6700f79d670677c3831b550d19540979a6c2c3
        }
    }
}
