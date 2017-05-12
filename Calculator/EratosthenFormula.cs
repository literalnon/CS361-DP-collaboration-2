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

        public EratosthenFormula(SortedSet<int> set, int n)
        {
            cnt = n;
            Assembly a = Assembly.Load("EratosthenesSieveSet");
            Object o = a.CreateInstance("EratosthenesSieveSet");
            Type E_Set = a.GetType("EratosthenesSieveSet");
            MethodInfo m_create = E_Set.GetMethod("EratosthenesSieveSet");
            m_create.Invoke(o, new Object[1] { n });
            MethodInfo m_remove_not_primes = E_Set.GetMethod("RemoveNotPrimes");
            List<int> list = new List<int>();

            foreach (int s in set)
                list.Add(s);

            m_remove_not_primes.Invoke(o, new Object[1] { list });
            set = new SortedSet<int>();
            foreach (int x in list)
                set.Add(x);
        }

        public SortedSet<int> Evaluate()
        {
            return set;
        }

        public override string ToString()
        {
            return "(" + string.Join(", ", set) + ")" + "#" + cnt;
        }
    }
}
