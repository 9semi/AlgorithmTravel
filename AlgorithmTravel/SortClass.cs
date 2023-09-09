using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgorithmTravel
{
    class SortClass
    {
        public void PrintArray(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
        }

        public void BubbleSort(int[] array)
        {
            int iEndNumber;

            for (int i = 0; i < array.Length; i++)
            {
                iEndNumber = array.Length - i;

                for (int k = 1; k < iEndNumber; k++)
                {
                    if (array[k - 1] > array[k])
                    {
                        int temp = array[k - 1];
                        array[k - 1] = array[k];
                        array[k] = temp;
                    }
                }
            }
        }

        public void SelectionSort(int[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                for (int k = i + 1; k < array.Length; k++)
                {
                    if (array[i] > array[k])
                    {
                        int temp = array[i];
                        array[i] = array[k];
                        array[k] = temp;
                    }
                }
            }
        }

        public void InsertionSort(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                int iKey = array[i];
                int k = i - 1;

                for (; k >= 0 && iKey < array[k]; k--)
                {
                    array[k + 1] = array[k];
                }
                array[k + 1] = iKey;
            }
        }

        public void MergeSort(int[] array, int iStartIndex, int iEndIndex)
        {
            if (iStartIndex < iEndIndex)
            {
                int iMiddleIndex = (iStartIndex + iEndIndex) / 2;

                MergeSort(array, iStartIndex, iMiddleIndex);
                MergeSort(array, iMiddleIndex + 1, iEndIndex);

                Merge(array, iStartIndex, iMiddleIndex, iEndIndex);
            }
        }
        public void Merge(int [] array, int iStartIndex, int iMiddleIndex, int iEndIndex)
        {
            int[] arrTemp = new int[array.Length];
            int iTempArrayIndex = 0;
            int iFirstPartStartIndex = iStartIndex;
            int iSecondPartStartIndex = iMiddleIndex + 1;

            while(iFirstPartStartIndex <= iMiddleIndex && iSecondPartStartIndex <= iEndIndex)
            {
                if(array[iFirstPartStartIndex] > array[iSecondPartStartIndex])
                {
                    arrTemp[iTempArrayIndex++] = array[iFirstPartStartIndex++];
                }
                else
                {
                    arrTemp[iTempArrayIndex++] = array[iSecondPartStartIndex++];
                }
            }
            
        }
    }
}
