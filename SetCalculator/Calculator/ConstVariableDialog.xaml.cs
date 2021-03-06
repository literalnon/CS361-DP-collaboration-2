﻿using System;
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
    public partial class ConstVariableDialog : Window
    {
        public int VariableName { get; private set; }

        public ConstVariableDialog()
        {
            InitializeComponent();
        }

        private bool Validate(string name)
        {
            return 0 != name.Length && name.All(c => char.IsDigit(c));
        }

        private void OKButton_Click(object sender, RoutedEventArgs e)
        {
            if (!Validate(ResponseTextBox.Text))
            {
                MessageBox.Show("не константа!");
                return;
            }
            VariableName = int.Parse(ResponseTextBox.Text);
            DialogResult = true;
        }

        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            DialogResult = false;
        }
    }
}
