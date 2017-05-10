using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class ConstFormula : Formula
    {
        private SortedSet<int> set;

        public ConstFormula(SortedSet<int> set)
        {
            this.set = set;
        }

        public SortedSet<int> Evaluate()
        {
            return set;
        }

        public override string ToString()
        {
            return "[" + string.Join(", ", set) + "]";
        }
    }
}
