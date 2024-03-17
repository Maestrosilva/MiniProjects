using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        private double num1;
        private double num2;
        private string sign;
        private double result;
        public Form1()
        {
            InitializeComponent();
        }

        private void btn_num_click(object sender, EventArgs e)
        {
            if (textBox.Text.Equals("0") && !((Button)sender).Text.Equals(","))
            {
                textBox.Clear();
            }
            textBox.Text = textBox.Text + ((Button)sender).Text;
        }

        private void btn_sign_click(object sender, EventArgs e)
        {
            try
            {
                if (textBox.Text[0].Equals(','))
                {
                    textBox.Text = "0" + textBox.Text;
                }
                num1 = double.Parse(textBox.Text);
            }
            catch (Exception){}
            label.Text = num1.ToString();
            sign = ((Button)sender).Text;
            label.Text = num1 + " " + sign + " ";
            result = 0;
            textBox.Clear();
        }

        private void clear(object sender, EventArgs e)
        {
            textBox.Text = textBox.Text.Substring(0, textBox.Text.Length - 1);
        }

        private void clearAll(object sender, EventArgs e)
        {
            label.Text = "";
            textBox.Clear();
            num1 = 0;
            num2 = 0;
            result = 0;
            sign = "";
        }

        private void equals(object sender, EventArgs e)
        {
           
            if (textBox.Text[0].Equals(','))
            {
                textBox.Text = "0" + textBox.Text[0];
                Console.WriteLine(textBox.Text);
            }
            try
            {
                if (result == 0)
                    num2 = double.Parse(textBox.Text);
            }
            catch (Exception) { }
            try
            {
                switch (sign)
                {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "/":
                        result = num1 / num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                }
                textBox.Text = result.ToString();
            }
            catch (Exception) { }
            label.Text = num1 + " " + sign + " " + num2 + " = ";
        }
    }
}