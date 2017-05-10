using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class VariableFormula : Formula
    {
        private string name;
        private Formula value;

        public VariableFormula(string name, Formula value)
        {
            this.name = name;
            this.value = value;
        }

        public SortedSet<int> Evaluate()
        {
            return value.Evaluate();
        }

        public override string ToString()
        {
            return name;
        }
    }
}
