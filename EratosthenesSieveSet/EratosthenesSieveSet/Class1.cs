using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EratosthenesSieveSet
{
    public class EratosthenesSieveSet
    {
        List<int> arr_simple_digits;
        int cnt;

        EratosthenesSieveSet(int n)
        {
            cnt = n;

            arr_simple_digits = new List<int>(); // создание массива 

            for (int i = 0; i < n; i++) // и инициализация его всеми единицами
            {
                arr_simple_digits[i] = 1;
            }

            for (int i = 2; i < n; i++) // цикл прохода по всему массиву с первого простого числа "2"
            {
                if (arr_simple_digits[i] == 1)
                {
                    for (int j = i; j < n; j += i) // вычеркивание всех чисел кратных данному невычеркнутому
                    {
                        arr_simple_digits[j] = 0;
                    }
                    arr_simple_digits[i] = 1; // присваивание данному числу значение простого
                }
            }
        }

        public void RemoveNotPrimes(List<int> list_digits)
        {
            for(int i = 0; i < list_digits.Count; i++){
                if (list_digits.ElementAt(i) < cnt && arr_simple_digits.ElementAt(list_digits.ElementAt(i)) == 0)
                    list_digits.RemoveAt(i);

            }
        }
    }
}
