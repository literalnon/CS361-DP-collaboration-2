using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class IntersectFormula : BinaryFormula
    {
        public IntersectFormula(Formula lhs, Formula rhs) : base(lhs, rhs)
        {
        }

        public override SortedSet<int> Evaluate()
        {
            var result = lhs.Evaluate();
            result.IntersectWith(rhs.Evaluate());
            return result;
        }

        protected override string GetOperationSymbol()
        {
            return "∩";
        }
    }
}
