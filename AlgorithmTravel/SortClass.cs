using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SortTravel
{
    class SortClass
    {
        public void BubbleSort(int[] array)
        {
            {
                //for (int i = 0; i < array.Length - 1; i++)
                //{
                //    int iEndNumber = array.Length - i;

                //    for(int k = 1; k < iEndNumber; k++)
                //    {
                //        if (array[k - 1] > array[k])
                //        {
                //            int iTemp = array[k];
                //            array[k] = array[k - 1];
                //            array[k - 1] = iTemp;
                //        }
                //    }
                //}
            }

            {
                for(int i = 0; i < array.Length - 1; i++)
                {
                    int iEnd = array.Length - 1;

                    for(int k = 1; k < iEnd; k++)
                    {
                        if (array[k - 1] > array[k])
                        {
                            int iTemp = array[k];
                            array[k] = array[k - 1];
                            array[k - 1] = iTemp;
                        }
                    }
                }
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
                for(int i = 1; i < array.Length; i++)
                {
                    int k = i - 1;
                    int iKey = array[i];

                    for(; k >= 0 && array[k] > iKey; k--)
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
                //if(iStartIndex < iEndIndex)
                //{
                //    int iMiddleIndex = (iStartIndex + iEndIndex) / 2;

                //    MergeSort(array, iStartIndex, iMiddleIndex);
                //    MergeSort(array, iMiddleIndex + 1, iEndIndex);

                //    Merge(array, iStartIndex, iMiddleIndex, iEndIndex);
                //}
            }

            {
                if(iStartIndex < iEndIndex)
                {
                    int iMiddleIndex = (iStartIndex + iEndIndex) / 2;

                    MergeSort(array, iStartIndex, iMiddleIndex);
                    MergeSort(array, iMiddleIndex + 1, iEndIndex);

                    Merge(array, iStartIndex, iMiddleIndex, iEndIndex);
                }
            }
        }
        void Merge(int[] array, int iStartIndex, int iMiddleIndex, int iEndIndex)
        {
            {
                int[] arrTemp = new int[array.Length];
                int iArrTempIndex = iStartIndex;
                int iFirstPartIndex = iStartIndex;
                int iSecondPartIndex = iMiddleIndex + 1;

                while(iFirstPartIndex <= iMiddleIndex && iSecondPartIndex <= iEndIndex)
                {
                    if(array[iFirstPartIndex] < array[iSecondPartIndex])
                    {
                        arrTemp[iArrTempIndex++] = array[iFirstPartIndex++];
                    }
                    else
                    {
                        arrTemp[iArrTempIndex++] = array[iSecondPartIndex++];
                    }
                }

                while(iFirstPartIndex <= iMiddleIndex)
                {
                    arrTemp[iArrTempIndex++] = array[iFirstPartIndex++];
                }
                while(iSecondPartIndex <= iEndIndex)
                {
                    arrTemp[iArrTempIndex++] = array[iSecondPartIndex++];
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
                int iMiddleIndex = (iStartIndex + iEndIndex) / 2;
                int iKey = array[iMiddleIndex];

                while(iStartIndex <= iEndIndex)
                {
                    while (array[iStartIndex] < iKey)
                    {
                        iStartIndex++;
                    }

                    while (array[iEndIndex] > iKey)
                    {
                        iEndIndex--;
                    }
                    
                    if(iStartIndex <= iEndIndex)
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
