using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortTravel
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[] sortArray = { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            SortClass sortClass = new SortClass();
            //sortClass.BubbleSort(sortArray);
            //sortClass.SelectionSort(sortArray);
            //sortClass.InsertionSort(sortArray);
            //sortClass.MergeSort(sortArray, 0, sortArray.Length - 1);
            //sortClass.QuickSort(sortArray, 0, sortArray.Length - 1);
            //PrintArray(sortArray);
            RunAllMethod(sortClass);
        }

        static void RunAllMethod(SortClass sc)
        {
            int[] sortArray = { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            Console.Write("버블 정렬 전: ");
            PrintArray(sortArray);
            sc.BubbleSort(sortArray);
            Console.Write("                                                 버블 정렬 후: ");
            PrintArray(sortArray);

            sortArray = new int[] { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            Console.Write("선택 정렬 전: ");
            PrintArray(sortArray);
            sc.SelectionSort(sortArray);
            Console.Write("                                                선택 정렬 후: ");
            PrintArray(sortArray);

            sortArray = new int[] { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            Console.Write("삽입 정렬 전: ");
            PrintArray(sortArray);
            sc.InsertionSort(sortArray);
            Console.Write("                                                 삽입 정렬 후: ");
            PrintArray(sortArray);

            sortArray = new int[] { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            Console.Write("합병 정렬 전: ");
            PrintArray(sortArray);
            sc.MergeSort(sortArray, 0, sortArray.Length - 1);
            Console.Write("                                               합병 정렬 후: ");
            PrintArray(sortArray);  

            sortArray = new int[] { 6, 85, 231, 112, 14, 64, 22, 1, 78 };
            Console.Write("퀵 정렬 전: ");
            PrintArray(sortArray);
            sc.QuickSort(sortArray, 0, sortArray.Length - 1);
            Console.Write("                                               퀵 정렬 후: ");
            PrintArray(sortArray);
        }

        static void PrintArray(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
        }
    }
}
