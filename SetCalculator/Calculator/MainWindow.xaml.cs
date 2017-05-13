using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{
    public partial class MainWindow : Window
    {
        private Formula rootFormula = new ConstFormula(new SortedSet<int>());
        private List<VariableFormula> savedVariables = new List<VariableFormula>();

        public MainWindow()
        {
            InitializeComponent();
            UpdateFormulaText();
            SetVariableOperationEnability(false);
        }

        private void UpdateFormulaText()
        {
            FormulaText.Text = rootFormula.ToString();
        }

        private Formula ObtainConstant()
        {
            var constantDialog = new ConstantDialog();
            constantDialog.Hide();
            if ((bool) constantDialog.ShowDialog())
                return new ConstFormula(constantDialog.resultSet);
            return null;
        }

        private Formula ObtainVariable()
        {
            return savedVariables[ListOfVariables.SelectedIndex];
        }

        private void ConstOperationClick(object sender, RoutedEventArgs e)
        {
            var rhs = ObtainConstant();
            if (null == rhs)
                return;
            if (UnionConst == sender)
                rootFormula = new UnionFormula(rootFormula, rhs);
            else if (IntersectConst == sender)
                rootFormula = new IntersectFormula(rootFormula, rhs);
            else if (DifferenceConst == sender)
                rootFormula = new DifferenceFormula(rootFormula, rhs);
            else if (SymmetricDifferenceConst == sender)
                rootFormula = new SymmetricDifferenceFormula(rootFormula, rhs);
            UpdateFormulaText();
        }

        private void VariableOperationClick(object sender, RoutedEventArgs e)
        {
            var rhs = ObtainVariable();
            if (UnionVar == sender)
                rootFormula = new UnionFormula(rootFormula, rhs);
            else if (IntersectVar == sender)
                rootFormula = new IntersectFormula(rootFormula, rhs);
            else if (DifferenceVar == sender)
                rootFormula = new DifferenceFormula(rootFormula, rhs);
            else if (SymmetricDifferenceVar == sender)
                rootFormula = new SymmetricDifferenceFormula(rootFormula, rhs);
            UpdateFormulaText();
        }

        private void EratospheneClick(object sender, RoutedEventArgs e)
        {
<<<<<<< HEAD
=======
           // rootFormula = ObtainConstant();

>>>>>>> ac6700f79d670677c3831b550d19540979a6c2c3
            var constDialog = new ConstVariableDialog();
            constDialog.Hide();
            int n = 0;
            if ((bool)constDialog.ShowDialog())
                n = constDialog.VariableName;
            rootFormula = new EratosthenFormula(rootFormula, n);
            UpdateFormulaText();
        }

        private void CalculateClick(object sender, RoutedEventArgs e)
        {
            rootFormula = new ConstFormula(rootFormula.Evaluate());
            UpdateFormulaText();
        }

        private void ClearEntryClick(object sender, RoutedEventArgs e)
        {
            rootFormula = ObtainConstant();
            UpdateFormulaText();
        }

        private void AddVariableClick(object sender, RoutedEventArgs e)
        {
            var dialog = new VariableNameDialog();
            if (!(bool)dialog.ShowDialog())
                return;
            var variableName = dialog.VariableName;
            savedVariables.Add(new VariableFormula(variableName, rootFormula));
            var textBox = new TextBlock();
            textBox.Text = variableName + " = " + rootFormula.ToString();
            ListOfVariables.Items.Add(textBox);
        }

        private void RemoveVariableClick(object sender, RoutedEventArgs e)
        {
            ListOfVariables.Items.RemoveAt(ListOfVariables.SelectedIndex);
        }

        private void SetVariableOperationEnability(bool enability)
        {
            UnionVar.IsEnabled = enability;
            IntersectVar.IsEnabled = enability;
            DifferenceVar.IsEnabled = enability;
            SymmetricDifferenceVar.IsEnabled = enability;
            RemoveVariable.IsEnabled = enability;
        }

        private void VariableSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var selectedVariable = ListOfVariables.SelectedIndex;
            SetVariableOperationEnability(-1 != selectedVariable);
        }
    }
}
