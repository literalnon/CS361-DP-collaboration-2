using Microsoft.VisualStudio.TestTools.UnitTesting;
using EratosthenesSieveSet;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EratosthenesSieveSet.Tests
{
    [TestClass()]
    public class EratosthenesSieveSetTests
    {
        public void Check(int n, int[] before, int[] after)
        {
            EratosthenesSieveSet sieve = new EratosthenesSieveSet(n);
            List<int> numbers = new List<int>(before);
            sieve.RemoveNotPrimes(numbers);
            Assert.IsTrue(numbers.SequenceEqual(new List<int>(after)));
        }

        [TestMethod()]
        public void CheckEratosthenesSieveSet()
        {
            Check(0, new int[] { 1 }, new int[] { 1 });
            Check(0, new int[] { 1, 2 }, new int[] { 1, 2 });
            Check(0, new int[] { 1, 2, 3 }, new int[] { 1, 2, 3 });
            Check(1, new int[] { 1, 2, 3 }, new int[] { 1, 2, 3 });
            Check(5, new int[] { 1, 2, 3, 4 }, new int[] { 1, 2, 3 });
            Check(5, new int[] { 1, 2, 3, 4, 5, 6, 7, 8 }, new int[] { 1, 2, 3, 5, 6, 7, 8 });
        }
    }
}