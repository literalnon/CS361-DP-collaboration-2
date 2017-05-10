using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class SymmetricDifferenceFormula : BinaryFormula
    {
        public SymmetricDifferenceFormula(Formula lhs, Formula rhs) : base(lhs, rhs)
        {
        }

        public override SortedSet<int> Evaluate()
        {
            var result = lhs.Evaluate();
            result.SymmetricExceptWith(rhs.Evaluate());
            return result;
        }

        protected override string GetOperationSymbol()
        {
            return "∆";
        }
    }
}
