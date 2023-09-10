using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmTravel
{
    class Program
    {
        static void Main(string[] args)
        {
            // Sort 
            int[] arrSortArray = { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            SortClass sortClass = new SortClass();
            //sortClass.BubbleSort(arrSortArray);
            //sortClass.SelectionSort(arrSortArray);
            //sortClass.InsertionSort(arrSortArray);
            //sortClass.MergeSort(arrSortArray, 0, arrSortArray.Length - 1);
            sortClass.QuickSort2(arrSortArray, 0, arrSortArray.Length - 1);
            sortClass.PrintArray(arrSortArray);
        }
    }
}
