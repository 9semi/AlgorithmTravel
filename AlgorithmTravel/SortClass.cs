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
            {
                for(int i = 0; i < array.Length; i++)
                {
                    int iEndNumber = array.Length - i;

                    for(int k = 1; k < iEndNumber; k++)
                    {
                        if(array[k - 1] > array[k])
                        {
                            int iTemp = array[k - 1];
                            array[k - 1] = array[k];
                            array[k] = iTemp;
                        }
                    }
                }
            }

            {
                //for (int i = 0; i < array.Length - 1; i++)
                //{
                //    int iEndNumber = array.Length - i;

                //    for(int k = 1; k < iEndNumber; k++)
                //    {
                //        if (array[k - 1] > array[k])
                //        {
                //            int iTemp = array[k - 1];
                //            array[k - 1] = array[k];
                //            array[k] = iTemp;
                //        }
                //    }
                //}
            }
        }

        public void SelectionSort(int[] array)
        {
            {
                for(int i = 0; i < array.Length - 1; i++)
                {
                    for (int k = i + 1; k < array.Length; k++)
                    {
                        if(array[i] > array[k])
                        {
                            int iTemp = array[i];
                            array[i] = array[k];
                            array[k] = iTemp;
                        }
                    }
                }
            }

            {
                //for(int i = 0; i < array.Length - 1; i++)
                //{
                //    for(int k = i + 1; k < array.Length; k++)
                //    {
                //        if(array[i] > array[k])
                //        {
                //            int iTemp = array[i];
                //            array[i] = array[k];
                //            array[k] = iTemp;
                //        }
                //    }
                //}
            }
        }

        public void InsertionSort(int[] array)
        {
            {
                for (int i = 1; i < array.Length; i++)
                {
                    int iKey = array[i];
                    int k = i - 1;
                    for(; k >= 0 && iKey < array[k]; k--)
                    {
                        array[k + 1] = array[k];
                    }

                    array[k + 1] = iKey;
                }
            }

            {
                //for (int i = 1; i < array.Length; i++)
                //{
                //    int k = i - 1;
                //    int iKey = array[i];

                //    for (; k >= 0 && array[k] > iKey; k--)
                //    {
                //        array[k + 1] = array[k];
                //    }

                //    array[k + 1] = iKey;
                //}
            }
        }

        public void MergeSort(int[] array, int iStartIndex, int iEndIndex)
        {
            {
                if (iStartIndex < iEndIndex)
                {
                    int iMiddleIndex = (iStartIndex + iEndIndex) / 2;
                    MergeSort(array, iStartIndex, iMiddleIndex);
                    MergeSort(array, iMiddleIndex + 1, iEndIndex);

                    Merge(array, iStartIndex, iMiddleIndex, iEndIndex);
                }
            }

            {
                //if(iStartIndex < iEndIndex)
                //{
                //    int iMiddleIndex = (iStartIndex + iEndIndex) / 2;

                //    MergeSort(array, iStartIndex, iMiddleIndex);
                //    MergeSort(array, iMiddleIndex + 1, iEndIndex);

                //    Merge(array, iStartIndex, iMiddleIndex, iEndIndex);
                //}
            }
        }
        void Merge(int [] array, int iStartIndex, int iMiddleIndex, int iEndIndex)
        {
            {
                int[] arrTemp = new int[array.Length];
                int arrTempIndex = iStartIndex;
                int iFirstPartIndex = iStartIndex;
                int iSecondPartIndex = iMiddleIndex + 1;

                while(iFirstPartIndex <= iMiddleIndex && iSecondPartIndex <= iEndIndex)
                {
                    if(array[iFirstPartIndex] < array[iSecondPartIndex])
                    {
                        arrTemp[arrTempIndex++] = array[iFirstPartIndex++];
                    }
                    else
                    {
                        arrTemp[arrTempIndex++] = array[iSecondPartIndex++];
                    }
                }

                while(iFirstPartIndex <= iMiddleIndex)
                {
                    arrTemp[arrTempIndex++] = array[iFirstPartIndex++];
                }

                while(iSecondPartIndex <= iEndIndex)
                {
                    arrTemp[arrTempIndex++] = array[iSecondPartIndex++];
                }

                for(int i = iStartIndex; i <= iEndIndex; i++)
                {
                    array[i] = arrTemp[i];
                }
            }

            {
                //int[] arrTemp = new int[array.Length];
                //int tempArrayIndex = iStartIndex;
                //int iFirstPartIndex = iStartIndex;
                //int iSecondPartIndex = iMiddleIndex + 1;
                
                //while(iFirstPartIndex <= iMiddleIndex && iSecondPartIndex <= iEndIndex)
                //{
                //    if(array[iFirstPartIndex] < array[iSecondPartIndex])
                //    {
                //        arrTemp[tempArrayIndex++] = array[iFirstPartIndex++];
                //    }
                //    else
                //    {
                //        arrTemp[tempArrayIndex++] = array[iSecondPartIndex++];
                //    }
                //}

                //while(iFirstPartIndex <= iMiddleIndex)
                //{
                //    arrTemp[tempArrayIndex++] = array[iFirstPartIndex++];
                //}

                //while(iSecondPartIndex <= iEndIndex)
                //{
                //    arrTemp[tempArrayIndex++] = array[iSecondPartIndex++];
                //}

                //for(int i = iStartIndex; i <= iEndIndex; i++)
                //{
                //    array[i] = arrTemp[i];
                //}
            }
        }

        public void QuickSort(int [] array, int iStartIndex, int iEndIndex)
        {
            {
                if(iStartIndex < iEndIndex)
                {
                    int iMiddleIndex = Partition(array, iStartIndex, iEndIndex);

                    QuickSort(array, iStartIndex, iMiddleIndex - 1);
                    QuickSort(array, iMiddleIndex, iEndIndex);
                }
            }

            {
                //if(iStartIndex < iEndIndex)
                //{
                //    int iMiddleIndex = Partition(array, iStartIndex, iEndIndex);

                //    QuickSort(array, iStartIndex, iMiddleIndex - 1);
                //    QuickSort(array, iMiddleIndex, iEndIndex);
                //}
            }
        }
        public int Partition(int [] array, int iStartIndex, int iEndIndex)
        {
            {
                int iPivotData = array[(iStartIndex + iEndIndex) / 2];

                while (iStartIndex <= iEndIndex)
                {
                    while (array[iStartIndex] < iPivotData)
                    {
                        iStartIndex++;
                    }

                    while (array[iEndIndex] > iPivotData)
                    {
                        iEndIndex--;
                    }

                    if (iStartIndex <= iEndIndex)
                    {
                        int iTemp = array[iStartIndex];
                        array[iStartIndex] = array[iEndIndex];
                        array[iEndIndex] = iTemp;

                        iStartIndex++;
                        iEndIndex--;
                    }
                }

                return iStartIndex;
            }

            {
                //int iPivotData = array[(iStartIndex + iEndIndex) / 2];

                //while(iStartIndex <= iEndIndex)
                //{
                //    while(iPivotData > array[iStartIndex])
                //    {
                //        iStartIndex++;
                //    }

                //    while(iPivotData < array[iEndIndex])
                //    {
                //        iEndIndex--;
                //    }

                //    if(iStartIndex <= iEndIndex)
                //    {
                //        int iTemp = array[iStartIndex];
                //        array[iStartIndex] = array[iEndIndex];
                //        array[iEndIndex] = iTemp;

                //        iStartIndex++;
                //        iEndIndex--;
                //    }
                //}

                //return iStartIndex;
            }
        }
    }
}
