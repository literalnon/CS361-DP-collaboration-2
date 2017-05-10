using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    abstract class BinaryFormula : Formula
    {
        protected Formula lhs;
        protected Formula rhs;

        protected BinaryFormula(Formula lhs, Formula rhs)
        {
            this.lhs = lhs;
            this.rhs = rhs;
        }

        public abstract SortedSet<int> Evaluate();

        protected abstract string GetOperationSymbol();

        public override string ToString()
        {
            return "(" + lhs.ToString() + ") " + GetOperationSymbol() + " (" + rhs.ToString() + ")";
        }
    }
}
