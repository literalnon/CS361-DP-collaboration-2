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
using System.Windows.Shapes;

namespace Calculator
{
    public partial class ConstantDialog : Window
    {
        public SortedSet<int> resultSet = new SortedSet<int>();

        public ConstantDialog()
        {
            InitializeComponent();
        }

        private void AddClick(object sender, RoutedEventArgs e)
        {
            var textNumber = NewItem.Text;
            int number;
            if (!int.TryParse(textNumber, out number))
            {
                MessageBox.Show("Ошибка: введено не число");
                return;
            }
            NewItem.Text = "";
            if (resultSet.Contains(number))
                return;
            resultSet.Add(number);
            var newTextBlock = new TextBlock();
            newTextBlock.Text = textNumber;
            ListOfNumbers.Items.Add(newTextBlock);
        }

        private void OkButtonClick(object sender, RoutedEventArgs e)
        {
            DialogResult = true;
        }
    }
}
